#ifndef BRICKEXPLOSIONS_H_
#define BRICKEXPLOSIONS_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
#include"BrickBreak.h"
#include<vector>

using std::vector;
class CBrickExplosions:public CGameObject
{
private:
	CSprite *m_spriteBrick;
	vector<CBrickBreak*> m_brickBreak;
public:
	CBrickExplosions();
	CBrickExplosions(int,D3DXVECTOR2);
	~CBrickExplosions();
	void Init();
	void Update(CInput*,float,CCamera*);//update vi tri cua object va sprite tuong ung
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};

#endif

