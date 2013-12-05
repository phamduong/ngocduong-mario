#ifndef OPTION_H_
#define OPTION_H_
#include"GameState.h"
class COptionState:public CGameState
{
private:

public:
	COptionState();
	~COptionState();
	COptionState(CGameStateManager* _game);
	void Init();
	void CleanUp();
	void Pause();
	void Resume();
	void Update(CInput* ,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	//GameStateId GetGameStateId();
};
#endif