#ifndef BOSS_H_
#define BOSS_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
#include"FireBoss.h"

class CBoss:public CGameObject
{
private:
	CSprite *m_boss;
	vector<CFireBoss*> m_fire;
public:
	static int Hit;
	bool BossJump;
	float TimeFire;//sau thoi gian nay ban ra lua
	CBoss();
	CBoss(int _id,D3DXVECTOR2);
	~CBoss();
	void Init();
	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
	void UpdateCollison(CGameObject* _orther, CInput* _input , float _time);
};
#endif

