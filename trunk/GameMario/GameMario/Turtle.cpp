#include"Turtle.h"
CTurtle::CTurtle(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CTurtle::CTurtle(int _id,D3DXVECTOR2 pos){
	m_Id = _id;
	m_pos = pos;
	Init();
}
void CTurtle::Init(){
	CGameObject::Init();
	life = 2;
	m_status = TurtleNormal;
	m_direct = -1;
	m_maxVelocity = D3DXVECTOR2(15.0f,65.0f);
	m_maxAccelemeter = D3DXVECTOR2(5.0f,-10.0f);
	m_spriteTurtle= CResourceManager::GetInstance()->GetResouce(TURTLE_ID);
	m_spriteTurtleShield= CResourceManager::GetInstance()->GetResouce(TURTLESHIELD_ID);
	switch(m_status){
	case TurtleNormal:
		{
			m_sprite = m_spriteTurtle;
			break;
		}
	case TurtleShield:
		{
			m_sprite =m_spriteTurtleShield;
			break;
		}
	}
	m_type = TURTLETYPE;

}
void CTurtle::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*> ListObjectInViewPort){
	UpdateAnimation(_input,_time);
	if (m_status == TurtleNormal)
	{	
		m_veloc.x = m_direct * m_maxVelocity.x;
		m_accel.y = m_maxAccelemeter.y;
	}
	else if(m_status == TurtleShield && m_GrowUp ==false)
	{
		m_veloc.x = 0;
		m_accel.y = m_maxAccelemeter.y;
	}
	else if(m_status == TurtleShield && m_GrowUp ==true)
	{
		m_veloc.x = 50.0f * m_direct;
		m_accel.y = m_maxAccelemeter.y;
	}
	else if(m_status == TurleEatBulet)
	{
		m_veloc.x = m_direct * m_maxVelocity.x * 2;
		m_accel.y = m_maxAccelemeter.y;
	}
	CGameObject::Update(_input,_time,_camera,ListObjectInViewPort);


}
void CTurtle::ChangeStatus()
{
	if (life == 2 )
	{
		m_status = TurtleNormal;
		m_sprite = m_spriteTurtle;
	}
	else if (life == 1)
	{
		m_status = TurtleShield;
		m_sprite = m_spriteTurtleShield;
	}
	if (!m_Islife)
	{
		m_status = TurleEatBulet;
		m_sprite = m_spriteTurtleShield;
	}
}
void CTurtle::UpdateAnimation(CInput *_input,float _time){
	ChangeStatus();
	if(m_status == TurtleNormal){
		if(m_direct ==1){
			m_sprite->SetTimeAmination(1.6f);
			m_sprite->UpdateSprite(_time,0,1,1);
		}
		else if(m_direct ==-1){
			m_sprite->SetTimeAmination(1.6f);
			m_sprite->UpdateSprite(_time,2,3,-1);
		}
	}
	else if(m_status == TurtleShield && m_GrowUp ==false){
		m_sprite->SetCurrentSprite(1);
		m_sprite->UpdateSprite();
		m_TimeShow += _time;
		if (m_TimeShow >=20.0f)
		{
			m_sprite->SetTimeAmination(1.6f);
			m_sprite->UpdateSprite(_time,0,2,1);
		}
		if (m_TimeShow>=50.0f)
		{
			life = 2;
			m_status = TurtleNormal;
			m_veloc.y = 20.0f;
			SetBound();
		}
	}
	else if(m_status == TurtleShield && m_GrowUp ==true)
	{
		m_sprite->SetCurrentSprite(1);
		m_sprite->UpdateSprite();

	}
	else if (m_status == TurleEatBulet)
	{
		m_sprite->SetCurrentSprite(3);
		m_sprite->UpdateSprite();
	}
}
void CTurtle::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){

	CGameObject::Draw(_spritehandle,_camera);

}
void CTurtle::UpdateCollison(CGameObject* _orther, CInput* _input, float _time)
{
	float time = m_collision->CheckAABBCollision(this,_orther,_time);
	if(time<1.0f)
	{
		switch (_orther->GetType())
		{
		case PIPETYPE:
		case LANDTYPE:
		case BRICKTYPE:
		case COINQUESTIONTYPE:
			{
				if(m_collision->GetDirectCollision() == BOTTOM)
				{
					m_pos.y += GetVelocity().y*_time*time + 2;
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
					SetBound();
				}

				if(m_collision->GetDirectCollision() == RIGHT)
				{
					m_direct = -1;
					SetBound();
				}
				break;
			}
		case MUSHROOMTYPE:
			{
				if (m_GrowUp==true)
				{
					if(!CAudio::m_isSoundOff)
						m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_MUSHROOMDIE_ID));
					_orther->m_EatBulet = true;
					_orther->m_Islife = false;
					_orther->m_direct = m_direct;
					_orther->SetVelocityY(40.0f);
				}

				break;
			}
		case TURTLETYPE:
			{
				if (m_GrowUp==true)
				{
					if(!CAudio::m_isSoundOff)
						m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_MUSHROOMDIE_ID));
					_orther->m_EatBulet = true;
					_orther->m_Islife = false;
					_orther->m_direct = m_direct;
					_orther->SetVelocityY(40.0f);
				}

				if (_orther->life ==1)
				{

					if(m_collision->GetDirectCollision() == BOTTOM)
					{
						m_pos.y += GetVelocity().y*_time*time +2;
						m_pos.y = (int)m_pos.y;//_orther->GetBound().top + m_sprite->GetSpriteHeight()/2 + 2;
						SetVelocityY(0);
						SetBound();
					}
					if(m_collision->GetDirectCollision()== TOP)
					{

					}
					if(m_collision->GetDirectCollision() == LEFT)
					{
						if (m_GrowUp==false)
						{
							m_direct = 1;
						}

					}

					if(m_collision->GetDirectCollision() == RIGHT)
					{
						if (m_GrowUp==false)
						{
							m_direct = -1;
						}

					}

				}
				break;
			}
		default:
			break;


		}	

	}
}
CTurtle::~CTurtle(){}

