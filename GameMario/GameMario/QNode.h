#ifndef QNODE_H_
#define QNODE_H_
#include <fstream>
#include <string>
#include <vector>

#include<Windows.h>
#include<vector>
#include"Object.h"
#include<algorithm>
using std::vector;
using namespace std;
class CQNode
{
public:
	int m_IdNode;
	RECT m_boundNode;
	vector<int>m_ListIdGameObject;
	vector<CGameObject*> m_ListGameObject;
	CQNode *NodeLeftTop, *NodeLeftBottom, *NodeRightTop, *NodeRightBottom;
	CQNode();
	CQNode(int,RECT,vector<CGameObject*>);
	~CQNode();
	//set
};
#endif