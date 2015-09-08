#include "ChooseScene.h"
//#include "GameMark.h"
#include "GameMenuScene.h"
CCScene* ChooseClass::scene()
{
	CCScene *scene = CCScene::create();

	ChooseClass*layer = ChooseClass::create();

	scene->addChild(layer);

	return scene;
}

bool ChooseClass::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}
	CCSize size = CCDirector::sharedDirector()->getWinSize();    

	CCSprite* bg = CCSprite::create("bglight.png");
	bg->setPosition( ccp(size.width/2, size.height/2) );
	this->addChild(bg, 0,0);

	//quit button

	CCUserDefault*handler=CCUserDefault::sharedUserDefault();
	  isworld11unlocked=handler->getIntegerForKey("world11lock",1);
  isworld12unlocked=handler->getIntegerForKey("world12lock",0);
	  isworld13unlocked=handler->getIntegerForKey("world13lock",0);
 isworld14unlocked=handler->getIntegerForKey("world14lock",0);
	CCSprite*temp=CCSprite::create("world_lock.png");
	CCTexture2D*unlockTexture=temp->getTexture();

CCMenuItemImage*quitItem = CCMenuItemImage::create("btn_quit1.png", "btn_quit2.png",
												   this,menu_selector(ChooseClass::menuQuitCallback));
	//soundItem->setScale(0.5);
	 
	quitItem->setPosition(ccp(1190,60));
	  quitItem->setScale(1.5f);
CCMenuItemImage*class1=CCMenuItemImage::create("world11.png",NULL,
											   this,menu_selector(ChooseClass::gotoclass1));
class1->setPosition(ccp(30,400));
class1->setAnchorPoint(ccp(0,0));
class1->setTag(1);
class1->setScale(0.7f);


CCMenuItemImage*class2;
if(isworld12unlocked==1)
class2=CCMenuItemImage::create("world12.png",NULL,
											   this,menu_selector(ChooseClass::gotoclass2));
if (isworld12unlocked==0)
	class2=CCMenuItemImage::create("world_lock.png",NULL,
													this,menu_selector(ChooseClass::gotoclass2));
class2->setPosition(ccp(360,400));
class2->setAnchorPoint(ccp(0,0));
class2->setTag(2);
class2->setScale(0.7f);

CCMenuItemImage*class3;
if(isworld13unlocked==1)
	class3=CCMenuItemImage::create("world13.png",NULL,
	this,menu_selector(ChooseClass::gotoclass3));
if (isworld13unlocked==0)
	class3=CCMenuItemImage::create("world_lock.png",NULL,
	this,menu_selector(ChooseClass::gotoclass3));
class3->setPosition(ccp(690,400));
class3->setAnchorPoint(ccp(0,0));
class3->setTag(3);
class3->setScale(0.7f);


CCMenuItemImage*class4;
if(isworld14unlocked==1)
	class4=CCMenuItemImage::create("world14.png",NULL,
	this,menu_selector(ChooseClass::gotoclass4));
if (isworld14unlocked==0)
	class4=CCMenuItemImage::create("world_lock.png",NULL,
	this,menu_selector(ChooseClass::gotoclass4));
class4->setPosition(ccp(1020,400));
class4->setAnchorPoint(ccp(0,0));
class4->setTag(4);
class4->setScale(0.7f);

 

 mainmenu = CCMenu::create(quitItem,class1,class2,class3,class4,NULL);
mainmenu->setPosition(ccp(0,0));
mainmenu->setTag(100);
//mainmenu->setScale(0.7f);
	this->addChild(mainmenu,3);

	waitSprite=CCSprite::create("text_wait.png");
	waitSprite->setPosition(ccp(640,280));
	this->addChild(waitSprite,4);
	waitSprite->setVisible(false);

	
		return true;
}

int ChooseClass::getWorldTag(){
   return SCENE_NUM;
}

void ChooseClass::gotoclass1(CCObject* pSender){
	CCSprite*psprite=(CCSprite*)this->getChildByTag(100)->getChildByTag(1);
	CCScaleTo*action1=CCScaleTo::create(0.5,1.2f,1.2f);
	CCScaleTo*action2=CCScaleTo::create(0.5,1.0f,1.0f);
	psprite->runAction(CCSequence::create(action1,action2,NULL));
	waitSprite->setVisible(true);
	 SCENE_NUM=11;
	 GameMainScene*sec_scene=GameMainScene::create();
 	  CCDirector::sharedDirector()->replaceScene(sec_scene->scene());
}

void ChooseClass::gotoclass2(CCObject* pSender){
	if(isworld12unlocked==1)
	{   
			waitSprite->setVisible(true);
		SCENE_NUM=12;
	 	GameMainScene*gamemainscene=GameMainScene::create();
		CCDirector::sharedDirector()->replaceScene(gamemainscene->scene());}
}

void ChooseClass::gotoclass3(CCObject* pSender){
		if(isworld13unlocked==1)
{	
		waitSprite->setVisible(true);
	SCENE_NUM=13;
	GameMainScene*gamemainscene=GameMainScene::create();
	CCDirector::sharedDirector()->replaceScene(gamemainscene->scene());}
}

void ChooseClass::gotoclass4(CCObject* pSender){
		if(isworld14unlocked==1)
{	
		waitSprite->setVisible(true);
	SCENE_NUM=14;
	GameMainScene*gamemainscene=GameMainScene::create();
	CCDirector::sharedDirector()->replaceScene(gamemainscene->scene());}
}

void ChooseClass::onEnter(){
 	CCLayer::onEnter();
}
void ChooseClass::onExit(){
	CCLayer::onExit();
}
void ChooseClass::menuQuitCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MainMenuScene::scene());
	// CCDirector::sharedDirector()->end();
}