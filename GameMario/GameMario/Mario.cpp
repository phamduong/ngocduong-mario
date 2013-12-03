#include"Mario.h"
#include <stdlib.h>
CMario::CMario()
{
	Init();
}
CMario::~CMario(){
}
void CMario::Init(){
	CGameObject::Init();
	m_pos = D3DXVECTOR2(100,600);
	m_veloc = D3DXVECTOR2(0,0);
	m_accel = D3DXVECTOR2(0,0);
	m_maxVelocity = D3DXVECTOR2(40.0f,120.0f);
	m_MaxVeloc = m_maxVelocity;
	m_maxAccelemeter = D3DXVECTOR2(5.0f,-30.0f);
	m_action = Jump;
	m_start_status = mariosmall;
	m_direct = 1;
	life = 1;
	CountCoin = 0;
	m_isProtected = false;
	m_eatStar = false;
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

	if(m_input->KeyDown(DIK_RIGHT)&&m_action != down&&m_pos.x<=g_widthMap)
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
	int keydown = m_input ->GetKeyDown();
	//mario ban
	if(keydown == DIK_C && m_action!=down && m_status == mariogun){
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
		if(m_action!=down && m_action!=Jump && m_action==normal){
			m_action = Jump;
			m_veloc.y = m_MaxVeloc.y;
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
		if (ListItem[i]->m_IsShow == false)
		{
			ListItem.erase(ListItem.begin() + i);
		}
		else
		{
			UpdateCollison(ListItem[i],m_input,_time);
		}
	}
	// update va va cham voi nhug thu ko fai item
	CGameObject::Update(m_input,_time,_camera,ListObjectInViewPort);
	UpdateAnimation(m_input,_time);
	_camera->Update(m_pos);

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
				m_sprite->SetCurrentSprite(10);
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
				m_sprite->UpdateSprite(_time,9,10,-1);
			}
		}
		if(m_action==Jump){//jump
			if(m_direct==1){
				m_sprite->SetCurrentSprite(2);
				m_sprite->UpdateSprite();
			}
			if(m_direct==-1){

				m_sprite->SetCurrentSprite(8);
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

				m_sprite->SetCurrentSprite(7);
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

				m_sprite->SetCurrentSprite(6);
				m_sprite->SetTimeAmination(0);
				m_sprite->UpdateSprite();
			}
		}
	}
#pragma endregion
}

void CMario::Draw(LPD3DXSPRITE _spriteHandler,CCamera* _camera){
	for (int i = 0; i < m_bullet.size(); i++)
	{
		if(m_bullet[i]!=NULL){
			m_bullet[i]->Draw(_spriteHandler,_camera);
		}
	}

	if (m_timeShowProtected == 0.0f)
	{
		CGameObject::Draw(_spriteHandler, _camera);
	}

}

void CMario::UpdateCollison(CGameObject* _orther, CInput* _input , float _time){
	if (_orther->GetType()!=MARIOTYPE)
	{

		float time = m_collision->CheckAABBCollision(this,_orther,_time);
		if(time<1.0f)
		{
			//ListObjectColision
			switch (_orther->GetType())
			{
			case PIPETYPE:
			case LANDTYPE:
				{
					if(m_collision->GetDirectCollision() == BOTTOM)
					{
						m_action = normal;
						m_pos.y += GetVelocity().y*_time*time +2;
						m_pos.y = (int)m_pos.y;//_orther->GetBound().top + m_sprite->GetSpriteHeight()/2 + 2;
						SetVelocityY(0);
						m_accel.y = 0;
						SetBound();

					}
					if(m_collision->GetDirectCollision()== TOP)
					{
						m_pos.y += GetVelocity().y*_time*time-2;
						m_pos.y = (int)m_pos.y;
						SetVelocityY(0);
						SetBound();
					}
					if(m_collision->GetDirectCollision() == LEFT)
					{
						m_pos.x += GetVelocity().x*_time*time+2;
						m_pos.x = (int)m_pos.x;
						m_veloc.x = 0;
						m_accel.x = 0;
						SetBound();
						//MessageBox(NULL,"BOTTOM","",MB_OK);
					}

					if(m_collision->GetDirectCollision() == RIGHT)
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
					if(m_collision->GetDirectCollision() == BOTTOM)
					{
						m_action = normal;
						m_pos.y += GetVelocity().y*_time*time + 2;
						m_pos.y = (int)m_pos.y;
						SetVelocityY(0);
						m_accel.y = 0;
						SetBound();
					}
					if(m_collision->GetDirectCollision()== TOP)
					{
						m_pos.y += GetVelocity().y*_time*time-2;
						m_pos.y = (int)m_pos.y;
						SetVelocityY(0);
						m_accel.y = 0;
						SetBound();
						if(m_status!=mariosmall)
						{
							_orther->m_IsShow = false;
							_orther->m_Islife = false;
						}
						else
						{
							_orther->SetVelocityY(15);
							_orther->SetAccelerationY(-10.0f );

						}
					}
					if(m_collision->GetDirectCollision() == LEFT)
					{
						m_pos.x += GetVelocity().x*_time*time+2;
						m_pos.x = (int)m_pos.x;
						m_veloc.x = 0;
						m_accel.x = 0;
						SetBound();
					}

					if(m_collision->GetDirectCollision() == RIGHT)
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
					if(m_collision->GetDirectCollision() == BOTTOM)
					{
						m_action = normal;
						m_pos.y += GetVelocity().y*_time*time + 2;
						m_pos.y = (int)m_pos.y;
						SetVelocityY(0);
						m_accel.y = 0;
						SetBound();
					}
					if(m_collision->GetDirectCollision()== TOP)
					{
						// neu con la dau hoi 
						/*if (_orther->m_IsShow ==true)
						{
						_orther->SetVelocityY(15);
						_orther->SetAccelerationY(-10.0f );
						}*/
						m_pos.y += GetVelocity().y*_time*time-2;
						m_pos.y = (int)m_pos.y;
						SetVelocityY(0);
						m_accel.y = 0;
						_orther->m_IsShow = false;//chuyen ve ko co dau hoi
						_orther->m_GrowUp = true; //moc item len
						SetBound();
						//
						CQuestion * Item = (CQuestion*) _orther;
						if (Item->m_itemname!=ITEM_COIN)
						{
							ListItem.push_back(Item->m_object);
						}

					}
					if(m_collision->GetDirectCollision() == LEFT)
					{
						m_pos.x += GetVelocity().x*_time*time+2;
						m_pos.x = (int)m_pos.x;
						m_veloc.x = 0;
						m_accel.x = 0;
						SetBound();
					}

					if(m_collision->GetDirectCollision() == RIGHT)
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
						if(m_collision->GetDirectCollision() == BOTTOM)
						{
							m_pos.y = (int)m_pos.y;
							//SetVelocityY(-(GetVelocity().y *(1.0f - time))); //xet theo thoi gian con lai
							SetVelocityY(80);
							m_accel.y = 0;
							_orther->m_Islife = false;
							_orther->SetVelocity(D3DXVECTOR2(0,0));
							SetBound();
						}
						if((m_collision->GetDirectCollision()== TOP || m_collision->GetDirectCollision() == RIGHT||m_collision->GetDirectCollision() == LEFT) && (m_isProtected ==false))
						{

							life--;
							m_isProtected = true;
							if (life < 1)
							{
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
					}
					else
					{
						if(m_collision->GetDirectCollision() == BOTTOM)
						{
							_orther->m_GrowUp = false;
							m_pos.y = (int)m_pos.y;
							SetVelocityY(80); //xet theo thoi gian con lai
							m_accel.y = 0;
							_orther->life = 1; 
							_orther->m_TimeShow = 0;
							SetBound();
						}
						if((m_collision->GetDirectCollision()== TOP)&& (m_isProtected ==false))
						{
							if (_orther->life == 2)
							{
								life--;
								m_isProtected = true;
								if (life < 1)
								{
									m_veloc.x = 0;
									m_veloc.y = 120.0f;
									m_maxAccelemeter.x = 0;
								}
							}


						}
						if(m_collision->GetDirectCollision() == LEFT)
						{
							//rua dang di chuyen
							if ((_orther->life == 2 || _orther->m_GrowUp == true) )
							{
								if  (m_isProtected ==false)
								{				
									life--;
									m_isProtected = true;
									if (life < 1)
									{
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

						if(m_collision->GetDirectCollision() == RIGHT)
						{
							if ((_orther->life == 2 ||  _orther->m_GrowUp == true))
							{
								if ((m_isProtected ==false))
								{						
									life--;
									m_isProtected = true;
									if (life < 1)
									{
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
					CountCoin++;
					_orther->m_IsShow= false;
					_orther->m_Islife = false;
					break;
				}
			case MUSHROOMBIGTYPE:
				{
					_orther->m_IsShow =  false;
					_orther->m_Islife = false;
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
					_orther->m_IsShow =  false;
					_orther->m_Islife = false;
					m_isProtected = true;
					life++;
					break;
				}
			case STARTYPE:
				{
					_orther->m_IsShow =  false;
					_orther->m_Islife = false;
					m_isProtected = true;
					m_eatStar = true;
					break;
				}
			default:
				break;


			}	

		}	

	}
}