#include "ScoreScene.h"
//#include "GameMark.h"
#include "GameMenuScene.h"
CCScene* ScoreScene::scene()
{
	CCScene *scene = CCScene::create();

	ScoreScene*layer = ScoreScene::create();

	scene->addChild(layer);

	return scene;
}

bool ScoreScene::init()
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

CCMenuItemImage*quitItem = CCMenuItemImage::create("btn_quit1.png", "btn_quit2.png",
												   this,menu_selector(ScoreScene::menuQuitCallback));
	//soundItem->setScale(0.5);
	 
	quitItem->setPosition(ccp(1190,60));
	   quitItem->setScale(1.5f);
	CCMenu* mainmenu = CCMenu::create(quitItem,NULL);
	mainmenu->setPosition(ccp(0,0));
	this->addChild(mainmenu,1,3);

CCSprite*helpSprite=CCSprite::create("text_help.png");
this->addChild(helpSprite);
helpSprite->setPosition(ccp(640,360));

//GameMark
/*
CCUserDefault*handler=CCUserDefault::sharedUserDefault();
	int top1=handler->getIntegerForKey("top1",0);
	int top2=handler->getIntegerForKey("top2",0);
	int top3=handler->getIntegerForKey("top3",0);
	int top4=handler->getIntegerForKey("top4",0);
	int top5=handler->getIntegerForKey("top5",0);
	int top6=handler->getIntegerForKey("top6",0);
	int top7=handler->getIntegerForKey("top7",0);

	int scores[]={top1,top2,top3,top4,top5,top6,top7};

gamemark=CCArray::create();
int fontsize=60;

  char buffer1[128];  
  std::sprintf(buffer1,"%s%d","top1:   ",top1);
CCLabelTTF*lable1=CCLabelTTF::create(buffer1,"AppleGothic",fontsize);
this->addChild(lable1);
gamemark->addObject(lable1);

char buffer2[128];  
std::sprintf(buffer2,"%s%d","top2:   ",top2);
CCLabelTTF*lable2=CCLabelTTF::create(buffer2,"AppleGothic",fontsize);
this->addChild(lable2);
gamemark->addObject(lable2);

char buffer3[128];  
std::sprintf(buffer3,"%s%d","top3:   ",top3);
CCLabelTTF*lable3=CCLabelTTF::create(buffer3,"AppleGothic",fontsize);
this->addChild(lable3);
gamemark->addObject(lable3);


char buffer4[128];  
std::sprintf(buffer4,"%s%d","top4:   ",top4);
CCLabelTTF*lable4=CCLabelTTF::create(buffer4,"AppleGothic",fontsize);
this->addChild(lable4);
gamemark->addObject(lable4);


char buffer5[128];  
std::sprintf(buffer5,"%s%d","top5:   ",top5);
CCLabelTTF*lable5=CCLabelTTF::create(buffer5,"AppleGothic",fontsize);
this->addChild(lable5);
gamemark->addObject(lable5);

char buffer6[128];  
std::sprintf(buffer6,"%s%d","top6:   ",top6);
CCLabelTTF*lable6=CCLabelTTF::create(buffer6,"AppleGothic",fontsize);
this->addChild(lable6);
gamemark->addObject(lable6);

char buffer7[128];  
std::sprintf(buffer7,"%s%d","top7:   ",top7);
CCLabelTTF*lable7=CCLabelTTF::create(buffer7,"AppleGothic",fontsize);
this->addChild(lable7);
gamemark->addObject(lable7);

gamemark->retain();

for (int i = 0; i < 7; i++)
{
	((CCLabelTTF*)gamemark->objectAtIndex(i))->setAnchorPoint(ccp(0,0));
((CCLabelTTF*)gamemark->objectAtIndex(i))->setPosition(ccp(10-i*100,720-110*i));
}
*/

//lable1->setPosition(ccp(360,600));
/*	
	

	for (int i = 0; i < 7; i++)

	{

	//	this->addChild((GameMark*)gamemark->objectAtIndex(i),1);

		//((GameMark*)gamemark->objectAtIndex(i))->setPosition(ccp(size.width/2,size.height/2-300+50*i));

			}

	//	gamemark->retain();*/

		return true;
}
void ScoreScene::onEnter(){
	CCLayer::onEnter();
	/*for (int i = 0; i < 7; i++)
	{
		((CCLabelTTF*)gamemark->objectAtIndex(i))->runAction(CCMoveTo::create(0.6,ccp(100,720-110*i)));
	//	((CCLabelTTF*)gamemark->objectAtIndex(i))->setPosition(ccp(100,950-110*i));
	}*/
	 
}
void ScoreScene::onExit(){
	CCLayer::onExit();
}
void ScoreScene::menuQuitCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MainMenuScene::scene());
}