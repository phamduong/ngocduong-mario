#include"Star.h"
CStar::CStar(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CStar::CStar(int _id,D3DXVECTOR2 pos){
	m_Id = _id;
	m_pos = pos;
	Init();
}
void CStar::Init(){
	CGameObject::Init();
	m_spriteStar = CResourceManager::GetInstance()->GetResouce(ITEM_ID);
	m_sprite = m_spriteStar;
	m_maxVelocity = D3DXVECTOR2(0.0f, 20.0f);

}
void CStar::Update(CInput *_input,float _time,CCamera* _camera){
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
}
void CStar::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetCurrentSprite(3);
	m_sprite->SetTimeAmination(0);
	m_sprite->UpdateSprite();
}
void CStar::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	CGameObject::Draw(_spritehandle,_camera);
}
CStar::~CStar(){}

