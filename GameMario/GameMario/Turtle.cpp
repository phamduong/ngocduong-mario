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
	m_status = Normal;
	m_direct = -1;
	m_spriteTurtle= CResourceManager::GetInstance()->GetResouce(TURTLE_ID);
	m_spriteTurtleShield= CResourceManager::GetInstance()->GetResouce(TURTLESHIELD_ID);
	
	switch(m_status){
	case Normal:
		{
			m_sprite = m_spriteTurtle;
			break;
		}
	case Shield:
		{
			m_sprite = m_spriteTurtleShield;
			break;
		}
	}


}
void CTurtle::Update(CInput *_input,float _time,CCamera* _camera){
	//m_veloc.x = m_direct*10.0f;
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
	/*if(m_pos.x<=875 || m_pos.x >=1463){
		m_direct = -1.0f * m_direct;
	}*/
}
void CTurtle::UpdateAnimation(CInput *_input,float _time){
	if(m_status == Normal){
		if(m_direct ==1){
			m_sprite->SetTimeAmination(1.6f);
			m_sprite->UpdateSprite(_time,0,1,1);
		}
		else if(m_direct ==-1){
			m_sprite->SetTimeAmination(1.6f);
			m_sprite->UpdateSprite(_time,2,3,-1);
		}
	}
	else if(m_status == Shield){
		m_sprite->SetCurrentSprite(1);
		m_sprite->UpdateSprite();
		/*m_sprite->SetTimeAmination(1.6f);
		m_sprite->Update(_time,0,2,1);*/
	}
}
void CTurtle::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	CGameObject::Draw(_spritehandle,_camera);
}
CTurtle::~CTurtle(){}

