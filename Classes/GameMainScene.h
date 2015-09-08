#ifndef  SuperMario_GameMain_h
#define SuperMario_GameMain_h
#include "cocos2d.h"
#include "GameObjHero.h"
#include "GameConst.h"
#include "Monster1.h"
#include "Monster2.h"
#include "GameScore.h"
#include "BonusMogu.h"
#include "ChooseScene.h"
#include "MDialog.h"
#include "WinFlag.h"


using namespace cocos2d;
#define  COLI_TYPE_NO 10
#define  COLI_TYPE_LR 11
#define  COLI_TYPE_U2D 12

class GameMainScene :public CCLayer
{
	

private:


	int stepindex;
	int smallstepindex;
	short enemymovetick;
	CCSize ownsize;
	CCSize othersize;
	bool isreduce;
public:

	 int WORLD_TAG;
	 int world_num;
	GameObjHero*gameplayer;

	short hmove;
	double vmove;
	int updateTimes;
 

	
//	CCSprite* gameplayer;
	CCSprite* enemy;  
	CCArray *isMapUnitDestroyed;
	CCArray*gameMonsterbirds;
	CCArray*gameMonsterguis;
	CCArray*gameBonusMogus;
	WinFlag*winflag;
	DoneDialog*donedialog;
	DieDialog*diedialog;
	QuitDialog*backdialog;
	BonusMogu*bonusMoney;
	GameScore*gamescore;
	bool isInited;
	virtual bool init(); 
	void resetreduce(float dt);
	void initSomeDatas(void );
	void refreshMonsterPosx(CCTMXTiledMap* map);
	void playermapvcollision();
	void playermapvDowncollision();
	void playermaphcollision();
	void setDropDown();
	void heroColisionwithMonster(CCTMXTiledMap*pmap);
	int  colisiionType(CCPoint pos1,CCPoint pos2,CCSize size1,CCSize size2,CCTMXTiledMap*pmap);
	//bool isColisionU2D(CCPoint pos1,CCPoint pos2,CCSize size1,CCSize size2);
	void enemytick();
	void setTileInvisiable(CCNode*pnode);
	void runColisionedAction(CCSprite*psprite,short tiltType,CCTMXTiledMap*pMap);
	void update(float dt);
	static cocos2d::CCScene* scene();
	bool iscollision(CCSprite *mysprite,CCSprite *testsprite);
	void makeUpTileIndex(int indexx,int indexy, CCTMXTiledMap*map);
	void makeUpHeroPos();

	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
	virtual void registerWithTouchDispatcher();
	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();

	virtual void keyBackClicked();
	virtual void keyMenuClicked();
	void nextWorld();

	CCPoint offset;
	short TOUCHMODE;

	CREATE_FUNC(GameMainScene);
};
#endif
