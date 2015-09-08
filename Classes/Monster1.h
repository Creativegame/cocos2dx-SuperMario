#ifndef _SuperMario_H_Monster1 
#define  _SuperMario_H_Monster1     
#include "cocos2d.h"
#include "GameConst.h"
//#include "cocos-ext.h"



using namespace cocos2d;
//USING_NS_CC_EXT;
#define  MOVE_LEFT  10
#define  MOVE_RIGHT  11 
class Monster1:public CCNode
{
public:
	Monster1(void);
	~Monster1(void);
	virtual void onEnter();
	virtual void onExit();
	float getOriPosX();
	void setOriPosx(float posx);
	void tempAction();
	void moveTicking(CCTMXTiledMap* pmap);
	void exutedMoveTick(CCTMXTiledMap* pmap);
	void detectColisionH(CCTMXTiledMap* pmap);
	void detectColisionV(CCTMXTiledMap* pmap);
	void setDie();
	void setDieByGui();
	void setDropDown();

	void setspVisiable(CCSprite*psprite);
	void setspInVisiable(CCSprite*psprite);
	CCSprite*monsterbird1;

	float moveTick;
	float moveTickV;
	CCMenuItemFont*testLable;
	//CCArmature *armature;
	CCSprite *testsprite;
	bool IS_DIE;
private :
	float posx;
	bool isMoveTickExuted;
	int moveType;
	//static int MOVELEFT=100;

	 
};

#endif