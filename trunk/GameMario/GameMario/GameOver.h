#ifndef GAMEOVER_H_
#define GAMEOVER_H_
#include"GameState.h"
class CGameOver:public CGameState
{
private:

public:
	CGameOver();
	~CGameOver();
	CGameOver(CGameStateManager* _game);
	void Init();
	void CleanUp();
	void Update(CInput* ,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
};
#endif