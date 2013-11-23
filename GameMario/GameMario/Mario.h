#ifndef MARIO_H_
#define MARIO_H_
#define VELOCNORMAL  30.0f
#define GROUNDY  95

#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
#include"LoadMap.h"
#include"Bullet.h"
#define TIMEAMINATION  1.6f
enum ActionMario
{
	normal,
	Jump,
	run,
	down
};
enum StatusMario
{
	mariosmall,
	mariobig,
	mariogun
};
class CMario :public CGameObject{
private:
	CSprite *m_spriteBig;
	CSprite *m_sriteSmall;
	CSprite *m_spriteGun;
	int m_direct;
	ActionMario m_action;
	StatusMario m_status;
	StatusMario m_start_status;
	//
	vector<CBullet*> m_bullet;
	// bo sung ngay 17/11/2013
	int life;// so mang song small = 1, big and gun =2; die = 0
	public:
	int g_widthMap,g_heightMap;
	CMario();
	~CMario();
	 void Init();
	 void Update(CInput*,float,CCamera*);
	 void Draw(LPD3DXSPRITE,CCamera*);
	 void UpdateAnimation(CInput*,float);
	 bool CanCollision() {return true;}
	 void UpdateCollison(CGameObject* , CInput* , float);

};

#endif

