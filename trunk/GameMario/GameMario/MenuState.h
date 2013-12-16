#ifndef MENUSTATE_H_
#define MENUSTATE_H_
#include"GameState.h"
#include"PLayingGameState.h"
class CMuneState:public CGameState
{
private:
	int Select ;
	CSprite *m_menunewgame;
	CSprite *m_menuabout;
	CSprite *m_menuexit;
	CSprite *m_menuoption;
	CSprite *m_menucontinue;
	D3DXVECTOR2 m_posSelect;// vi tri ve  select 

public:
	CMuneState();
	~CMuneState();
	CMuneState(CGameStateManager* _game);
	void Init();
	void CleanUp();
	void Update(CInput* ,float,CCamera* _camera);
	void Draw(LPD3DXSPRITE,CCamera* _camera);
	GameStateId GetGameStateId();
};
#endif