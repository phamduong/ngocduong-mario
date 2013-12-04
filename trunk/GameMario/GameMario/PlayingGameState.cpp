#include"PLayingGameState.h"
#include"GamestateManager.h"
#include"MenuState.h"
CPLayingGameState::CPLayingGameState()
{
	Init();
}
void CPLayingGameState::Init()
{
	CGameState::Init();
	m_mario = new CMario();
	m_Tobject = new CTreeObject();
	m_map = new CMap();
	object = m_map->GetObjectFromFile("Resource//map//Map6.txt");
	m_nodeRoot = m_Tobject->LoadTree("Resource//map//Map6Tree.txt"); 
	m_mario->g_widthMap = m_map->m_widthmap;
	m_mario->g_heightMap = m_map->m_heightmap;
	m_text = new CText(m_game->m_graphic->Get_pd3device());
	//
	m_life = 3;
	m_coin =0;
	m_mapWorld = 1;
	m_timePLay = 360;
	Score = 0;
	m_timePlayCount = 0;
}
void CPLayingGameState::CleanUp()
{
	CPLayingGameState::CleanUp();
}
void CPLayingGameState::Resume()
{
	CGameState::Resume();
}
void CPLayingGameState::Pause()
{
	CGameState::Pause();
}
void CPLayingGameState::Update(CInput* _input,float _time,CCamera* _camera)
{
	m_ListObjectInViewport.clear();
	m_ListIdObjectInViewport = m_Tobject->GetIDObjectInViewPort(m_nodeRoot,_camera->GetBoundCamera());
	for (int i = 0; i < object.size(); i++)
	{
		for (int j = 0; j < m_ListIdObjectInViewport.size(); j++)
		{
			if(object[i]->GetId() == m_ListIdObjectInViewport[j])
			{
				m_ListObjectInViewport.push_back(object[i]);
			}

		}
	}
	m_Tobject->Update(m_ListObjectInViewport,_input,_camera,_time);
	m_mario->Update(_input,_time,_camera,m_ListObjectInViewport);
	//Giam Thoi gian choi
	m_timePlayCount+=_time;
	if (m_timePlayCount >=10.0f)
	{
		m_timePlayCount =0;
		m_timePLay--;
	}
	// cong coin
	if (m_mario->CountCoin!=0)
	{
		m_coin+=m_mario->CountCoin;
		Score+=m_mario->Score;
		m_mario->CountCoin = 0;
		m_mario->Score = 0;
	}
	if (m_mario->Score!=0)
	{
		Score+=m_mario->Score;
		m_mario->Score = 0;
	}
	// AN MANG
	if (m_mario->EatLife)
	{
		m_mario->EatLife = false;
		m_life++;
	}
	CGameState::Update(_input,_time,_camera);
}
void CPLayingGameState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_Tobject->Draw(m_ListObjectInViewport,_spriteHandle,_camera);
	m_mario->Draw(_spriteHandle,_camera);
	DrawTextGame();
}
void CPLayingGameState::DrawTextGame()
{
	char _text[10];
	SetRect(&m_textpostion,0,10,190,100);
	m_text->Draw("MARIO x ",m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	itoa(m_life,_text,10);
	SetRect(&m_textpostion,140,10,180,100);
	m_text->Draw(_text,m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	itoa(Score,_text,10);
	SetRect(&m_textpostion,10,35,190,100);
	m_text->Draw(_text,m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	//
	SetRect(&m_textpostion,200,10,400,100);
	m_text->Draw("COIN",m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	itoa(m_coin,_text,10);
	SetRect(&m_textpostion,200,35,400,100);
	m_text->Draw(_text,m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	//
	SetRect(&m_textpostion,400,10,600,100);
	m_text->Draw("WORLD",m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	itoa(m_mapWorld,_text,10);
	SetRect(&m_textpostion,400,35,600,100);
	m_text->Draw(_text,m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));

	SetRect(&m_textpostion,600,10,800,100);
	m_text->Draw("TIME",m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	itoa(m_timePLay,_text,10);
	SetRect(&m_textpostion,600,35,800,100);
	m_text->Draw(_text,m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
}
CPLayingGameState::~CPLayingGameState()
{
}