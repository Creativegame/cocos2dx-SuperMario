#ifndef _SuperMario_H_MDialog 
#define  _SuperMario_H_MDialog     
#include "cocos2d.h"
#include "GameConst.h"
//#include "cocos-ext.h"



using namespace cocos2d;
 
class DoneDialog:public CCNode
{
public:
	DoneDialog(void);
	~DoneDialog(void);
	bool isShow;
	virtual void onEnter();
	virtual void onExit();
	
	void menuBackCallback(CCObject* pSender);
	void menuNextCallback(CCObject* pSender);
	CREATE_FUNC(DoneDialog);
 };

class DoneAllDialog:public CCNode
{
public:
	DoneAllDialog(void);
	~DoneAllDialog(void);
	virtual void onEnter();
	virtual void onExit();
	void menuOkCallback(CCObject* pSender);
		CREATE_FUNC(DoneAllDialog);
};

class QuitDialog:public CCNode
{
public:
	QuitDialog(void);
	~QuitDialog(void);
	virtual void onEnter();
	virtual void onExit();
	void menuOkCallback(CCObject* pSender);
	void menuCancelCallback(CCObject* pSender);
	CREATE_FUNC(QuitDialog);
};

class DieDialog:public CCNode
{
public:
	DieDialog(void);
	~DieDialog(void);
	virtual void onEnter();
	virtual void onExit();
	void menuOkCallback(CCObject* pSender);
	void menuCancelCallback(CCObject* pSender);
	CREATE_FUNC(DieDialog);
};


#endif