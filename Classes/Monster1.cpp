#include "Monster1.h"


Monster1::Monster1(void)
{
	moveTick=0.0f;
	moveTickV=0.0f;
	isMoveTickExuted=false;
	moveType=MOVE_LEFT;
	IS_DIE=false;
//	testsprite=CCSprite::create("CloseSelected.png");
//	testLable=CCMenuItemFont::create("test");
}
void Monster1::onEnter(){
	CCNode::onEnter();
	//	this->setAnchorPoint(ccp(0.5f,0));
		this->setContentSize(CCSizeMake(20,20));
	//CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("monster/Mario-animation.ExportJson");
	//armature = CCArmature::create("Mario-animation");
	//a//rmature->getAnimation()->playWithIndex(0);
	
	//this->addChild(testsprite);
	//sprite->setp
	//armature->setAnchorPoint(ccp(0.5,0));
	//this->addChild(armature);

	monsterbird1=CCSprite::create("monsterbird1.png");
	monsterbird1->setAnchorPoint(ccp(0.5f,0));
	this->addChild(monsterbird1);
	CCScaleTo*action1=CCScaleTo::create(0.4f,1.0f,0.9f);
	CCScaleTo*action2=CCScaleTo::create(0.4f,1.0f,1.0f);
	monsterbird1->runAction(CCRepeatForever::create(CCSequence::create(action1,action2,NULL)));
	//this->setScale(0.85f);
//	this->addChild(testLable);
}
void Monster1::onExit(){
	CCNode::onExit();
}

void Monster1::setDie(){
	//armature->getAnimation()->playWithIndex(1);
	//armature->getAnimation()->
	CCScaleTo*action1=CCScaleTo::create(0.3f,1.0f,0.0f);
	CCCallFuncN*action2=CCCallFuncN::create(monsterbird1,callfuncN_selector(Monster1::setspInVisiable));
	monsterbird1->runAction(CCSequence::create(action1,action2,NULL));
	IS_DIE=true;
}

void Monster1::setDieByGui(){
//	armature->getAnimation()->playWithIndex(2);
	//armature->getAnimation()->
	CCRotateTo*action1=CCRotateTo::create(0.3f,90.0f,90.0f);
	CCCallFuncN*action2=CCCallFuncN::create(monsterbird1,callfuncN_selector(Monster1::setspInVisiable));
	monsterbird1->runAction(CCSequence::create(action1,action2,NULL));
	IS_DIE=true;
}

void Monster1::setDropDown(){
	IS_DIE=true;
	this->setVisible(false);
}

float Monster1::getOriPosX(){
	return this->posx;
}

void Monster1::setOriPosx(float px){
	this->posx=px;
}

void Monster1::tempAction(){
	CCMoveBy*action1=CCMoveBy::create(2,ccp(300,0));
	CCMoveBy*action2=CCMoveBy::create(2,ccp(-300,0));
	CCSequence*sequence=CCSequence::create(action1,action2,NULL);
	CCRepeatForever*repeat=CCRepeatForever::create(sequence);
	this->runAction(repeat);
}

void Monster1::moveTicking(CCTMXTiledMap* pmap){
	if (isMoveTickExuted==true)
	{
		//moveTick--;
		detectColisionH(pmap);
		detectColisionV(pmap);
		switch (moveType)
		{
		case  MOVE_LEFT: {moveTick--; }break;
		case MOVE_RIGHT:{ moveTick++;}break;
		default: {moveTick--;}
			break;
		}
	//	moveTickV++;
	}
	else return;
}

void Monster1::exutedMoveTick(CCTMXTiledMap* pmap){
	isMoveTickExuted=true;
}

void Monster1::detectColisionH(CCTMXTiledMap* pmap){
	//主角与地图水平（左右）图素的碰撞检测
	CCPoint playerpoint = this->getPosition();
	//playerpoint.x=playerpoint.x+pmap->getPositionX();
	CCSize palyersize = this->getContentSize();
	CCTMXTiledMap* map =pmap;
	int indexx=0,indexy=0;
	//	char mch[256];
	CCTMXLayer* layer = map->layerNamed("mainlayer");
	//遍历图素块
	//for(int playery = playerpoint.y - palyersize.height;playery <= playerpoint.y;playery ++)
	{
		//人物左边界
		indexx = (playerpoint.x - palyersize.width / 2-map->getPositionX()) / map->getTileSize().width;
		indexy=(map->getMapSize().height*map->getTileSize().height-playerpoint.y)/map->getTileSize().height-1;
		//		CCLog("inx=%d,iny=%d,playy=%f,mapheight=%f,heroy=%f\n",indexx,indexy,playerpoint.y,map->getMapSize().height
		//			,playerpoint.y);
		int width=map->getMapSize().width;
		int height=map->getMapSize().height;
		if (indexx<0)indexx=0;
		if(indexx>width-1)indexx=width-1;
		if (indexy<0)indexy=0;
		if(indexy>height-1)indexy=height-1;

		CCPoint playerindex = ccp(indexx,indexy);
		int tilegid = layer->tileGIDAt(playerindex);
		//tilegid>0说明碰撞了
		if(tilegid > 0){
			//如果碰撞，设置主角位置
			CCDictionary *tiledic = map->propertiesForGID(tilegid);
			CCString *mvalue = (CCString *)tiledic->objectForKey("type");
			int mv = mvalue->intValue();
			////
			if(mv==TILE_TYPE_TONG||mv==TILE_TYPE_STEEL){
			//	hmove = 0;
				//this->moveTick++;
			moveType=MOVE_RIGHT;
			//	moveType=MOVE_LEFT;
			//	playerpoint.x = (indexx + 1) * map->getTileSize().width + palyersize.width / 2;
			//	this->setPosition(playerpoint);
				//makeUpHeroPos();
		//	CCLOG("MonsterRight:index=%d,posx=%f\n",indexx,playerpoint.x);
			}
			return;
		}
		//人物右边界
		indexx = (playerpoint.x + palyersize.width / 2 - 1-map->getPositionX()) / map->getTileSize().width;
		indexy=(map->getMapSize().height*map->getTileSize().height-playerpoint.y)/map->getTileSize().height-1;


		width=map->getMapSize().width;
		height=map->getMapSize().height;
		if (indexx<0)indexx=0;
		if(indexx>width-1)indexx=width-1;
		if (indexy<0)indexy=0;
		if(indexy>height-1)indexy=height-1;

		playerindex = ccp(indexx,indexy);			
		tilegid = layer->tileGIDAt(playerindex);
		if(tilegid > 0){
			//如果碰撞，设置主角位置
			CCDictionary *tiledic = map->propertiesForGID(tilegid);
			CCString *mvalue = (CCString *)tiledic->objectForKey("type");
			int mv = mvalue->intValue();
			/////
			if(mv==TILE_TYPE_TONG||mv==TILE_TYPE_STEEL){
			//	hmove = 0;
				moveType=MOVE_LEFT;
			//	moveType=MOVE_RIGHT;
			//	CCLOG("MonsterLeft:index=%d,posx=%f\n",indexx,playerpoint.x);
			//	playerpoint.x = (indexx) * map->getTileSize().width - palyersize.width / 2;
			//	this->setPosition(playerpoint);
				//makeUpHeroPos();
			}
			return;
		}
	}
	
}
void Monster1::detectColisionV(CCTMXTiledMap* pmap){
	CCPoint playerpoint = this->getPosition();
	CCSize palyersize = this->getContentSize();
	CCTMXTiledMap* map =pmap;
	int indexx,indexy;
	CCTMXLayer* layer = map->layerNamed("mainlayer");
	//人物下边界
	indexx = (playerpoint.x-map->getPositionX()) / map->getTileSize().width;
	//indexy = map->getMapSize().height - (playerpoint.y) / map->getTileSize().height;
	//CCLog("indexy1=%d\n",indexy);
	indexy=(map->getMapSize().height*map->getTileSize().height-playerpoint.y)/map->getTileSize().height;
	// CCLog("indexy2=%d\n",indexy);
	int width=map->getMapSize().width;
	int height=map->getMapSize().height;
	if (indexx<1)indexx=1;
	if(indexx>width-1)indexx=width-1;
	if (indexy<0){ indexy=0;}
	if(indexy>height-1){ this->setDropDown();indexy=height-1;}

	CCPoint playerindex = ccp(indexx,indexy);
	int tilegid = layer->tileGIDAt(playerindex);
	if(tilegid > 0){
		CCDictionary *tiledic = map->propertiesForGID(tilegid);
		CCString *mvalue = (CCString *)tiledic->objectForKey("type");
		int mv = mvalue->intValue();
		bool ismapunitdestyoyed=(CCSprite*)	(layer->tileAt(ccp(indexx	,indexy)))->isVisible();
		////////////
		if(true&&ismapunitdestyoyed){
			if(moveTickV < 0){
				moveTickV = 0;
				moveTickV = 0;
				playerpoint.y = (map->getMapSize().height - indexy) * map->getTileSize().height;
				this->setPosition(playerpoint);
				//gameplayer->setState(0);
			}
			return;//从此截断运行
		}
	}
	moveTickV -= 0.2;
}
Monster1::~Monster1(void)
{
}
void Monster1::setspVisiable(CCSprite*psprite){
	psprite->setVisible(true);
}

void Monster1::setspInVisiable(CCSprite*psprite){
	psprite->setVisible(false);
}