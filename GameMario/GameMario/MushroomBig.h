#ifndef MUSHROOOMBIG_H_
#define MUSHROOOMBIG_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"


class CMushroomBig:public CGameObject
{
private:
	CSprite *m_spriteLife;
	 
public:
	CMushroomBig();
	CMushroomBig(int _id,D3DXVECTOR2);
	~CMushroomBig();
	void Init();
	void Update(CInput*,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};

#endif

