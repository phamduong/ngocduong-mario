#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_
#define MARIO_BIG "Resource//Images//PlayLon.png"
#define MARIO_SMALL "Resource//Images//PlayNho.png"
#define MARIO_GUN "Resource//Images//PlaySung.png"
#define BRICK "Resource//Images//brick.png"
#define QUESTION "Resource//Images//Question.png"
#define PIPEMEDIUM "Resource//Images//MEDIUM_PIPE.png"
#define PIPESMALL "Resource//Images//SMALL_PIPE.png"
#define PIPEBIG "Resource//Images//BIG_PIPE.png"
#define BIGTREE "Resource//Images//BIG_TREE.png"
#define SMALLTREE "Resource//Images//SMALL_TREE.png"
#define CLOUD "Resource//Images//CLOUD.png"
#define GRASS "Resource//Images//GRASS.png"
#define MOUNTAIN "Resource//Images//MOUNTAIN.png"
#define FENCE "Resource//Images//FENCE.png"
#define FLOWER "Resource//Images//FlOWER.png"
#define COIN "Resource//Images//Coin.png"
#define HOUSE "Resource//Images//house.png"
#define MUSHROOM "Resource//Images//Mushroom.png"
#define TURTLE "Resource//Images//Turtle.png"
#define TURTLESHIELD "Resource//Images//TurtuleShield.png"
#define BULLET "Resource//Images//Bullet.png"
#define ITEM "Resource//Images//item.png"
#define BRICKBREAK "Resource//Images//BrickBreak.png"
#define COLUMNFLAG "Resource//Images//ColumnFlag.png"
#define FLAG "Resource//Images//Flag.png"
#define FLAGKHUA "Resource//Images//Khua.png"
//boss
#define BOSS "Resource//Images//Boss.png"
#define FIREBOSS "Resource//Images//FireBoss.png"

#define LOADING "Resource//Images//Loading.png"
// menu
#define BACKGROUNDMENU "Resource//Images//BackGroundMenu.png"
#define MENUABOUT "Resource//Images//MENU_ABOUT.png"
#define MENUEXIT "Resource//Images//MENU_EXIT.png"
#define MENUCONTINUE "Resource//Images//MENU_CONTINUE.png"
#define MENUNEWGAME "Resource//Images//MENU_NEWGAME.png"
#define MENUOPTION "Resource//Images//MENU_OPTIONS.png"
#define SELECT "Resource//Images//Select.png"
#define ABOUT "Resource//Images//about.png"
#define OPTION "Resource//Images//option.png"
#define WIN "Resource//Images//Win.png"
#define SCORE "Resource//Images//Score.png"
#define GAMEOVER "Resource//Images//GameOver.png"
//sounds

#define SOUND_ABOUT "Resource//Sounds//About.wav"
#define SOUND_BRICKBREAK "Resource//Sounds//BrickBreaked.wav"
#define SOUND_BRICKSLIDE "Resource//Sounds//BrickSlide.wav" 
#define SOUND_COIN "Resource//Sounds//Coin.wav"
#define SOUND_DEATH "Resource//Sounds//Death.wav"
#define SOUND_ITEMUP "Resource//Sounds//ItemUp.wav"
#define SOUND_JUMP "Resource//Sounds//Jump.wav"
#define SOUND_LIFEUP "Resource//Sounds//LifeUp.wav"
#define SOUND_LOADING "Resource//Sounds//Loading.wav"
#define SOUND_LOSE "Resource//Sounds//Lose.wav"
#define SOUND_MAP1 "Resource//Sounds//Map1.wav"
#define SOUND_MAP2 "Resource//Sounds//Map2.wav"
#define SOUND_MARIOGROW "Resource//Sounds//MarioGrow.wav"
#define SOUND_MARIOKICK "Resource//Sounds//MarioKick.wav"
#define SOUND_MENU "Resource//Sounds//Menu.wav"
#define SOUND_MUSHROOMDIE "Resource//Sounds//Mushroom Die.wav"
#define SOUND_OPTIONS "Resource//Sounds//Options.wav"
#define SOUND_POWERUP "Resource//Sounds//PowerUp.wav"
#define SOUND_SHOTTED "Resource//Sounds//Shotted.wav"
#define SOUND_SLIDEPIPE "Resource//Sounds//SlidePipe.wav"
#define SOUND_STARTGAME "Resource//Sounds//StartGame.wav"
#define SOUND_TURTLEHEAD "Resource//Sounds//TurTleHead.wav"
#define SOUND_WIN  "Resource//Sounds//Win.wav"
#define STAGE_CLEAR  "Resource//Sounds//stage_clear.wav"
#define SOUND_GAMEOVER  "Resource//Sounds//GameOver.wav"

#include<d3d9.h>
#include<d3dx9.h>
#include"Sprite.h"
#include"Texture.h"
#include"CAudio.h"
enum ResourceId {
	MARIOSMALL_ID,
	MARIOBIG_ID,
	MARIOGUN_ID,
	BRICK_ID,
	QUESTION_ID,
	PIPEMEDIUM_ID,
	PIPESMALL_ID,
	PIPEBIG_ID,
	BIGTREE_ID,
	SMALLTREE_ID,
	CLOUD_ID,
	MOUNTAIN_ID,
	GRASS_ID,
	FENCE_ID,
	FLOWER_ID,
	COIN_ID,
	HOUSE_ID,
	MUSHROOM_ID,
	TURTLE_ID,
	TURTLESHIELD_ID,
	BULLET_ID,
	ITEM_ID,
	BRICKBREAK_ID,
	//stategame
	LOADING_ID,
	BACKGROUNDMENU_ID,
	MENUABOUT_ID,
	MENUNEWGAME_ID,
	MENUCONTINUE_ID,
	MENUEXIT_ID,
	MENUOPTION_ID,
	SELECT_ID,
	ABOUT_ID,
	OPTION_ID,
	WIN_ID,
	SCORE_ID,
	GAMEOVER_ID,
	FLAG_ID,
	COLUMNFLAG_ID,
	FLAGKHUA_ID,
	//boss
	BOSS_ID,
	FIREBOSS_ID,

	//Sounds
	SOUND_ABOUT_ID,
	SOUND_BRICKBREAK_ID,
	SOUND_BRICKSLIDE_ID,
	SOUND_COIN_ID,
	SOUND_DEATH_ID,
	SOUND_ITEMUP_ID,
	SOUND_JUMP_ID,
	SOUND_LIFEUP_ID,
	SOUND_LOADING_ID,
	SOUND_LOSE_ID,
	SOUND_MAP1_ID,
	SOUND_MAP2_ID,
	SOUND_MARIOGROW_ID,
	SOUND_MARIOKICK_ID,
	SOUND_MENU_ID,
	SOUND_MUSHROOMDIE_ID,
	SOUND_OPTIONS_ID,
	SOUND_POWERUP_ID,
	SOUND_SHOTTED_ID,
	SOUND_SLIDEPIPE_ID,
	SOUND_STARTGAME_ID,
	SOUND_TURTLEHEAD_ID,
	SOUND_WIN_ID,
	SOUND_STAGECLEAR_ID,
	SOUND_GAMEOVER_ID

};

class CResourceManager{
public:
	CSprite *m_marioBig;
	CSprite *m_marioSmall;
	CSprite *m_marioGun;
	CSprite *m_brick;
	CSprite *m_question;
	CSprite *m_pipemedium;
	CSprite *m_pipesmall;
	CSprite *m_pipebig;
	CSprite *m_bigtree;
	CSprite *m_smalltree;
	CSprite *m_clound;
	CSprite *m_mountain;
	CSprite *m_grass;
	CSprite *m_fence;
	CSprite *m_flower;
	CSprite *m_coin;
	CSprite *m_house;
	CSprite *m_mushroom;
	CSprite *m_turtle;
	CSprite *m_turtleshield;
	CSprite *m_bullet;
	CSprite *m_item;
	CSprite *m_brickbreak;
	CSprite *m_boss;
	CSprite *m_fireboss;
	CSprite *m_columnflag;
	CSprite *m_flag;
	CSprite *m_flagKhua;
	//menu
	CSprite *m_loading;
	CSprite *m_backgroundmenu;
	CSprite *m_menunewgame;
	CSprite *m_menuabout;
	CSprite *m_menuexit;
	CSprite *m_menuoption;
	CSprite *m_menucontinue;
	CSprite *m_select;
	CSprite *m_about;
	CSprite *m_option;
	CSprite *m_win;
	CSprite *m_score;
	CSprite *m_gameover;


	//sounds
	CSound * m_soundAbout;
	CSound * m_soundBrickBreak;
	CSound * m_soundBrickSlide;
	CSound * m_soundCoin;
	CSound * m_soundDeath;
	CSound * m_soundItemUp;
	CSound * m_soundJump;
	CSound * m_soundLifeUp;
	CSound * m_soundLoading;
	CSound * m_soundLose;
	CSound * m_soundMap1;
	CSound * m_soundMap2;
	CSound * m_soundMarioGrow;
	CSound * m_soundMarioKick;
	CSound * m_soundMenu;
	CSound * m_soundMushroomDie;
	CSound * m_soundOptions;
	CSound * m_soundPowerUp;
	CSound * m_soundShotted;
	CSound * m_soundSlidePipe;
	CSound * m_soundStartGame;
	CSound * m_soundTurtleHead;
	CSound * m_soundWin;
	CSound * m_soundGameOver;
	CSound * m_stage_clear;

	CTexture *m_texture;
	static CResourceManager *m_resource;
	static LPDIRECT3DDEVICE9 m_pd3device;
	static HWND  m_wndHandle;
	static CAudio * m_audio;
public:
	CResourceManager(void);
	~CResourceManager(void);

	bool Init(LPDIRECT3DDEVICE9 ,HWND);


	CSprite* GetResouce(ResourceId);
	CSound * GetSound(ResourceId);
	//static
	static CAudio * GetAudio();
	static CResourceManager* GetInstance();
};
#endif