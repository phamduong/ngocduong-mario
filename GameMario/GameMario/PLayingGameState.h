#ifndef PLAYINGSTATE_H_
#define PLAYINGSTATE_H_
#include"GameState.h"
#include"Mario.h"
#include"TreeObject.h"
#include"LoadMap.h"
#include"Camera.h"
#include"Text.h"
class CPLayingGameState:public CGameState
{
private:
	CMario * m_mario;
	CQNode *m_nodeRoot;
	CTreeObject *m_Tobject;
	vector<CGameObject*> object;
	vector<int> m_ListIdObjectInViewport;
	vector<CGameObject*> m_ListObjectInViewport;
	CMap *m_map;
	CText *m_text;
	RECT m_textpostion;
	//
	int m_life;//so  mang
	int m_coin;//so tien
	int m_mapWorld;// man  choi
	int m_timePLay ;//thoi gian choi
	int Score;
	float m_timePlayCount;// dung de giam m_timePlay
public:
	CPLayingGameState();
	~CPLayingGameState();
	CPLayingGameState::CPLayingGameState(CGameStateManager* _game):CGameState(_game)
	{
		this->m_game = _game;
	}
	void Init();
	void CleanUp();
	void Pause();
	void Resume();
	void Update(CInput* ,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void DrawTextGame();
	//GameStateId GetGameStateId();
};
#endif