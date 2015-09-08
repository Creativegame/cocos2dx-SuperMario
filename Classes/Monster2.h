#ifndef _SuperMario_H_Monster2
#define  _SuperMario_H_Monster2
#include "cocos2d.h"
#include "GameConst.h"
//#include "cocos-ext.h"



using namespace cocos2d;
//USING_NS_CC_EXT;
#define  MOVE_LEFT  10
#define  MOVE_RIGHT  11 
#define  MOVE_LEFT_FAST 12
#define MOVE_RIGHT_FAST 13
class Monster2:public CCNode
{
public:
	Monster2(void);
	~Monster2(void);
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
		void setDropDown();
	float moveTick;
	float moveTickV;
	CCMenuItemFont*testLable;
	//CCArmature *armature;
	CCSprite *testsprite;
	bool IS_DIE;

	void setspVisiable(CCSprite*psprite);
	void setspInVisiable(CCSprite*psprite);
	CCSprite*monstergui1;
	CCSprite*monsterguibei;

private :
	float posx;
	bool isMoveTickExuted;
	int moveType;
	float moveSpeed;
	//static int MOVELEFT=100;


};

#endif