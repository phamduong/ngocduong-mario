#include"OptionState.h"
#include"GamestateManager.h"
#include"MenuState.h"
#include"GameOver.h"
CGameOver::CGameOver()
{
	Init();
}
CGameOver::CGameOver(CGameStateManager* _game):CGameState(_game)
{
	this->m_game = _game;
	Init();
}
void CGameOver::Init()
{
	CGameState::Init();
	m_background = CResourceManager::GetInstance()->GetResouce(GAMEOVER_ID);
	m_time = 0;
	CGameState::StopSoundBackGound();
	m_sound = CResourceManager::GetAudio();
	m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_GAMEOVER_ID));
}

void CGameOver::CleanUp()
{
	CGameState::CleanUp();
}
void CGameOver::Update(CInput* _input,float _time,CCamera* _camera)
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
void CGameOver::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_background->DrawSprite(_spriteHandle,D3DXVECTOR2(400,400));

}
CGameOver::~CGameOver()
{
}