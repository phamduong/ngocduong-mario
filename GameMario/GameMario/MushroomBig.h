#ifndef MUSHROOOMBIG_H_
#define MUSHROOOMBIG_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
#include"AABBCollisionDetected.h"

class CMushroomBig:public CGameObject
{
private:
	CSprite *m_spriteLife;
	bool GrowUpFinish;
public:
	CMushroomBig();
	CMushroomBig(int _id,D3DXVECTOR2);
	~CMushroomBig();
	void Init();
	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
	void UpdateCollison(CGameObject* , CInput* , float);
};

#endif

