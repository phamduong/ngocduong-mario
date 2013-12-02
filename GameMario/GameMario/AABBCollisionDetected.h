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
	DirectCollision m_direct;
public:
	CAABBCollision();
	~CAABBCollision();
	bool CheckCollision(RECT ,RECT);
	float CheckAABBCollision(CGameObject*,CGameObject*,float);
	DirectCollision GetDirectCollision(){return m_direct;}
	bool CheckCollisionFrameNext(CGameObject*,CGameObject*,float);// da va cham roi, huong di chuyen tranh di su va cham
	bool checkCollisionObject(CGameObject*,CGameObject*);
	static bool SortObject(CGameObject* a,CGameObject* b);
	float intersectX(CGameObject* ,CGameObject*,float);
};

#endif


