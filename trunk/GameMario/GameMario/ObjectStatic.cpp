#include"ObjectStatic.h"
CObjectStatic::CObjectStatic(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CObjectStatic::CObjectStatic(int _id,D3DXVECTOR2 _pos,ObjectName _name){
	m_Id = _id;
	m_pos = _pos;
	m_name = _name;
	Init();
}
void CObjectStatic::Init(){
	CGameObject::Init();
	m_bigtree = CResourceManager::GetInstance()->GetResouce(BIGTREE_ID);
	m_smalltree = CResourceManager::GetInstance()->GetResouce(SMALLTREE_ID);
	m_cloud = CResourceManager::GetInstance()->GetResouce(CLOUD_ID);
	m_grass = CResourceManager::GetInstance()->GetResouce(GRASS_ID);
	m_mountain = CResourceManager::GetInstance()->GetResouce(MOUNTAIN_ID);
	m_fence = CResourceManager::GetInstance()->GetResouce(FENCE_ID);
	m_house = CResourceManager::GetInstance()->GetResouce(HOUSE_ID);
	m_type = OBJECTTYPE;
	switch (m_name)
	{
	case NAMEBIGTREE:
		m_sprite = m_bigtree;
		break;
	case NAMESMALLTREE:
		m_sprite = m_smalltree;
		break;
	case NAMEMOUNTAIN:
		m_sprite = m_mountain;
		break;
	case NAMECLOUD:
		m_sprite = m_cloud;
		break;
	case NAMEGRASS:
		m_sprite = m_grass;
		break;
	case NAMEHOUSE:
		m_sprite = m_house;
		m_type = HOUSETYPE;
		break;
	case NAMEFENCE:
		m_sprite = m_fence;
		break;
	default:
		break;
	}
}
void CObjectStatic::Update(CInput *_input,float _time,CCamera* _camera){
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
}
void CObjectStatic::UpdateAnimation(CInput *_input,float _time){

	switch(m_name)
	{
	case NAMEBIGTREE:
	case NAMESMALLTREE:
	case NAMEFENCE:
	case NAMEHOUSE:
	case NAMEMOUNTAIN:
		{
			m_sprite->SetCurrentSprite(0);
			m_sprite->SetTimeAmination(0);
			m_sprite->UpdateSprite();
			break;
		}
	case NAMEGRASS:
	case NAMECLOUD:
		{
			m_sprite->SetTimeAmination(1.6f);
			m_sprite->UpdateSprite(_time,0,1,1);
			break;
		}
	}

}
void CObjectStatic::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	CGameObject::Draw(_spritehandle,_camera);
}

