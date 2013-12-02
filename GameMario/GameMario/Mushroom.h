#ifndef MUSHROOM_H_
#define MUSHROOM_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
#include"AABBCollisionDetected.h"
enum MushroomStatus
{
	MushRoomLife,
	MushRoomEatMario,
	MushroomEatBulet
};
class CMushroom:public CGameObject
{
private:
	CSprite *m_spriteMushroom;
	CAABBCollision * m_collision;
	MushroomStatus m_status;
public:
	CMushroom();
	CMushroom(int _id,D3DXVECTOR2);
	~CMushroom();
	void Init();
	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
	void UpdateCollison(CGameObject* , CInput* , float);
	void ChangeStatus();
};

#endif

