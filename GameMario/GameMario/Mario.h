#ifndef MARIO_H_
#define MARIO_H_
#define VELOCNORMAL  30.0f
#define GROUNDY  95

#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
#include"LoadMap.h"
#include"Bullet.h"
#include"AABBCollisionDetected.h"
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
	DirectCollision  m_directCollion;//xem dang va cham theo huong nao
	D3DXVECTOR2 m_MaxVeloc;//luu tru maxveloc ban dau,khi va cham cho maxvecloc ve 0
	//

	vector<CBullet*> m_bullet;
	// bo sung ngay 17/11/2013
	int life;// so mang song small = 1, big and gun =2; die = 0
	//22/11/2013
	CAABBCollision* m_collision;
	D3DXVECTOR2 m_lastPos;
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

