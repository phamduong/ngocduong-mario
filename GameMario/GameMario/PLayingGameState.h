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

	CQNode *m_nodeRoot;
	CTreeObject *m_Tobject;

	vector<int> m_ListIdObjectInViewport;
	vector<CGameObject*> m_ListObjectInViewport;
	CMap *m_map;
	CText *m_text;
	RECT m_textpostion;
	//

	float m_timePlayCount;// dung de giam m_timePlay
	float m_timeCount;//thoi gian chuyen ve khi mario chet
	LPD3DXSPRITE m_reset;//reset vi khi vao game playing no bi quay

public:
	static vector<CGameObject*> object;
	static CMario * m_mario; 
	static int m_life;//so  mang
	static int m_coin;//so tien
	static int m_mapWorld;// man  choi
	static int m_timePLay ;//thoi gian choi
	static int Score;
	static int status;
	static float m_posmarioX;
	static float m_posmarioY;
	//

	CPLayingGameState();
	~CPLayingGameState();
	CPLayingGameState(CGameStateManager* _game);
	CPLayingGameState(CGameStateManager* _game,CMario* mario,int _live,int _score,int _coin,int _time ,int _mapworld);
	CPLayingGameState(CGameStateManager* _game,int status,D3DXVECTOR2 pos,int _live,int _score,int _coin,int _time ,int _mapworld);
	void Init();
	void CleanUp();
	void Update(CInput* ,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void DrawTextGame();
	//GameStateId GetGameStateId();
};
#endif