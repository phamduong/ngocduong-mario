#include"LoadMap.h"

CMap::CMap(){}
vector<string> CMap::SplitString(std::string str, char ch)
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
vector<CGameObject*> CMap::ObjectFromFile(char* filePath)//co the hieu la tao map o day
{
	vector<CGameObject*> object;
	ifstream f(filePath);
	vector<string> itemsInfo;
	if(f.is_open())
	{
		string line;
		D3DXVECTOR2 _pos;
		string _objecttype;
		int _idObject;
		getline(f,line);
		itemsInfo = SplitString(line,' ');
		m_widthmap = atoi(itemsInfo.at(0).c_str());
		m_heightmap = atoi(itemsInfo.at(1).c_str());

		while(1){
			getline(f,line);
			itemsInfo = SplitString(line,' ');
			if(strcmp(line.c_str(), "<End>") == 0)
				break;
			_idObject = atoi(itemsInfo.at(0).c_str());
			_objecttype=itemsInfo.at(1).c_str();
			_pos.x = atoi(itemsInfo.at(2).c_str());
			_pos.y=atoi(itemsInfo.at(3).c_str());
			if(_objecttype=="LAND"){
				CBrick *_brick = new CBrick(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y));
				object.push_back(_brick);
			}
			if(_objecttype=="BRICK"){
				CBrickExplosions *_brick = new CBrickExplosions(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y));
				object.push_back(_brick);
			}
			if(_objecttype=="QUESTION"){
				CQuestion *_question = new CQuestion(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y));
				object.push_back(_question);
			}
			if(_objecttype=="MEDIUMPIPE"){
				CPipe *_pipe = new CPipe(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),2);
				object.push_back(_pipe);
			}
			if(_objecttype=="SMALLPIPE"){
				CPipe *_pipe = new CPipe(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),1);
				object.push_back(_pipe);
			}
			if(_objecttype=="BIGPIPE"){
				CPipe *_pipe = new CPipe(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),3);
				object.push_back(_pipe);
			}
			if(_objecttype=="COIN"){
				CCoin *_coin = new CCoin(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y));
				object.push_back(_coin);
			}
			// cac item
			if(_objecttype=="MUSHROOMBIG"){
				CQuestion *_mushroomBig = new CQuestion(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),ITEM_MUSHROOMBIG);
				object.push_back(_mushroomBig);
			}
			if(_objecttype=="MUSHROOMLIFE"){
				CQuestion *_mushroomlife = new CQuestion(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),ITEM_MIUSHROOMLIFE);
				object.push_back(_mushroomlife);
			}
			if(_objecttype=="FLOWER"){
				CQuestion *_mushroomBig = new CQuestion(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),ITEM_FLOWER);
				object.push_back(_mushroomBig);
			}
			if(_objecttype=="STAR"){
				CQuestion *_mushroomBig = new CQuestion(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),ITEM_STAR);
				object.push_back(_mushroomBig);
			}
			if(_objecttype=="COINQUESTION"){
				CQuestion *_mushroomBig = new CQuestion(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),ITEM_COIN);
				object.push_back(_mushroomBig);
			}
			if(_objecttype=="TURTLE"){
				CTurtle *_turtle = new CTurtle(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y));
				object.push_back(_turtle);
			}
			if(_objecttype=="MUSHROOM"){
				CMushroom *_mushroom = new CMushroom(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y));
				object.push_back(_mushroom);
			}
			//
			if(_objecttype=="BIGTREE"){
				CObjectStatic *_objectstatic = new CObjectStatic(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),NAMEBIGTREE);
				object.push_back(_objectstatic);
			}
			if(_objecttype=="SMALLTREE"){
				CObjectStatic *_objectstatic = new CObjectStatic(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),NAMESMALLTREE);
				object.push_back(_objectstatic);
			}
			if(_objecttype=="MOUNTAIN"){
				CObjectStatic *_objectstatic = new CObjectStatic(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),NAMEMOUNTAIN);
				object.push_back(_objectstatic);
			}
			if(_objecttype=="CLOUD"){
				CObjectStatic *_objectstatic = new CObjectStatic(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),NAMECLOUD);
				object.push_back(_objectstatic);
			}
			if(_objecttype=="GRASS"){
				CObjectStatic *_objectstatic = new CObjectStatic(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),NAMEGRASS);
				object.push_back(_objectstatic);
			}
			if(_objecttype=="FENCE"){
				CObjectStatic *_objectstatic = new CObjectStatic(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),NAMEFENCE);
				object.push_back(_objectstatic);
			}
			if(_objecttype=="HOUSE"){
				CObjectStatic *_objectstatic = new CObjectStatic(_idObject,D3DXVECTOR2((float)_pos.x,(float)_pos.y),NAMEHOUSE);
				object.push_back(_objectstatic);
			}

		}
	}
	// back groud ve truoc tranh de hinh

	return object;
}
vector<CGameObject*> CMap::GetObjectFromFile(char* filePath)//co the hieu la tao map o day
{	
	//doi background ve truoc cac doi tuong game
	vector<CGameObject*> object;
	object = ObjectFromFile(filePath);
	vector<CGameObject*> listBackground;
	vector<CGameObject*> listObject;
	for (int i = 0; i < object.size(); i++)
	{
		if (object[i]->GetType()==OBJECTTYPE)
		{
			listBackground.push_back(object[i]);
		}
		else
		{		
			listObject.push_back(object[i]);
		}
	}
	object.clear();
	for (int i = 0; i < listBackground.size(); i++)
	{
		object.push_back(listBackground[i]);
	}
	for (int i = 0; i < listObject.size(); i++)
	{
		object.push_back(listObject[i]);
	}
	return object;
}

























CMap::~CMap(){}