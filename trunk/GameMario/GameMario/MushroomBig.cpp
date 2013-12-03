#include"MushroomBig.h"
CMushroomBig::CMushroomBig(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CMushroomBig::CMushroomBig(int _id,D3DXVECTOR2 pos){
	m_Id = _id;
	m_pos = pos;
	Init();
}
void CMushroomBig::Init(){
	CGameObject::Init();
	m_maxAccelemeter = D3DXVECTOR2(0.0f , -10.0f);
	m_maxVelocity = D3DXVECTOR2(20.0f, -60.0f);
	m_spriteLife = CResourceManager::GetInstance()->GetResouce(ITEM_ID);
	m_sprite = m_spriteLife;
	m_type = MUSHROOMBIGTYPE;
	m_IsShow = true;
	m_direct =1;
	m_GrowUp = false;
	GrowUpFinish = false;  
}
void CMushroomBig::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*> ListObjectInViewPort){
	if (m_GrowUp == true && GrowUpFinish ==false)
	{
		if (m_pos.y < StartPostion.y + m_sprite->GetSpriteHeight() )
		{
			m_accel.y = -m_maxAccelemeter.y/10;
			
		}

		else
		{
			GrowUpFinish = true;
			SetVelocityY(0);

		}
	}
	if (GrowUpFinish==true)
	{
		m_accel.y = m_maxAccelemeter.y;
		m_veloc.x =m_direct * m_maxVelocity.x;
	}
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera,ListObjectInViewPort);

	/**************************************************************************************/
}
void CMushroomBig::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetCurrentSprite(0);
	m_sprite->SetTimeAmination(0);
	m_sprite->UpdateSprite();
}
void CMushroomBig::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	if (m_IsShow==true)
	{
		CGameObject::Draw(_spritehandle,_camera);
	}

}
void CMushroomBig::UpdateCollison(CGameObject* _orther, CInput* _input , float _time)
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
CMushroomBig::~CMushroomBig(){}

