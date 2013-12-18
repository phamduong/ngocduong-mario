#include"Mario.h"
#include <stdlib.h>

int CMario::g_heightMap;
int CMario::g_widthMap;
int CMario::Score;
bool CMario::WinState;
CScore *CMario::sc;
CMario::CMario()
{
	m_pos = D3DXVECTOR2(100,600);
	life = 1;
	Init();
}
CMario::CMario(int _life,D3DXVECTOR2 _pos)
{
	Init();
	m_pos = _pos;
	life = _life;

}
CMario::~CMario(){
}
void CMario::Init(){
	CGameObject::Init();
	m_veloc = D3DXVECTOR2(0,0);
	m_accel = D3DXVECTOR2(0,0);
	m_maxVelocity = D3DXVECTOR2(40.0f,120.0f);
	m_MaxVeloc = m_maxVelocity;
	m_maxAccelemeter = D3DXVECTOR2(5.0f,-30.0f);
	m_action = Jump;
	m_start_status = mariosmall;
	m_direct = 1;
	CountCoin = 0;
	EatLife = false;
	Score =0;
	m_isProtected = false;
	m_eatStar = false;
	WinState = false;
	m_timeProtected =0;
	m_timeShowProtected =0;
	m_lastPos = D3DXVECTOR2(0,0);
	m_spriteBig = CResourceManager::GetInstance()->GetResouce(MARIOBIG_ID);
	m_sriteSmall = CResourceManager::GetInstance()->GetResouce(MARIOSMALL_ID);
	m_spriteGun = CResourceManager::GetInstance()->GetResouce(MARIOGUN_ID);
	m_sprite = m_spriteBig;
	//m_bullet = NULL;
	switch(m_start_status){
	case mariosmall:
		{
			m_status =  mariosmall;
			m_sprite = m_sriteSmall;
			break;
		}
	case mariobig:
		{
			m_status =  mariobig;
			m_sprite = m_spriteBig;
			break;
		}
	case mariogun:
		{
			m_status =  mariogun;
			m_sprite = m_spriteGun;
			break;
		}
	}
	m_collision = new CAABBCollision();
	m_directCollion = NONE;
	CGameObject::SetBound();
	sc = new CScore();
	m_sound = CResourceManager::GetAudio();
}
void CMario::ChangeStatus()
{
	if (life >=3)
	{
		life = 3;
		m_status = mariogun;
		m_sprite = m_spriteGun;

	}
	if (life ==2)
	{
		m_status = mariobig;
		m_sprite = m_spriteBig;
	}
	if (life ==1)
	{
		m_status = mariosmall;
		m_sprite = m_sriteSmall;
	}
	if (life < 1)
	{
		life = 0;
		m_Islife = false;
		m_sprite = m_sriteSmall;
	}
}
void CMario::Update(CInput *m_input,float _time,CCamera * _camera,vector<CGameObject*> ListObjectInViewPort){
	m_accel.y = m_maxAccelemeter.y;
	if (m_veloc.y < - m_MaxVeloc.y)
	{
		m_veloc.y = - m_MaxVeloc.y;
	}

	//chuyen status
	if (m_isProtected==true && m_Islife ==true)
	{
		m_timeProtected+=_time;
		m_timeShowProtected +=_time;
		if (m_timeShowProtected >=TIMESHOWPROTECTED)
		{
			m_timeShowProtected = 0;
		}
		if (m_eatStar ==true)
		{
			if (m_timeProtected >= TIMEPROTECTED  * 3)
			{
				m_isProtected = false;
				m_timeProtected =0;
				m_timeShowProtected = 0;
				m_eatStar =  false;
			}
		}
		else
		{
			if (m_timeProtected >= TIMEPROTECTED)
			{
				m_isProtected = false;
				m_timeProtected =0;
				m_timeShowProtected = 0;
			}
		}

	}
	//

#pragma region Nhap phim 
	if (!WinState)
	{


		if(m_input->KeyDown(DIK_RIGHT)&&m_action != down &&m_pos.x <= g_widthMap-200)
		{	

			m_direct = 1;
			if(m_veloc.x < m_maxVelocity.x)
			{
				m_accel.x = m_maxAccelemeter.x ;
			}
			else //if (m_veloc.x >= m_maxVelocity.x)
			{
				m_accel.x = 0;
				m_veloc.x = m_maxVelocity.x ;
			}
		}
		//
		else if(m_input->KeyDown(DIK_LEFT)&& m_action != down&&m_pos.x>=25)
		{
			m_direct = -1;
			if(m_veloc.x > m_direct* m_maxVelocity.x)
			{
				m_accel.x =m_direct* m_maxAccelemeter.x;
			}
			if (m_veloc.x <= m_direct*m_maxVelocity.x)
			{
				m_veloc.x = m_maxVelocity.x * m_direct;
				m_accel.x = 0;
			}

		}
		else if(m_input->KeyDown(DIK_DOWN) && m_action!=Jump)
		{
			m_action = down;
			m_veloc.x = 0;
			m_accel.x = 0;
			m_veloc.y = 0;
			m_accel.y = 0;

		}
		else 
		{
			if(m_veloc.x!=0){
				m_accel.x =- 1.0f*m_direct*(m_maxAccelemeter.x);
			}
			if((m_direct*m_veloc.x) <=0){
				m_veloc.x = 0;
				m_accel.x= 0;
				//	m_action = normal;
			}

		}

		/**********************************KEY DOWN**************************************************/
		keydown = m_input ->GetKeyDown();
		//mario ban
		if(keydown == DIK_C && m_action!=down && m_status == mariogun){

			//am thanh ban sung
			if(!CAudio::m_isSoundOff)
				m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_MARIOKICK_ID));
			//vi tri khoi tao vien dan
			if (m_veloc.x<=10 && m_veloc.x>=-10)
			{
				CBullet *_bullet = new CBullet(D3DXVECTOR2(m_pos.x -m_direct * 100,m_pos.y + m_sprite->GetSpriteHeight()/2 -10 ),m_direct);
				_bullet->Shotting();
				m_bullet.push_back(_bullet);
			}
			else if (abs(m_veloc.x*m_direct) <= 40 )
			{
				CBullet *_bullet = new CBullet(D3DXVECTOR2(m_pos.x -m_direct * 50,m_pos.y + m_sprite->GetSpriteHeight()/2 -10 ),m_direct);
				_bullet->Shotting();
				m_bullet.push_back(_bullet);
			}
			else
			{
				CBullet *_bullet = new CBullet(D3DXVECTOR2(m_pos.x ,m_pos.y + m_sprite->GetSpriteHeight()/2 -10 ),m_direct);
				_bullet->Shotting();
				m_bullet.push_back(_bullet);
			}

		}
		for (int i = 0; i < m_bullet.size(); i++)
		{
			if(m_bullet[i] !=NULL){
				if (m_bullet[i]->m_Islife == false)
				{
					m_bullet.erase(m_bullet.begin() + i);
				}
				else
				{
					m_bullet[i]->Update(m_input,_time,_camera,ListObjectInViewPort);
				}
			}
		}
		//mario nhay
		if(keydown==DIK_V){
			if(m_veloc.y==0&& m_action==normal){
				if(!CAudio::m_isSoundOff)
					m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_JUMP_ID));
				m_action = Jump;
				m_veloc.y = m_MaxVeloc.y;
			}

		}
	}
	/************************************KEY UP********************************************************/

	/************************************KEY CHEAT********************************************************/
	if (keydown==DIK_1)
	{
		life = 1;

	}
	if (keydown==DIK_2)
	{
		if (life<2)
		{
			m_pos.y +=100;
		}
		life = 2;
		m_action = Jump;

	}
	if (keydown==DIK_3)
	{
		if (life<2)
		{
			m_pos.y +=100;
		}
		m_action = Jump;
		life = 3;

	}
	if (keydown == DIK_4)
	{
		m_eatStar = true;
		m_isProtected = true;
	}

#pragma endregion
	// va cham voi ITem
	for (int i = 0; i < ListItem.size(); i++)
	{
		if (ListItem[i]->m_IsShow == false || ListItem[i]->GetPosition().y<  0)
		{
			ListItem.erase(ListItem.begin() + i);
		}
		else
		{
			//UpdateCollison(ListItem[i],m_input,_time);
			ListObjectInViewPort.push_back(ListItem[i]);
		}
	}
	// update va va cham voi nhug thu ko fai item
	CGameObject::Update(m_input,_time,_camera,ListObjectInViewPort);
	UpdateAnimation(m_input,_time);
	_camera->Update(m_pos);
	if (WinState)
	{
		SetVelocityX(30);
	}
	if (GetPosition().x > g_widthMap -150)
	{
		SetVelocityX(0);
	}

	//
	if (sc!=NULL)
	{
		sc->Update(m_input,_time,_camera);
	}
}
void CMario ::UpdateAnimation(CInput *m_input,float _time){
	///**********************************STatus la Big or Gun **************/
	ChangeStatus();
#pragma region Mariobig and gun
	if(m_status ==mariobig ||m_status==mariogun){
		if(m_veloc.x==0 &&m_veloc.y==0)//normal
		{
			if(m_direct==1){
				m_sprite->SetCurrentSprite(0);
				m_sprite->UpdateSprite();
			}
			if(m_direct==-1){
				m_sprite->SetCurrentSprite(9);
				m_sprite->UpdateSprite();
			}
		}
		if(m_veloc.x!=0 && m_veloc.y==0 &&m_action !=down){//run
			if(m_direct==1){
				m_sprite->SetTimeAmination(TIMEAMINATION);
				m_sprite->UpdateSprite(_time,2,3,1);
			}
			if(m_direct==-1){

				m_sprite->SetTimeAmination(TIMEAMINATION);
				m_sprite->UpdateSprite(_time,6,7,-1);
			}
		}
		if(m_action==Jump ){//jump
			if(m_direct==1){
				m_sprite->SetCurrentSprite(1);
				m_sprite->UpdateSprite();
			}
			if(m_direct==-1){

				m_sprite->SetCurrentSprite(8);
				m_sprite->UpdateSprite();
			}
		}
		if(m_action ==down && m_veloc.x ==0 && m_veloc.y ==0){//down
			if(m_direct==1){
				m_sprite->SetCurrentSprite(4);
				m_sprite->SetTimeAmination(0);
				m_sprite->UpdateSprite();
			}
			if(m_direct==-1){

				m_sprite->SetCurrentSprite(5);
				m_sprite->SetTimeAmination(0);
				m_sprite->UpdateSprite();
			}
		}
	}
#pragma endregion
#pragma region mario small
	if(m_status ==mariosmall){
		if(m_veloc.x==0 && m_veloc.y==0)//normal
		{
			if(m_direct==1){
				m_sprite->SetCurrentSprite(0);
				m_sprite->UpdateSprite();
			}
			if(m_direct==-1){
				m_sprite->SetCurrentSprite(9);
				m_sprite->UpdateSprite();
			}
		}
		if(m_veloc.x!=0 && m_veloc.y==0 &&m_action !=down){//run
			if(m_direct==1){
				m_sprite->SetTimeAmination(TIMEAMINATION);
				m_sprite->UpdateSprite(_time,0,1,1);
			}
			if(m_direct==-1){

				m_sprite->SetTimeAmination(TIMEAMINATION);
				m_sprite->UpdateSprite(_time,8,9,-1);
			}
		}
		if(m_action==Jump){//jump
			if(m_direct==1){
				m_sprite->SetCurrentSprite(2);
				m_sprite->UpdateSprite();
			}
			if(m_direct==-1){

				m_sprite->SetCurrentSprite(7);
				m_sprite->UpdateSprite();
			}
		}
		if(m_action ==down && m_veloc.x ==0 && m_veloc.y==0){//down
			if(m_direct==1){
				m_sprite->SetCurrentSprite(3);
				m_sprite->SetTimeAmination(0);
				m_sprite->UpdateSprite();
			}
			if(m_direct==-1){

				m_sprite->SetCurrentSprite(6);
				m_sprite->SetTimeAmination(0);
				m_sprite->UpdateSprite();
			}
		}
		//chet
		if(life <= 0)
		{
			if(m_direct==1){
				m_sprite->SetCurrentSprite(4);
				m_sprite->SetTimeAmination(0);
				m_sprite->UpdateSprite();
			}
			if(m_direct==-1){

				m_sprite->SetCurrentSprite(5);
				m_sprite->SetTimeAmination(0);
				m_sprite->UpdateSprite();
			}
		}
	}
#pragma endregion
}

void CMario::Draw(LPD3DXSPRITE _spriteHandler,CCamera* _camera){
	// chuyen state win g_widthMap - 1000 khong ve Bullet nua 
	if ( m_pos.x < g_widthMap - 1000)
	{
		for (int i = 0; i < m_bullet.size(); i++)
		{
			if(m_bullet[i]!=NULL){
				m_bullet[i]->Draw(_spriteHandler,_camera);
			}
		}
	}
	if (sc!=NULL)
	{
		sc->Draw(_spriteHandler,_camera);
	}


	if (m_timeShowProtected == 0.0f && m_pos.x < g_widthMap -150)
	{
		CGameObject::Draw(_spriteHandler, _camera);
	}

}

void CMario::UpdateCollison(CGameObject* _orther, CInput* _input , float _time){
	if (_orther->GetType()!=MARIOTYPE)
	{
		float time = m_collision->CheckAABBCollision(this,_orther,_time);
		m_directCollion = m_collision->GetDirectCollision();
		if (time <=1.0f)
		{
			ExecuteCollision(_orther,m_directCollion,_time,time);
		}



	}
}

void CMario::ExecuteCollision(CGameObject* _orther,DirectCollision m_directCollion,float _time,float time)
{

	if(time<=1.0f)
	{	
		//ListObjectColision
		switch (_orther->GetType())
		{
		case PIPETYPE:
		case LANDTYPE:
			{
				if( m_directCollion== BOTTOM)
				{
					m_action = normal;
					if (time!=0)
					{
						m_pos.y += GetVelocity().y*_time*time +2;
						m_pos.y = (int)m_pos.y;//_orther->GetBound().top + m_sprite->GetSpriteHeight()/2 + 2;
					}
					else
					{
						m_pos.y = _orther->GetBound().top + m_sprite->GetSpriteHeight()/2 + 2;
					}
					SetVelocityY(0);
					m_accel.y = 0;
					SetBound();

				}
				if(m_directCollion== TOP)
				{
					if(!CAudio::m_isSoundOff)
						m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_BRICKSLIDE_ID));
					m_pos.y += GetVelocity().y*_time*time-2;
					m_pos.y = (int)m_pos.y;
					SetVelocityY(0);
					SetBound();
				}
				if(m_directCollion == LEFT)
				{
					m_pos.x += GetVelocity().x*_time*time+2;
					m_pos.x = (int)m_pos.x;
					m_veloc.x = 0;
					m_accel.x = 0;
					SetBound();
					//MessageBox(NULL,"BOTTOM","",MB_OK);
				}

				if(m_directCollion== RIGHT)
				{
					m_pos.x += GetVelocity().x*_time*time-2;
					m_pos.x = (int)m_pos.x;
					m_veloc.x = 0;
					m_accel.x = 0;
					SetBound();
					//MessageBox(NULL,"BOTTOM","",MB_OK);
				}
				break;
			}
		case BRICKTYPE:
			{
				if(m_directCollion == BOTTOM)
				{
					m_action = normal;
					m_pos.y += GetVelocity().y*_time*time + 2;
					m_pos.y = (int)m_pos.y;
					SetVelocityY(0);
					m_accel.y = 0;
					SetBound();
				}
				if(m_directCollion== TOP)
				{
					m_pos.y += GetVelocity().y*_time*time-2;
					m_pos.y = (int)m_pos.y;
					SetVelocityY(0);
					m_accel.y = 0;
					SetBound();
					if(m_status!=mariosmall)
					{
						if(!CAudio::m_isSoundOff)
							m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_BRICKBREAK_ID));
						_orther->m_IsShow = false;
						_orther->m_Islife = false;
					}
					else
					{
						if(!CAudio::m_isSoundOff)
							m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_BRICKSLIDE_ID));
						_orther->SetVelocityY(15);
						_orther->SetAccelerationY(-10.0f );

					}
				}
				if(m_directCollion == LEFT)
				{
					m_pos.x += GetVelocity().x*_time*time+2;
					m_pos.x = (int)m_pos.x;
					m_veloc.x = 0;
					m_accel.x = 0;
					SetBound();
				}

				if(m_directCollion == RIGHT)
				{
					m_pos.x += GetVelocity().x*_time*time -2;
					m_pos.x = (int)m_pos.x;
					m_veloc.x = 0;
					m_accel.x = 0;
				}
				break;
			}
		case COINQUESTIONTYPE:
			{
				if(m_directCollion == BOTTOM)
				{
					m_action = normal;
					m_pos.y += GetVelocity().y*_time*time + 2;
					m_pos.y = (int)m_pos.y;
					SetVelocityY(0);
					m_accel.y = 0;
					SetBound();
				}
				if(m_directCollion== TOP)
				{
					m_pos.y += GetVelocity().y*_time*time-2;
					m_pos.y = (int)m_pos.y;
					SetVelocityY(0);
					m_accel.y = 0;
					_orther->m_IsShow = false;//chuyen ve ko co dau hoi

					SetBound();
					//
					CQuestion * Item = (CQuestion*) _orther;
					if (Item->m_GrowUp)
					{
						if(!CAudio::m_isSoundOff)
							m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_BRICKSLIDE_ID));
					}
					if (Item->m_itemname!=ITEM_COIN && !Item->m_GrowUp)
					{
						ListItem.push_back(Item->m_object);
						if(!CAudio::m_isSoundOff)
							m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_ITEMUP_ID));
					}
					else
					{
						if (!Item->m_GrowUp)
						{
							CountCoin++;
							Score+=100;
							sc = new CScore(_orther->GetPosition(),MOTTRAM);
							if(!CAudio::m_isSoundOff)
								m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_COIN_ID));
						}

					}
					_orther->m_GrowUp = true; //moc item len
				}
				if(m_directCollion == LEFT)
				{
					m_pos.x += GetVelocity().x*_time*time+2;
					m_pos.x = (int)m_pos.x;
					m_veloc.x = 0;
					m_accel.x = 0;
					SetBound();
				}

				if(m_directCollion== RIGHT)
				{
					m_pos.x += GetVelocity().x*_time*time-2;
					m_pos.x = (int)m_pos.x;
					m_veloc.x = 0;
					m_accel.x = 0;
				}
				break;
			}
		case MUSHROOMTYPE:
			{
				if (m_eatStar== false)
				{
					if(m_directCollion == BOTTOM)
					{
						if(!CAudio::m_isSoundOff)
							m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_MUSHROOMDIE_ID));
						m_pos.y = (int)m_pos.y;
						SetVelocityY(80);
						m_accel.y = 0;
						_orther->m_Islife = false;
						_orther->SetVelocity(D3DXVECTOR2(0,0));
						Score+=100;
						sc = new CScore(_orther->GetPosition(),MOTTRAM);
						SetBound();
					}
					if((m_directCollion== TOP || m_directCollion == RIGHT||m_directCollion == LEFT) && (m_isProtected ==false))
					{

						life--;
						if (life!=0)
						{
							if(!CAudio::m_isSoundOff)
								m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_MARIOGROW_ID));
						}

						m_isProtected = true;
						if (life < 1)
						{
							if(!CAudio::m_isSoundOff)
								m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_DEATH_ID));
							m_veloc.x = 0;
							m_veloc.y = 120.0f;
							m_maxAccelemeter.x = 0;
						}
					}
				}
				else
				{
					_orther->m_EatBulet = true;
					_orther->m_Islife = false;
					_orther->m_direct = m_direct;
					_orther->SetVelocityY(40.0f);
				}

				break;
			}
		case TURTLETYPE:
			{
				if (m_eatStar ==true)
				{
					_orther->m_EatBulet = true;
					_orther->m_Islife = false;
					_orther->m_direct = m_direct;
					_orther->SetVelocityY(40.0f);
					Score+=300;
					sc = new CScore(_orther->GetPosition(),BATRAM);
				}
				else
				{
					if(m_directCollion == BOTTOM)
					{
						if(!CAudio::m_isSoundOff)
							m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_TURTLEHEAD_ID));
						if (_orther->life == 1 && _orther->m_GrowUp == false && (GetPosition().x < _orther->GetPosition().x ||(GetPosition().x > _orther->GetPosition().x)) )
						{
							_orther->m_GrowUp = true;
							if (GetPosition().x < _orther->GetPosition().x)
							{
								_orther->m_direct = 1;
							}
							else
							{
								_orther->m_direct = -1;
							}

						}
						else
						{
							_orther->m_GrowUp = false;
							m_pos.y = (int)m_pos.y;
							SetVelocityY(80); //xet theo thoi gian con lai
							m_accel.y = 0;
							_orther->life = 1; 
							_orther->m_TimeShow = 0;
							SetBound();
						}
					}

					if((m_directCollion== TOP)&& (m_isProtected ==false))
					{
						if (_orther->life == 2)
						{
							life--;
							if (life!=0)
							{
								if(!CAudio::m_isSoundOff)
									m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_MARIOGROW_ID));
							}
							m_isProtected = true;
							if (life < 1)
							{
								if(!CAudio::m_isSoundOff)
									m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_DEATH_ID));
								m_veloc.x = 0;
								m_veloc.y = 120.0f;
								m_maxAccelemeter.x = 0;
							}
						}


					}
					if(m_directCollion == LEFT)
					{
						//rua dang di chuyen
						if ((_orther->life == 2 || _orther->m_GrowUp == true) )
						{
							if  (m_isProtected ==false)
							{				
								life--;
								if (life!=0)
								{
									if(!CAudio::m_isSoundOff)
										m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_MARIOGROW_ID));
								}
								m_isProtected = true;
								if (life < 1)
								{
									if(!CAudio::m_isSoundOff)
										m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_DEATH_ID));
									m_veloc.x = 0;
									m_veloc.y = 120.0f;
									m_maxAccelemeter.x = 0;
								}
							}
						}
						// rua dang nam Im
						else
						{
							_orther->m_GrowUp = true;
							_orther->m_direct = this->m_direct;
						}
					}

					if(m_directCollion == RIGHT)
					{
						if ((_orther->life == 2 ||  _orther->m_GrowUp == true))
						{
							if ((m_isProtected ==false))
							{						
								life--;
								if (life!=0)
								{
									if(!CAudio::m_isSoundOff)
										m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_MARIOGROW_ID));
								}
								m_isProtected = true;
								if (life < 1)
								{
									if(!CAudio::m_isSoundOff)
										m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_DEATH_ID));
									m_veloc.x = 0;
									m_accel.x = 0;
									m_maxAccelemeter.x = 0;
									m_veloc.y = 120.0f;
								}
							}
						}
						else
						{
							_orther->m_GrowUp = true;
							_orther->m_direct = this->m_direct;
						}
					}
				}
				break;
			}
		case COINTYPE:
			{
				m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_COIN_ID));
				if(!CAudio::m_isSoundOff)
					m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_COIN_ID));
				CountCoin+=1;
				Score += 100;
				sc = new CScore(_orther->GetPosition(),MOTTRAM);
				_orther->m_IsShow= false;
				_orther->m_Islife = false;

				break;
			}
		case MUSHROOMBIGTYPE:
			{
				if(!CAudio::m_isSoundOff)
					m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_POWERUP_ID));
				_orther->m_IsShow =  false;
				_orther->m_Islife = false;
				Score+=500;
				sc = new CScore(_orther->GetPosition(),NAMTRAM);
				m_isProtected = true;
				if (life ==1)
				{
					m_pos.y+=20;
				}
				if (life <= 2)
				{
					life = 2;
				}

				break;
			}
		case FLOWERTYPE:
			{
				if(!CAudio::m_isSoundOff)
					m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_POWERUP_ID));
				_orther->m_IsShow =  false;
				_orther->m_Islife = false;
				m_isProtected = true;
				life++;
				Score+=500;
				sc = new CScore(_orther->GetPosition(),NAMTRAM);
				break;
			}
		case MUSHROOMLIFETYPE:
			{
				if(!CAudio::m_isSoundOff)
					m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_LIFEUP_ID));
				_orther->m_IsShow =  false;
				_orther->m_Islife = false;
				m_isProtected = true;
				EatLife = true;
				Score+=500;
				sc = new CScore(_orther->GetPosition(),NAMTRAM);
				break;
			}
		case STARTYPE:
			{
				if(!CAudio::m_isSoundOff)
					m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_POWERUP_ID));
				_orther->m_IsShow =  false;
				_orther->m_Islife = false;
				m_isProtected = true;
				m_eatStar = true;
				Score+=500;
				sc = new CScore(_orther->GetPosition(),NAMTRAM);
				break;
			}
		case BOSSTYPE:
			{
				if (m_eatStar== false)
				{
					if(m_directCollion == BOTTOM)
					{
						if(!CAudio::m_isSoundOff)
							m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_MUSHROOMDIE_ID));
						m_pos.y = (int)m_pos.y;
						SetVelocityY(80);
						SetBound();
					}
					if((m_directCollion== TOP || m_directCollion == RIGHT||m_directCollion == LEFT) && (m_isProtected ==false))
					{

						life--;
						if (life!=0)
						{
							if(!CAudio::m_isSoundOff)
								m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_MARIOGROW_ID));
						}

						m_isProtected = true;
						if (life < 1)
						{
							if(!CAudio::m_isSoundOff)
								m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_DEATH_ID));
							m_veloc.x = 0;
							m_veloc.y = 120.0f;
							m_maxAccelemeter.x = 0;
						}
					}
				}
				else
				{
					_orther->m_EatBulet = true;
					_orther->m_Islife = false;
					_orther->m_direct = m_direct;
					_orther->SetVelocityY(40.0f);
				}

				break;
			}
		case FLAGTYPE:
			{
				_orther->m_GrowUp = true;
				if (!WinState)
				{					
					m_pos.x += GetVelocity().x*_time*time -2;
					m_pos.x = (int)m_pos.x;
					m_veloc.x = 0;
					m_accel.x = 0;
				}

				break;
			}
		default:
			break;

		}
	}	

}	
