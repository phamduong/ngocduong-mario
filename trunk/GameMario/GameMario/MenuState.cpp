#include"MenuState.h"
#include"GamestateManager.h"
#include"PLayingGameState.h"
CMuneState::CMuneState()
{
	Init();
}
void CMuneState::Init()
{
	CGameState::Init();
	m_background = CResourceManager::GetInstance()->GetResouce(BACKGROUNDMENU_ID);
	m_menunewgame = CResourceManager::GetInstance()->GetResouce(MENUNEWGAME_ID);
	m_menuabout = CResourceManager::GetInstance()->GetResouce(MENUABOUT_ID);
	m_menuexit = CResourceManager::GetInstance()->GetResouce(MENUEXIT_ID);
	m_menuoption = CResourceManager::GetInstance()->GetResouce(MENUOPTION_ID);
	m_menucontinue = CResourceManager::GetInstance()->GetResouce(MENUCONTINUE_ID);
	m_select = CResourceManager::GetInstance()->GetResouce(SELECT_ID);
	m_time = 0;
	Select = 1;

}
void CMuneState::CleanUp()
{
	CGameState::CleanUp();
}
void CMuneState::Resume()
{
	CGameState::Resume();
}
void CMuneState::Pause()
{
	CGameState::Pause();
}
void CMuneState::Update(CInput* _input,float _time,CCamera* _camera)
{
	m_background->SetCurrentSprite(0);
	m_menunewgame->SetCurrentSprite(0);
	m_menucontinue->SetCurrentSprite(0);
	m_menuoption->SetCurrentSprite(0);
	m_menuabout->SetCurrentSprite(0);
	m_menuexit->SetCurrentSprite(0);
	m_select->SetCurrentSprite(0);
	int key = _input->GetKeyDown();
	if (key==DIK_DOWN)
	{
		Select++;
	}
	else if (key==DIK_UP)
	{
		Select--;
	}
	if (Select > 5)
	{
		Select = 1;
	}
	if (Select < 1)
	{
		Select = 5;
	}

	if (Select==1)
	{
		m_menunewgame->SetCurrentSprite(1);
		m_posSelect = D3DXVECTOR2(350- m_menunewgame->GetSpriteWidth()/2,300);
	}
	else if (Select==2)
	{
		m_menucontinue->SetCurrentSprite(1);
		m_posSelect = D3DXVECTOR2(350- m_menucontinue->GetSpriteWidth()/2,380);
	}
	else if (Select==3)
	{
		m_menuoption->SetCurrentSprite(1);
		m_posSelect = D3DXVECTOR2(350- m_menuoption->GetSpriteWidth()/2,460);
	}	
	else if (Select==4)
	{
		m_menuabout->SetCurrentSprite(1);
		m_posSelect = D3DXVECTOR2(350- m_menuabout->GetSpriteWidth()/2,540);
	}	
	else if (Select==5)
	{
		m_menuexit->SetCurrentSprite(1);
		m_posSelect = D3DXVECTOR2(350- m_menuexit->GetSpriteWidth()/2,620);
	}	
	if (key == DIK_RETURN)
	{
		switch (Select)
		{
		case 1:
			{
				m_game->ChangeState( new CPLayingGameState(this->m_game));
				m_isQuit = true;
				break;
			}
		case 2:
			{
				m_game->ChangeState( new CLoadingState(this->m_game));
				m_isQuit = true;
				break;
			}
		case 3:
			{
				m_game->ChangeState( new CLoadingState(this->m_game));
				m_isQuit = true;
				break;
			}
		case 4:
			{
				m_game->ChangeState( new CLoadingState(this->m_game));
				m_isQuit = true;
				break;
			}
		case 5:
			{
				PostQuitMessage(0);
				break;
			}
		default:
			break;
		}


	}

	//
	m_background->UpdateSprite();
	m_menunewgame->UpdateSprite();
	m_menucontinue->UpdateSprite();
	m_menuoption->UpdateSprite();
	m_menuabout->UpdateSprite();
	m_menuexit->UpdateSprite();
	m_select->UpdateSprite();

}
void CMuneState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_background->DrawSprite(_spriteHandle,D3DXVECTOR2(0,0));
	m_select->DrawSprite(_spriteHandle,m_posSelect);
	m_menunewgame->DrawSprite(_spriteHandle,D3DXVECTOR2(400- m_menunewgame->GetSpriteWidth()/2,300));
	m_menucontinue->DrawSprite(_spriteHandle,D3DXVECTOR2(400- m_menucontinue->GetSpriteWidth()/2,380));
	m_menuoption->DrawSprite(_spriteHandle,D3DXVECTOR2(400- m_menuoption->GetSpriteWidth()/2,460));
	m_menuabout->DrawSprite(_spriteHandle,D3DXVECTOR2(400- m_menuabout->GetSpriteWidth()/2,540));
	m_menuexit->DrawSprite(_spriteHandle,D3DXVECTOR2(400- m_menuexit->GetSpriteWidth()/2,620));
}
CMuneState::~CMuneState()
{
}