#ifndef FLOWER_H_
#define FLOWER_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"


class CFlower:public CGameObject
{
private:
	CSprite *m_spriteFlower;
	bool GrowUpFinish;
public:
	CFlower();
	CFlower(int _id,D3DXVECTOR2);
	~CFlower();
	void Init();
	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
	void UpdateCollison(CGameObject* , CInput* , float);
};

#endif

