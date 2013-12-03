#ifndef MUSHROOMLIFE_H_
#define MUSHROOMLIFE_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"


class CMushroomLife:public CGameObject
{
private:
	CSprite *m_spriteLife;
	bool GrowUpFinish;
public:
	CMushroomLife();
	CMushroomLife(int _id,D3DXVECTOR2);
	~CMushroomLife();
	void Init();
	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
	void UpdateCollison(CGameObject* , CInput* , float);
};

#endif

