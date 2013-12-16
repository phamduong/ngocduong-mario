#include"LoadingState.h"
#include"GamestateManager.h"
#include"MenuState.h"
#include"CAudio.h"
CLoadingState::CLoadingState()
{
	Init();
}
CLoadingState::CLoadingState(CGameStateManager* _game)
{
	this->m_game = _game;
	m_texture = new CTexture(_game->m_graphic->Get_pd3device());
	m_Loading = new CSprite(1,1,800,800);
	m_Loading->Init(m_texture->GetTexture(LOADING1));
	Init();

}
void CLoadingState::Init()
{
	CGameState::Init();
	m_time = 0;
	CResourceManager::GetInstance()->Init(m_game->m_graphic->Get_pd3device(), m_game->m_wndHandle);
}
void CLoadingState::CleanUp()
{
	CGameState::CleanUp();
}
void CLoadingState::Update(CInput* _input,float _time,CCamera* _camera)
{
	m_Loading->SetCurrentSprite(0);
	m_Loading->UpdateSprite();
	CGameState::Update(_input,_time,_camera);
	m_sound = CResourceManager::GetAudio();
	if(!CAudio::m_isSoundOff)
		m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_LOADING_ID));
	m_time +=_time;
}
void CLoadingState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_Loading->DrawSprite(_spriteHandle,D3DXVECTOR2(400,400));

	if (m_time>10.0f)
	{
		m_time = 0;
		m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_LOADING_ID));
		m_game->ChangeState( new CMuneState(this->m_game));

	}


}
CLoadingState::~CLoadingState()
{
}