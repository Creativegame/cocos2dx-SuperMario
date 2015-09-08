#include "WinFlag.h"


WinFlag::WinFlag(void)
{
 
}
void WinFlag::onEnter(){
	CCNode::onEnter();
	this->setContentSize(CCSizeMake(20,400));
		CCSprite*sprite=CCSprite::create("winflag.png");
	this->addChild(sprite);
	 
}
void WinFlag::onExit(){
	CCNode::onExit();
}
 
float WinFlag::getOriPosX(){
	return this->posx;
}

void WinFlag::setOriPosx(float px){
	this->posx=px;
}

 
WinFlag::~WinFlag(void)
{
}
