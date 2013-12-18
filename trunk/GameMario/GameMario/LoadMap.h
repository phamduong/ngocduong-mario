#ifndef MAP_H_
#define MAP_H_
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <fstream>
#include <string>
#include <vector>
//
#include"Brick.h"
#include"Question.h"
#include"Object.h"
#include"Camera.h"
#include"pipe.h"
#include"ObjectStatic.h"
#include"BrickExplosions.h"
#include"Flower.h"
#include"Coin.h"
#include"Mushroom.h"
#include"Turtle.h"
#include"Bullet.h"
#include"Star.h"
#include"MushroomLife.h"
#include"MushroomBig.h"
#include"BrickBreak.h"
#include"Boss.h"
#include"Flag.h"
using std::vector;
using namespace std;
class CMap{
public:
	int m_widthmap,m_heightmap;
public:
	CMap();
	~CMap();
	vector<string> SplitString(string str, char ch);
	vector<CGameObject*> ObjectFromFile(char* filePath);
	vector<CGameObject*> GetObjectFromFile(char* filePath);
	int GetWidthMap(){return m_widthmap;};
	int GetHeightMap(){return m_heightmap;}
};



#endif