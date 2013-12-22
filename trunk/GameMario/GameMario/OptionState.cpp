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
	m_onoffSound = CResourceManager::GetInstance()->GetResouce(ONOFF_ID);
	m_time = 0;
}

void COptionState::CleanUp()
{
	CGameState::CleanUp();
}

void COptionState::Update(CInput* _input,float _time,CCamera* _camera)
{

	if (CAudio::m_isSoundOff)
	{
		m_onoffSound->SetCurrentSprite(0);
	}
	else
	{
		m_onoffSound->SetCurrentSprite(1);
	}
	m_onoffSound->UpdateSprite();
	CGameState::Update(_input,_time,_camera);
	int keydown = _input->GetKeyDown();
	if (keydown==DIK_RETURN)
	{
		m_game->ChangeState( new CMuneState(this->m_game));
	}
	if (keydown==DIK_RIGHT)
	{
		if (CAudio::m_isSoundOff)
		{
			CAudio::m_isSoundOff=false;
		}
		else
		{
			CAudio::m_isSoundOff=true;
		}
	}
	if (keydown==DIK_LEFT)
	{
		if (CAudio::m_isSoundOff)
		{
			CAudio::m_isSoundOff=false;
		}
		else
		{
			CAudio::m_isSoundOff=true;
		}
	}
}
void COptionState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_onoffSound->DrawSprite(_spriteHandle,D3DXVECTOR2(400,400));

}
COptionState::~COptionState()
{
}