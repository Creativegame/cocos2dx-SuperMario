#ifndef _SuperMario_H_Hero 
#define  _SuperMario_H_Hero     

#include "cocos2d.h"


using namespace cocos2d;

class GameObjHero :
	public CCNode
{
public:
	GameObjHero(void);
	~GameObjHero(void);
	virtual void onEnter();
	virtual void onExit();

	bool * HRRT_ABLE;
	bool hurt_able;

	CCSprite*body;
	CCTexture2D*textcommom;
	CCTexture2D*textjump;
	CCTexture2D*jumpleft;
	CCTexture2D*dead;
	
	CCAnimation*animtoleft;

	short walkstate;
	short jumpstate;
	void jumpend(CCNode*pnode);
	void hurtend(CCNode*pnode);
	void setState(short var);

	void setHurt();

	void setCanHurt(CCNode*pnode);
	void setCanNotHurt(CCNode*pnode);
	 

	//about jump
	void jumpBegin();
	void jumpEnd();
	CCJumpBy*mjumpby;

	//about walk
	void walkRightBegin();
	void walkRightEnd();
	void mapMoveRtoHero();
	void mapStopMovetoRight();
	CCAnimation*animtionoright;
	CCAnimate*animatetoright;
	CCRepeatForever*animrightReapte;
	CCRepeatForever*TruemapmoveRtohero;
	CCMoveTo*moveRtoMap;//主角相对地图运动至屏幕X中间位置
	CCMoveBy*mapmoveRtoHero;
	short walkcalledtimes;
	   //walk left
	void walkLeftBegin();
	void walkLeftEnd();

	 
	

};
#endif
