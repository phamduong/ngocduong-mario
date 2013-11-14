#ifndef BULLET_H_
#define BULLET_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
#define BULLETSHOWTIME  5.0f
enum BulletStatus {BULLET_NONE,BULLET_SHOT,BULLET_EXPLOSION};
class CBullet:public CGameObject
{
private:
	CSprite *m_spriteBullet;
	int m_direct;
	BulletStatus m_BulletStatus;
	BulletStatus m_nextBulletStatus;
public:
	CBullet();
	CBullet(D3DXVECTOR2,int);
	~CBullet();
	void Init();
	void Update(CInput*,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
	void ChangeStatus();
	void Shotting();
	void Explosion();
};

#endif

