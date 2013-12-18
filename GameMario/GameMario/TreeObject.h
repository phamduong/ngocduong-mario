#ifndef QUADTREE_H_
#define QUADTREE_H_
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include<algorithm>
#include<map>
#include"QNode.h"
#include <fstream>
#include <string>
#include <vector>
#include"Object.h"
#include"Boss.h"
#include"Flag.h"
using std::map;
class  CTreeObject
{
private:
	map<int,CQNode*> m_map ;
	vector<CQNode*> ListNodeInViewport;
public:
	CTreeObject();
	~ CTreeObject();
	vector<string> SplitString(string str, char ch);
	map<int,CQNode*> LoadTreeInSTLMap(char* filePath);
	CQNode *  LoadTree(char *);// tao cay chua cac Id game
	CQNode *  CreateTreeObject(CQNode*,vector<CGameObject*>);
	CQNode *m_NodeRoot;

	//  tao node cha( day la cai cay se su dung)
	void CreateTree(CQNode*,map<int,CQNode*>);
	// nhug node giao voi man hjnh
	vector<CQNode*> GetListNodeIntersectViewport(CQNode*,RECT Viewport);
	// lay id cua doi tuong game
	vector<CGameObject*> GetObjectInViewPort(CQNode*,RECT);
	bool CheckCollision(RECT ,RECT);
	// lam rong ListNodeInViewport truoc khi goi ham GetListNodeIntersectViewport();
	void ClearListNodeInViewport(){
		ListNodeInViewport.clear();
	}
	vector<CGameObject*> xoatrung(vector<CGameObject*> list);
	void Update(vector<CGameObject*>,CInput*, CCamera*, float);
	void Draw(vector<CGameObject*>,LPD3DXSPRITE, CCamera*);
};

#endif