#include"Object.h"

CGameObject::CGameObject(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CGameObject::CGameObject(int _id,D3DXVECTOR2 _mpos){
	m_Id = _id;
	m_pos = _mpos;
	Init();
}
CGameObject::~CGameObject(){}
void CGameObject::Init(){
	m_Islife = true;
	m_TimeShow = 0;
	m_IsShow = true;
	m_type  = OBJECTTYPE;
	m_veloc = D3DXVECTOR2(0,0);
	m_accel = D3DXVECTOR2(0,0);
	StartPostion = m_pos;
	m_GrowUp = false;
	m_EatBulet = false;
	m_IsShow = true;
	m_collision  =  new CAABBCollision();
}
void CGameObject::SetBound(){
	m_bound.left = (LONG)m_pos.x - m_sprite->GetSpriteWidth()/2;
	m_bound.bottom = (LONG)m_pos.y - m_sprite->GetSpriteHeight()/2;
	m_bound.right = (LONG)(m_bound.left + m_sprite->GetSpriteWidth());
	m_bound.top = (LONG)(m_bound.bottom + m_sprite->GetSpriteHeight() -2);

}
void CGameObject::SetBound(RECT *r){
	m_bound.left = r->left;//(LONG)m_pos.x - m_sprite->GetSpriteWidth()/2;
	m_bound.bottom =r->bottom;// (LONG)m_pos.y - m_sprite->GetSpriteHeight()/2;
	m_bound.right = r->right;//(LONG)(m_bound.left + m_sprite->GetSpriteWidth());
	m_bound.top = r->top;//(LONG)(m_bound.bottom + m_sprite->GetSpriteHeight());
}
void CGameObject::UpdatePosition(CInput *m_input,float _time){
	
	m_veloc += m_accel * _time;
	m_pos += m_veloc * _time + 1.0f/2 *m_accel*_time*_time;
	SetBound();
}
void CGameObject::Update(CInput *m_input,float _time,CCamera* _camera){
	UpdatePosition(m_input,_time);
}
void CGameObject::Update(CInput *m_input,float _time,CCamera* _camera,vector<CGameObject*> ListObjectInViewPort){
	UpdatePosition(m_input,_time);
	if (m_Islife == true)
	{
		vector<CGameObject*> ListObjectCollision;
		for (int i = 0; i < ListObjectInViewPort.size(); i++)
		{
			if(ListObjectInViewPort[i]->GetType()!=OBJECTTYPE)
			{
				ListObjectInViewPort[i]->m_TimeCollision = m_collision->CheckAABBCollision(this,ListObjectInViewPort[i],_time);
				//int timecollision = m_collision->CheckAABBCollision(this,ListObjectInViewPort[i],_time);
				if (ListObjectInViewPort[i]->m_TimeCollision<=1.0f)
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
				if (ListObjectCollision[i]->m_Islife ==true)
				{
					UpdateCollison(ListObjectCollision[i],m_input,_time);
				}

			}	
		}
	}
}
void CGameObject::Draw(LPD3DXSPRITE _spriteHandler,CCamera* _camera){
	D3DXMATRIX Scale;
	D3DXMatrixIdentity(&Scale);
	D3DXMatrixTransformation2D(&Scale, &D3DXVECTOR2(m_pos.x, m_pos.y), 0.0f, &D3DXVECTOR2(1.f, -1.f),NULL, 0.f, NULL);
	D3DXMatrixMultiply(&Scale,&Scale, &_camera->Get_ViewPort());
	_spriteHandler->SetTransform(&Scale);
	m_sprite->DrawSprite(_spriteHandler,D3DXVECTOR2(m_pos.x - m_sprite->GetSpriteWidth()/2 ,m_pos.y - m_sprite->GetSpriteHeight()/2));
}
void CGameObject::UpdateAnimation(CInput *m_input,float _time)
{

}
void CGameObject::UpdateCollison(CGameObject* _orther,CInput *m_input,float _time)
{

}
ObjectType CGameObject::GetType()
{
	return m_type;
}
void CGameObject::Stop()
{
	SetVelocity(D3DXVECTOR2(0,0));
	SetAcceleration(D3DXVECTOR2(0,0));
	SetMaxAcceleration(D3DXVECTOR2(0,0));
	SetMaxVelocity(D3DXVECTOR2(0,0));
}


