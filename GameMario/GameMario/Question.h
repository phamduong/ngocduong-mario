#ifndef QUESTION_H_
#define QUESTION_H_

#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"
#include"Flower.h"
#include"Coin.h"
#include"MushroomBig.h"
#include"MushroomLife.h"
#include"Star.h"
#include"Object.h"
// ten cac item
enum ItemName{
	ITEM_FLOWER,
	ITEM_COIN,
	ITEM_MUSHROOMBIG,
	ITEM_MIUSHROOMLIFE,
	ITEM_STAR
};
enum StatusItem{
	STATUSITEM_START,// luc khoi tao nam cung vj trj question
	STATUSITEM_RUNNING,//dang moc len
	STATUSITEM_FINISH// da moc xong
};

class CQuestion:public CGameObject
{
private:
	CSprite *m_spritequestion;
	ItemName m_itemname;
	StatusItem m_statusitem;
	CGameObject * m_object;// de khoi tao cac item
public:
	CQuestion();
	CQuestion(int _id,D3DXVECTOR2);
	CQuestion(int _id,D3DXVECTOR2,ItemName);
	~CQuestion();
	void Init();
	void Update(CInput*,float,CCamera*,vector<CGameObject*>);
	void Draw(LPD3DXSPRITE,CCamera*);
	void UpdateAnimation(CInput*,float);
};

#endif

