#ifndef WINSTATE_H_
#define WINSTATE_H_
#include"GameState.h"
class CWinState:public CGameState
{
private:
	CText *m_text;
	RECT m_textpostion;
public:
	CWinState();
	~CWinState();
	CWinState(CGameStateManager* _game);
	void Init();
	void CleanUp();
	void Update(CInput* ,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void DrawText();
};
#endif