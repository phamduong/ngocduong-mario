#ifndef BRICK_H_
#define BRICK_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"


class CBrick:public CGameObject
{
private:
	CSprite *m_spriteBrick;
	 
public:
	CBrick();
	CBrick(int,D3DXVECTOR2);
	~CBrick();
	void Init();
	void Update(CInput*,float,CCamera*);//update vi tri cua object va sprite tuong ung
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};

#endif

