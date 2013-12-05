#ifndef ABOUTSTATE_H_
#define ABOUTSTATE_H_
#include"GameState.h"
class CAboutState:public CGameState
{
private:

public:
	CAboutState();
	~CAboutState();
	CAboutState(CGameStateManager* _game);
	void Init();
	void CleanUp();
	void Pause();
	void Resume();
	void Update(CInput* ,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	
};
#endif