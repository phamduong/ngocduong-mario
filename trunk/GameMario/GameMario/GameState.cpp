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
	m_time = 0.0f;
	m_background = NULL;
	m_sound = NULL;
	m_sound = CResourceManager::GetAudio();
}

void CGameState::CleanUp()
{

}
void CGameState::Update(CInput* _keyboard,float _time,CCamera* _camera)
{

}

void CGameState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{

}
void CGameState::StopSoundBackGound()
{
	m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_MAP1_ID));
	m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_MAP2_ID));
}
CGameState::~CGameState(void)
{
}
