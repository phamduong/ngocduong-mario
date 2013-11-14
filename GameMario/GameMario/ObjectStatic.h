#ifndef OBJECTSTATIC_H_
#define OBJECTSTATIC_H_

#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
// 10/10/2013
enum ObjectName
{
	NAMEBIGTREE,
	NAMESMALLTREE,
	NAMEMOUNTAIN,
	NAMECLOUD,
	NAMEGRASS,
	NAMEHOUSE,
	NAMEFENCE
};

class CObjectStatic:public CGameObject
{
private:
	CSprite *m_bigtree;// id =1
	CSprite *m_smalltree;//id =2
	CSprite *m_mountain;//id =3
	CSprite *m_cloud;//id =4
	CSprite *m_grass;//id =5
	CSprite *m_fence;//6
	CSprite *m_house;//7

	ObjectName m_name;

public:
	CObjectStatic();
	CObjectStatic(int _id,D3DXVECTOR2,ObjectName);
	~CObjectStatic();
	void Init();
	void Update(CInput*,float,CCamera*);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};

#endif

