#include"FireBoss.h"
CFireBoss::CFireBoss(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CFireBoss::CFireBoss(int _direct,D3DXVECTOR2 pos){
	m_direct = _direct;
	m_pos = pos;
	Init();
}
void CFireBoss::Init(){
	CGameObject::Init();
	m_maxVelocity = D3DXVECTOR2(35.0f,0.0f);
	m_fireboss = CResourceManager::GetInstance()->GetResouce(FIREBOSS_ID);
	m_sprite = m_fireboss;
	m_type = BOSSTYPE;
	m_IsShow = true;
}
void CFireBoss::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*> ListObjectInViewPort){
	m_veloc.x = m_direct * m_maxVelocity.x;
	if (m_pos.x < -100 || m_pos.y >1100)
	{
		m_Islife = false;
		m_IsShow = false;
	}
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera,ListObjectInViewPort);

	/**************************************************************************************/
}
void CFireBoss::UpdateAnimation(CInput *_input,float _time){
	if (m_direct==1)
	{
		m_sprite->SetTimeAmination(1.6f);
		m_sprite->UpdateSprite(_time,0,2,1);
	}
	else
	{
		m_sprite->SetTimeAmination(1.6f);
		m_sprite->UpdateSprite(_time,3,5,-1);
	}

}
void CFireBoss::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	if (m_IsShow==true)
	{
		CGameObject::Draw(_spritehandle,_camera);
	}

}
void CFireBoss::UpdateCollison(CGameObject* _orther, CInput* _input , float _time)
{
	//float time = m_collision->CheckAABBCollision(this,_orther,_time);
	//if(time<1.0f)
	//{
	//	//ListObjectColision
	//	switch (_orther->GetType())
	//	{
	//	case PIPETYPE:
	//	case LANDTYPE:
	//	case COINQUESTIONTYPE:
	//	case BRICKTYPE:
	//		{
	//			if(m_collision->GetDirectCollision() == BOTTOM)
	//			{
	//				m_pos.y += GetVelocity().y*_time*time +2;
	//				m_pos.y = (int)m_pos.y;//_orther->GetBound().top + m_sprite->GetSpriteHeight()/2 + 2;
	//				SetVelocityY(0);
	//				m_accel.y = 0;
	//				SetBound();

	//			}
	//			if(m_collision->GetDirectCollision()== TOP)
	//			{

	//			}
	//			if(m_collision->GetDirectCollision() == LEFT)
	//			{

	//				m_direct = 1;
	//			}

	//			if(m_collision->GetDirectCollision() == RIGHT)
	//			{
	//				m_direct = -1;
	//			}
	//			break;
	//		}
	//	}
	//}
}
CFireBoss::~CFireBoss(){}

