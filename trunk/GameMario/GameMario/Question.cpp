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
	m_type = COINQUESTIONTYPE;
	m_IsShow =true;//hjen thj dau hoi(?)
	m_spritequestion = CResourceManager::GetInstance()->GetResouce(QUESTION_ID);
	m_sprite = m_spritequestion;
	m_statusitem = STATUSITEM_START;
	switch (m_itemname)
	{
	case ITEM_FLOWER:
		{
			m_object = new CFlower(-1,m_pos);
			m_object->Init();
			break;
		}
	case ITEM_COIN:
		{
			m_object = new CCoin(-1,m_pos);
			m_object->Init();
			break;
		}
	case ITEM_MUSHROOMBIG:
		{
			m_object = new CMushroomBig(-1,D3DXVECTOR2(m_pos.x,m_pos.y));
			m_object->Init();
			break;
		}

	case ITEM_MIUSHROOMLIFE:
		{
			m_object = new CMushroomLife(-1,m_pos);
			m_object->Init();
			break;
		}
	case ITEM_STAR:
		{
			m_object = new CStar(-1,m_pos);
			m_object->Init();
			break;
		}
	default:
		break;
	}
}
void CQuestion::Update(CInput *_input,float _time,CCamera* _camera,vector<CGameObject*> list){
	if (m_GrowUp == true)
	{
		m_statusitem = STATUSITEM_RUNNING;
	}
	if(m_statusitem == STATUSITEM_RUNNING){
		if (m_itemname == ITEM_COIN)
		{
			m_object->SetAcceleration(D3DXVECTOR2(0,20.0f));
			if(m_object->GetPosition().y >= m_pos.y + 150){
				m_object->SetIsShow(false); //ko ve tien nua
			}
		}
		else
		{
			m_object->m_GrowUp = true;
		}
	}
	UpdateAnimation(_input,_time);
	m_object->Update(_input,_time,_camera,list);
	CGameObject::Update(_input,_time,_camera,list);
	if (m_pos.y < StartPostion.y)
	{
		m_maxAccelemeter.y = 0;
		m_veloc.y=0;
		m_pos.y = StartPostion.y;
	}
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
	m_object->Draw(_spritehandle,_camera);
	CGameObject::Draw(_spritehandle,_camera);
	

}

