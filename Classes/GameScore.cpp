#include "GameScore.h"
GameScore::GameScore(void)
{
}

GameScore::~GameScore(void)
{
}
void GameScore::onExit()
{
	CCNode::onExit();
}
void GameScore::onEnter()
{
	CCNode::onEnter();
	CCSize size = CCDirector::sharedDirector()->getWinSize(); 
	this->setContentSize(size);
	bits = CCArray::create();
	moneybits=CCArray::create();
	worldbits=CCArray::create();
	lifebits=CCArray::create();
	//world title
	CCSprite*world=CCSprite::create("world.png");
	world->setPosition(ccp(60,size.height-32));
	this->addChild(world);
	
	//第三位
			CCSprite * shu = CCSprite::create("shu.png");
			ui = shu->getTexture();
			shu->setScale(1.0);
			shu->setTextureRect(CCRectMake(234,0,26,31));
			shu->setPosition(ccp(200 - 15 - 0* 30,size.height - 32));
			worldbits->addObject(shu);
			addChild(shu);
	//第二位
			CCSprite*connect=CCSprite::create("shuconnect.png");
			connect->setScale(1.0f);
			connect->setTextureRect(CCRectMake(0,0,26,31));
			connect->setPosition(ccp(200 - 15 - 1* 20,size.height - 32));
			worldbits->addObject(connect);
			addChild(connect);
	//第一位
			 shu = CCSprite::create("shu.png");
			ui = shu->getTexture();
			shu->setScale(1.0);
			shu->setTextureRect(CCRectMake(234,0,26,31));
			shu->setPosition(ccp( 200 - 2* 30,size.height - 32));
			worldbits->addObject(shu);
			addChild(shu);

	worldbits->retain();
//life title
	CCSprite*life=CCSprite::create("life.png");
	life->setPosition(ccp(380,size.height-32));
	this->addChild(life);
 
	for (int i=0;i<2;i++)
	{
		shu = CCSprite::create("shu.png");
		ui = shu->getTexture();
		shu->setScale(1.0);
		shu->setTextureRect(CCRectMake(234,0,26,31));
		shu->setPosition(ccp(520 - 15 - i* 20,size.height - 32));
		lifebits->addObject(shu);
		addChild(shu);
	}
	//第er位
	connect=CCSprite::create("shusquare.png");
	connect->setScale(1.0f);
	connect->setTextureRect(CCRectMake(0,0,26,31));
	connect->setPosition(ccp(520 - 15 - 2* 20,size.height - 32));
	lifebits->addObject(connect);
	addChild(connect);
	//第一位
	shu = CCSprite::create("mogu.png");
	ui = shu->getTexture();
	shu->setScale(0.5f);
//	shu->setTextureRect(CCRectMake(234,0,26,31));
	shu->setPosition(ccp( 520 - 80,size.height - 32));
	lifebits->addObject(shu);
	addChild(shu);

	lifebits->retain();
	lifeSum=3;

	//Money title
	CCSprite*money=CCSprite::create("moneytitle.png");
	money->setPosition(ccp(670,size.height-32));
	this->addChild(money);

	for (int i=0;i<2;i++)
	{
		shu = CCSprite::create("shu.png");
		ui = shu->getTexture();
		shu->setScale(1.0);
		shu->setTextureRect(CCRectMake(234,0,26,31));
		shu->setPosition(ccp(840 - 15 - i* 20,size.height - 32));
		moneybits->addObject(shu);
		addChild(shu);
	}
	//第er位
	connect=CCSprite::create("shusquare.png");
	connect->setScale(1.0f);
	connect->setTextureRect(CCRectMake(0,0,26,31));
	connect->setPosition(ccp(840 - 15 - 2* 20,size.height - 32));
	moneybits->addObject(connect);
	addChild(connect);
	//第一位
	shu = CCSprite::create("money.png");
	ui = shu->getTexture();
	shu->setScale(0.5f);
	//	shu->setTextureRect(CCRectMake(234,0,26,31));
	shu->setPosition(ccp( 840 - 80,size.height - 32));
	moneybits->addObject(shu);
	addChild(shu);

	moneybits->retain();
	moneySum=0;

	//分数标题
	CCSprite *title = CCSprite::create("score.png");
	title->setPosition(ccp(size.width-180-20,size.height - 32));
	title->setScale(1.0);
	addChild(title);
	//数字按位设置
	for(int i = 0;i < 5;i ++){
		CCSprite * shu = CCSprite::create("shu.png");
		ui = shu->getTexture();
		shu->setScale(1.0);
		shu->setTextureRect(CCRectMake(234,0,26,31));
		shu->setPosition(ccp(size.width - 15 -20- i * 22,size.height - 32));
		bits->addObject(shu);
		addChild(shu);
	}
	bits->retain();
	mark = 0;
}
void GameScore::addnumber(int var){
	//分数，按位设置数字
	mark += var;
	int temp = mark % 10;
	if(temp > 0){
		((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
		((CCSprite *)bits->objectAtIndex(0))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 
	}else{
		((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
		((CCSprite *)bits->objectAtIndex(0))->setTextureRect(CCRectMake(234,0,26,31)); 
	}
	temp = (mark % 100) / 10;
	if(temp > 0){
		((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
		((CCSprite *)bits->objectAtIndex(1))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));  

	}else{
		((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
		((CCSprite *)bits->objectAtIndex(1))->setTextureRect(CCRectMake(234,0,26,31)); 
	}
	temp = (mark % 1000) / 100;
	if(temp > 0){
		((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
		((CCSprite *)bits->objectAtIndex(2))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 

	}else{
		((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
		((CCSprite *)bits->objectAtIndex(2))->setTextureRect(CCRectMake(234,0,26,31));
	}
	temp = (mark % 10000) / 1000;
	if(temp > 0){
		((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
		((CCSprite *)bits->objectAtIndex(3))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31)); 

	}else{
		((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
		((CCSprite *)bits->objectAtIndex(3))->setTextureRect(CCRectMake(234,0,26,31)); 
	}
	temp = mark / 10000;
	if(temp > 0){
		((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
		((CCSprite *)bits->objectAtIndex(4))->setTextureRect(CCRectMake((temp - 1) * 26,0,26,31));  

	}else{
		((CCSprite *)bits->objectAtIndex(0))->setTexture(ui);
		((CCSprite *)bits->objectAtIndex(4))->setTextureRect(CCRectMake(234,0,26,31));
	}
}
void GameScore::setWorld(short worldTag){
	int gewei=worldTag%10;
	int shiwei=worldTag/10;
	CCSprite * shu = CCSprite::create("shu.png");
	CCTexture2D*texture = shu->getTexture();
	//CCLOG("worldbits size %d=" ,worldbits->count());
	((CCSprite *)worldbits->objectAtIndex(0))->setTexture(texture);
	((CCSprite *)worldbits->objectAtIndex(0))->setTextureRect(CCRectMake((gewei - 1) * 26,0,26,31));  

	((CCSprite *)worldbits->objectAtIndex(0))->setTexture(texture);
	((CCSprite *)worldbits->objectAtIndex(2))->setTextureRect(CCRectMake((shiwei - 1) * 26,0,26,31));  
}

void GameScore::addLife(short var){
	lifeSum+=var;
	int gewei=lifeSum%10;
	int shiwei=lifeSum/10;
	CCSprite * shu = CCSprite::create("shu.png");
	CCTexture2D*texture = shu->getTexture();
	//CCLOG("worldbits size %d=" ,worldbits->count());
	((CCSprite *)lifebits->objectAtIndex(0))->setTexture(texture);
	((CCSprite *)lifebits->objectAtIndex(0))->setTextureRect(CCRectMake((gewei - 1) * 26,0,26,31));  

	((CCSprite *)lifebits->objectAtIndex(0))->setTexture(texture);
	((CCSprite *)lifebits->objectAtIndex(1))->setTextureRect(CCRectMake((shiwei - 1) * 26,0,26,31));  
}

void GameScore::addMoney(short var){
	moneySum+=var;
	int gewei=moneySum%10;
	int shiwei=moneySum/10;
	CCSprite * shu = CCSprite::create("shu.png");
	CCTexture2D*texture = shu->getTexture();
	//CCLOG("worldbits size %d=" ,worldbits->count());
	((CCSprite *)moneybits->objectAtIndex(0))->setTexture(texture);
	((CCSprite *)moneybits->objectAtIndex(0))->setTextureRect(CCRectMake((gewei - 1) * 26,0,26,31));  

	((CCSprite *)moneybits->objectAtIndex(0))->setTexture(texture);
	((CCSprite *)moneybits->objectAtIndex(1))->setTextureRect(CCRectMake((shiwei - 1) * 26,0,26,31));  
}
void GameScore::saveScore(int score){
	CCUserDefault*handler=CCUserDefault::sharedUserDefault();
	int top1=handler->getIntegerForKey("top1",0);
	int top2=handler->getIntegerForKey("top2",0);
	int top3=handler->getIntegerForKey("top3",0);
	int top4=handler->getIntegerForKey("top4",0);
	int top5=handler->getIntegerForKey("top5",0);
	int top6=handler->getIntegerForKey("top6",0);
	int top7=handler->getIntegerForKey("top7",0);
	int scores[]={top1,top2,top3,top4,top5,top6,top7};
	if (scores[0]<score)
	{
		scores[0]=score;
	}

	for (int i=0;i<6;i++)
	{
		if (score>scores[i+1]&&score<scores[i])
		{
			scores[i+1]=score;
			//handler->setIntegerForKey()
		}

	}
	handler->setIntegerForKey("top1",scores[0]);
	handler->setIntegerForKey("top2",scores[1]);
	handler->setIntegerForKey("top3",scores[2]);
	handler->setIntegerForKey("top4",scores[3]);
	handler->setIntegerForKey("top5",scores[4]);
	handler->setIntegerForKey("top6",scores[5]);
	handler->setIntegerForKey("top7",scores[6]);

	handler->flush();

	//debug
	for (int i=0;i<7;i++)	
		CCLOG("%d\n",scores[i]);
}