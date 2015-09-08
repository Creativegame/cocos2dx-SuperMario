#include "GameMenuScene.h"
/*#include "ScoreScene.h"

#include "GameAboutScene.h"
#include "GameScene.h"*/
#include "GameMainScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* GameMenuScene::scene()
{
	CCScene *scene = CCScene::create();

	GameMenuScene *layer = GameMenuScene::create();

	scene->addChild(layer);

	return scene;
}
bool GameMenuScene::init()
{
	if ( !CCLayer::init() )
	{
		return false;
	}

	CCSize size = CCDirector::sharedDirector()->getWinSize();    
	CCUserDefault*handler=CCUserDefault::sharedUserDefault();
	issound=handler->getBoolForKey("issound",true);
	//playaudio=new PlayAudio();
	 
	//	playaudio->bgSound();
	
	 
	
	CCSprite* bg = CCSprite::create("ui/menubg.jpg");
	 
	bg->setPosition( ccp(size.width/2, size.height/2) );
	this->addChild(bg, 0,0);
 //logo
	CCSprite*logo=CCSprite::create("ui/logo.png");
	logo->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(logo,3);
	logo->setPosition(ccp(360,920));
	 
	//³õÊ¼»¯°´Å¥
	CCMenuItemImage *newGameItem = CCMenuItemImage::create("ui/start1.png", "ui/start2.png.png",this,menu_selector(GameMenuScene::menuNewGameCallback));
	//newGameItem->setScale(0.5);
	newGameItem->setPosition(ccp(size.width / 2,size.height / 2 - 20));
	//newGameItem->setEnabled(false);
	CCMenuItemImage *continueItem = CCMenuItemImage::create("ui/score1.png", "ui/score2.png",this,menu_selector(GameMenuScene::menuScoreCallback));
	//continueItem->setScale(0.5);
	continueItem->setPosition(ccp(size.width / 2,size.height / 2 - 195));
	//continueItem->setEnabled(false);
	CCMenuItemImage *aboutItem = CCMenuItemImage::create("ui/about1.png", "ui/about2.png",this,menu_selector(GameMenuScene::menuScoreCallback));
	//aboutItem->setScale(0.5);
	aboutItem->setPosition(ccp(size.width / 2,size.height / 2 - 280));
//	aboutItem->setEnabled(false);
	soundItem = CCMenuItemImage::create("ui/ound1.png", "ui/sound2.png",this,menu_selector(GameMenuScene::menuSoundCallback));
	//soundItem->setScale(0.5);
	soundItem->setEnabled(true);
	soundItem->setPosition(ccp(50,50));

	if(issound){
		soundItem->setNormalImage(CCSprite::create("ui/sound1.png"));
		//soundItem->setDisabledImage(CCSprite::create("sound1.png"));
	 	}else{
		soundItem->setNormalImage(CCSprite::create("ui/sound2.png"));
		//soundItem->setDisabledImage(CCSprite::create("sound2.png"));
		 	}

	quitItem = CCMenuItemImage::create("ui/back1.png", "ui/back2.png",this,menu_selector(GameMenuScene::menuQuitCallback));
	//soundItem->setScale(0.5);
	quitItem->setEnabled(false);
	quitItem->setPosition(ccp(670,50));

	CCMenu* mainmenu = CCMenu::create(newGameItem,continueItem,soundItem,quitItem,NULL);
	mainmenu->setPosition(ccp(0,0));
	this->addChild(mainmenu,1,3);

	issound = true;
	/*SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("background.mp3");
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.mp3", true);
	*/


	 
	
//	 this->addChild(pNode);
	 CCMenuItemFont*menuitem1=CCMenuItemFont::create("menuitem1",
		 this,menu_selector(GameMenuScene::menu1CallBack));

	 menuitem1->setPosition(ccp(300,300));
	 CCMenu*tempmenu=CCMenu::create(menuitem1,NULL);
	 
	 this->addChild(tempmenu);

	return true;
}

void GameMenuScene::menu1CallBack(CCObject* pSender){
	CCScene*newscene=MainMenuScene::scene();
	CCDirector::sharedDirector()->replaceScene(newscene);
}
void GameMenuScene::onEnter(){
	CCLayer::onEnter();
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCNode* mainmenu = this->getChildByTag(3);
	mainmenu->setPositionX(-200);
	mainmenu->runAction(CCSequence::create(
		//CCEaseElasticIn::create
		(CCMoveTo::create(0.5,ccp(0,0))),
		CCCallFuncN::create(this->getChildByTag(3), callfuncN_selector(GameMenuScene::menuEnter)
		)
		,
		NULL));

	 

}
void GameMenuScene::menuEnter(CCNode*pnode){

	//CCNode*mainmenu=this->getChildByTag(3);
//	CCArray* temp = mainmenu->getChildren();
	CCArray*temp=pnode->getChildren();
	for(int i = 0;i < temp->count();i ++)
		((CCMenuItemImage *)temp->objectAtIndex(i))->setEnabled(true);
}
void GameMenuScene::onExit(){
	CCLayer::onExit();
}
void GameMenuScene::menuNewGameCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(GameMainScene::scene());
}
void GameMenuScene::menuAboutCallback(CCObject* pSender)
{
	//CCDirector::sharedDirector()->replaceScene(GameMain::scene());
}
void GameMenuScene::menuScoreCallback(CCObject* pSender)
{
//CCDirector::sharedDirector()->replaceScene(ScoreScene::scene());
}
void GameMenuScene::menuQuitCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->end();
}
void GameMenuScene::menuSoundCallback(CCObject* pSender)
{
	CCUserDefault*handler=CCUserDefault::sharedUserDefault();
	if(! issound){
		soundItem->setNormalImage(CCSprite::create("sound1.png"));
	//	soundItem->setDisabledImage(CCSprite::create("sound1.png"));
	//	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/bg.mp3", true);
		issound = true;
		handler->setBoolForKey("issound",true);
		handler->flush();
	}else{
		soundItem->setNormalImage(CCSprite::create("sound2.png"));
	//	soundItem->setDisabledImage(CCSprite::create("sound2.png"));
	//	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		issound = false;
		handler->setBoolForKey("issound",false);
		handler->flush();
	}
}