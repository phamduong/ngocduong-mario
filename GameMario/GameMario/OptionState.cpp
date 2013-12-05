#include"OptionState.h"
#include"GamestateManager.h"
#include"MenuState.h"
COptionState::COptionState()
{
	Init();
}
COptionState::COptionState(CGameStateManager* _game):CGameState(_game)
{
	this->m_game = _game;
	Init();
}
void COptionState::Init()
{
	CGameState::Init();
	m_background = CResourceManager::GetInstance()->GetResouce(OPTION_ID);
	m_time = 0;
}

void COptionState::CleanUp()
{
	CGameState::CleanUp();
}
void COptionState::Resume()
{
	CGameState::Resume();
}
void COptionState::Pause()
{
	CGameState::Pause();
}
void COptionState::Update(CInput* _input,float _time,CCamera* _camera)
{
	m_background->SetCurrentSprite(0);
	m_background->UpdateSprite();
	CGameState::Update(_input,_time,_camera);
	int keydown = _input->GetKeyDown();
	if (keydown==DIK_RETURN)
	{
		m_game->ChangeState( new CMuneState(this->m_game));
		m_isQuit = true;
	}
}
void COptionState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_background->DrawSprite(_spriteHandle,D3DXVECTOR2(400,400));

}
COptionState::~COptionState()
{
}