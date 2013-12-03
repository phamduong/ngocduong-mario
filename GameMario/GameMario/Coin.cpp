#include"Coin.h"
CCoin::CCoin(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CCoin::CCoin(int _id,D3DXVECTOR2 pos){
	m_Id = _id;
	m_pos = pos;
	Init();
	
}
void CCoin::Init(){
	CGameObject::Init();
	m_type = COINTYPE;
	m_spriteCoin = CResourceManager::GetInstance()->GetResouce(COIN_ID);
	m_sprite = m_spriteCoin;
}
void CCoin::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*>){
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
}
void CCoin::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetTimeAmination(1.6f);
	m_sprite->UpdateSprite(_time,0,6,1);
}
void CCoin::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	if(m_IsShow){
		CGameObject::Draw(_spritehandle,_camera);
	}
}
CCoin::~CCoin(){}

