#ifndef LOADINGSTATE_H_
#define LOADINGSTATE_H_
#include"GameState.h"
#include"Texture.h"

#define LOADING1 "Resource//Images//Loading.png"
class CLoadingState:public CGameState
{
private:
	CTexture *m_texture ;

public:
	CSprite *m_Loading;
	CLoadingState();
	~CLoadingState();
	CLoadingState(CGameStateManager* _game);	
	void Init();
	void CleanUp();
	void Update(CInput* ,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
};
#endif