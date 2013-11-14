#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_
#define MARIO_BIG "Resource//Images//PlayLon.png"
#define MARIO_SMALL "Resource//Images//PlayNho.png"
#define MARIO_GUN "Resource//Images//PlaySung.png"
#define BRICK "Resource//Images//brick.png"
#define QUESTION "Resource//Images//Question.png"
#define PIPEMEDIUM "Resource//Images//MEDIUM_PIPE.png"
#define PIPESMALL "Resource//Images//SMALL_PIPE.png"
#define PIPEBIG "Resource//Images//BIG_PIPE.png"
#define BIGTREE "Resource//Images//BIG_TREE.png"
#define SMALLTREE "Resource//Images//SMALL_TREE.png"
#define CLOUD "Resource//Images//CLOUD.png"
#define GRASS "Resource//Images//GRASS.png"
#define MOUNTAIN "Resource//Images//MOUNTAIN.png"
#define FENCE "Resource//Images//FENCE.png"
#define FLOWER "Resource//Images//FlOWER.png"
#define COIN "Resource//Images//Coin.png"
#define HOUSE "Resource//Images//house.png"
#define MUSHROOM "Resource//Images//Mushroom.png"
#define TURTLE "Resource//Images//Turtle.png"
#define TURTLESHIELD "Resource//Images//TurtleShield.png"
#define BULLET "Resource//Images//Bullet.png"
#define ITEM "Resource//Images//item.png"
#define BRICKBREAK "Resource//Images//BrickBreak.png"



#include<d3d9.h>
#include<d3dx9.h>
#include"Sprite.h"
#include"Texture.h"

enum ResourceId {
	MARIOSMALL_ID,
	MARIOBIG_ID,
	MARIOGUN_ID,
	BRICK_ID,
	QUESTION_ID,
	PIPEMEDIUM_ID,
	PIPESMALL_ID,
	PIPEBIG_ID,
	BIGTREE_ID,
	SMALLTREE_ID,
	CLOUD_ID,
	MOUNTAIN_ID,
	GRASS_ID,
	FENCE_ID,
	FLOWER_ID,
	COIN_ID,
	HOUSE_ID,
	MUSHROOM_ID,
	TURTLE_ID,
	TURTLESHIELD_ID,
	BULLET_ID,
	ITEM_ID,
	BRICKBREAK_ID
	
};

class CResourceManager{
public:
	CSprite *m_marioBig;
	CSprite *m_marioSmall;
	CSprite *m_marioGun;
	CSprite *m_brick;
	CSprite *m_question;
	CSprite *m_pipemedium;
	CSprite *m_pipesmall;
	CSprite *m_pipebig;
	CSprite *m_bigtree;
	CSprite *m_smalltree;
	CSprite *m_clound;
	CSprite *m_mountain;
	CSprite *m_grass;
	CSprite *m_fence;
	CSprite *m_flower;
	CSprite *m_coin;
	CSprite *m_house;
	CSprite *m_mushroom;
	CSprite *m_turtle;
	CSprite *m_turtleshield;
	CSprite *m_bullet;
	CSprite *m_item;
	CSprite *m_brickbreak;;
	
	CTexture *m_texture;
	static CResourceManager *m_resource;
	static LPDIRECT3DDEVICE9 m_pd3device;
	static HWND  m_wndHandle;
public:
	CResourceManager(void);
	~CResourceManager(void);

	bool Init(LPDIRECT3DDEVICE9 ,HWND);


	CSprite* GetResouce(ResourceId);
	//static
	static CResourceManager* GetInstance();
};
#endif