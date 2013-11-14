#ifndef GAMEAPP_H_
#define GAMEAPP_H_

#include"CWindown.h"
#include"Time.h"
#include<d3d9.h>
#include"DxGraPhic.h"
#include"Mario.h"
#include"Brick.h"
#include"Input.h"
#include"Question.h"
#include"LoadMap.h"
#include"QNode.h"
#include"TreeObject.h"

class CGameApp
{
private :
	CWindown * m_windown;
	CGraphic *m_graphic;
	CMario *m_mario;
	CInput *m_input;
	CTimer *m_time;
	CCamera *m_camera;
	//

	CMap *m_map;

	vector<CGameObject*> object;
	//quad  tree
	CQNode *m_nodeRoot;
	CTreeObject *m_Tobject;
	vector<int> m_ListIdObjectInViewport;
public:
	LPD3DXSPRITE m_spriteHandler;
	CGameApp();
	~CGameApp();

	int GameInit(HINSTANCE);
	int GameRun();
	int GameEnd();

	void UpdateWorld(float);
	void DrawWorld();

};

#endif