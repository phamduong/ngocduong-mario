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
	m_pos = D3DXVECTOR2(50,600);
	m_veloc = D3DXVECTOR2(0,0);
	m_accel = D3DXVECTOR2(0,0);
	m_maxVelocity = D3DXVECTOR2(25.0f,50.0f);
	m_maxAccelemeter = D3DXVECTOR2(120.0f,550.0f);
	m_action = normal;
	m_start_status = mariobig;
	m_direct = 1;
	life = 1;
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

	CGameObject::SetBound();

}
void CMario::Update(CInput *m_input,float _time,CCamera * _camera){

	UpdateAnimation(m_input,_time);
	for (int i = 0; i < m_bullet.size(); i++)
	{
		if(m_bullet[i] !=NULL){
			m_bullet[i]->Update(m_input,_time,_camera);
		}
	}

#pragma region Nhap phim 

	if(m_input->KeyDown(DIK_RIGHT)&&m_action != down&&m_pos.x<=g_widthMap)
	{

		if(m_direct = -1){
			m_veloc.x = 0;
		}
		m_direct = 1;
		m_action = run;
		if(m_veloc.x < m_maxVelocity.x)
		{
			m_accel.x =m_maxAccelemeter.x ;
		}
		if (m_veloc.x >= m_maxVelocity.x)
		{
			m_accel.x = 0;
			m_veloc.x = m_maxVelocity.x ;
		}


	}

	else
	{

		if(m_input->KeyDown(DIK_LEFT)&& m_action != down&&m_pos.x>=25)
		{
			if(m_direct = 1 )
			{
				m_veloc.x =0;
			}
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

		else 
		{

			if(m_input->KeyDown(DIK_DOWN) && m_action!=Jump){
				m_action = down;
				m_veloc.x = 0;
				m_accel.x = 0;

			}
			else {
				if(m_veloc.x!=0){
					m_accel.x =- 1.0f*m_direct*(m_maxAccelemeter.x / 10);
				}
				if((m_direct*m_veloc.x) <=0){
					m_veloc.x = 0;
					m_accel.x= 0;
					m_action = normal;
				}

			}
		}
	}

	/**********************************KEY DOWN**************************************************/
	int keydown = m_input ->GetKeyDown();
	//mario ban
	if(keydown == DIK_V){
		CBullet *_bullet = new CBullet(D3DXVECTOR2(m_pos.x-10 + m_sprite->GetSpriteWidth()/2,m_pos.y -10 + m_sprite->GetSpriteHeight()/2),m_direct);
		_bullet->Shotting();
		m_bullet.push_back(_bullet);

	}
	//mario nhay
	if(keydown==DIK_C){
		if(m_action!=down && m_action!=Jump){
			m_action = Jump;
			if(m_pos.y <=GROUNDY)
				m_accel.y = m_maxAccelemeter.y;
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


	if (m_pos.y > GROUNDY) m_accel.y = -20;
	else 
	{
		m_pos.y = GROUNDY;
		m_veloc.y = 0;
	}

}

//void CMario::UpdateCollison(CGameObject* _other, CInput* _input , float _time){
//	//D3DXVECTOR2 _deltaDistance = D3DXVECTOR2(0,0);
//	//if(!(this->m_collision->AABBCollision(this , _other,&_deltaDistance,_time)))
//	//{
//	//	return;
//	//}
//	//D3DXVECTOR2 _deepDistance = this->m_collision->GetDeepDistance();
//	//DirectCollision _directCollision = this->m_collision->GetDirectCollision();
//	//D3DXVECTOR2 _continueDistance;
//	//_continueDistance = this->GetVelocity() * _time - _deltaDistance;
//
//	////
//	//int x =1;
//	//switch (x)
//	//{
//	//case 1:
//	//	{
//	//		if (_directCollision == BOTTOM)
//	//		{
//	//		/*	m_pos.y += _deepDistance.y;
//	//			this->SetVelocityY(0);*/
//	//		}
//	//		else if(_directCollision == TOP)
//	//		{
//	//			/*if(m_veloc.y > 0|| _other->m_isInColumn)
//	//				return;
//	//			m_pos.y =_other->GetBound().bottom;
//	//			this->SetVelocityY(0);
//	//			m_action = normal;
//	//			break;*/
//	//		}
//	//		else if(_directCollision == RIGHT)
//	//		{
//	//			/*m_pos.x += _deepDistance.x;*/
//	//		/*	this->SetAccelerationX(0);*/
//	//			this->SetVelocityX(0);
//	//		}
//	//		else if(_directCollision == LEFT)
//	//		{
//	//			/*m_pos.x += _deepDistance.x;*/
//	//		/*	this->SetAccelerationX(0);*/
//	//			this->SetVelocityX(0);
//	//		}
//	//		break;
//	//	}
//	//}
//
//}
