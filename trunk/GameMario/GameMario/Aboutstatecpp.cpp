#include"AboutState.h"
#include"GamestateManager.h"
#include"MenuState.h"
CAboutState::CAboutState()
{
	Init();
}
CAboutState::CAboutState(CGameStateManager* _game)
{
	this->m_game = _game;
	Init();
}
void CAboutState::Init()
{
	CGameState::Init();
	m_background = CResourceManager::GetInstance()->GetResouce(ABOUT_ID);
	m_time = 0;
}
void CAboutState::CleanUp()
{
	CGameState::CleanUp();
}
void CAboutState::Update(CInput* _input,float _time,CCamera* _camera)
{
	m_background->SetCurrentSprite(0);
	m_background->UpdateSprite();
	CGameState::Update(_input,_time,_camera);
	int keydown = _input->GetKeyDown();
	if (keydown==DIK_RETURN)
	{
		m_game->ChangeState( new CMuneState(this->m_game));
	}
}
void CAboutState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_background->DrawSprite(_spriteHandle,D3DXVECTOR2(400,400));

}
CAboutState::~CAboutState()
{
}