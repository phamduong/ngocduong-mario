#include"Mushroom.h"
CMushroom::CMushroom(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CMushroom::CMushroom(int _id,D3DXVECTOR2 pos){
	m_Id = _id;
	m_pos = pos;
	Init();
}
void CMushroom::Init(){
	CGameObject::Init();
	m_direct = -1;
	m_spriteMushroom = CResourceManager::GetInstance()->GetResouce(MUSHROOM_ID);
	m_sprite = m_spriteMushroom;
	
}
void CMushroom::Update(CInput *_input,float _time,CCamera* _camera){
	//m_veloc.x = m_direct*10.f;
	//m_accel.x = m_direct* 0.1;
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
	/*if(m_pos.x<=1 || m_pos.x >=5000){
		m_direct = -1.0f * m_direct;
	}*/
}
void CMushroom::UpdateAnimation(CInput *_input,float _time){
	//m_sprite->SetCurrentSprite(0);
	m_sprite->SetTimeAmination(1.6f);
	m_sprite->UpdateSprite(_time,0,1,1);
}
void CMushroom::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	CGameObject::Draw(_spritehandle,_camera);
}
CMushroom::~CMushroom(){}

