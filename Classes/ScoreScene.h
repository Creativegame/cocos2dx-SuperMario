

#ifndef SuperMario_ScoreScene_h
#define SuperMario_ScoreScene_h

#include "cocos2d.h"
using namespace cocos2d;
class ScoreScene :
	public CCLayer
{
public:
	 
	virtual bool init();

	virtual void onEnter();

	virtual void onExit();

	static cocos2d::CCScene* scene();

	 CCArray*gamemark;

	void menuQuitCallback(CCObject* pSender);

	CREATE_FUNC(ScoreScene);
};

#endif