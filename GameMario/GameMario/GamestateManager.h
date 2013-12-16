#ifndef GAMESTATEMANAGER_H_
#define GAMESTATEMANAGER_H_

#include "DxGraphic.h"
#include "Input.h"
#include "Camera.h"
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>
#include"LoadingState.h"
#include"MenuState.h"
#include"Camera.h"
using namespace std;
class CGameState;
class CGameStateManager
{
private:
	HINSTANCE m_hInstance;

	//CResourceManager *m_resource;
	LPD3DXSPRITE m_spriteHandle;
	vector<CGameState*> m_gameState;
public:
	HWND m_wndHandle;
	CInput* m_input;
	CGraphic*m_graphic;
	CGameState* m_nextState;
	CGameStateManager(void);
	~CGameStateManager(void);
	void Init(HINSTANCE, HWND,CGraphic* , CInput*); //19/12/2012
	void CleanUp();
	void InitFirstState(CGameState*);
	void ChangeState(CGameState*);
	void Update(float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
};
#endif


