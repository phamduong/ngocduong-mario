#include"ContinueState.h"
#include"GamestateManager.h"
#include"MenuState.h"
#include"PLayingGameState.h"
CContinueState::CContinueState()
{
	Init();
}
CContinueState::CContinueState(CGameStateManager* _game)
{
	this->m_game = _game;
	Init();
}
void CContinueState::Init()
{
	CGameState::Init();
}
void CContinueState::CleanUp()
{
	CGameState::CleanUp();
}
void CContinueState::Resume()
{
	CGameState::Resume();
}
void CContinueState::Pause()
{
	CGameState::Pause();
}
void CContinueState::Update(CInput* _input,float _time,CCamera* _camera)
{
	if (CPLayingGameState::m_posmarioX!=0 || CPLayingGameState::m_posmarioY!=0)
	{
		m_game->ChangeState( new CPLayingGameState(this->m_game,CPLayingGameState::status,D3DXVECTOR2(CPLayingGameState::m_posmarioX,CPLayingGameState::m_posmarioY + 2),CPLayingGameState::m_life,CPLayingGameState::Score,CPLayingGameState::m_coin,CPLayingGameState::m_timePLay,CPLayingGameState::m_mapWorld));
		m_isQuit = true;
	}
	else
	{
		m_game->ChangeState( new CMuneState(this->m_game));
		m_isQuit = true;
	}
}
void CContinueState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{


}
CContinueState::~CContinueState()
{
}