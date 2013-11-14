#include"Object.h"

CGameObject::CGameObject(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CGameObject::CGameObject(int _id,D3DXVECTOR2 _mpos){
	m_Id = _id;
	m_pos = _mpos;
	Init();
}
CGameObject::~CGameObject(){}
void CGameObject::Init(){
	m_Islife = true;
	m_TimeShow = 0;
	m_IsShow = true;
	m_veloc = D3DXVECTOR2(0,0);
	m_accel = D3DXVECTOR2(0,0);

}
void CGameObject::SetBound(){
	m_bound.top = (LONG)m_pos.y;
	m_bound.left = (LONG)m_pos.x;
	m_bound.bottom = (LONG)(m_bound.top + m_sprite->GetSpriteHeight());
	m_bound.right = (LONG)(m_bound.left + m_sprite->GetSpriteWidth());
}
void CGameObject::UpdatePosition(CInput *m_input,float _time){
	m_veloc += m_accel * _time;
	m_pos += m_veloc * _time + 1.0f/2 *m_accel*_time*_time;
	SetBound();
}
void CGameObject::Update(CInput *m_input,float _time,CCamera* _camera){
	UpdatePosition(m_input,_time);
	m_sprite->UpdateSprite();
}
void CGameObject::Draw(LPD3DXSPRITE _spriteHandler,CCamera* _camera){
	D3DXMATRIX Scale;
	D3DXMatrixIdentity(&Scale);
	D3DXMatrixTransformation2D(&Scale, &D3DXVECTOR2(m_pos.x, m_pos.y), 0.0f, &D3DXVECTOR2(1.f, -1.f),NULL, 0.f, NULL);
	D3DXMatrixMultiply(&Scale,&Scale, &_camera->Get_ViewPort());
	_spriteHandler->SetTransform(&Scale);
	m_sprite->DrawSprite(_spriteHandler,D3DXVECTOR2(m_pos.x - m_sprite->GetSpriteWidth()/2 ,m_pos.y - m_sprite->GetSpriteHeight()/2));
}
void CGameObject::UpdateAnimation(CInput *m_input,float _time)
{

}


