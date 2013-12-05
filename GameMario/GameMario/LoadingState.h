#ifndef LOADINGSTATE_H_
#define LOADINGSTATE_H_
#include"GameState.h"
class CLoadingState:public CGameState
{
private:

public:
	CLoadingState();
	~CLoadingState();
	CLoadingState(CGameStateManager* _game);	
	void Init();
	void CleanUp();
	void Pause();
	void Resume();
	void Update(CInput* ,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	//GameStateId GetGameStateId();
};
#endif