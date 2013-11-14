#ifndef MUSHROOM_H_
#define MUSHROOM_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"


class CMushroom:public CGameObject
{
private:
	CSprite *m_spriteMushroom;
	int m_direct;
public:
	CMushroom();
	CMushroom(int _id,D3DXVECTOR2);
	~CMushroom();
	void Init();
	void Update(CInput*,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};

#endif

