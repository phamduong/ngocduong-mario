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
	CQNode *  LoadTree(char *);
	CQNode *m_NodeRoot;
	void CreateTree(CQNode*,map<int,CQNode*>);
	vector<CQNode*> GetListNodeIntersectViewport(CQNode*,RECT Viewport);
	vector<int> GetIDObjectInViewPort(CQNode*,RECT);
	bool CheckCollision(RECT ,RECT);
	void ClearListNodeInViewport(){
		ListNodeInViewport.clear();
	}
	vector<int> xoatrung(vector<int> list);
};

#endif