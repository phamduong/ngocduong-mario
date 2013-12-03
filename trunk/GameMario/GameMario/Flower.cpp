#include"Flower.h"
CFlower::CFlower(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CFlower::CFlower(int _id,D3DXVECTOR2 pos){
	m_Id = _id;
	m_pos = pos;
	Init();
}
void CFlower::Init(){
	CGameObject::Init();
	m_spriteFlower = CResourceManager::GetInstance()->GetResouce(FLOWER_ID);
	m_sprite = m_spriteFlower;
	m_maxAccelemeter = D3DXVECTOR2(0.0f , -10.0f);
	m_maxVelocity = D3DXVECTOR2(20.0f, -60.0f);
	m_type = FLOWERTYPE;
	m_IsShow = true;
	m_direct =1;
	m_GrowUp = false;
	GrowUpFinish = false; 
}
void CFlower::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*> ListObjectInViewPort){
	if (m_GrowUp == true && GrowUpFinish ==false)
	{
		if (m_pos.y < StartPostion.y + m_sprite->GetSpriteHeight() )
		{
			m_accel.y = -m_maxAccelemeter.y/10;
		}

		else
		{
			GrowUpFinish = true;
			SetVelocityY(0);
			m_accel.y = 0;

		}
	}

	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera,ListObjectInViewPort);

	/**************************************************************************************/
}
void CFlower::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetTimeAmination(1.6f);
	m_sprite->UpdateSprite(_time,0,3,1);
}
void CFlower::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	if (m_IsShow )
	{
		CGameObject::Draw(_spritehandle,_camera);
	}
}
void CFlower::UpdateCollison(CGameObject* _orther, CInput* _input , float _time)
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

				}
				if(m_collision->GetDirectCollision() == LEFT)
				{

					m_direct = 1;
				}

				if(m_collision->GetDirectCollision() == RIGHT)
				{
					m_direct = -1;
				}
				break;
			}
		}
	}
}
CFlower::~CFlower(){}

