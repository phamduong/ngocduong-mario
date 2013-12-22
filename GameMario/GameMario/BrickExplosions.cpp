#include"BrickExplosions.h"
CBrickExplosions::CBrickExplosions(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CBrickExplosions::CBrickExplosions(int _id,D3DXVECTOR2 pos){
	m_Id =_id;
	m_pos = pos;
	Init();
}
void CBrickExplosions::Init(){
	CGameObject::Init();
	m_spriteBrick = CResourceManager::GetInstance()->GetResouce(BRICK_ID);
	m_sprite = m_spriteBrick;
	D3DXVECTOR2 _veclocBrickBreak(10.0f,20.0f);
	D3DXVECTOR2 _accelBrickBreak(1.0f,-10.0f);
	CBrickBreak *lefttop = new CBrickBreak(D3DXVECTOR2(m_pos.x ,m_pos.y + 25),D3DXVECTOR2(-_veclocBrickBreak.x ,_veclocBrickBreak.y*2),D3DXVECTOR2(-_accelBrickBreak.x ,_accelBrickBreak.y));
	m_brickBreak.push_back(lefttop);
	CBrickBreak *leftBottom = new CBrickBreak(D3DXVECTOR2(m_pos.x,m_pos.y),D3DXVECTOR2(-_veclocBrickBreak.x ,_veclocBrickBreak.y),D3DXVECTOR2(-_accelBrickBreak.x ,_accelBrickBreak.y));
	m_brickBreak.push_back(leftBottom);
	CBrickBreak *righttop = new CBrickBreak(D3DXVECTOR2(m_pos.x + 25,m_pos.y + 25),D3DXVECTOR2(_veclocBrickBreak.x ,_veclocBrickBreak.y*2),D3DXVECTOR2(_accelBrickBreak.x ,_accelBrickBreak.y));
	m_brickBreak.push_back(righttop);
	CBrickBreak *rightbotom = new CBrickBreak(D3DXVECTOR2(m_pos.x+25,m_pos.y ),D3DXVECTOR2(_veclocBrickBreak.x ,_veclocBrickBreak.y),D3DXVECTOR2(_accelBrickBreak.x ,_accelBrickBreak.y));
	m_brickBreak.push_back(rightbotom);
	m_type = BRICKTYPE;
}
void CBrickExplosions::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*> ListObjectInViewPort){
	/***********************************************************/
	CGameObject::Update(_input,_time,_camera,ListObjectInViewPort);
	if (m_pos.y < StartPostion.y)
	{
		m_maxAccelemeter.y = 0;
		m_veloc.y=0;
		m_pos.y = StartPostion.y;
	}
	UpdateAnimation(_input,_time);
	if(m_IsShow == false){
		for (int i = 0; i < m_brickBreak.size(); i++)
		{
			m_brickBreak[i]->Update(_input,_time,_camera);
		}

		SetBound(new RECT ());
	}
}
void CBrickExplosions::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetCurrentSprite(1);
	m_sprite->SetTimeAmination(0);
	m_sprite->UpdateSprite();
}
void CBrickExplosions::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	if(m_IsShow){
		CGameObject::Draw(_spritehandle,_camera);
	}
	else
	{
		for (int i = 0; i < m_brickBreak.size(); i++)
		{
			m_brickBreak[i]->Draw(_spritehandle,_camera);
		}

	}
}
void CBrickExplosions::UpdateCollison(CGameObject* _orther, CInput* _input , float _time)
{
	if (m_veloc.y != 0)
	{
		float time = m_collision->CheckAABBCollision(this,_orther,_time);
		if(time<1.0f)
		{
			//ListObjectColision
			switch (_orther->GetType())
			{
			case MUSHROOMTYPE:
			case TURTLETYPE:
				{
					_orther->m_EatBulet = true;
					_orther->m_Islife = false;
					//_orther->m_direct = m_direct;
					_orther->SetVelocityY(40.0f);
					break;
				}
			}
		}
	}

}
CBrickExplosions::~CBrickExplosions(){}

