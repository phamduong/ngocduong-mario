#include"Question.h"
CQuestion::CQuestion(){
	m_pos = D3DXVECTOR2(1000,200);
	Init();
}
CQuestion::CQuestion(int _id,D3DXVECTOR2 _pos){
	m_Id = _id;
	m_pos = _pos;
	Init();
}
CQuestion::CQuestion(int _id,D3DXVECTOR2 _pos,ItemName _name){
	m_Id = _id;
	m_pos = _pos;
	m_itemname = _name;
	Init();
}
void CQuestion::Init(){
	CGameObject::Init();
	m_IsShow =true;//hjen thj dau hoi(?)
	m_spritequestion = CResourceManager::GetInstance()->GetResouce(QUESTION_ID);
	m_sprite = m_spritequestion;
	m_statusitem = STATUSITEM_RUNNING;
	switch (m_itemname)
	{
	case ITEM_FLOWER:
		{
			m_object = new CFlower(m_Id,m_pos);
			m_object->Init();
			break;
		}
	case ITEM_COIN:
		{
			m_object = new CCoin(m_Id,m_pos);
			m_object->Init();
			break;
		}
	case ITEM_MUSHROOMBIG:
		{
			m_object = new CMushroomBig(m_Id,D3DXVECTOR2(m_pos.x,m_pos.y));
			m_object->Init();
			break;
		}

	case ITEM_MIUSHROOMLIFE:
		{
			m_object = new CMushroomLife(m_Id,m_pos);
			m_object->Init();
			break;
		}
	case ITEM_STAR:
		{
			m_object = new CStar(m_Id,m_pos);
			m_object->Init();
			break;
		}
	default:
		break;
	}
}
void CQuestion::Update(CInput *_input,float _time,CCamera* _camera){
	if(m_statusitem == STATUSITEM_RUNNING){
		if(m_itemname==ITEM_COIN){
			m_object->SetAcceleration(D3DXVECTOR2(0,10.0f));
			if(m_object->GetPosition().y >= m_pos.y + 150){
				m_object->SetIsShow(false);
			}
			
		}
		else if(m_itemname==ITEM_STAR){
			m_object->SetVelocity(m_object->GetMaxVelocity());
			
			if(m_object->GetPosition().y >= m_pos.y + 150){
				m_object->SetAccelerationY(-100.0f);
				m_object->SetMaxVelocity(D3DXVECTOR2(0,0));
			}
				
			
					
		}
		else{
			m_object->SetAcceleration(D3DXVECTOR2(0,1.0f));
			if(m_object->GetPosition().y >= m_pos.y + m_sprite->GetSpriteHeight()){
				m_object->SetAcceleration(D3DXVECTOR2(0,0));
				m_object->SetVelocity(D3DXVECTOR2(0,0));
			}
		}
	}

	UpdateAnimation(_input,_time);
	m_object->Update(_input,_time,_camera);
	CGameObject::Update(_input,_time,_camera);

}
void CQuestion::UpdateAnimation(CInput *_input,float _time){
	//m_sprite->SetCurrentSprite(1);
	if(m_IsShow==true){
		m_sprite->SetTimeAmination(1.6f);
		m_sprite->UpdateSprite(_time,1,2,1);
	}
	else {
		m_sprite->SetCurrentSprite(0);
		m_sprite->UpdateSprite();
	}
}
void CQuestion::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	
	CGameObject::Draw(_spritehandle,_camera);
	m_object->Draw(_spritehandle,_camera);

}

