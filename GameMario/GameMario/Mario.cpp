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
	m_pos = D3DXVECTOR2(309,600);
	m_veloc = D3DXVECTOR2(0,0);
	m_accel = D3DXVECTOR2(0,0);
	m_maxVelocity = D3DXVECTOR2(25.0f,50.0f);
	m_MaxVeloc = m_maxVelocity;
	m_maxAccelemeter = D3DXVECTOR2(5.0f,400.0f);
	m_action = normal;
	m_start_status = mariobig;
	m_direct = 1;
	life = 1;
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
void CMario::Update(CInput *m_input,float _time,CCamera * _camera){


	UpdateAnimation(m_input,_time);
	if (m_pos.y > GROUNDY)
	{
		if(m_veloc.y > - m_maxVelocity.y)
			m_accel.y = -10;
		else
		{
			m_accel.y = 0;
			m_veloc.y = -m_maxVelocity.y;
		}
	}
	else 
	{
		m_pos.y = GROUNDY;
		m_veloc.y = 0;
		m_accel.y = 0;
	}
	for (int i = 0; i < m_bullet.size(); i++)
	{
		if(m_bullet[i] !=NULL){
			m_bullet[i]->Update(m_input,_time,_camera);
		}
	}

#pragma region Nhap phim 

	if(m_input->KeyDown(DIK_RIGHT)&&m_action != down&&m_pos.x<=g_widthMap)
	{	
		m_directCollion= NONE;
		m_direct = 1;
		m_action = run;
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
		m_directCollion=NONE;
		m_direct = -1;
		m_action = run;
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

	}
	else 
	{
		if(m_veloc.x!=0){
			m_accel.x =- 1.0f*m_direct*(m_maxAccelemeter.x);
		}
		if((m_direct*m_veloc.x) <=0){
			m_veloc.x = 0;
			m_accel.x= 0;
			m_action = normal;
		}

	}

	/**********************************KEY DOWN**************************************************/
	int keydown = m_input ->GetKeyDown();
	//mario ban
	if(keydown == DIK_C){
		CBullet *_bullet = new CBullet(D3DXVECTOR2(m_pos.x,m_pos.y ),m_direct);
		_bullet->Shotting();
		m_bullet.push_back(_bullet);

	}
	//mario nhay
	if(keydown==DIK_V){
		if(m_action!=down && m_action!=Jump){
			m_action = Jump;
			if(m_pos.y <=GROUNDY)
				if(m_veloc.y < m_maxVelocity.y)
					m_accel.y = m_maxAccelemeter.y;
				else
				{
					m_accel.y = 0;
					m_veloc.y = m_maxVelocity.y;
				}
		}

	}

	/************************************KEY UP********************************************************/


#pragma endregion
	CGameObject::Update(m_input,_time,_camera);
	_camera->Update(m_pos);
}
void CMario ::UpdateAnimation(CInput *m_input,float _time){
	///**********************************STatus la Big or Gun **************/

#pragma region Mariobig and gun
	if(m_status ==mariobig ||m_status==mariogun){
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
				m_sprite->UpdateSprite(_time,2,3,1);
			}
			if(m_direct==-1){

				m_sprite->SetTimeAmination(TIMEAMINATION);
				m_sprite->UpdateSprite(_time,6,7,-1);
			}
		}
		if(m_veloc.y!=0){//jump
			if(m_direct==1){
				m_sprite->SetCurrentSprite(1);
				m_sprite->UpdateSprite();
			}
			if(m_direct==-1){

				m_sprite->SetCurrentSprite(8);
				m_sprite->UpdateSprite();
			}
		}
		if(m_action ==down){//down
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
		if(m_veloc.y!=0){//jump
			if(m_direct==1){
				m_sprite->SetCurrentSprite(2);
				m_sprite->UpdateSprite();
			}
			if(m_direct==-1){

				m_sprite->SetCurrentSprite(8);
				m_sprite->UpdateSprite();
			}
		}
		if(m_action ==down){//down
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
		if(life == 0)
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

	CGameObject::Draw(_spriteHandler,_camera);



}

void CMario::UpdateCollison(CGameObject* _orther, CInput* _input , float _time){

	float time = m_collision->CheckAABBCollision(this,_orther,_time);
	if(time<1.0f){
		if (_orther->GetType()==PIPE)
		{
			if(m_collision->GetDirectCollision() == BOTTOM)
			{
				MessageBox(NULL,"BOT","THONG BAO",MB_OK);
			}
			else if(m_collision->GetDirectCollision()== TOP)
			{
				MessageBox(NULL,"TOP","THONG BAO",MB_OK);
			}
			else if(m_collision->GetDirectCollision() == LEFT)
			{
				MessageBox(NULL,"LEFT","THONG BAO",MB_OK);
			}
			else
				if(m_collision->GetDirectCollision() == RIGHT)
				{
					MessageBox(NULL,"RIGHT","THONG BAO",MB_OK);
				}
		}
	}

}
