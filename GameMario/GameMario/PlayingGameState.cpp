#include"PLayingGameState.h"
#include"GamestateManager.h"
#include"MenuState.h"
#include"AboutState.h"
#include"ContinueState.h"
#include"WinState.h"
#include"GameOver.h"
// cac bien static su dung de truyen qua trag thai continue
int CPLayingGameState::m_life = 0;
int CPLayingGameState::m_coin = 0;
int CPLayingGameState::Score = 0;
int CPLayingGameState::m_timePLay = 0;
int CPLayingGameState::m_mapWorld = 0;
int CPLayingGameState::status = 0;
float CPLayingGameState::m_posmarioX = 0;
float  CPLayingGameState::m_posmarioY = 0;
vector<CGameObject*> CPLayingGameState::object;
CMario* CPLayingGameState::m_mario;
CPLayingGameState::CPLayingGameState()
{
	/*Init();*/
}
CPLayingGameState::CPLayingGameState(CGameStateManager* _game)
{
	m_mario = new CMario();
	this->m_game = _game;
	m_life = 3;
	m_coin =0;
	m_mapWorld = 3;
	m_timePLay = 360;
	Score = 0;
	Init();


}
CPLayingGameState::CPLayingGameState(CGameStateManager* _game,int _status,D3DXVECTOR2 _pos,int _live,int _score,int _coin,int _time ,int _mapwold)
{	

	this->m_game = _game;
	m_mario = new CMario(_status,_pos);
	CPLayingGameState::m_life = _live;
	Score = _score;
	m_coin =_coin;
	m_timePLay = _time;
	m_mapWorld =_mapwold;
	Init();
}
CPLayingGameState::CPLayingGameState(CGameStateManager* _game,CMario * mario,int _live,int _score,int _coin,int _time ,int _mapwold)
{	
	this->m_game = _game;
	m_mario = mario;
	CPLayingGameState::m_life = _live;
	Score = _score;
	m_coin =_coin;
	m_timePLay = _time;
	m_mapWorld =_mapwold;
	Init();
}
void CPLayingGameState::Init()
{
	CGameState::Init();
	m_Tobject = new CTreeObject();
	m_map = new CMap();
	m_text = new CText(m_game->m_graphic->Get_pd3device());
	m_timePlayCount = 0;
	m_sound = CResourceManager::GetAudio();
	if (m_mapWorld > 2)
	{
		m_mapWorld = 1;
	}
	if (!CContinueState::Iscontinue)
	{
		switch(m_mapWorld)
		{
		case 1:
			{
				object = m_map->GetObjectFromFile("Resource//map//Map1.txt");
				m_mario->g_widthMap = m_map->m_widthmap;
				m_mario->g_heightMap = m_map->m_heightmap;
				break;
			}
		case 2:
			{
				object = m_map->GetObjectFromFile("Resource//map//Map2.txt");
				m_mario->g_widthMap = m_map->m_widthmap;
				m_mario->g_heightMap = m_map->m_heightmap;
				break;
			}
		case 3:
			{
				object = m_map->GetObjectFromFile("Resource//map//Map3.txt");
				m_mario->g_widthMap = m_map->m_widthmap;
				m_mario->g_heightMap = m_map->m_heightmap;
				break;
			}
		}

		CContinueState::Iscontinue = false;
	}
	switch(m_mapWorld)
	{
	case 1:
		{
			m_nodeRoot = m_Tobject->CreateTreeObject(m_Tobject->LoadTree("Resource//map//Map1Tree.txt"),object); 
			m_sound->LoopSound(CResourceManager::GetInstance()->GetSound(SOUND_MAP1_ID));
			break;
		}
	case 2:
		{
			m_nodeRoot = m_Tobject->CreateTreeObject(m_Tobject->LoadTree("Resource//map//Map2Tree.txt"),object); 
			m_sound->LoopSound(CResourceManager::GetInstance()->GetSound(SOUND_MAP2_ID));
			break;
		}
	case 3:
		{
			m_nodeRoot = m_Tobject->CreateTreeObject(m_Tobject->LoadTree("Resource//map//Map2Tree.txt"),object); 
			break;
		}
	}
	m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_DEATH_ID));
}
void CPLayingGameState::CleanUp()
{
	D3DXMATRIX reset;
	D3DXMatrixIdentity(&reset);
	m_reset->SetTransform(&reset);
	CGameState::CleanUp();
}
void CPLayingGameState::Update(CInput* _input,float _time,CCamera* _camera)
{	
	m_ListObjectInViewport.clear();
	m_ListObjectInViewport = m_Tobject->GetObjectInViewPort(m_nodeRoot,_camera->GetBoundCamera());
	m_mario->Update(_input,_time,_camera,m_ListObjectInViewport);
	m_Tobject->Update(m_ListObjectInViewport,_input,_camera,_time);



	//Giam Thoi gian choi
	if (m_timePLay>0)
	{
		m_timePlayCount+=_time;
		if (m_timePlayCount >=10.0f)
		{
			m_timePlayCount =0;
			m_timePLay--;
		}
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
		CPLayingGameState::m_life++;
	}
	//ve menu
	if (m_mario->keydown==DIK_ESCAPE)
	{
		// nho tat nhac nen game di da nhe'
		m_game->ChangeState( new CMuneState(this->m_game));
	}
	status = m_mario->life;
	m_posmarioX = m_mario->GetPosition().x;
	m_posmarioY = m_mario->GetPosition().y;
	if(m_mario->GetPosition().y < 0)
	{
		m_mario->m_Islife = true;
		// bi rot hố
		if (m_mario->life!=0)
		{
			if(!CAudio::m_isSoundOff)
				m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_DEATH_ID));
			if(m_mario->GetPosition().y < -3000)
			{
				m_life--;
				m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_DEATH_ID));
				CContinueState::Iscontinue = false;
				m_game->ChangeState( new CPLayingGameState(this->m_game,1,D3DXVECTOR2(100,600),m_life,Score,m_coin,360,m_mapWorld));
			}
		}
		//thoi gian nhac SOUND_DEATH_ID keu la posy tu 0 - -1600 
		else
		{
			if(!CAudio::m_isSoundOff)
				m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_DEATH_ID));
			if(m_mario->GetPosition().y < -2000)
			{
				m_life--;
				m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_DEATH_ID));
				CContinueState::Iscontinue = false;
				m_game->ChangeState( new CPLayingGameState(this->m_game,1,D3DXVECTOR2(100,600),m_life,Score,m_coin,360,m_mapWorld));
			}
		}

	}
	//chay qua  g_widthMap - 150 chien thag
	if (m_mario->WinState)
	{
		CGameState::StopSoundBackGound();
		if(!CAudio::m_isSoundOff)
			m_sound->PlaySoundA(CResourceManager::GetInstance()->GetSound(SOUND_WIN_ID));
	}
	if (m_mario->WinState && m_mario->GetPosition().x > CMario::g_widthMap - 150)
	{
		m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_WIN_ID));
		if(!CAudio::m_isSoundOff)
			m_sound->LoopSound(CResourceManager::GetInstance()->GetSound(SOUND_STAGECLEAR_ID));
		if (m_timePLay>0)
		{
			m_timePlayCount+=_time;
			if (m_timePlayCount >=0.30f)
			{
				m_timePlayCount =0;
				m_timePLay--;
				Score+=10;
			}
		}
		else
		{
			m_mario->WinState = false;
			m_sound->StopSound(CResourceManager::GetInstance()->GetSound(SOUND_STAGECLEAR_ID));
			m_game->ChangeState( new CWinState(this->m_game));
		}
	}

	CGameState::Update(_input,_time,_camera);

}
void CPLayingGameState::Draw(LPD3DXSPRITE _spriteHandle,CCamera* _camera)
{
	m_reset = _spriteHandle;
	m_Tobject->Draw(m_ListObjectInViewport,_spriteHandle,_camera);
	m_mario->Draw(_spriteHandle,_camera);
	DrawTextGame();
	//Game over
	if (m_life <= 0)
	{
		m_game->ChangeState( new CGameOver(this->m_game));

	}
}
void CPLayingGameState::DrawTextGame()
{
	char _text[10];
	SetRect(&m_textpostion,0,10,190,100);
	m_text->Draw("MARIO x ",m_textpostion,DT_CENTER,D3DCOLOR_XRGB(255,255,255));
	itoa(CPLayingGameState::m_life,_text,10);
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