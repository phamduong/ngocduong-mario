#include"MushroomLife.h"
CMushroomLife::CMushroomLife(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CMushroomLife::CMushroomLife(int _id,D3DXVECTOR2 pos){
	m_Id =_id;
	m_pos = pos;
	Init();
}
void CMushroomLife::Init(){
	CGameObject::Init();
	
	m_spriteLife = CResourceManager::GetInstance()->GetResouce(ITEM_ID);
	m_sprite = m_spriteLife;
}
void CMushroomLife::Update(CInput *_input,float _time,CCamera* _camera){
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
}
void CMushroomLife::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetCurrentSprite(1);
	m_sprite->SetTimeAmination(0);
	m_sprite->UpdateSprite();
}
void CMushroomLife::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	CGameObject::Draw(_spritehandle,_camera);
}
CMushroomLife::~CMushroomLife(){}

