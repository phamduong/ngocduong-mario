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
	vector<CGameObject*> object;
	vector<int> m_ListIdObjectInViewport;
	vector<CGameObject*> m_ListObjectInViewport;
	CMap *m_map;
	CText *m_text;
	RECT m_textpostion;
	//

	float m_timePlayCount;// dung de giam m_timePlay
	LPD3DXSPRITE m_reset;//reset vi khi vao game playing no bi quay
	CMario * m_mario; 
public:
	
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
	CPLayingGameState(CGameStateManager* _game,int _status,D3DXVECTOR2 _pos,int _live,int _score,int _coin,int _time ,int _mapworld);
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