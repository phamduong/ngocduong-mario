#include"LoadingState.h"
#include"GamestateManager.h"
#include"MenuState.h"
CLoadingState::CLoadingState()
{
	Init();
}
CLoadingState::CLoadingState(CGameStateManager* _game)
{
	this->m_game = _game;
	Init();
}
void CLoadingState::Init()
{
	CGameState::Init();
	m_background = CResourceManager::GetInstance()->GetResouce(LOADING_ID);
	m_time = 0;
}
void CLoadingState::CleanUp()
{
	CGameState::CleanUp();
}
void CLoadingState::Resume()
{
	CGameState::Resume();
}
void CLoadingState::Pause()
{
	CGameState::Pause();
}
void CLoadingState::Update(CInput* _input,float _time,CCamera* _camera)
{
	m_background->SetCurrentSprite(0);
	m_background->UpdateSprite();
	m_time +=_time;
	if (m_time >= 10.0f)
	{
		m_game->ChangeState( new CMuneState(this->m_game));
		m_isQuit = true;
	}
	CGameState::Update(_input,_time,_camera);
}
void CLoadingState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_background->DrawSprite(_spriteHandle,D3DXVECTOR2(400,400));
	//CGameState::Draw(_spriteHandle);
}
CLoadingState::~CLoadingState()
{
}