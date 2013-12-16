#include"OptionState.h"
#include"GamestateManager.h"
#include"MenuState.h"
#include"WinState.h"
#include"PLayingGameState.h"
CWinState::CWinState()
{
	Init();
}
CWinState::CWinState(CGameStateManager* _game):CGameState(_game)
{
	this->m_game = _game;
	Init();
}
void CWinState::Init()
{
	CGameState::Init();
	m_background = CResourceManager::GetInstance()->GetResouce(WIN_ID);
	m_time = 0;
	m_text = new CText(m_game->m_graphic->Get_pd3device());
}

void CWinState::CleanUp()
{
	CGameState::CleanUp();
}
void CWinState::Update(CInput* _input,float _time,CCamera* _camera)
{
	m_background->SetCurrentSprite(0);
	m_background->UpdateSprite();
	CGameState::Update(_input,_time,_camera);
	int keydown = _input->GetKeyDown();
	m_time +=_time;
	if (m_time>=20.0f)
	{
		m_time = 0;
		m_game->ChangeState( new CPLayingGameState(this->m_game,CPLayingGameState::status,D3DXVECTOR2(100,600),CPLayingGameState::m_life,CPLayingGameState::Score,CPLayingGameState::m_coin,360,CPLayingGameState::m_mapWorld+1));

	}
}
void CWinState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_background->DrawSprite(_spriteHandle,D3DXVECTOR2(350,400));
	DrawText();
}
CWinState::~CWinState()
{
}
void CWinState::DrawText()
{
	char _text[10];
	SetRect(&m_textpostion,0,10,190,100);
	m_text->Draw("SCORE ",m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	itoa(CPLayingGameState::Score,_text,10);
	SetRect(&m_textpostion,10,35,190,100);
	m_text->Draw(_text,m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	//
	SetRect(&m_textpostion,200,10,400,100);
	m_text->Draw("COIN",m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	itoa(CPLayingGameState::m_coin,_text,10);
	SetRect(&m_textpostion,200,35,400,100);
	m_text->Draw(_text,m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	//
	SetRect(&m_textpostion,400,10,600,100);
	m_text->Draw("WORLD",m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	itoa(CPLayingGameState::m_mapWorld + 1,_text,10);
	SetRect(&m_textpostion,400,35,600,100);
	m_text->Draw(_text,m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	//
	SetRect(&m_textpostion,600,10,800,100);
	m_text->Draw("TIME",m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	//	
	SetRect(&m_textpostion,0,300,750,390);
	m_text->Draw("WORLD",m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	itoa(CPLayingGameState::m_mapWorld + 1,_text,10);
	SetRect(&m_textpostion,400,300,500,390);
	m_text->Draw(_text,m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	//
	SetRect(&m_textpostion,390,390,400,410);
	m_text->Draw("X",m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	itoa(CPLayingGameState::m_life,_text,10);
	SetRect(&m_textpostion,400,390,450,460);
	m_text->Draw(_text,m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));

}