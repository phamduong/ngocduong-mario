#include"TreeObject.h"
#include"Question.h"

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
CQNode * CTreeObject::CreateTreeObject(CQNode* _noderoot,vector<CGameObject*> Listobject)
{
	if (_noderoot->m_ListIdGameObject.size()!=0)
	{
		for (int i = 0; i < Listobject.size(); i++)
		{
			for (int j = 0; j < _noderoot->m_ListIdGameObject.size(); j++)
			{
				if (Listobject[i]->GetId() == _noderoot->m_ListIdGameObject[j])
				{
					_noderoot->m_ListGameObject.push_back(Listobject[i]);
				}
			}

		}
	}
	//
	if(_noderoot->NodeLeftTop != NULL)
	{
		CreateTreeObject(_noderoot->NodeLeftTop,Listobject);
	}
	if(_noderoot->NodeLeftBottom != NULL)
	{
		CreateTreeObject(_noderoot->NodeLeftBottom,Listobject);
	}
	if(_noderoot->NodeRightBottom != NULL)
	{
		CreateTreeObject(_noderoot->NodeRightBottom,Listobject);
	}
	if(_noderoot->NodeRightTop != NULL)
	{
		CreateTreeObject(_noderoot->NodeRightTop,Listobject);
	}

	return _noderoot;
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
vector<CGameObject*> CTreeObject::GetObjectInViewPort(CQNode* noderoot,RECT viewport){
	vector<CQNode*> listnode;
	vector<CGameObject*> ListGame;
	ClearListNodeInViewport();/// vi GetListNodeIntersectViewport no cong don cac node nen phai xoa di chu ko no lang game lam'
	listnode = GetListNodeIntersectViewport(noderoot,viewport);
	for (int i = 0; i < listnode.size(); i++)
	{
		if(listnode[i]->m_ListGameObject.size() !=0){
			for (int j = 0; j < listnode[i]->m_ListGameObject.size(); j++)
			{
				ListGame.push_back(listnode[i]->m_ListGameObject[j]);
			}
		}
	}
	ListGame = xoatrung(ListGame);//xoa cahoic id trung nhau di, de ve 1 lan thoi
	return ListGame;
}

vector<CGameObject*>CTreeObject::xoatrung(vector<CGameObject*> list)
{
	vector<CGameObject*> Listkq;
	int size =  list.size();
	for (int i=0;i<size - 1;i++) 
		for (int j=i+1;j<size;j++) 
		{ 
			if (list[i]->GetId()==list[j]->GetId()) 
				list[j--]=list[--size];   
		}

		for (int i = 0; i < size; i++)
		{
			Listkq.push_back(list[i]);
		}
		return Listkq;
}
void CTreeObject::Draw(vector<CGameObject*> ListObjectInViewport,LPD3DXSPRITE _spriteHandle, CCamera* _camera)
{

	for (int i = 0; i < ListObjectInViewport.size(); i++)
	{
		ListObjectInViewport[i]->Draw(_spriteHandle,_camera);
	}
}
void CTreeObject::Update(vector<CGameObject*> ListObjectInViewport,CInput* _input, CCamera* _camera, float _time)
{

	for (int i = 0; i < ListObjectInViewport.size(); i++)
	{
		if (ListObjectInViewport[i]->GetType()==OBJECTTYPE||ListObjectInViewport[i]->GetType()==HOUSETYPE||ListObjectInViewport[i]->GetType()==FLAGTYPE)
		{
			ListObjectInViewport[i]->Update(_input,_time,_camera);
		}
		else
		{
			//neu la item thi luon luon update ko kan nam torng view port
			//ko lam cai nay item se bi dung khi ko kon trong view port nua
			/*if (ListObjectInViewport[i]->GetType()==COINQUESTIONTYPE )
			{
			CQuestion * Item = (CQuestion*) ListObjectInViewport[i];
			if (Item->GetItem()==ITEM_MUSHROOMBIG ||Item->GetItem()==ITEM_MIUSHROOMLIFE||Item->GetItem()==ITEM_STAR)
			{*/
			ListObjectInViewport[i]->Update(_input,_time,_camera,ListObjectInViewport);
			//	}
			//	//coin question, hoa
			//	else
			//	{
			//		ListObjectInViewport[i]->SetBound();
			//		if (CheckCollision(ListObjectInViewport[i]->GetBound(),_camera->GetBoundCamera()))
			//		{
			//			ListObjectInViewport[i]->Update(_input,_time,_camera,ListObjectInViewport);
			//		}
			//	}

			//}
			//else
			//{

			//	ListObjectInViewport[i]->SetBound();
			//	if (CheckCollision(ListObjectInViewport[i]->GetBound(),_camera->GetBoundCamera()))
			//	{
			//		ListObjectInViewport[i]->Update(_input,_time,_camera,ListObjectInViewport);
			//	}
			//}
		}

	}
}