#include "GameObjHero.h"
#include "GameConst.h"
#include "GameMainScene.h"


GameObjHero::GameObjHero(void)
{
	animtionoright=CCAnimation::create();
	walkstate=HERO_STATE_COMMON;
	jumpstate=HERO_STATE_COMMON;
	hurt_able=true;
	HRRT_ABLE=&hurt_able;
	
}


GameObjHero::~GameObjHero(void)
{
}
void GameObjHero::onEnter(){
	CCNode::onEnter();
	this->setContentSize(CCSizeMake(48,50));
	//state=HERO_STATE_COMMON;
	body=CCSprite::create("sprite/bighero.png");
	textcommom=body->getTexture();
	body->setAnchorPoint(ccp(0.5,0));
	this->addChild(body);
	 
CCSprite*obj=CCSprite::create("sprite/jump.png"); 
textjump=obj->getTexture();

walkcalledtimes=0;
}
void GameObjHero::setState(short var){
	/*if(state == var)
		return;*/
	walkstate = var;

	switch(walkstate){
	case 0://common
		{
			this->stopAllActions();
		if(this->hurt_able)	body->stopAllActions();
		///body->stop
			body->setTexture(textcommom);
		}break;
	case 1://ÌøÔ¾
	{	this->stopAllActions();
		if(this->hurt_able)	body->stopAllActions();
		body->setTexture(textjump);
	}
	break;
	case 2://ÐÐ×ß
	{	this->stopAllActions();
	if(this->hurt_able)	body->stopAllActions();
		body->setTexture(textcommom);
		animtionoright=CCAnimation::create();
		//	animtionoright->addSpriteFrameWithFileName("sprite/bighero.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk1.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk2.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk3.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk2.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk1.png");
		animtionoright->setDelayPerUnit(0.1);
		animtionoright->setRestoreOriginalFrame(true);
		animatetoright=CCAnimate::create(animtionoright);	
		animrightReapte=CCRepeatForever::create(animatetoright);
		animrightReapte->setTag(ANIMATE_RIGHT_TAG);
		body->runAction(animrightReapte);
	 
	}	 
		break;
	 	}
}

void GameObjHero::setHurt(){
//	CCBlink*blink=CCBlink::create(5,9);
/*
	CCAnimation*animation=CCAnimation::create();
	animation->addSpriteFrameWithFileName("sprite/bigherohurt1.png");
	animation->addSpriteFrameWithFileName("sprite/bigherohurt.png");
	animation->addSpriteFrameWithFileName("sprite/bigherohurt1.png");
	animation->addSpriteFrameWithFileName("sprite/bigherohurt.png");
	animation->addSpriteFrameWithFileName("sprite/bigherohurt1.png");

	animation->addSpriteFrameWithFileName("sprite/bigherohurt.png");
	animation->addSpriteFrameWithFileName("sprite/bigherohurt1.png");
	animation->addSpriteFrameWithFileName("sprite/bigherohurt.png");
	animation->addSpriteFrameWithFileName("sprite/bigherohurt1.png");
	animation->addSpriteFrameWithFileName("sprite/bigherohurt.png");
	animation->addSpriteFrameWithFileName("sprite/bigherohurt1.png");
	animation->setDelayPerUnit(0.5);
	animation->setRestoreOriginalFrame(true);
	CCAnimate*animate=CCAnimate::create(animation);*/

//	short mRGB=120;
//	CCTintBy*tintby=CCTintBy::create(0.01f,mRGB,mRGB,mRGB);
	//CCTintBy*tintby1=CCTintBy::create(0.01f,-mRGB,-mRGB,-mRGB);
	CCActionInterval*  tintby = CCTintBy::create(1.0f, 0, 255, 0);
	CCActionInterval*  tintby1 =CCTintBy::create(1.0f, 255, 255, 255);
	CCRepeat*	maction=
		CCRepeat::create(CCSequence::create(tintby,
		tintby1,NULL),2);

	// CCActionInterval*  action1 = CCBlink::create(1, 5);

	// CCFadeTo*act1=CCFadeTo::create(0.5,GLubyte(0));
	// CCAction*act2=CCFadeTo::create(0.5,GLubyte(256));
	// CCRepeat*maction=CCRepeat::create(CCSequence::create(act1,act2,NULL),5);
	CCCallFuncN*cannotHurt=CCCallFuncN::create(this,callfuncN_selector(GameObjHero::setCanNotHurt));
	CCCallFuncN*canHurt=CCCallFuncN::create(this,callfuncN_selector(GameObjHero::setCanHurt));
	//this->sets
	//canHurt->
	body->runAction(CCSequence::create(cannotHurt,maction,canHurt,NULL));
}

void GameObjHero::setCanHurt(CCNode*pnode){
	GameMainScene *p = (GameMainScene *) this->getParent();
	//*(p->HERO_HURTABLE)=true;
	*HRRT_ABLE=true;
   body->setOpacity(255);
   body->setVisible(true);
   CCLog("can hurt");
//	body->setColor(ccColor3B());
}

void GameObjHero::setCanNotHurt(CCNode*pnode){
	GameMainScene *p = (GameMainScene *) this->getParent();
	*HRRT_ABLE=false;
	CCLog("cannot hurt");
}
void GameObjHero::onExit(){
	CCNode::onExit();
}
void GameObjHero::jumpend(CCNode*pnode){
	setState(0);
}
void GameObjHero::hurtend(CCNode*pnode){
	setState(0);
}

void GameObjHero::jumpBegin(){
	mjumpby=CCJumpBy::create(JUMPTIME,ccp(0,0),200,1);
	if (//walkstate==HERO_STATE_COMMON||state==HERO_STATE_WALKRIGHT
		//&&state!=HERO_STATE_JUMP
			jumpstate!=HERO_STATE_JUMP
		)
	{
		jumpstate=HERO_STATE_JUMP;
	
	body->setTexture(textjump);
	this->runAction(CCSequence::create(mjumpby,
		CCCallFunc::create(this,callfunc_selector(GameObjHero::jumpEnd)),
		NULL));
	//this->runAction(mjumpby);
	}
}

void GameObjHero::jumpEnd(){
	body->setTexture(textcommom);
	jumpstate=HERO_STATE_COMMON;
}

void GameObjHero::walkRightBegin(){
	if(walkstate==HERO_STATE_COMMON&&jumpstate!=HERO_STATE_JUMP)
	{
	walkstate=HERO_STATE_WALKRIGHT;
	animtionoright=CCAnimation::create();
//	animtionoright->addSpriteFrameWithFileName("sprite/bighero.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk1.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk2.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk3.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk2.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk1.png");
		animtionoright->setDelayPerUnit(0.1);
	animtionoright->setRestoreOriginalFrame(true);
	animatetoright=CCAnimate::create(animtionoright);	
	animrightReapte=CCRepeatForever::create(animatetoright);
	animrightReapte->setTag(ANIMATE_RIGHT_TAG);
	body->runAction(animrightReapte);
	body->setFlipX(false);
	 
    /**/moveRtoMap=CCMoveTo::create((640-this->getPositionX())*1.0f/MAP_MOVE_SPEED,ccp(640,this->getPositionY()));
	moveRtoMap->setTag(	ANIMATE_RIGHT_R_MAP_TAG);
		CCCallFunc*temp0=CCCallFunc::create(this,callfunc_selector(GameObjHero::mapStopMovetoRight));
	CCCallFunc*temp=CCCallFunc::create(this,callfunc_selector(GameObjHero::mapMoveRtoHero));
	CCSequence*temp1=CCSequence::create(moveRtoMap,temp0,temp,NULL);
//	this->setPositionX(640);
	temp1->setTag(	ANIMATE_RIGHT_R_MAP_TAG),
	this->stopActionByTag(ANIMATE_RIGHT_R_MAP_TAG);
	this->runAction(temp1);
 /*
if(	(640-this->getPositionX())*1.0f>0.1)
{	((GameMainScene*)this->getParent())->class1map->runAction(
	CCSequence::create(
	CCDelayTime::create(   ( 640 - this->getPositionX() )*1.0f/MAP_MOVE_SPEED   ),
	CCCallFunc::create(this,callfunc_selector(GameObjHero::walkRightEnd)),
	CCCallFunc::create(this,callfunc_selector(GameObjHero::walkRightBegin)),	
	NULL));
CCLog("hero continue walk");
}
else if ((640-this->getPositionX())*1.0f<=0.1&&(640-this->getPositionX())*1.0f>0)
{
	this->setPositionX(640);
}
else
{
	((GameMainScene*)this->getParent())->class1map->runAction(TruemapmoveRtohero);
	TruemapmoveRtohero->setTag(MAP_MOVE_R_TOHERO_TAG);
	CCLog("map begin move");
}*/
}
}

void GameObjHero::walkRightEnd(){
	if(walkstate==HERO_STATE_WALKRIGHT
		//&&jumpstate!=HERO_STATE_JUMP
		)
	{
	body->setTexture(textcommom);
	//state=HERO_STATE_COMMON;
	body->stopActionByTag(ANIMATE_RIGHT_TAG);
	this->stopActionByTag(ANIMATE_RIGHT_R_MAP_TAG);
//	((GameMainScene*)this->getParent())->class1map->stopAllActions();
	walkstate=HERO_STATE_COMMON;
	}
}
void GameObjHero::mapMoveRtoHero(){
	mapmoveRtoHero=CCMoveBy::create(0.6*10000,ccp(MAP_MOVE_SPEED*(-1)*10000,0));
	//	CCRepeatForever*temp=CCRepeatForever::create(mapmoveRtoHero);
	TruemapmoveRtohero=CCRepeatForever::create(mapmoveRtoHero);
	CCRepeat*tempRepeat=CCRepeat::create(mapmoveRtoHero,6);
	//	((GameMainScene*)this->getParent())->class1map->stopAllActions();
	//	((GameMainScene*)this->getParent())->class1map->runAction(mapmoveRtoHero);
		TruemapmoveRtohero->setTag(MAP_MOVE_R_TOHERO_TAG);
}

void GameObjHero::mapStopMovetoRight(){
	this->stopActionByTag(ANIMATE_RIGHT_R_MAP_TAG);
//	this->stopAllActions();
	//	((GameMainScene*)this->getParent())->class1map->stopAllActions();
		CCLog("Map move stop");
}

void GameObjHero::walkLeftBegin(){
	if(walkstate==HERO_STATE_COMMON&&jumpstate!=HERO_STATE_JUMP)
	{
		walkstate=HERO_STATE_WALKLEFT;
		animtionoright=CCAnimation::create();
		//	animtionoright->addSpriteFrameWithFileName("sprite/bighero.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk1.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk2.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk3.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk2.png");
		animtionoright->addSpriteFrameWithFileName("sprite/walk1.png");
		animtionoright->setDelayPerUnit(0.1);
		animtionoright->setRestoreOriginalFrame(true);
		animatetoright=CCAnimate::create(animtionoright);	
		animrightReapte=CCRepeatForever::create(animatetoright);
		animrightReapte->setTag(ANIMATE_RIGHT_TAG);
	//	animrightReapte->set
		body->runAction(animrightReapte);
		body->setFlipX(true);

		moveRtoMap=CCMoveTo::create((this->getPositionX()-50)*1.0f/MAP_MOVE_SPEED,ccp(50,this->getPositionY()));
		moveRtoMap->setTag(	ANIMATE_RIGHT_R_MAP_TAG);
		//CCCallFunc*temp0=CCCallFunc::create(this,callfunc_selector(GameObjHero::mapStopMovetoRight));
		//CCCallFunc*temp=CCCallFunc::create(this,callfunc_selector(GameObjHero::mapMoveRtoHero));
		CCSequence*temp1=CCSequence::create(moveRtoMap ,NULL);
		//	this->setPositionX(640);
		temp1->setTag(	ANIMATE_RIGHT_R_MAP_TAG),
			this->stopActionByTag(ANIMATE_RIGHT_R_MAP_TAG);
		this->runAction(temp1);
}
}
void GameObjHero::walkLeftEnd(){
	if(walkstate==HERO_STATE_WALKLEFT
		//&&jumpstate!=HERO_STATE_JUMP
			)
	{
		body->setTexture(textcommom);
		//state=HERO_STATE_COMMON;
		body->stopActionByTag(ANIMATE_RIGHT_TAG);
		this->stopActionByTag(ANIMATE_RIGHT_R_MAP_TAG);
	//	((GameMainScene*)this->getParent())->class1map->stopAllActions();
		walkstate=HERO_STATE_COMMON;
	}
}