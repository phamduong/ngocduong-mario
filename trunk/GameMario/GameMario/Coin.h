#ifndef COIN_H_
#define COIN_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"


class CCoin:public CGameObject
{
private:
	CSprite *m_spriteCoin;

public:
	CCoin();
	CCoin(int _id,D3DXVECTOR2);
	~CCoin();
	void Init();
	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};

#endif

