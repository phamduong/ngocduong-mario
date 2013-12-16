#ifndef GAMESTATE_H_
#define GAMESTATE_H_
#include <d3d9.h>
#include <d3dx9.h>
#include "Input.h"
#include "Camera.h"
#include "Sprite.h"
#include"ResourceManager.h"
enum GameStateId
{
	GAME_LOADING,GAME_MENU,GAME_PLAY,GAME_CONTINUE,GAME_OPTIONS,GAME_EXIT,GAME_ABOUT
};

class CGameStateManager;
class CGameState
{
protected:
	GameStateId m_id;
	CGameStateManager* m_game;
	CSprite* m_background;
	float m_time;
	CAudio* m_sound;
public:
	CGameState(void);
	~CGameState(void);
	CGameState(CGameStateManager*);
	virtual void Init();
	virtual void CleanUp();
	virtual void Update(CInput* ,float,CCamera*);
	virtual void Draw(LPD3DXSPRITE,CCamera*);
	void StopSoundBackGound();
};
#endif
