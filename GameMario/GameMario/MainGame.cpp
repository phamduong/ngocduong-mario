
#include "GameApp.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CGameApp *m_game;
	m_game = new CGameApp();
	if (! m_game->GameInit(hInstance))
	{
		return 0;
	}

	m_game->GameRun();
	m_game->GameEnd();
	return 1;
	///
}

