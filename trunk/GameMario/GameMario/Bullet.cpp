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
	m_maxVelocity = D3DXVECTOR2(70.0f,0);
	m_maxAccelemeter = D3DXVECTOR2(0, -10.0f);

}
void CBullet::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*> ListObjectInViewPort){
	if(m_BulletStatus == BULLET_EXPLOSION){
		m_TimeShow += _time;
		if(m_TimeShow >= BULLETSHOWTIME){
			m_Islife = false;
		}
	}
	m_accel.y = m_maxAccelemeter.y;
	ChangeStatus();
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera,ListObjectInViewPort);
	if (m_pos.x > StartPostion.x + 1000 ||m_pos.x < StartPostion.x - 800)
	{
		m_Islife =false;
	}
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
	m_veloc.x = m_direct*m_maxVelocity.x;
}
void CBullet::Explosion(){
	m_nextBulletStatus=BULLET_EXPLOSION;
	m_veloc = D3DXVECTOR2(0.0f,0);
	m_maxAccelemeter = D3DXVECTOR2(0.0f,0);
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
void CBullet::UpdateCollison(CGameObject* _orther, CInput* _input , float _time)
{
	float time = m_collision->CheckAABBCollision(this,_orther,_time);
	if(time<1.0f)
	{
		//ListObjectColision
		switch (_orther->GetType())
		{
		case PIPETYPE:
		case LANDTYPE:
		case COINQUESTIONTYPE:
		case BRICKTYPE:
			{
				if(m_collision->GetDirectCollision() == BOTTOM)
				{
					m_pos.y += GetVelocity().y*_time*time +2;
					m_pos.y = (int)m_pos.y;//_orther->GetBound().top + m_sprite->GetSpriteHeight()/2 + 2;
					SetVelocityY(30);
					m_accel.y = 0;
					SetBound();

				}
				if(m_collision->GetDirectCollision()== TOP)
				{
					Explosion();
				}
				if(m_collision->GetDirectCollision() == LEFT)
				{
					Explosion();

				}

				if(m_collision->GetDirectCollision() == RIGHT)
				{
					Explosion();
				}
				break;
			}
		case MUSHROOMTYPE:
		case TURTLETYPE:
			{
				_orther->m_EatBulet = true;
				_orther->m_Islife = false;
				_orther->m_direct = m_direct;
				_orther->SetVelocityY(40.0f);
				m_Islife = false;
				break;
			}
		}
	}
}
CBullet::~CBullet(){}

