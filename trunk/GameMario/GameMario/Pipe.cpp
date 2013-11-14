#include"pipe.h"
CPipe::CPipe(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CPipe::CPipe(int _id,D3DXVECTOR2 _pos,int _status){
	m_Id = _id;
	m_pos = _pos;
	m_status = _status;
	Init();
}
void CPipe::Init(){
	CGameObject::Init();
	m_pipesmall = CResourceManager::GetInstance()->GetResouce(PIPESMALL_ID);
	m_pipemedium = CResourceManager::GetInstance()->GetResouce(PIPEMEDIUM_ID);
	m_pipebig = CResourceManager::GetInstance()->GetResouce(PIPEBIG_ID);
	if(m_status == 1){
		m_sprite = m_pipesmall;
	}
	else if(m_status == 3){
		m_sprite = m_pipebig;
	}
	else 
		m_sprite = m_pipemedium;
}
void CPipe::Update(CInput *_input,float _time,CCamera* _camera){
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
}
void CPipe::UpdateAnimation(CInput *_input,float _time){
	//m_sprite->SetCurrentSprite(1);
	m_sprite->SetCurrentSprite(0);
	m_sprite->UpdateSprite();
}
void CPipe::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	CGameObject::Draw(_spritehandle,_camera);
}

