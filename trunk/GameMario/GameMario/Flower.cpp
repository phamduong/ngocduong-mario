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
}
void CFlower::Update(CInput *_input,float _time,CCamera* _camera){
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
}
void CFlower::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetTimeAmination(1.6f);
	m_sprite->UpdateSprite(_time,0,3,1);
}
void CFlower::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	CGameObject::Draw(_spritehandle,_camera);
}
CFlower::~CFlower(){}

