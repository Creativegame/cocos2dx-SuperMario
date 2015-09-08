

#ifndef SuperMario_GameScore_h
#define SuperMario_GameScore_h

#include "cocos2d.h"
using namespace cocos2d;

class GameScore : public CCNode
{
public:
	GameScore(void);
	virtual ~GameScore(void);
	virtual void onEnter();
	virtual void onExit();
	CCArray *bits;
	CCArray*worldbits;
	CCArray*moneybits;
	CCArray*lifebits;
	int mark;
	int moneySum;
	int lifeSum;
	void addnumber(int var);
	void saveScore(int score);
	void setWorld(short worldTag);
	void addMoney(short var);
	void addLife(short var);
	CCTexture2D* ui;
};

#endif
