#ifndef TURTLE_H_
#define TURTLE_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
#include"AABBCollisionDetected.h"
enum statusTurtle
{
	TurtleNormal,
	TurtleShield,
	TurleEatBulet
};
class CTurtle:public CGameObject
{
private:
	CSprite *m_spriteTurtle;
	CSprite *m_spriteTurtleShield;
	statusTurtle m_status;
public:
	CTurtle();
	CTurtle(int _id,D3DXVECTOR2);
	~CTurtle();
	void Init();
	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
	void UpdateCollison(CGameObject* , CInput* , float);
	void ChangeStatus();
};

#endif

