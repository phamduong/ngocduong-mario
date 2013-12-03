#ifndef STAR_H_
#define STAR_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"


class CStar:public CGameObject
{
private:
	CSprite *m_spriteStar;
	bool GrowUpFinish;
public:
	CStar();
	CStar(int _id,D3DXVECTOR2);
	~CStar();
	void Init();
	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
	void UpdateCollison(CGameObject* , CInput* , float);
};

#endif

