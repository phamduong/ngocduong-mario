#include"TreeObject.h"


CTreeObject:: CTreeObject()
{
}

CTreeObject::~ CTreeObject()
{
}
vector<string> CTreeObject::SplitString(std::string str, char ch)
{
	vector<string> result;
	int n = str.size();
	string line = "";
	for(int i = 0; i < n; i++){
		while((i<n)&&(str.at(i)!=ch))
		{
			line.push_back(str.at(i));
			i++;
		}
		result.push_back(line);
		line.clear();		
	}
	return result;
}
map<int,CQNode*> CTreeObject::LoadTreeInSTLMap(char* filePath){
	map<int,CQNode*> m_map ;
	ifstream f(filePath);
	vector<string> itemsInfo;

	if(f.is_open()){
		string line;
		while(1){
			CQNode* Node= new CQNode();
			getline(f,line);
			itemsInfo = SplitString(line,' ');
			if(strcmp(line.c_str(), "<End>") == 0)
				break;
			Node->m_IdNode = atoi(itemsInfo.at(0).c_str());
			Node->m_boundNode.left =(LONG)atoi(itemsInfo.at(1).c_str());
			Node->m_boundNode.top =(LONG)atoi(itemsInfo.at(2).c_str());
			Node->m_boundNode.right = (LONG)atoi(itemsInfo.at(3).c_str());
			Node->m_boundNode.bottom =(LONG)atoi(itemsInfo.at(4).c_str());
			if (itemsInfo.size() >5)
			{
				for (int i = 5; i < itemsInfo.size(); i++)
				{
					Node->m_ListIdGameObject.push_back(atoi(itemsInfo.at(i).c_str()));
				}
			}
			if(Node->m_IdNode!=0)
			{
				m_map[Node->m_IdNode] = Node;
			}
			else
			{
				m_NodeRoot = Node;
			}
		}
	}	
	return m_map;
}

CQNode* CTreeObject::LoadTree(char * filepath)
{
	map<int,CQNode*> m_map ;
	m_map = LoadTreeInSTLMap(filepath);
	CreateTree(m_NodeRoot,m_map);
	return m_NodeRoot;

}
void CTreeObject::CreateTree(CQNode *_NodeParent,map<int,CQNode*> _map){
	//map<int,CQNode*>::
	if(_map.find(_NodeParent->m_IdNode * 8 + 1) != _map.end())
	{
		_NodeParent->NodeLeftTop = _map.find(_NodeParent->m_IdNode * 8  + 1)->second;
		CreateTree(_NodeParent->NodeLeftTop,_map);
	}
	if(_map.find(_NodeParent->m_IdNode * 8  + 2) != _map.end())
	{
		_NodeParent->NodeRightTop = _map.find(_NodeParent->m_IdNode * 8  + 2)->second;
		CreateTree(_NodeParent->NodeRightTop,_map);
	}
	if(_map.find(_NodeParent->m_IdNode * 8  + 3) != _map.end())
	{
		_NodeParent->NodeLeftBottom = _map.find(_NodeParent->m_IdNode * 8  + 3)->second;
		CreateTree(_NodeParent->NodeLeftBottom,_map);
	}
	if(_map.find(_NodeParent->m_IdNode * 8  + 4) != _map.end())
	{
		_NodeParent->NodeRightBottom = _map.find(_NodeParent->m_IdNode * 8  + 4)->second;
		CreateTree(_NodeParent->NodeRightBottom,_map);
	}
}
///////////////////////////////////////////////////////////////////
bool CTreeObject::CheckCollision(RECT orther ,RECT Node){
	if (orther.right <= Node.left)
		return false;
	else if (orther.left >= Node.right)
		return false;
	else if (orther.top <= Node.bottom)
		return false;
	else if (orther.bottom >= Node.top)
		return false;
	return true;
}
vector<CQNode*> CTreeObject::GetListNodeIntersectViewport(CQNode* Noderoot,RECT viewport){

	if(CheckCollision(viewport,Noderoot->m_boundNode) && Noderoot->m_ListIdGameObject.size()!=0)
	{
		ListNodeInViewport.push_back(Noderoot);
	}
	//co va cham la nut cha hoac nut la khong co doi tuong
	if(Noderoot->m_ListIdGameObject.size()==0 && CheckCollision(Noderoot->m_boundNode,viewport))
	{
		//la nut cha
		if(Noderoot->NodeLeftTop != NULL)
		{
			GetListNodeIntersectViewport(Noderoot->NodeLeftTop,viewport);
		}
		if(Noderoot->NodeLeftBottom != NULL)
		{
			GetListNodeIntersectViewport(Noderoot->NodeLeftBottom,viewport);
		}
		if(Noderoot->NodeRightBottom != NULL)
		{
			GetListNodeIntersectViewport(Noderoot->NodeRightBottom,viewport);
		}
		if(Noderoot->NodeRightTop != NULL)
		{
			GetListNodeIntersectViewport(Noderoot->NodeRightTop,viewport);
		}
	}

	return ListNodeInViewport;
}
vector<int> CTreeObject::GetIDObjectInViewPort(CQNode* noderoot,RECT viewport){
	vector<CQNode*> listnode;
	vector<int> ListIdGame;
	ClearListNodeInViewport();/// vi GetListNodeIntersectViewport no cong don cac node nen phai xoa di chu ko no lang game lam'
	listnode = GetListNodeIntersectViewport(noderoot,viewport);
	for (int i = 0; i < listnode.size(); i++)
	{
		if(listnode[i]->m_ListIdGameObject.size() !=0){
			for (int j = 0; j < listnode[i]->m_ListIdGameObject.size(); j++)
			{
				ListIdGame.push_back(listnode[i]->m_ListIdGameObject[j]);
			}
		}
	}
	ListIdGame = xoatrung(ListIdGame);//xoa cahoic id trung nhau di, de ve 1 lan thoi
	return ListIdGame;
}

vector<int>CTreeObject::xoatrung(vector<int> list)
{
	vector<int> Listkq;
	int size =  list.size();
	for (int i=0;i<size - 1;i++) 
		for (int j=i+1;j<size;j++) 
		{ 
			if (list[i]==list[j]) 
				list[j--]=list[--size];   
		}

		for (int i = 0; i < size; i++)
		{
			Listkq.push_back(list[i]);
		}
		return Listkq;
}