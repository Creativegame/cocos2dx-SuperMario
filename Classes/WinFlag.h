#ifndef _SuperMario_H_WinFlag 
#define  _SuperMario_H_WinFlag     
#include "cocos2d.h"
#include "GameConst.h"
//#include "cocos-ext.h"



using namespace cocos2d;
//USING_NS_CC_EXT;
#define  MOVE_LEFT  10
#define  MOVE_RIGHT  11 
class WinFlag:public CCNode
{
public:
	WinFlag(void);
	~WinFlag(void);
	virtual void onEnter();
	virtual void onExit();
	float getOriPosX();
	void setOriPosx(float posx);
private :
	float posx;
 

};

#endif