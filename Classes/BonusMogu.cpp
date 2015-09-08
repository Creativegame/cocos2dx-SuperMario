#include "BonusMogu.h"


BonusMogu::BonusMogu(void)
{
		IS_GETED=false;
	//	testsprite=CCSprite::create("CloseSelected.png");
	//	testLable=CCMenuItemFont::create("test");
}
void BonusMogu::onEnter(){
	CCNode::onEnter();
		//this->setAnchorPoint(ccp(0.5f,0));
	this->setContentSize(CCSizeMake(20,20));
	//CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("bonus/BonusMogu.ExportJson");
	//armature = CCArmature::create("BonusMogu");
	//armature->getAnimation()->playWithIndex(0);

	//this->addChild(testsprite);
	//sprite->setp
	//armature->setAnchorPoint(ccp(0,0));
	spMogu=CCSprite::create("mogu.png");
	spJinbi=CCSprite::create("money.png");
	spMogu->setAnchorPoint(ccp(0.5,0));
	spJinbi->setAnchorPoint(ccp(0.5,1));
	spMogu->setPositionX(15.0f);
	//this->addChild(armature);
	this->addChild(spMogu);
	this->addChild(spJinbi);

	spJinbi->setVisible(false);

	CCTintTo*tintto1=CCTintTo::create(0.3,120,120,120);
	CCTintTo*tintto2=CCTintTo::create(0.3, 0,0,0);

	CCRepeatForever*maction=CCRepeatForever::create(CCSequence::create(tintto1,tintto2,NULL));

	spMogu->runAction(maction);

	this->setScale(0.85f);
	//	this->addChild(testLable);
}



void BonusMogu::onExit(){
	CCNode::onExit();
}

void BonusMogu::setGeted(){
//	armature->getAnimation()->playWithIndex(1);
	//armature->getAnimation()->
	CCCallFuncN*action1=CCCallFuncN::create(spMogu,callfuncN_selector(BonusMogu::setspVisiable));
	CCScaleTo*action2=CCScaleTo::create(0.3f,1.0f,0.0f);
	CCCallFuncN*action3=CCCallFuncN::create(spMogu,callfuncN_selector(BonusMogu::setspInVisiable));
	spMogu->runAction(CCSequence::create(action1,action2,action3,NULL));
	IS_GETED=true;
}


float BonusMogu::getOriPosX(){
	return this->posx;
}

void BonusMogu::setOriPosx(float px){
	this->posx=px;
}

void BonusMogu::runMoneyAnim(CCPoint pos){
	pos.x=pos.x+15;
	pos.y=pos.y+96;
	this->setPosition(pos);
	spMogu->setVisible(false);
		CCScaleTo*action0=CCScaleTo::create(0.01f,1.0f,1.0f);
	CCCallFuncN*action1=CCCallFuncN::create(spJinbi,callfuncN_selector(BonusMogu::setspVisiable));
	CCScaleTo*action2=CCScaleTo::create(0.3,1.0f,0.0f);
	CCCallFuncN*action3=CCCallFuncN::create(spJinbi,callfuncN_selector(BonusMogu::setspInVisiable));

	CCRotateTo*rotate=CCRotateTo::create(0.3f,90,0);

	spJinbi->runAction(CCSequence::create(action0,action1,action2,action3,NULL));
	//spJinbi->runAction(rotate);

	//armature->getAnimation()->playWithIndex(2);
}

 

 
BonusMogu::~BonusMogu(void)
{
}
void BonusMogu::setspVisiable(CCSprite*psprite){
	psprite->setVisible(true);
}

void BonusMogu::setspInVisiable(CCSprite*psprite){
	psprite->setVisible(false);
}