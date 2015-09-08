#ifndef _SuperMario_H_BonusMogu
#define  _SuperMario_H_BonusMogu     
#include "cocos2d.h"
#include "GameConst.h"
//#include "cocos-ext.h"



using namespace cocos2d;
//USING_NS_CC_EXT;
#define  MOVE_LEFT  10
#define  MOVE_RIGHT  11 

 /**
 @brief	蘑菇动画和金币动画的CCSprite.
 */ 
class BonusMogu:public CCNode
{
public:
	BonusMogu(void);
	~BonusMogu(void);
	virtual void onEnter();
	virtual void onExit();
	float getOriPosX();
	void setOriPosx(float posx);
	//void tempAction();
	//void moveTicking(CCTMXTiledMap* pmap);
	//void exutedMoveTick(CCTMXTiledMap* pmap);
	//void detectColisionH(CCTMXTiledMap* pmap);
	//void detectColisionV(CCTMXTiledMap* pmap);
	void setGeted();

	void runMoneyAnim(CCPoint pos);

	CCSprite*spMogu;
	CCSprite*spJinbi;

	void setspVisiable(CCSprite*psprite);
	void setspInVisiable(CCSprite*psprite);
	//void setDieByGui();
	//void setDropDown();
//	float moveTick;
	//float moveTickV;
	//CCMenuItemFont*testLable;
	//CCArmature *armature;
	//CCSprite *testsprite;
	bool IS_GETED;
private :
	float posx;
	//bool isMoveTickExuted;
//	int moveType;
	//static int MOVELEFT=100;


};

#endif