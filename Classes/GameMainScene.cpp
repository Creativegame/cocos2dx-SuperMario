#include "GameMainScene.h"
#include <math.h>
#include "ChooseClassScene.h"
using namespace cocos2d;

enum 
{
	kTagTileMap = 1,
	kTagWhatBlink=2,
};

 

CCScene* GameMainScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	GameMainScene *layer = GameMainScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameMainScene::init()
{
	this->setKeypadEnabled(true);
	//地图背景层
	isInited=false;
	//CCSprite *bg = CCSprite::create("background.png");
	//bg->setScale(1.5f);
	//addChild(bg, 0);
	//地图初始化
	CCSprite*bg=NULL;
	CCTMXTiledMap *map ;//= CCTMXTiledMap::create("class1map.tmx");
//	WORLD_TAG=SCENE_NUM;
    WORLD_TAG=ChooseClass::getWorldTag();
	switch (WORLD_TAG)
	{
	case 11:{ map=CCTMXTiledMap::create("class1map.tmx");bg=CCSprite::create("simplebglight.png");}break;
	case 12:{ map=CCTMXTiledMap::create("class2map.tmx");}break;
	case 13:{ map=CCTMXTiledMap::create("class3map.tmx");bg=CCSprite::create("simplebglight.png");}break;
	case 14:{ map=CCTMXTiledMap::create("class4map.tmx");}break;
	default:{map= CCTMXTiledMap::create("class1map.tmx");}
		break;
	}
	if (bg!=NULL)
	{
		this->addChild(bg,0);
		bg->setPosition(ccp(640,360));
		bg->setScale(10.0f);
	}
	//CCLOG("world tag %d",WORLD_TAG);
	addChild(map, 0, kTagTileMap);
	CCSize s = map->getContentSize();
	int mapWidth = map->getMapSize().width * map->getTileSize().width;
	int mapHeight = map->getMapSize().height * map->getTileSize().height;
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	map->setPosition(ccp(0,0));
	CCTMXLayer*layer=map->layerNamed("mainlayer");

	//初始化主角
	gameplayer = new GameObjHero();
	//enemy = CCSprite::create("SpinningPeas.png");
	map->addChild(gameplayer, map->getChildren()->count() );
	//map->addChild(enemy, map->getChildren()->count() );
	//初始化敌人
	//enemy->setPosition(ccp(winSize.width/2 + 80,32));
	//enemy->setAnchorPoint(ccp(0.5f,0));
	CCOrbitCamera*camera=CCOrbitCamera::create(2,1,0,0,180,0,0);
	//enemy->runAction(camera);
	gameplayer->setPosition(ccp(100,560));
	gameplayer->setAnchorPoint(ccp(0,0));
	setTouchEnabled(true);
	scheduleUpdate();
	hmove = 0;
	vmove = 0;
	enemymovetick = 0;
	offset=ccp(0,0);
	//初始化金币
	bonusMoney=new BonusMogu();
	this->addChild(bonusMoney,2);
	bonusMoney->setPosition(ccp(-200,-200));
	//从地图初始化怪兽_蘑菇
	gameMonsterbirds=CCArray::create();
	gameMonsterguis=CCArray::create();
	gameBonusMogus=CCArray::create();
	CCTMXObjectGroup*monsterGroup=map->objectGroupNamed("monster");

	
	///CCTMXObjectGroup *objGroup = map_physical->tmxMap->objectGroupNamed("shan");
	CCArray *objArray = monsterGroup->getObjects();


	if (objArray && objArray->count() > 0)
	{
		CCObject* pObj = NULL;
		CCARRAY_FOREACH(objArray, pObj)
		{//pObj是每次循环中从objArray转型来的对象指针；
			CCDictionary* dict = (CCDictionary*)pObj;
			const char* keytype="type";
			int type = ((CCString*)dict->objectForKey("type"))->intValue();
			//CCLOG("%d\n",type);
			if (type)
			{
				switch (type)
				{
				case 1 :{
					float posx=((CCString*)dict->objectForKey("x"))->floatValue();
					float posy=((CCString*)dict->objectForKey("y"))->floatValue();
					//CCSprite*temp=CCSprite::create("monsterbird1.png");
					Monster1*temp=new Monster1();
					this->addChild(temp,2);
					temp->setPosition(ccp(posx,posy));
					//CCLOG("temp....x=%f\n",posx);
					temp->setOriPosx(posx);
					//temp->tempAction();
				//	addChild(temp->testsprite);
					gameMonsterbirds->addObject(temp);
						}
					break;
				case 2:{
					float posx=((CCString*)dict->objectForKey("x"))->floatValue();
					float posy=((CCString*)dict->objectForKey("y"))->floatValue();
				//	CCSprite*temp=CCSprite::create("monstergui1.png");
					Monster2*temp=new Monster2();
					this->addChild(temp,2);
					temp->setPosition(ccp(posx,posy));
					//CCLOG("temp....x=%f\n",posx);
					temp->setOriPosx(posx);
					//temp->tempAction();
					//	addChild(temp->testsprite);
					gameMonsterguis->addObject(temp);
					   }
					break;
				case 3:{
					float posx=((CCString*)dict->objectForKey("x"))->floatValue();
					float posy=((CCString*)dict->objectForKey("y"))->floatValue();
					BonusMogu*temp=new BonusMogu();
					this->addChild(temp,2);
					temp->setPosition(ccp(posx,posy));
					//CCLOG("temp....x=%f\n",posx);
					temp->setOriPosx(posx);
					//temp->tempAction();
					//	addChild(temp->testsprite);
					gameBonusMogus->addObject(temp);
					   }break;

				case 4:{
					float posx=((CCString*)dict->objectForKey("x"))->floatValue();
					float posy=((CCString*)dict->objectForKey("y"))->floatValue();
				winflag=new WinFlag();
					this->addChild(winflag,2);
					winflag->setPosition(ccp(posx,posy));
					//CCLOG("temp....x=%f\n",posx);
					winflag->setOriPosx(posx);
					   }break;

				}
			}

			gameMonsterbirds->retain();
			gameMonsterguis->retain();
			gameBonusMogus->retain();
//game score
			gamescore=new GameScore();
			this->addChild(gamescore);
			//gamescore->setWorld(31);
			this->runAction(CCSequence::create(CCDelayTime::create(1)	,
				CCCallFunc::create(this,callfunc_selector(GameMainScene::initSomeDatas)),
				NULL
				));

		//	CCLOG("M1 size = %d",gameMonsterbirds->count());
			
			/*CCDictElement *keyString = NULL;
			CCDICT_FOREACH(spawnPoint, keyString)
			{
				const char *xps =  keyString->getStrKey();
				CCLog("dict:key %s", xps);
				CCString  *xps1 =  (CCString *)(keyString->getObject());
				CCLog("dict:value %f", xps1->floatValue());
			}*/
		}
	}


	//主角矩形区域大小
	ownsize = CCSizeMake(100,100);
	//敌人矩形区域大小
	othersize = CCSizeMake(32,32);
	//是否是受伤状态
	isreduce = false;

	//handle map unit animate
	CCTMXLayer*testLayer=map->layerNamed("mainlayer");
	/**/for(int i=0; i<(map->getMapSize().width);i++)
		for(int j=0; j<(map->getMapSize().height);j++){
			CCPoint temppos=ccp(i,j);
			int tilegid=testLayer->tileGIDAt(temppos);
			/**/if(tilegid>0){
				CCDictionary *tiledic = map->propertiesForGID(tilegid);
				CCString *mvalue = (CCString *)tiledic->objectForKey("type");
				int mv = mvalue->intValue();
				if(mv == TILE_TYPE_WHAT){
					CCAnimation*animation=CCAnimation::create();
					animation->addSpriteFrameWithFileName("mapunit/what.png");
					animation->addSpriteFrameWithFileName("mapunit/what2.png");
					animation->setDelayPerUnit(0.2f);
					//	animation->setRestoreOriginalFrame(true);
					short mRGB=-120;
					CCTintBy*tintby=CCTintBy::create(0.01f,mRGB,mRGB,mRGB);
					CCTintBy*tintby1=CCTintBy::create(0.01f,-mRGB,-mRGB,-mRGB);
					CCRepeatForever*	maction=
						CCRepeatForever::create(CCSequence::create(tintby,CCDelayTime::create(1.0f),
						tintby1,CCDelayTime::create(1.0f),NULL));
					maction->setTag(kTagWhatBlink);
					CCRepeatForever*	maction1=CCRepeatForever::create(CCAnimate::create(animation));
					(CCSprite*)	(testLayer->tileAt(ccp(i,j)))->runAction(maction);
				}
			}
		}

		donedialog=new DoneDialog();
 
		this->addChild(donedialog,5);

		donedialog->setVisible(false);

		diedialog=new DieDialog();
		this->addChild(diedialog,5);
		diedialog->setVisible(false);

		backdialog=new QuitDialog();
		this->addChild(backdialog,5);
		backdialog->setVisible(false);

		return true;
}

void GameMainScene::initSomeDatas(void ){
	gamescore->setWorld(WORLD_TAG);
	gamescore->addLife(0);
	isInited=true;
}

int  GameMainScene::colisiionType(CCPoint pos1,CCPoint pos2,CCSize size1,CCSize size2,CCTMXTiledMap*pmap){
	float w1=size1.width;
	float h1=size1.height;
	float w2=size2.width;
	float h2=size2.height;
	//pos1=convertToWindowSpace(pos1);         
	//pos1.x=pos1.x+pmap->getPositionX();
	//pos2.x=pos2.x+pmap->getPositionX();
	//pos2=convertToWorldSpace(pos2);
	bool isHeroU2D;//判断主角是否在下落以及是否在怪物头顶一定范围
	isHeroU2D=(vmove<0&&((pos1.y)-(pos2.y+h2))<10&&((pos1.y)-(pos2.y+h2))>-10);
	//float MIN(h1,h2);
	if(abs(pos1.x - pos2.x) < (w1 + w2)&& abs(pos1.y - pos2.y) <MIN( h1,h2)&&isHeroU2D){
	//	CCLOG("TEMP_U2D num=%f",(pos1.y)-(pos2.y+h2));
		return COLI_TYPE_U2D;

	}
	 if ((abs(pos1.x - pos2.x) <( w1 + w2)) && (abs(pos1.y - pos2.y) <MIN( h1,h2))&&(!isHeroU2D))
	{
	//CCLOG("x1=%f,y1=%f,x2=%f,y2=%f",pos1.x,pos1.y,pos2.x,pos2.y);
		//CCLOG("w1=%f,h1=%f,xw2=%f,h2=%f",w1,h1,w2,h2);
	//	CCLOG("TEMP_LR num=%f",(pos1.y)-(pos2.y+h2));
		return COLI_TYPE_LR;		
	}
   return COLI_TYPE_NO;
}

void GameMainScene::heroColisionwithMonster(CCTMXTiledMap*pmap){
	for (int i=0;i<gameMonsterbirds->count();i++)
	{
		Monster1* temp=	(Monster1*) gameMonsterbirds->objectAtIndex(i);
		CCPoint pos1=gameplayer->getPosition();
		CCPoint pos2=temp->getPosition();
		pos1.x=pos1.x+pmap->getPositionX();
	if(!temp->IS_DIE){	switch (colisiionType(pos1,pos2,
		gameplayer->getContentSize(),
		temp->getContentSize(),pmap))
		{
		case COLI_TYPE_LR:{
				if (gameplayer->hurt_able)
			{
				gameplayer->setHurt();
				gamescore->addLife(-1);
					CCLOG("COLI_LR,index=%d\n",i);
			}
						  }  break;
		case COLI_TYPE_U2D:{
		//	if(!temp->IS_DIE){
		temp->setDie();
		gamescore->addnumber(100);
		vmove=2;
		CCLOG("COLI_U2D,index=%d\n",i);
								   }break;
		default:
			break;
		}
	}
	}
	gameMonsterbirds->retain();

	for (int i=0;i<gameMonsterguis->count();i++)
	{
		Monster2* temp=	(Monster2*) gameMonsterguis->objectAtIndex(i);
		CCPoint pos1=gameplayer->getPosition();
		CCPoint pos2=temp->getPosition();
		pos1.x=pos1.x+pmap->getPositionX();
		if(!temp->IS_DIE)	{
			switch (colisiionType(pos1,pos2,
			gameplayer->getContentSize(),
			temp->getContentSize(),pmap))
		{
		case COLI_TYPE_LR:{
			if (gameplayer->hurt_able)
			{
				gameplayer->setHurt();
					gamescore->addLife(-1);
				//CCLOG("COLI_LR,index=%d\n",i);
			}
						  }  break;
		case COLI_TYPE_U2D:{
			//	if(!temp->IS_DIE){
			temp->setDie();
		gamescore->addnumber(200);
			vmove=2;
		//	CCLOG("COLI_U2D,index=%d\n",i);
						   }break;
		default:
			break;
		}
		}
	}
	gameMonsterguis->retain();
	//龟背和monster1碰撞
	for (int i=0;i<gameMonsterguis->count();i++)
	{
		Monster2*mons2=(Monster2*)gameMonsterguis->objectAtIndex(i);
		if (mons2->IS_DIE)
		{
			for (int j=0;j<gameMonsterbirds->count();j++)
		{
			Monster1*mons1=(Monster1*)gameMonsterbirds->objectAtIndex(j);
			if(!mons1->IS_DIE){
				if(		iscollision((CCSprite*)mons1,(CCSprite*)mons2))
					{mons1->setDieByGui();
				gamescore->addnumber(100);}
			}
			}
		}

		/*if (iscollision((CCSprite*)gameplayer,(CCSprite*)winflag)&&!donedialog->isVisible())
		{
			donedialog->setVisible(true);
		}*/

		CCPoint pos1=gameplayer->getPosition();
		CCPoint pos2=winflag->getPosition();
		pos1.x=pos1.x+pmap->getPositionX();
		if(!donedialog->isVisible()){	
			switch (colisiionType(pos1,pos2,
			gameplayer->getContentSize(),
			winflag->getContentSize(),pmap))
			{
			case COLI_TYPE_LR:{
				donedialog->setVisible(true);
							  }break;
			}
			}
		{

	}

	//主角和蘑菇碰撞

	for (int i=0;i<gameBonusMogus->count();i++)
	{
		BonusMogu*temp=(BonusMogu*)gameBonusMogus->objectAtIndex(i);
		if (!temp->IS_GETED)
		{

		/*	if(		iscollision((CCSprite*)temp,(CCSprite*)gameplayer))
			{temp->setGeted();
			gamescore->addnumber(1000);}*/
			BonusMogu* temp=	(BonusMogu*) gameBonusMogus->objectAtIndex(i);
			CCPoint pos1=gameplayer->getPosition();
			CCPoint pos2=temp->getPosition();
			pos1.x=pos1.x+pmap->getPositionX();
			switch (colisiionType(pos1,pos2,gameplayer->getContentSize(),temp->getContentSize(),pmap))
			{
			case COLI_TYPE_LR:{
				if (!temp->IS_GETED){temp->setGeted();
				gamescore->addnumber(1000);
				gamescore->addLife(1);
				}
							  }break;
			case  COLI_TYPE_U2D:{
			if (!temp->IS_GETED)	{temp->setGeted();
			gamescore->addnumber(1000);
			gamescore->addLife(1);
			}
								}break;
			default:
				break;
			}
		
		}
	}
	}
}

void GameMainScene::enemytick(){
	//敌人自动在自己的区域内运行逻辑
	CCPoint enemypoint = enemy->getPosition();
	if(enemymovetick >= 0 && enemymovetick <= 20){
		enemymovetick ++;
		enemypoint.x += 2;
	}else if(enemymovetick > 20 && enemymovetick <= 60){
		enemymovetick ++;
		enemypoint.x -= 2;
	}else if(enemymovetick > 60 && enemymovetick <= 80){
		enemymovetick ++;
		enemypoint.x += 2;
	}else if(enemymovetick > 80){
		enemymovetick = 0;
	}
//	enemy->setPosition(enemypoint);

		
}
bool GameMainScene::iscollision(CCSprite *mysprite,CCSprite *testsprite)
{
	//矩形区域是否碰撞
	CCPoint ownp = mysprite->getPosition();
	CCPoint otherp = testsprite->getPosition();
	if(abs(ownp.x - otherp.x) <= ownsize.width/2 + othersize.width/2 
		&& ownp.y - otherp.y <= othersize.height/2
		&& ownp.y - otherp.y >= -1 * ownsize.height/2){
			return true;
	}
	return false;
}
void GameMainScene::resetreduce(float dt){
	isreduce = false;
}
void GameMainScene::update(float dt)
{

	if (isInited&&!diedialog->isVisible()&&gamescore->lifeSum<=0)
	{
		diedialog->setVisible(true);
	}

	CCTMXTiledMap* map = (CCTMXTiledMap*) getChildByTag(kTagTileMap);
	//主角与地图的水平和数值碰撞检测
	playermaphcollision();
	// 落下时的垂直碰撞 主角
	playermapvcollision();
	playermapvDowncollision();
	
	//主角与怪兽的碰撞检测

	
	//设置主角位置
	CCPoint playerpoint = gameplayer->getPosition();
	playerpoint.y += vmove;
	playerpoint.x += 1 * hmove;
	//enemytick();
	gameplayer->setPosition(playerpoint);
	//如果主角不是受伤状态，检测是否与敌人碰撞
	/*if(! isreduce && iscollision(gameplayer,enemy)){
	//设置为受伤状态
	CCActionInterval*  action = CCBlink::create(5,10);
	gameplayer->runAction(action);
	schedule(schedule_selector(GameMainScene::resetreduce), 5.0f);
	isreduce = true;
	hmove = 0;
	}*/

	//地图随主角移动逻辑
	//CCTMXTiledMap* map = (CCTMXTiledMap*) getChildByTag(kTagTileMap);
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	int mapWidth = map->getMapSize().width * map->getTileSize().width;
	int mapHeight = map->getMapSize().height * map->getTileSize().height;
	//获得地图相对主角位置，并设置地图位置
	float deltax = playerpoint.x - winSize.width/2;
	float deltay = playerpoint.y - 32;
	if(-deltax > 0){
		deltax = 0;
	}
	if(-deltax < -mapWidth + winSize.width){
		deltax = mapWidth - winSize.width;
	}
	if(-deltay > 0){
		deltay = 0;
	}
	if(-deltay < -mapHeight + winSize.height){
		deltay = mapHeight - winSize.height;
	}
	map->setPosition(ccp(- deltax,-deltay));
	makeUpHeroPos();


	//设置怪兽位置，使之与地图无相对位移
	refreshMonsterPosx(map);
	heroColisionwithMonster(map);

}

/*
void GameMainScene::makeUpTileIndex(int indexx,int indexy, CCTMXTiledMap*map){
int width=map->getMapSize().width;
int height=map->getMapSize().height;
if (indexx<0)indexx=0;
if(indexx>width-1)indexx=width-1;
if (indexy<0)indexy=0;
if(indexy>height-1)indexy=height-1;
}*/
void GameMainScene::makeUpHeroPos(){
	int width=CCDirector::sharedDirector()->getWinSize().width;

	int herowidth=gameplayer->getContentSize().width;

	if(gameplayer->getPositionX()<0+herowidth/2)
	{hmove=0;} 

}

void GameMainScene::refreshMonsterPosx(CCTMXTiledMap* pmap){
	//updateTimes++;
	CCTMXTiledMap* map = (CCTMXTiledMap*) getChildByTag(kTagTileMap);
	for (int i=0;i<gameMonsterbirds->count();i++)
	{

		Monster1*temp=((Monster1*)gameMonsterbirds->objectAtIndex(i));
		//temp->moveTick--;//在地图上移动；
		if (temp->getPositionX()<1280&&temp->getPositionX()>1000
			||temp->getOriPosX()<1000
					)
		{
			temp->exutedMoveTick(pmap);
		}
		if(!temp->IS_DIE)
		{
		temp->moveTicking(pmap);
		temp->setPositionX(temp->getOriPosX()+pmap->getPositionX()+temp->moveTick);
		temp->setPositionY(temp->getPositionY()+temp->moveTickV);
		}
		}
		gameMonsterbirds->retain();

		for (int i=0;i<gameMonsterguis->count();i++)
		{

			Monster2*temp=((Monster2*)gameMonsterguis->objectAtIndex(i));
			//temp->moveTick--;//在地图上移动；
			if (temp->getPositionX()<1280&&temp->getPositionX()>1000
					||temp->getOriPosX()<1000
				)
			{
				temp->exutedMoveTick(pmap);
			}
			temp->moveTicking(pmap);
			temp->setPositionX(temp->getOriPosX()+pmap->getPositionX()+temp->moveTick);
			temp->setPositionY(temp->getPositionY()+temp->moveTickV);
		}
		gameMonsterguis->retain();

		for (int i = 0; i < gameBonusMogus->count(); i++)
		{
			BonusMogu*temp=(BonusMogu*) gameBonusMogus->objectAtIndex(i);
					temp->setPositionX(temp->getOriPosX()+pmap->getPositionX());
		}

		winflag->setPositionX(winflag->getOriPosX()+pmap->getPositionX());

}

void GameMainScene::playermaphcollision(){
	//主角与地图水平（左右）图素的碰撞检测
	CCPoint playerpoint = gameplayer->getPosition();
	CCSize palyersize = gameplayer->getContentSize();
	CCTMXTiledMap* map = (CCTMXTiledMap*) getChildByTag(kTagTileMap);
	int indexx=0,indexy=0;
	//	char mch[256];
	CCTMXLayer* layer = map->layerNamed("mainlayer");
	//遍历图素块
	//for(int playery = playerpoint.y - palyersize.height;playery <= playerpoint.y;playery ++)
	{
		//人物左边界
		indexx = (playerpoint.x - palyersize.width / 2) / map->getTileSize().width;
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
			if(mv==TILE_TYPE_TONG||mv==TILE_TYPE_STEEL||mv==TILE_TYPE_WHAT){
				hmove = 0;
				playerpoint.x = (indexx + 1) * map->getTileSize().width + palyersize.width / 2;
				gameplayer->setPosition(playerpoint);
				//makeUpHeroPos();
			//	CCLOG("Collision");
			//	CCPoint pos1=gameplayer->getPosition();
			//	CCLOG("playx=%f,playy=%f",pos1.x,pos1.y);
			}
			return;
		}
		//人物右边界
		indexx = (playerpoint.x + palyersize.width / 2 - 1) / map->getTileSize().width;
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
				hmove = 0;
				playerpoint.x = (indexx) * map->getTileSize().width - palyersize.width / 2;
				gameplayer->setPosition(playerpoint);
				//makeUpHeroPos();
			}
			return;
		}
	}
}

void GameMainScene::setDropDown(){
	//主角在下落且主角以下没有地图是判定为主角掉落悬崖
	 
}

void GameMainScene::playermapvcollision(){
	//主角与地图竖直（下）图素的碰撞检测
	CCPoint playerpoint = gameplayer->getPosition();
	CCSize palyersize = gameplayer->getContentSize();
	CCTMXTiledMap* map = (CCTMXTiledMap*) getChildByTag(kTagTileMap);
	int indexx,indexy;
	CCTMXLayer* layer = map->layerNamed("mainlayer");
	//人物下边界
	indexx = (playerpoint.x) / map->getTileSize().width;
	//indexy = map->getMapSize().height - (playerpoint.y) / map->getTileSize().height;
	//CCLog("indexy1=%d\n",indexy);
	indexy=(map->getMapSize().height*map->getTileSize().height-playerpoint.y)/map->getTileSize().height;
	// CCLog("indexy2=%d\n",indexy);
	//处理掉落悬崖的逻辑
	int width=map->getMapSize().width;
	int height=map->getMapSize().height;
	if (indexx<1)indexx=1;
	if(indexx>width-1)indexx=width-1;
	if (indexy<0)indexy=0;
	if(indexy>height-1){
		//indexx--;
		//hmove-=96;
		indexy=height-1;
	//	indexx=indexx-1;
		if(gameplayer->hurt_able)
		{	gameplayer->setHurt();
			gamescore->addLife(-1);
		}
			//gameplayer->setState(0);
			vmove=0;
			hmove=0;
			gameplayer->setPositionY(750);

			gameplayer->setPositionX(gameplayer->getPositionX()-48);
		//	gameplayer->setHurt();
 
	}

	CCPoint playerindex = ccp(indexx,indexy);
	int tilegid = layer->tileGIDAt(playerindex);
	if(tilegid > 0){
		CCDictionary *tiledic = map->propertiesForGID(tilegid);
		CCString *mvalue = (CCString *)tiledic->objectForKey("type");
		int mv = mvalue->intValue();
		bool ismapunitdestyoyed=(CCSprite*)	(layer->tileAt(ccp(indexx	,indexy)))->isVisible();
		////////////
		if(true&&ismapunitdestyoyed&&mv!=1007){
			if(vmove < 0){
				vmove = 0;
				hmove = 0;
				playerpoint.y = (map->getMapSize().height - indexy) * map->getTileSize().height;
				gameplayer->setPosition(playerpoint);
				gameplayer->setState(0);
			}
			return;//从此截断运行
		}
	}
	vmove -= 0.2;
}

void GameMainScene::playermapvDowncollision(){
	//主角与地图竖直（下）图素的碰撞检测
	CCPoint playerpoint = gameplayer->getPosition();
	CCSize palyersize = gameplayer->getContentSize();
	CCTMXTiledMap* map = (CCTMXTiledMap*) getChildByTag(kTagTileMap);
	int indexx,indexy;
	CCTMXLayer* layer = map->layerNamed("mainlayer");
	//人物shang边界
	indexx = (playerpoint.x) / map->getTileSize().width;
	//indexy = map->getMapSize().height + (playerpoint.y) / map->getTileSize().height;
	indexy=(map->getMapSize().height*map->getTileSize().height-playerpoint.y
		-gameplayer->getContentSize().height		)/map->getTileSize().height;
	//CCLog("indexx=%d\n",indexx);
	int width=map->getMapSize().width;
	int height=map->getMapSize().height;
	if (indexx<1)indexx=1;
	if(indexx>width-1)indexx=width-1;
	if (indexy<0)indexy=0;
	if(indexy>height-1)indexy=height-1;

	CCPoint playerindex = ccp(indexx,indexy);
	//	CCLog("inx=%d,iny=%d\n",indexx,indexy);		
	int tilegid = layer->tileGIDAt(playerindex);
	if(tilegid > 0){

		CCDictionary *tiledic = map->propertiesForGID(tilegid);
		CCString *mvalue = (CCString *)tiledic->objectForKey("type");
		int mv = mvalue->intValue();

	//	CCLog("indexx=%d,mv=%d,herohead=%f\n",indexx,mv,gameplayer->getPositionY()+68);
		////////////
		bool ismapunitdestyoyed=(CCSprite*)	(layer->tileAt(ccp(indexx	,indexy)))->isVisible();
		if(true&&ismapunitdestyoyed){
			if(vmove > 0&&mv!=1007&&mv!=1000){
				//v>0,表示正在向上
				vmove = -vmove;
				hmove = 0;
				//在此运行碰撞图块的逻辑//h还要设置地图图块被打掉的属性
				/*CCMoveBy*maction1=CCMoveBy::create(1.0,ccp(0,100));
				CCCallFuncN*maction2=CCCallFuncN::create(	(CCSprite*)	(layer->tileAt(ccp(indexx	,indexy)))
					,callfuncN_selector(GameMainScene::setTileInvisiable));
				(CCSprite*)	(layer->tileAt(ccp(indexx	,indexy)))->runAction(CCSequence::create(maction1,maction2,NULL));*/
				runColisionedAction((CCSprite*)	(layer->tileAt(ccp(indexx	,indexy))),mv,map);
				//map->set

				//	layer->removeTileAt();
				//	layer->add
				//	isMapUnitDestroyed->objectAtIndex(tilegid);
				//	isMapUnitDestroyed->removeObjectAtIndex(tilegid);
				//	isMapUnitDestroyed->insertObject(CCString::create("true"),tilegid);
				/*playerpoint.y = (map->getMapSize().height - indexy
				-map->getTileSize().height-gameplayer->getContentSize().height) * map->getTileSize().height;
				gameplayer->setPosition(playerpoint);*/
				gameplayer->setState(0);
			}
			return;
		}
	}
	//	vmove += 0.2;
}

bool GameMainScene::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	/*CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);*/

	CCPoint m_tBeginPos = touch->getLocationInView();	
	m_tBeginPos = CCDirector::sharedDirector()->convertToGL( m_tBeginPos );
	CCPoint playerpoint = gameplayer->getPosition();
	CCSize palyersize = gameplayer->getContentSize();
	CCTMXTiledMap* map = (CCTMXTiledMap*) getChildByTag(kTagTileMap);
	CCPoint mappoint = map->getPosition();
	//根据触摸点的位置判断人物移动方向
	if(m_tBeginPos.x < playerpoint.x - palyersize.width / 2 + mappoint.x){
		//	hmove = -1;//左移
	}else if(m_tBeginPos.x > playerpoint.x + palyersize.width / 2 + mappoint.x){
		//	hmove = 1;//右移
	}else{
		//	hmove = 0;
	}
	if(m_tBeginPos.y > playerpoint.y + palyersize.height + mappoint.y){
		//vmove = 6;//上跳
	}else{
		//	vmove = 0;
	}

//	CCLog("touch begin");
	CCPoint touchPoint = touch->getLocation();
	offset.x = touchPoint.x;
	offset.y = touchPoint.y;
	return true;   

}
void GameMainScene::runColisionedAction(CCSprite*psprite,short tiltType,CCTMXTiledMap*pMap){
	CCMoveBy*maction1=CCMoveBy::create(0.5,ccp(0,100));
	CCCallFuncN*maction2=CCCallFuncN::create(psprite
		,callfuncN_selector(GameMainScene::setTileInvisiable));
	CCSkewBy*skew=CCSkewBy::create(0.5,50,50);
	CCOrbitCamera*camera=CCOrbitCamera::create(2,1,0,0,180,0,0);
	CCScaleTo*scale=CCScaleTo::create(0.5,1,0);
	CCSequence*bickAction =CCSequence::create(maction1,maction2,NULL);
	CCMoveBy*maction3=CCMoveBy::create(0.2,ccp(0,10));
	CCMoveBy*maction4=CCMoveBy::create(0.2,ccp(0,-10));
	CCSequence*whatAction =CCSequence::create(maction3,maction4,NULL);
	switch (tiltType)
	{
	case TILE_TYPE_BICK :{
		psprite->runAction(bickAction);
		psprite->runAction(scale);
	//	gameplayer->runAction(camera);
						 }
		break;
	case TILE_TYPE_WHAT:{
		if(psprite->getOpacity()!=254){
		psprite->runAction(whatAction);
		CCPoint pos=psprite->getPosition();
		pos.x=pos.x+pMap->getPositionX();
		CCSprite*temp=CCSprite::create("mapunit/what3.png");
		CCTexture2D*texture=temp->getTexture();
		{
			bonusMoney->runMoneyAnim(pos);
			psprite->setColor(ccc3(100,100,100));
			//psprite->stopAllActions();
			psprite->stopActionByTag(kTagWhatBlink);
			psprite->setOpacity(254);
			gamescore->addMoney(1);
		}		
		}
						}
		break;
	}
}
void GameMainScene::setTileInvisiable(CCNode*pnode){
	pnode->setVisible(false);
}
void GameMainScene::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
//	CCLog("touch move");
}
void GameMainScene::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCPoint touchPoint = touch->getLocation();
	///////
//	CCLOG("touchx=%f,touchy=%f",touchPoint.x,touchPoint.y);

	int x = touchPoint.x - offset.x; 
	int y = touchPoint.y - offset.y;
	if(abs(x)<TOUCH_CLICK_LIM&&abs(y)<TOUCH_CLICK_LIM)
	{	TOUCHMODE=TOUCH_MODE_ClICK;}
	if(abs(x)>TOUCH_ACTION_LIM&&abs(y)<abs(x)&&x>0)
	{	TOUCHMODE=TOUCH_MODE_RIGHT;}
	if(abs(y)>TOUCH_ACTION_LIM&&abs(x)<abs(y)&&y>0)
	{	TOUCHMODE=TOUCH_MODE_UP;}
	if(abs(x)>TOUCH_ACTION_LIM&&abs(y)<abs(x)&&x<0)
	{	TOUCHMODE=TOUCH_MODE_LEFT;}
	//	CCLog("touch end");
	switch (TOUCHMODE)
	{
	case TOUCH_MODE_ClICK:{
		gameplayer->setState(0);
		vmove=0;
		hmove=0;
						  }break;
	case TOUCH_MODE_UP:{
		//	hero->jumpBegin();
		if(vmove==0)
		{vmove=9;
		gameplayer->setState(1);
		}
					   }break;
	case TOUCH_MODE_DOWN:{

						 }break;
	case TOUCH_MODE_LEFT:{
		//	CCLog("TOUCH_MODE_Left");
		hmove = -2;

		//	hero->walkLeftEnd();
		//		hero->walkLeftBegin();
						 }break;
	case TOUCH_MODE_RIGHT:{
		//	CCLog("TOUCH_MODE_RIGHT");
		hmove = 2;
		gameplayer->setState(2);
		//	hero->walkRightEnd();
		//	hero->walkRightBegin();

						  }break;
	default:{hmove=0;vmove=0;}
			break;
	}
}

void GameMainScene::touchDelegateRetain()
{
	this->retain();
}

void GameMainScene::touchDelegateRelease()
{
	this->release();
}
void GameMainScene::registerWithTouchDispatcher(){
	CCDirector* pDirector = CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this,0, false);
}

void GameMainScene::nextWorld(){
	if (WORLD_TAG>13)
	{
	}

	else{
		// SCENE_NUM+=1;
		// WORLD_TAG+=1;
		 //ChooseClass::scene_num=
	 	//GameMainScene*gamemainscene=GameMainScene::create();
		//CCDirector::sharedDirector()->replaceScene(gamemainscene->scene());
		ChooseClass*p=ChooseClass::create();
		CCUserDefault*handler=CCUserDefault::sharedUserDefault();
		
		switch (WORLD_TAG)
		{
		case 11:{
			handler->setIntegerForKey("world12lock",1);
		//	p->gotoclass2(this);
			CCScene*pscene=ChooseClass::scene();
			CCDirector::sharedDirector()->replaceScene(pscene);
				}break;
		case 12:{	
			handler->setIntegerForKey("world13lock",1);
		//	p->gotoclass3(this);
			CCScene*pscene=ChooseClass::scene();
				CCDirector::sharedDirector()->replaceScene(pscene);
				}break;
		case 13:{
				handler->setIntegerForKey("world14lock",1);
		//	p->gotoclass4(this);
				CCScene*pscene=ChooseClass::scene();
					CCDirector::sharedDirector()->replaceScene(pscene);
				}break;
		default:{}break;
	}
		 
} ;
}

void GameMainScene::keyBackClicked(){
	//	if (backdialog->getPositionY()<500)
	{
		//backdialog->runAction(CCMoveTo::create(0.4,ccp(backdialog->getPositionX(),200)));
		if (!backdialog->isVisible())
		{
			backdialog->setVisible(true);
		}
	}


}

void GameMainScene::keyMenuClicked(){

}