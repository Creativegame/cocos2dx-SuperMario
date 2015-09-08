

#ifndef SuperMario_ChooseClass_h
#define SuperMario_ChooseClass_h

#include "cocos2d.h"
#include "GameConst.h"
#include "GameMainScene.h"
using namespace cocos2d;
class ChooseClass :

	public CCLayer
{

	
public:

	virtual bool init();

	virtual void onEnter();

	virtual void onExit();

	static cocos2d::CCScene* scene();

	static  int getWorldTag();

	CCArray*gamemark;

	CCMenu*mainmenu;

	CCSprite*waitSprite;

	 int static  CLASS_TAG;

	 //GameMainScene*gamemainscene;

	void menuQuitCallback(CCObject* pSender);

	void gotoclass1(CCObject* pSender);
	void gotoclass2(CCObject* pSender);
	void gotoclass3(CCObject* pSender);
	void gotoclass4(CCObject* pSender);

			int isworld11unlocked;
			int isworld12unlocked;
			int isworld13unlocked;
			int isworld14unlocked;

	CREATE_FUNC(ChooseClass);
};

#endif