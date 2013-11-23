#include"AABBCollisionDetected.h"
CAABBCollision::CAABBCollision()
{

}
CAABBCollision::~CAABBCollision()
{
}
bool CAABBCollision::CheckCollision(RECT Node,RECT orther)
{
	if (orther.right < Node.left)
		return false;
	else if (orther.left > Node.right)
		return false;
	else if (orther.top < Node.bottom)
		return false;
	else if (orther.bottom > Node.top)
		return false;
	return true;
}
float CAABBCollision::CheckAABBCollision(CGameObject* _Ob1,CGameObject* _Ob2,float _time)
{
	/*---------------------------------------------------------*/
	//tinh so pixels di duoc trong 1 frame
	D3DXVECTOR2 VelecOb1 = _Ob1->GetVelocity() * _time;
	D3DXVECTOR2 VelecOb2 = _Ob2->GetVelocity() * _time; 
	//Loai bo truong hop hien nhien  khong va cham
	RECT bound;//hcn bao quanh 2 fram lien tiep
	if(VelecOb1.x >= 0)
	{
		bound.left = _Ob1->GetBound().left;
		bound.right = _Ob1->GetBound().right + VelecOb1.x;
	}
	else
	{
		bound.right = _Ob1->GetBound().right;
		bound.left = _Ob1->GetBound().left + VelecOb1.x;
	}

	if(VelecOb1.y >= 0)
	{
		bound.bottom = _Ob1->GetBound().bottom;
		bound.top =_Ob1->GetBound().top + VelecOb1.y;
	}
	else
	{
		bound.top = _Ob1->GetBound().top;
		bound.bottom = _Ob1->GetBound().bottom + VelecOb1.y;
	}
	//hinh chu nhat co va cham moi su dung Swept aabb
	if (CheckCollision(bound,_Ob2->GetBound()))
	{
		// _time truyen vao la thoi gian thay doi 1 frame
		D3DXVECTOR2 TEntry;// = D3DXVECTOR2(0,0);// thoi gian de 1 va cham 2
		D3DXVECTOR2 TExit ;//= D3DXVECTOR2(1,1);//thoi gian de 1 thoat khoai 2
		D3DXVECTOR2 DEntry;// khoang cach de 1 va cham 2
		D3DXVECTOR2 DExit;//khoang cach  de 1 thoat khoai 2
		float TimeEntry,TimeExit;
		//Xet theo phuong X
		if(VelecOb1.x >0)//dt 1 dang di chuyen qua ben phai
		{
			DEntry.x = _Ob2->GetBound().left - _Ob1->GetBound().right;
			DExit.x = _Ob2->GetBound().right - _Ob1->GetBound().left;
		}
		else if(VelecOb1.x < 0)// di chuyen qua trai
		{
			DEntry.x = _Ob2->GetBound().right - _Ob1->GetBound().left;
			DExit.x = _Ob2->GetBound().left - _Ob1->GetBound().right;
		}
		//Xet theo phuong Y
		if(VelecOb1.y >0)//dt 1 dang di chuyen len
		{	
			DEntry.y = _Ob2->GetBound().bottom - _Ob1->GetBound().top;
			DExit.y = _Ob2->GetBound().top - _Ob1->GetBound().bottom;
		}
		else if(VelecOb1.y < 0)// di chuyen qua xuong
		{
			DEntry.y = _Ob2->GetBound().top - _Ob1->GetBound().bottom;
			DExit.y = _Ob2->GetBound().bottom - _Ob1->GetBound().top;
		}
		//Tinh thoi gian va cham && di qua
		if(VelecOb1.x == 0){
			TEntry.x = -std::numeric_limits<float>::infinity();
			TExit.x = std::numeric_limits<float>::infinity();
		}
		else
		{
			TEntry.x = DEntry.x / VelecOb1.x;
			TExit.x = DExit.x /VelecOb1.x;
		}
		if(VelecOb1.y == 0){
			TEntry.y = -std::numeric_limits<float>::infinity();
			TExit.y = std::numeric_limits<float>::infinity();
		}
		else
		{
			TEntry.y = DEntry.y / VelecOb1.y;
			TExit.y = DExit.y /VelecOb1.y;
		}
		TimeEntry = max(TEntry.x,TEntry.y);
		TimeExit = min(TExit.x,TExit.y);
		//if there are no collision
		if (TimeEntry > TimeExit || TEntry.x < 0.0f && TEntry.y < 0.0f  || TEntry.x > 1.0f||TEntry.y > 1.0f )
		{			
			return 1.0f;
		}
		//there are collision
		else 
		{
			if (TEntry.x > TEntry.y) 
			{
				if (DEntry.x < 0.0f) 
				{
					//MessageBox(NULL,"LEFT","THONG BAO",MB_OK);
					m_direct = LEFT;
				}
				else 
				{
					m_direct = RIGHT;
					//MessageBox(NULL,"RIGHT","THONG BAO",MB_OK);
				}        
			}
			else 
			{
				if (DEntry.y < 0.0f) 
				{
					m_direct = BOTTOM;
					//MessageBox(NULL,"BOTTOM","THONG BAO",MB_OK);
				} 
				else 
				{
					m_direct =TOP;
					//MessageBox(NULL,"TOP","THONG BAO",MB_OK);
				}
			}

			return TimeEntry;
		}
	}
	else
	{
		return 1.0f;
	}

}