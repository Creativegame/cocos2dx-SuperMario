#ifndef SuperMario_MainMenu_h
#define SuperMario_MainMenu_h
#include "cocos2d.h"
//#include "cocos-ext.h"
#include "GameMainScene.h"
#include "ScoreScene.h"
#include "ChooseScene.h"
using namespace cocos2d;
class MainMenuScene : public cocos2d::CCLayer
{
public:
 
	virtual bool init();

	virtual void onEnter();

	virtual void onExit();

	static cocos2d::CCScene* scene();

	void menuEnter(CCNode*pnode);

  // void touchEvent(CCObject *pSender,cocos2d::gui::TouchEventType type);

   void menu_newgameCallback(CCObject*psender);

   void menu_scoreCallback(CCObject*psender);

   void menu_quitCallback(CCObject*psender);
	 
	CREATE_FUNC(MainMenuScene);
};



#endif