#ifndef SuperMario_GameMenu_h
#define SuperMario_GameMenu_h
#include "cocos2d.h"
#include "MainMenuScene.h"
 
using namespace cocos2d;
class GameMenuScene : public cocos2d::CCLayer
{
 public:
 
	bool issound;

	CCMenuItemImage *soundItem;
	CCMenuItemImage *quitItem;
 

	virtual bool init();

	virtual void onEnter();

	virtual void onExit();

	static cocos2d::CCScene* scene();

	void menuEnter(CCNode*pnode);

	void menuNewGameCallback(CCObject* pSender);

	void menuScoreCallback(CCObject* pSender);

	void menuAboutCallback(CCObject* pSender);

	void menuSoundCallback(CCObject* pSender);

	void menuQuitCallback(CCObject* pSender);

	void menu1CallBack(CCObject* pSender);

	CREATE_FUNC(GameMenuScene);
};
	
 

#endif