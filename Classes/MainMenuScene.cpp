#include "MainMenuScene.h"
/*#include "ScoreScene.h"

#include "GameAboutScene.h"
#include "GameScene.h"*/
//using namespace cocos2d::extension;
//using namespace cocos2d::gui;

using namespace cocos2d;
 

CCScene* MainMenuScene::scene()
{
	CCScene *scene = CCScene::create();

	MainMenuScene *layer = MainMenuScene::create();

	scene->addChild(layer);

	return scene;
}
bool MainMenuScene::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}


	/*CCNode *pNode = SceneReader::sharedSceneReader()->
		createNodeWithSceneFile("NewProject.json");
	CCComRender *render = static_cast<CCComRender*>(pNode->getChildByTag(10006)
		->getComponent("mui"));
	cocos2d::gui::TouchGroup* touchGroup = static_cast<cocos2d::gui::TouchGroup*>(render->getNode());
	UIWidget* widget1 = static_cast<UIWidget*>(touchGroup->getWidgetByName("Panel_55"));		
	//UIWidget* widget2 = static_cast<UIWidget*>(widget1->getChildByName("ImageView_22"));
	UIButton* button = static_cast<UIButton*>(widget1->getChildByName("btn"));
	button->setScale(2.0f,2.0f);
	button->addTouchEventListener(this, toucheventselector(MainMenuScene::touchEvent));
	//button->
	this->addChild(pNode);*/

	CCSprite*bg=CCSprite::create("bglight.png");
	bg->setAnchorPoint(ccp(0,0));
	this->addChild(bg,0);

	//CCSprite*title


	CCMenuItemImage*menu_newgame=CCMenuItemImage::create("btn_newgame1.png","btn_newgame2.png",
		this,menu_selector(MainMenuScene::menu_newgameCallback));
		menu_newgame->setPosition(ccp(170,-150));
		menu_newgame->setScale(1.5f);
	CCMenuItemImage*menu_score=CCMenuItemImage::create("btn_help1.png","btn_help2.png",
		this,menu_selector(MainMenuScene::menu_scoreCallback));
	   menu_score->setPosition(ccp(450,-150));
	   menu_score->setScale(1.5f);
	CCMenuItemImage*menu_quit=CCMenuItemImage::create("btn_quit1.png","btn_quit2.png",
		this,menu_selector(MainMenuScene::menu_quitCallback));
	  menu_quit->setPosition(ccp(550,-300));
	  menu_quit->setScale(1.5f);
	CCMenu*mainmenu=CCMenu::create(menu_newgame,menu_score,menu_quit,NULL);

	//mainmenu->setScale(1.5f);

	this->addChild(mainmenu,1);
//mainmenu->setPosition(ccp(-640,-360));
//	mainmenu->setAnchorPoint(ccp(0,0));
//	CCLOG("x=%f,y=%f",menu_newgame->getPositionX(),menu_newgame->getPositionY());

	/*CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("NewProject.ExportJson");
	CCArmature*armature = CCArmature::create("NewProject");
	armature->getAnimation()->playWithIndex(0);
	this->addChild(armature);
	armature->setPosition(ccp(640,550));*/

	//CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("NewProject.ExportJson");
	/*CCArmature*armature1 = CCArmature::create("NewProject");
	armature1->getAnimation()->playWithIndex(1);
	this->addChild(armature1);
	armature1->setPosition(ccp(300,300));*/

	return true;
}


void MainMenuScene::menu_newgameCallback(CCObject*psender){
	//CCScene*pScene=GameMainScene::scene();
	CCScene*pScene=ChooseClass::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}
void MainMenuScene::menu_scoreCallback(CCObject*psender){
	CCScene*pScene=ScoreScene::scene();
	CCDirector::sharedDirector()->replaceScene(pScene);
}
void MainMenuScene::menu_quitCallback(CCObject*psender){
	CCDirector::sharedDirector()->end();
}
/*
void MainMenuScene::touchEvent(CCObject *pSender,cocos2d::gui::TouchEventType type){
	CCDirector::sharedDirector()->end();
}
*/

void MainMenuScene::onEnter(){
	CCLayer::onEnter();
 
}
void MainMenuScene::menuEnter(CCNode*pnode){

	 
}
void MainMenuScene::onExit(){
	CCLayer::onExit();
}
 