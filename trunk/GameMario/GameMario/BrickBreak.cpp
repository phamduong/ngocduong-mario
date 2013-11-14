#include"BrickBreak.h"         
CBrickBreak::CBrickBreak(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CBrickBreak::CBrickBreak(D3DXVECTOR2 pos,D3DXVECTOR2 _vecloc,D3DXVECTOR2 _accel){
	m_pos = pos;
	Init();
	m_accel = _accel;
	m_veloc = _vecloc;
}
void CBrickBreak::Init(){
	CGameObject::Init();
	m_spriteBrickBreak = CResourceManager::GetInstance()->GetResouce(BRICKBREAK_ID);
	m_sprite = m_spriteBrickBreak;


}
void CBrickBreak::Update(CInput *_input,float _time,CCamera* _camera){
	m_TimeShow += _time;
	if(m_TimeShow > TIMESHOWBRICKBREAK){
		m_IsShow =false;
	}
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
}
void CBrickBreak::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetCurrentSprite(0);
	m_sprite->SetTimeAmination(0);
	m_sprite->UpdateSprite();
}
void CBrickBreak::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	if(m_IsShow){
		CGameObject::Draw(_spritehandle,_camera);
	}
}
CBrickBreak::~CBrickBreak(){}

