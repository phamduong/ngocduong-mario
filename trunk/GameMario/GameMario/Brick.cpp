#include"Brick.h"
CBrick::CBrick(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CBrick::CBrick(int _id,D3DXVECTOR2 pos){
	m_Id = _id;
	m_pos = pos;
	Init();
}
void CBrick::Init(){
	CGameObject::Init();
	
	m_spriteBrick = CResourceManager::GetInstance()->GetResouce(BRICK_ID);
	m_sprite = m_spriteBrick;
}
void CBrick::Update(CInput *_input,float _time,CCamera* _camera){
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
}
void CBrick::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetCurrentSprite(0);
	m_sprite->SetTimeAmination(0);
	m_sprite->UpdateSprite();
}
void CBrick::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	CGameObject::Draw(_spritehandle,_camera);
}
CBrick::~CBrick(){}

