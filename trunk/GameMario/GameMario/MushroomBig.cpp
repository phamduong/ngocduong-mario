#include"MushroomBig.h"
CMushroomBig::CMushroomBig(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CMushroomBig::CMushroomBig(int _id,D3DXVECTOR2 pos){
	m_Id = _id;
	m_pos = pos;
	Init();
}
void CMushroomBig::Init(){
	CGameObject::Init();
	m_maxAccelemeter = D3DXVECTOR2(0.0f , -100.0f);
	m_maxVelocity = D3DXVECTOR2(10.0f, -60.0f);
	m_spriteLife = CResourceManager::GetInstance()->GetResouce(ITEM_ID);
	m_sprite = m_spriteLife;
	m_type = MUSHROOMBIGTYPE;
	m_collision = new CAABBCollision();
}
void CMushroomBig::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*> ListObjectInViewPort){
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
	/**************************************************************************************/
	vector<CGameObject*> ListObjectCollision;
	for (int i = 0; i < ListObjectInViewPort.size(); i++)
	{
		if(ListObjectInViewPort[i]->GetType()!=OBJECTTYPE)
		{
			ListObjectInViewPort[i]->m_TimeCollision = m_collision->CheckAABBCollision(this,ListObjectInViewPort[i],_time);
			//int timecollision = m_collision->CheckAABBCollision(this,ListObjectInViewPort[i],_time);
			if (ListObjectInViewPort[i]->m_TimeCollision<1.0f)
			{
				ListObjectInViewPort[i]->m_intetsect = m_collision->intersectX(this,ListObjectInViewPort[i],_time);
				ListObjectCollision.push_back(ListObjectInViewPort[i]);
			}
		}
	}


	if (ListObjectCollision.size()!=0)
	{	
		//xap sep theo thoi gian va giao theo x
		std::sort(ListObjectCollision.begin(),ListObjectCollision.end(),m_collision->SortObject);
		for (int i = 0; i < ListObjectCollision.size(); i++)
		{
			UpdateCollison(ListObjectCollision[i],_input,_time);
		}	
	}
}
void CMushroomBig::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetCurrentSprite(0);
	m_sprite->SetTimeAmination(0);
	m_sprite->UpdateSprite();
}
void CMushroomBig::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	CGameObject::Draw(_spritehandle,_camera);
}
void CMushroomBig::UpdateCollison(CGameObject* _orther, CInput* _input , float _time)
{
	float time = m_collision->CheckAABBCollision(this,_orther,_time);
	if(time<1.0f)
	{
		//ListObjectColision
		switch (_orther->GetType())
		{
		case PIPETYPE:
		case LANDTYPE:
		case COINQUESTIONTYPE:
			{
				if(m_collision->GetDirectCollision() == BOTTOM)
				{
					m_pos.y += GetVelocity().y*_time*time +2;
					m_pos.y = (int)m_pos.y;//_orther->GetBound().top + m_sprite->GetSpriteHeight()/2 + 2;
					SetVelocityY(0);
					m_accel.y = 0;
					SetBound();

				}
				if(m_collision->GetDirectCollision()== TOP)
				{
					m_pos.y += GetVelocity().y*_time*time-1;
					m_pos.y = (int)m_pos.y;
					SetVelocityY(0);
					m_accel.y = 0;
					SetBound();
				}
				if(m_collision->GetDirectCollision() == LEFT)
				{
					m_pos.x += GetVelocity().x*_time*time+1;
					m_pos.x = (int)m_pos.x;
					m_veloc.x = 0;
					m_accel.x = 0;
					SetBound();
					//MessageBox(NULL,"BOTTOM","",MB_OK);
				}

				if(m_collision->GetDirectCollision() == RIGHT)
				{
					m_pos.x += GetVelocity().x*_time*time-1;
					m_pos.x = (int)m_pos.x;
					m_veloc.x = 0;
					m_accel.x = 0;
					SetBound();
					//MessageBox(NULL,"BOTTOM","",MB_OK);
				}
				break;
			}
		}
	}
}
CMushroomBig::~CMushroomBig(){}

