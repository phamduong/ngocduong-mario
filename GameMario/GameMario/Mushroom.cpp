#include"Mushroom.h"
CMushroom::CMushroom(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CMushroom::CMushroom(int _id,D3DXVECTOR2 pos){
	m_Id = _id;
	m_pos = pos;
	Init();
}
void CMushroom::Init(){
	CGameObject::Init();
	m_direct = -1;
	m_spriteMushroom = CResourceManager::GetInstance()->GetResouce(MUSHROOM_ID);
	m_sprite = m_spriteMushroom;
	m_collision = new CAABBCollision();
	m_maxVelocity = D3DXVECTOR2(8.0f,65.0f);
	m_maxAccelemeter = D3DXVECTOR2(5.0f,-10.0f);
	m_type = MUSHROOMTYPE;
	m_status = MushRoomLife;

}
void CMushroom::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*> ListObjectInViewPort){
	UpdateAnimation(_input,_time);
	if (m_status == MushRoomLife)
	{
		m_veloc.x = m_direct * m_maxVelocity.x;
		m_accel.y = m_maxAccelemeter.y;
	}
	if (m_status == MushRoomEatMario)
	{
		m_veloc.x = 0;
		m_accel.y = 0;

	}
	if (m_status == MushroomEatBulet)
	{
		m_veloc.x = m_direct * m_maxVelocity.x * 2;
		m_accel.y = m_maxAccelemeter.y;
	}
	CGameObject::Update(_input,_time,_camera,ListObjectInViewPort);

}
void CMushroom::ChangeStatus()
{
	if (m_Islife==true)
	{
		m_status = MushRoomLife;
	}
	if (m_Islife == false && m_EatBulet == false )
	{
		m_status = MushRoomEatMario;
	}
	if (m_Islife == false && m_EatBulet == true)
	{
		m_status = MushroomEatBulet;
	}
}
void CMushroom::UpdateAnimation(CInput *_input,float _time){
	ChangeStatus();
	if (m_status == MushRoomLife)
	{
		m_sprite->SetTimeAmination(1.6f);
		m_sprite->UpdateSprite(_time,0,1,1);
	}
	if (m_status == MushRoomEatMario)
	{		
		m_sprite->SetCurrentSprite(3);
		m_sprite->UpdateSprite();
		m_TimeShow+=_time;		
	}
	if (m_status == MushroomEatBulet)
	{
		m_sprite->SetCurrentSprite(2);
		m_sprite->UpdateSprite();
	}



}
void CMushroom::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	if (m_TimeShow <= 5.0f)
	{
		CGameObject::Draw(_spritehandle,_camera);
	}

}
void CMushroom::UpdateCollison(CGameObject* _orther, CInput* _input , float _time){

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
					m_direct = 1;
				}

				if(m_collision->GetDirectCollision() == RIGHT)
				{
					m_direct = -1;

				}
				break;
			}
		default:
			break;


		}	

	}	
}

CMushroom::~CMushroom(){}

