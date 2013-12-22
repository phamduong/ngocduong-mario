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
	m_maxVelocity = D3DXVECTOR2(40.0f,0.0f);
	m_fireboss = CResourceManager::GetInstance()->GetResouce(FIREBOSS_ID);
	m_sprite = m_fireboss;
	m_type = BOSSFIRETYPE;
	m_IsShow = true;
	CheckCollisionMario = false;
}
void CFireBoss::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*> ListObjectInViewPort){
	if (m_IsShow==true)
	{
		m_veloc.x = m_direct * m_maxVelocity.x;
		if (m_pos.x < StartPostion.x -1000 || m_pos.x >StartPostion.x + 1000)
		{
			m_Islife = false;
			m_IsShow = false;
		}
		UpdateAnimation(_input,_time);
		CGameObject::Update(_input,_time,_camera,ListObjectInViewPort);
	}
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

}
CFireBoss::~CFireBoss(){}

