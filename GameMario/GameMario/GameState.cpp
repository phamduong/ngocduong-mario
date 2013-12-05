#include "GameState.h"
#include"GamestateManager.h"
#include"Object.h"

CGameState::CGameState(void)
{
}

CGameState::CGameState(CGameStateManager* _game)
{
	this->m_game = _game;
	Init();
}
void CGameState::Init()
{
	m_isQuit = false;
	m_time = 0.0f;
	m_background = NULL;
}

void CGameState::Pause()
{

}
void CGameState::CleanUp()
{

}
void CGameState::Resume()
{

}


void CGameState::Update(CInput* _keyboard,float _time,CCamera* _camera)
{

}

void CGameState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	
}
//GameStateId CGameState::GetGameStateId()
//{
//	return this->m_id;
//}
CGameState::~CGameState(void)
{
}
