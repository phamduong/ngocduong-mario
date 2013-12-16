#include"QNode.h"

CQNode::CQNode(){
	NodeLeftTop = NULL;
	NodeLeftBottom = NULL;
	NodeRightTop = NULL;
	NodeRightBottom = NULL;
}
CQNode::CQNode(int _idnode,RECT _bound,vector<CGameObject*> _list){
	m_IdNode = _idnode;
	m_boundNode = _bound;
	m_ListGameObject = _list;
}
CQNode::~CQNode(){
}