#include"ResourceManager.h"
CResourceManager* CResourceManager::m_resource = NULL;
LPDIRECT3DDEVICE9 CResourceManager::m_pd3device = NULL;
HWND CResourceManager::m_wndHandle = NULL;
CAudio* CResourceManager::m_audio = NULL;
CResourceManager::CResourceManager(void){
	m_marioBig = new CSprite( 10,5, 240, 184);
	m_marioSmall = new CSprite(10 ,5, 230 , 140 );
	m_marioGun = new CSprite(10,5, 240, 184);
	m_brick = new CSprite(2,2,100,50);
	m_question = new CSprite(3,3,150,50);
	m_pipesmall = new CSprite(1,1,75,100);
	m_pipemedium = new CSprite(1,1,75,150);
	m_pipebig = new CSprite(1,1,72,200);
	m_bigtree = new CSprite(1,1,30,100);
	m_smalltree = new CSprite(1,1,27,60);
	m_grass = new CSprite(2,2,128,30);
	m_mountain = new CSprite(1,1,300,100);
	m_clound = new CSprite(2,2,128,50);
	m_fence = new CSprite(1,1,141,32);
	m_flower = new CSprite(4,4,200,50);
	m_coin = new CSprite(7,7,315,50);
	m_house = new CSprite(1,1,300,400);
	m_mushroom = new CSprite(4,4,200,50);
	m_turtle = new CSprite(4,2,100,140);
	m_turtleshield = new CSprite(4,4,188,44);
	m_bullet = new CSprite(10,10,340,34);
	m_item = new CSprite(8,4,200,100);
	m_brickbreak = new CSprite(1,1,25,25);
	m_loading = new CSprite(1,1,800,800);
	m_backgroundmenu = new CSprite(1,1,800,800);
	m_menunewgame = new CSprite(2,2,428,50);
	m_menuabout = new CSprite(2,2,302,50);
	m_menuoption = new CSprite(2,2,374,50);
	m_menucontinue = new CSprite(2,2,420,50);
	m_menuexit = new CSprite(2,2,218,50);
	m_select = new CSprite(1,1,50,50);
	m_about = new CSprite(1,1,800,800);
	m_option = new CSprite(1,1,800,800);
	m_win = new CSprite(1,1,40,60);
	m_score = new CSprite(3,3,150,30);
	m_gameover = new CSprite(1,1,800,800);
}
bool CResourceManager::Init(LPDIRECT3DDEVICE9 _pd3device ,HWND _wndHandle){
	m_pd3device = _pd3device;
	m_wndHandle = _wndHandle;
	m_texture = new CTexture(m_pd3device);
	m_audio = new CAudio(m_wndHandle);
	if (m_texture == NULL)
	{
		return false;
	}
	if (m_audio == NULL)
	{
		return false;
	}
	m_marioBig->Init(m_texture->GetTexture(MARIO_BIG));
	m_marioSmall->Init(m_texture->GetTexture(MARIO_SMALL));
	m_marioGun->Init(m_texture->GetTexture(MARIO_GUN));
	m_brick->Init(m_texture->GetTexture(BRICK));
	m_question->Init(m_texture->GetTexture(QUESTION));
	m_pipesmall->Init(m_texture->GetTexture(PIPESMALL));
	m_pipemedium->Init(m_texture->GetTexture(PIPEMEDIUM));
	m_pipebig->Init(m_texture->GetTexture(PIPEBIG));
	m_flower->Init(m_texture->GetTexture(FLOWER));
	m_coin->Init(m_texture->GetTexture(COIN));
	m_mushroom->Init(m_texture->GetTexture(MUSHROOM));
	m_turtle->Init(m_texture->GetTexture(TURTLE));
	m_turtleshield->Init(m_texture->GetTexture(TURTLESHIELD));
	m_bullet->Init(m_texture->GetTexture(BULLET));
	m_item->Init(m_texture->GetTexture(ITEM));
	m_brickbreak->Init(m_texture->GetTexture(BRICKBREAK));
	//static object
	m_bigtree->Init(m_texture->GetTexture(BIGTREE));
	m_smalltree->Init(m_texture->GetTexture(SMALLTREE));
	m_clound->Init(m_texture->GetTexture(CLOUD));
	m_grass->Init(m_texture->GetTexture(GRASS));
	m_mountain->Init(m_texture->GetTexture(MOUNTAIN));
	m_fence->Init(m_texture->GetTexture(FENCE));
	m_house->Init(m_texture->GetTexture(HOUSE));
	//menu
	m_loading->Init(m_texture->GetTexture(LOADING));
	m_backgroundmenu->Init(m_texture->GetTexture(BACKGROUNDMENU));
	m_menuabout->Init(m_texture->GetTexture(MENUABOUT));
	m_menunewgame->Init(m_texture->GetTexture(MENUNEWGAME));
	m_menucontinue->Init(m_texture->GetTexture(MENUCONTINUE));
	m_menuexit->Init(m_texture->GetTexture(MENUEXIT));
	m_menuoption->Init(m_texture->GetTexture(MENUOPTION));
	m_select->Init(m_texture->GetTexture(SELECT));
	m_about->Init(m_texture->GetTexture(ABOUT));
	m_option->Init(m_texture->GetTexture(OPTION));
	m_win->Init(m_texture->GetTexture(WIN));
	m_score->Init(m_texture->GetTexture(SCORE));
	m_gameover->Init(m_texture->GetTexture(GAMEOVER));

	//sounds
	m_soundAbout = m_audio->LoadSound(SOUND_ABOUT);
	m_soundBrickBreak = m_audio->LoadSound(SOUND_BRICKBREAK);
	m_soundBrickSlide = m_audio->LoadSound(SOUND_BRICKSLIDE);
	m_soundCoin = m_audio->LoadSound(SOUND_COIN);
	m_soundDeath = m_audio->LoadSound(SOUND_DEATH);
	m_soundItemUp = m_audio->LoadSound(SOUND_ITEMUP);
	m_soundJump = m_audio->LoadSound(SOUND_JUMP);
	m_soundLifeUp = m_audio->LoadSound(SOUND_LIFEUP);
	m_soundLoading = m_audio->LoadSound(SOUND_LOADING);
	m_soundLose = m_audio->LoadSound(SOUND_LOSE);
	m_soundMap1 = m_audio->LoadSound(SOUND_MAP1);
	m_soundMap2 = m_audio->LoadSound(SOUND_MAP2);
	m_soundMarioGrow = m_audio->LoadSound(SOUND_MARIOGROW);
	m_soundMarioKick = m_audio->LoadSound(SOUND_MARIOKICK);
	m_soundMenu = m_audio->LoadSound(SOUND_MENU);
	m_soundMushroomDie = m_audio->LoadSound(SOUND_MUSHROOMDIE);
	m_soundOptions = m_audio->LoadSound(SOUND_OPTIONS);
	m_soundPowerUp  = m_audio->LoadSound(SOUND_POWERUP);
	m_soundShotted  = m_audio->LoadSound(SOUND_SHOTTED);
	m_soundSlidePipe = m_audio->LoadSound(SOUND_SLIDEPIPE);
	m_soundStartGame = m_audio->LoadSound(SOUND_STARTGAME);
	m_soundTurtleHead = m_audio->LoadSound(SOUND_TURTLEHEAD);
	m_soundWin = m_audio->LoadSound(SOUND_WIN);
	m_stage_clear = m_audio->LoadSound(STAGE_CLEAR);
	m_soundGameOver = m_audio->LoadSound(SOUND_GAMEOVER);
	return true;
}
CSprite* CResourceManager::GetResouce(ResourceId _id){
	switch (_id)
	{
	case MARIOBIG_ID:
		{
			return new CSprite(*m_marioBig);
			break;
		}
	case MARIOSMALL_ID:
		{
			return new CSprite(*m_marioSmall);
			break;
		}
	case MARIOGUN_ID:
		{
			return new CSprite(*m_marioGun);
			break;
		}
	case BRICK_ID:
		{
			return new CSprite(*m_brick);
			break;
		}
	case QUESTION_ID:
		{
			return new CSprite(*m_question);
			break;
		}
	case PIPESMALL_ID:
		{
			return new CSprite(*m_pipesmall);
			break;
		}
	case PIPEMEDIUM_ID:
		{
			return new CSprite(*m_pipemedium);
			break;
		}
	case PIPEBIG_ID:
		{
			return new CSprite(*m_pipebig);
			break;
		}
		//static
	case BIGTREE_ID:
		{
			return new CSprite(*m_bigtree);
			break;
		}
	case SMALLTREE_ID:
		{
			return new CSprite(*m_smalltree);
			break;
		}
	case CLOUD_ID:
		{
			return new CSprite(*m_clound);
			break;
		}
	case MOUNTAIN_ID:
		{
			return new CSprite(*m_mountain);
			break;
		}
	case GRASS_ID:
		{
			return new CSprite(*m_grass);
			break;
		}
	case FENCE_ID:
		{
			return new CSprite(*m_fence);
			break;
		}
	case FLOWER_ID:
		{
			return new CSprite(*m_flower);
			break;
		}
	case COIN_ID:
		{
			return new CSprite(*m_coin);
			break;
		}
	case HOUSE_ID:
		{
			return new CSprite(*m_house);
			break;
		}
	case MUSHROOM_ID:
		{
			return new CSprite(*m_mushroom);
			break;
		}
	case TURTLE_ID:
		{
			return new CSprite(*m_turtle);
			break;
		}
	case TURTLESHIELD_ID:
		{
			return new CSprite(*m_turtleshield);
			break;
		}
	case BULLET_ID:
		{
			return new CSprite(*m_bullet);
			break;
		}
	case ITEM_ID:
		{
			return new CSprite(*m_item);
			break;
		}
	case BRICKBREAK_ID:
		{
			return new CSprite(*m_brickbreak);
			break;
		}
		//menu
	case LOADING_ID:
		{
			return new CSprite(*m_loading);
			break;
		}
	case BACKGROUNDMENU_ID:
		{
			return new CSprite(*m_backgroundmenu);
			break;
		}
	case MENUNEWGAME_ID:
		{
			return new CSprite(*m_menunewgame);
			break;
		}
	case MENUCONTINUE_ID:
		{
			return new CSprite(*m_menucontinue);
			break;
		}
	case MENUABOUT_ID:
		{
			return new CSprite(*m_menuabout);
			break;
		}
	case MENUOPTION_ID:
		{
			return new CSprite(*m_menuoption);
			break;
		}
	case MENUEXIT_ID:
		{
			return new CSprite(*m_menuexit);
			break;
		}
	case SELECT_ID:
		{
			return new CSprite(*m_select);
			break;
		}
	case ABOUT_ID:
		{
			return new CSprite(*m_about);
			break;
		}
	case OPTION_ID:
		{
			return new CSprite(*m_option);
			break;
		}
	case WIN_ID:
		{
			return new CSprite(*m_win);
			break;
		}
	case SCORE_ID:
		{
			return new CSprite(*m_score);
			break;
		}
	case GAMEOVER_ID:
		{
			return new CSprite(*m_gameover);
			break;
		}
	default:
		{
			return NULL;
			break;
		}
	}

}
CSound* CResourceManager::GetSound(ResourceId _resourceId)
{
	switch (_resourceId)
	{
	case SOUND_ABOUT_ID:
		{
			return new CSound( *m_soundAbout);
			break;
		}
	case SOUND_BRICKBREAK_ID:
		{
			return new CSound( *m_soundBrickBreak);
			break;
		}
	case SOUND_BRICKSLIDE_ID:
		{
			return new CSound( *m_soundBrickSlide);
			break;
		}
	case SOUND_COIN_ID:
		{
			return new CSound( *m_soundCoin);
			break;
		}
	case SOUND_DEATH_ID:
		{
			return new CSound( *m_soundDeath);
			break;
		}
	case SOUND_ITEMUP_ID:
		{
			return new CSound( *m_soundItemUp);
			break;
		}
	case SOUND_JUMP_ID:
		{
			return new CSound( *m_soundJump);
			break;
		}
	case SOUND_LIFEUP_ID:
		{
			return new CSound( *m_soundLifeUp);
			break;
		}
	case SOUND_LOADING_ID:
		{
			return new CSound( *m_soundLoading);
			break;
		}
	case SOUND_LOSE_ID:
		{
			return new CSound( *m_soundLose);
			break;
		}
	case SOUND_MAP1_ID:
		{
			return new CSound( *m_soundMap1);
			break;
		}
	case SOUND_MAP2_ID:
		{
			return new CSound( *m_soundMap2);
			break;
		}
	case SOUND_MARIOGROW_ID:
		{
			return new CSound( *m_soundMarioGrow);
			break;
		}
	case SOUND_MARIOKICK_ID:
		{
			return new CSound(* m_soundMarioKick);
			break;
		}
	case SOUND_MENU_ID:
		{
			return new CSound( *m_soundMenu);
			break;
		}
	case SOUND_MUSHROOMDIE_ID:
		{
			return new CSound( *m_soundMushroomDie);
			break;
		}
	case SOUND_OPTIONS_ID:
		{
			return new CSound( *m_soundOptions);
			break;
		}
	case SOUND_POWERUP_ID:
		{
			return new CSound( *m_soundPowerUp);
			break;
		}
	case SOUND_SHOTTED_ID:
		{
			return new CSound( *m_soundShotted);
			break;
		}
	case SOUND_SLIDEPIPE_ID:
		{
			return new CSound( *m_soundSlidePipe);
			break;
		}
	case SOUND_STARTGAME_ID:
		{
			return new CSound( *m_soundStartGame);
			break;
		}
	case SOUND_TURTLEHEAD_ID:
		{
			return new CSound( *m_soundTurtleHead);
			break;
		}
	case SOUND_WIN_ID:
		{
			return new CSound( *m_soundWin);
			break;
		}
	case SOUND_STAGECLEAR_ID:
		{
			return new CSound( *m_stage_clear);
			break;
		}
	case SOUND_GAMEOVER_ID:
		{
			return new CSound( *m_soundGameOver);
			break;
		}
	default:
		break;
	}
}
CAudio * CResourceManager::GetAudio()
{
	if(m_audio == NULL)
	{
		m_audio = new CAudio(m_wndHandle);
	}
	return m_audio;
}
CResourceManager* CResourceManager::GetInstance()
{
	if (m_resource == NULL)
	{
		m_resource = new CResourceManager();
	}
	return m_resource;
}
CResourceManager::~CResourceManager(void)
{
}