#ifndef OPTION_H_
#define OPTION_H_
#include"GameState.h"
class COptionState:public CGameState
{
private:
	CSprite *m_onoffSound;
public:
	COptionState();
	~COptionState();
	COptionState(CGameStateManager* _game);
	void Init();
	void CleanUp();
	void Update(CInput* ,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
};
#endif