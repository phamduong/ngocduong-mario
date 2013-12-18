#include"Flag.h"
#include"Mario.h"
CFlag::CFlag(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CFlag::CFlag(int _id,D3DXVECTOR2 pos){
	m_Id = _id;
	m_pos = pos;
	Init();
}
void CFlag::Init(){
	CGameObject::Init();
	m_type = FLAGTYPE;
	VietNam = new CCoFlag(0,D3DXVECTOR2(m_pos.x+50,-50));
	Khua = new CCoFlag(1,D3DXVECTOR2(m_pos.x-50,m_pos.y + 262));
	m_flag= CResourceManager::GetInstance()->GetResouce(COLUMNFLAG_ID);
	m_sprite = m_flag;
}
void CFlag::Update(CInput *_input,float _time,CCamera* _camera){
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
	VietNam->Update(_input,_time,_camera);
	Khua->Update(_input,_time,_camera);
	if (m_GrowUp)
	{
		VietNam->SetVelocityY(-VietNam->GetMaxVelocity().y);
		Khua->SetVelocityY(VietNam->GetMaxVelocity().y);
	}
	if (VietNam->GetPosition().y + 37 >=GetPosition().y + 300)
	{
		VietNam->Stop();
		Khua->m_IsShow= false;
		CMario::WinState = true;
	}
	if (Khua->GetPosition().y - 38 <=GetPosition().y - 300)
	{
		Khua->Stop();
		
	}
}
void CFlag::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetCurrentSprite(0);
	m_sprite->SetTimeAmination(0);
	m_sprite->UpdateSprite();
}
void CFlag::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	VietNam->Draw(_spritehandle,_camera);
	Khua->Draw(_spritehandle,_camera);
	CGameObject::Draw(_spritehandle,_camera);
}

CFlag::~CFlag(){}


///co viet nam
CCoFlag::CCoFlag(){
	m_pos = D3DXVECTOR2(0,0);
	Init();
}
CCoFlag::CCoFlag(int typeFlag,D3DXVECTOR2 pos){
	m_typeflag = typeFlag;
	m_pos = pos;
	Init();
}
void CCoFlag::Init(){
	CGameObject::Init();
	m_type = FLAGTYPE;
	if (m_typeflag==0)
	{
		m_Coflag= CResourceManager::GetInstance()->GetResouce(FLAG_ID);
	}
	else
	{
		m_Coflag= CResourceManager::GetInstance()->GetResouce(FLAGKHUA_ID);
	}
	m_sprite = m_Coflag;
	m_maxVelocity =D3DXVECTOR2(0,-30);
}
void CCoFlag::Update(CInput *_input,float _time,CCamera* _camera){
	UpdateAnimation(_input,_time);
	CGameObject::Update(_input,_time,_camera);
}
void CCoFlag::UpdateAnimation(CInput *_input,float _time){
	m_sprite->SetCurrentSprite(0);
	m_sprite->SetTimeAmination(0);
	m_sprite->UpdateSprite();
}
void CCoFlag::Draw(LPD3DXSPRITE _spritehandle,CCamera* _camera){
	if (m_IsShow)
	{
		CGameObject::Draw(_spritehandle,_camera);
	}	
}
CCoFlag::~CCoFlag(){}

