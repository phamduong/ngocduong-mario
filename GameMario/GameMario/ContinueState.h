#ifndef CONTINUE_H_
#define CONTINUE_H_
#include"GameState.h"
class CContinueState:public CGameState
{
private:
	int m_life,m_status,m_worldmap,m_coin,m_score,m_timeplay;
	D3DXVECTOR2 m_posmario;
public:
	CContinueState();
	~CContinueState();
	CContinueState(CGameStateManager* _game);
	void Init();
	void CleanUp();
	void Pause();
	void Resume();
	void Update(CInput* ,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	
};
#endif