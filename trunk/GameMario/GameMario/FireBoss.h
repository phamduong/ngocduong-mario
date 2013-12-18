#ifndef FIREBOSS_H_
#define FIREBOSS_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"


class CFireBoss:public CGameObject
{
private:
	CSprite *m_fireboss;

public:
	CFireBoss();
	CFireBoss(int,D3DXVECTOR2);
	~CFireBoss();
	void Init();
	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
	void UpdateCollison(CGameObject* _orther, CInput* _input , float _time);
};

#endif

