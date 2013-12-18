#include"Boss.h"
CBoss::CBoss(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CBoss::CBoss(int _id,D3DXVECTOR2 pos){
	m_Id = _id;
	m_pos = pos;
	Init();
}
void CBoss::Init(){
	CGameObject::Init();
	m_maxAccelemeter = D3DXVECTOR2(0.0f , -10.0f);
	m_maxVelocity = D3DXVECTOR2(20.0f, 60.0f);
	m_boss = CResourceManager::GetInstance()->GetResouce(BOSS_ID);
	m_sprite = m_boss;
	m_type = BOSSTYPE;
	m_IsShow = true;
	m_direct =-1;
	BossJump = false;
	TimeFire =0;
	Hit = 100;
}
void CBoss::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*> ListObjectInViewPort){
	m_TimeShow+=_time;
	TimeFire +=_time;
	m_accel.y = m_maxAccelemeter.y;
	//Ban dan ra ne
	if (TimeFire >= 50.0f)
	{
		//MessageBox(NULL,"","",MB_OK);
		CFireBoss *fire = new CFireBoss(m_direct,m_pos);
		m_fire.push_back(fire);
		TimeFire = 0;
	}
	for (int i = 0; i < m_fire.size(); i++)
	{
		if(m_fire[i] !=NULL)
		{
			if (m_fire[i]->m_Islife == false)
			{
				m_fire.erase(m_fire.begin() + i);
			}
			else
			{
				m_fire[i]->Update(_input,_time,_camera,ListObjectInViewPort);
			}
		}
	}
	//action cua boss
	if (m_veloc.y < - m_maxVelocity.y)
	{
		m_veloc.y = - m_maxVelocity.y;
	}
	if (m_TimeShow<1.6f)
	{
		m_veloc.y = 60;
		m_veloc.x =  m_maxVelocity.x * m_direct;
	}
	if (m_TimeShow<40)
	{
		m_veloc.x = 0;
	}
	else
	{
		m_veloc.x =  m_maxVelocity.x * m_direct;
		if (m_TimeShow > 120.0f)
		{
			m_TimeShow =  0 ;
		}
	}

	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera,ListObjectInViewPort);

	/**************************************************************************************/
}
void CBoss::UpdateAnimation(CInput *_input,float _time){
	if (m_direct==1)
	{
		m_sprite->SetTimeAmination(1.6f);
		m_sprite->UpdateSprite(_time,0,3,1);
	}
	else
	{
		m_sprite->SetTimeAmination(1.6f);
		m_sprite->UpdateSprite(_time,4,7,-1);
	}

}
void CBoss::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	for (int i = 0; i < m_fire.size(); i++)
	{
		if(m_fire[i]!=NULL){
			m_fire[i]->Draw(_spritehandle,_camera);
		}
	}
	if (m_IsShow==true)
	{
		CGameObject::Draw(_spritehandle,_camera);
	}


}
void CBoss::UpdateCollison(CGameObject* _orther, CInput* _input , float _time)
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
		case HOUSETYPE:
			{
				if(m_collision->GetDirectCollision() == BOTTOM)
				{
					m_pos.y += GetVelocity().y*_time*time +2;
					m_pos.y = (int)m_pos.y;//_orther->GetBound().top + m_sprite->GetSpriteHeight()/2 + 2;
					SetVelocityY(0);
					m_accel.y = 0;
					SetBound();

				}
				if(m_collision->GetDirectCollision()== TOP)
				{

				}
				if(m_collision->GetDirectCollision() == LEFT)
				{

					m_direct = 1;
				}

				if(m_collision->GetDirectCollision() == RIGHT)
				{
					m_direct = -1;
				}
				break;
			}
		}
	}
}
CBoss::~CBoss(){}

