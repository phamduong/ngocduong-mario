#ifndef BRICKBREAK_H_
#define BRICKBREAK_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
#define TIMESHOWBRICKBREAK 15.0f

class CBrickBreak:public CGameObject
{
private:
	CSprite *m_spriteBrickBreak;
	 
public:
	CBrickBreak();
	CBrickBreak(D3DXVECTOR2,D3DXVECTOR2,D3DXVECTOR2);
	~CBrickBreak();
	void Init();
	void Update(CInput*,float,CCamera*);//update vi tri cua object va sprite tuong ung
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};

#endif

