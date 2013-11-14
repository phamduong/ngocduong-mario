#include"Bullet.h"
CBullet::CBullet(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CBullet::CBullet(D3DXVECTOR2 pos,int _directx){
	m_pos = pos;
	m_direct = _directx;
	Init();
}
void CBullet::Init(){
	CGameObject::Init();
	m_spriteBullet = CResourceManager::GetInstance()->GetResouce(BULLET_ID);
	m_sprite = m_spriteBullet;
	m_BulletStatus = BULLET_NONE;
	m_nextBulletStatus = BULLET_NONE;
}
void CBullet::Update(CInput *_input,float _time,CCamera* _camera){
	if(m_BulletStatus == BULLET_EXPLOSION){
		m_TimeShow += _time;
		if(m_TimeShow >= BULLETSHOWTIME){
			m_Islife = false;
		}
	}
	ChangeStatus();
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
	/*if(m_pos.x >= 800){
		Explosion();

	}*/

}
void CBullet::UpdateAnimation(CInput *_input,float _time){
	if(m_BulletStatus==BULLET_SHOT){
		m_sprite->SetTimeAmination(1.6f);
		m_sprite->UpdateSprite(_time,0,3,1);
	}
	if(m_BulletStatus==BULLET_EXPLOSION){
		m_sprite->SetTimeAmination(1.6f);
		m_sprite->UpdateSprite(_time,4,9,1);
	}
}
void CBullet::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	if(m_Islife){
		CGameObject::Draw(_spritehandle,_camera);
	}
}
void CBullet::Shotting(){
	m_nextBulletStatus=BULLET_SHOT;
	m_veloc.x = m_direct* 50.0f;
	//m_veloc.y = -15.0f;
}
void CBullet::Explosion(){
	m_nextBulletStatus=BULLET_EXPLOSION;
	m_veloc = D3DXVECTOR2(0.0f,0);
}
void CBullet::ChangeStatus(){
	if(m_BulletStatus == BULLET_NONE &&m_nextBulletStatus == BULLET_SHOT){
		m_BulletStatus = BULLET_SHOT;
	}
	if(m_BulletStatus == BULLET_SHOT &&m_nextBulletStatus ==BULLET_EXPLOSION){
		m_BulletStatus = BULLET_EXPLOSION;
		m_nextBulletStatus =  BULLET_NONE;
	}
}
CBullet::~CBullet(){}

