#ifndef AABBCOLLISIONDETECTED_H_
#define AABBCOLLISIONDETECTED_H_
#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include<stdlib.h>
class CGameObject;
enum DirectCollision
{
	NONE,
	LEFT,
	TOP,
	RIGHT,
	BOTTOM
};
class CAABBCollision
{
private:
	DirectCollision m_directCollision;
public:
	CAABBCollision();
	~CAABBCollision();
	bool CheckCollision(RECT ,RECT);
	float CheckAABBCollision(CGameObject*,CGameObject*,float);
	DirectCollision GetDirectCollision(){return m_directCollision;}
	void SetDirectCollsion(DirectCollision Direct){m_directCollision = Direct; }
	static bool SortObject(CGameObject* a,CGameObject* b);
	float intersectX(CGameObject* ,CGameObject*,float);
	RECT CLip(CGameObject*,CGameObject*);



};

#endif


