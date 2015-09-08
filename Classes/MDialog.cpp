#include "MDialog.h"
#include "MainMenuScene.h"
DoneDialog::DoneDialog(){
	isShow=false;
}

DoneDialog::~DoneDialog(){

}

void DoneDialog::onEnter(){
	CCNode::onEnter();
	CCSprite*bg=CCSprite::create("dialogbg.png");
	bg->setAnchorPoint(ccp(0.5,0.5));
	bg->setPosition(ccp(640,360));
	this->addChild(bg,10);
	CCSprite*title=CCSprite::create("donetitle.png");
	title->setAnchorPoint(ccp(0.5,0.5));
	title->setPosition(ccp(640,500));
	this->addChild(title,11);
	CCMenuItemImage*menuback=CCMenuItemImage::create("btn_mainmenu1.png","btn_mainmenu2.png"
		,this,menu_selector(DoneDialog::menuBackCallback));
	CCMenuItemImage*menunext=CCMenuItemImage::create("btn_next1.png","btn_next2.png"
		,this,menu_selector(DoneDialog::menuNextCallback));

	menuback->setPosition(ccp(640-200,220));
	menunext->setPosition(ccp(640+200,220));
	  menuback->setScale(1.5f);
	    menunext->setScale(1.5f);
	CCMenu*mmenu=CCMenu::create(menuback,menunext,NULL);
	mmenu->setPosition(ccp(0,0));

	this->addChild(mmenu,12);
}

void DoneDialog::onExit(){
	CCNode::onExit();
}

void DoneDialog::menuBackCallback(CCObject* pSender){
	CCDirector::sharedDirector()->replaceScene(MainMenuScene::scene());
}

void DoneDialog::menuNextCallback(CCObject* pSender){
	GameMainScene*p=(GameMainScene*)this->getParent();
	p->nextWorld();
	this->setVisible(false);
}

DieDialog::DieDialog(){

};
DieDialog::~DieDialog(){

};

void DieDialog::onEnter(){
	CCNode::onEnter();

	CCSprite*bg=CCSprite::create("dialogbg.png");
	bg->setAnchorPoint(ccp(0.5,0.5));
	bg->setPosition(ccp(640,360));
	this->addChild(bg,10);
	CCSprite*title=CCSprite::create("dietitle.png");
	title->setAnchorPoint(ccp(0.5,0.5));
	title->setPosition(ccp(640,500));
	this->addChild(title,11);
	CCMenuItemImage*menuback=CCMenuItemImage::create("btn_mainmenu1.png","btn_mainmenu2.png"
		,this,menu_selector(DieDialog::menuOkCallback));
	 

	menuback->setPosition(ccp(640,220));
 
	menuback->setScale(1.5f);
//	menunext->setScale(1.5f);
	CCMenu*mmenu=CCMenu::create(menuback,NULL);
	mmenu->setPosition(ccp(0,0));

	this->addChild(mmenu,12);

	}
void DieDialog::onExit(){
	CCNode::onExit();
}

void DieDialog::menuOkCallback(CCObject* pSender){
	CCDirector::sharedDirector()->replaceScene(MainMenuScene::scene());
}

QuitDialog::QuitDialog(){

}

QuitDialog::~QuitDialog(){

}

void QuitDialog::onEnter(){
	CCNode::onEnter();
	CCSprite*bg=CCSprite::create("dialogbg.png");
	bg->setAnchorPoint(ccp(0.5,0.5));
	bg->setPosition(ccp(640,360));
	this->addChild(bg,10);
	CCSprite*title=CCSprite::create("quittitle.png");
	title->setAnchorPoint(ccp(0.5,0.5));
	title->setPosition(ccp(640,500));
	this->addChild(title,11);
	CCMenuItemImage*menuback=CCMenuItemImage::create("btn_mainmenu1.png","btn_mainmenu2.png"
		,this,menu_selector(QuitDialog::menuOkCallback));
	CCMenuItemImage*menunext=CCMenuItemImage::create("btn_cancel1.png","btn_cancel2.png"
		,this,menu_selector(QuitDialog::menuCancelCallback));

	menuback->setPosition(ccp(640-200,220));
	menunext->setPosition(ccp(640+200,220));
	menuback->setScale(1.5f);
	menunext->setScale(1.5f);
	CCMenu*mmenu=CCMenu::create(menuback,menunext,NULL);
	mmenu->setPosition(ccp(0,0));

	this->addChild(mmenu,12);
}

void QuitDialog::onExit(){
	CCNode::onExit();
}

void QuitDialog::menuOkCallback(CCObject* pSender){
	CCDirector::sharedDirector()->replaceScene(MainMenuScene::scene());
}
void QuitDialog::menuCancelCallback(CCObject* pSender){
	this->setVisible(false);
}