#include "cocos2d.h"
#include "cocos-ext.h"

class WorldScene : public cocos2d::Layer, public cocos2d::extension::ScrollViewDelegate
{
public : 
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(WorldScene); 

	cocos2d::Sprite* map;
	cocos2d::Point sTouch;
	cocos2d::Point eTouch;

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

	//cocos2d::extension::ScrollView* scrollView = NULL;

	//void scrollViewDidScroll(cocos2d::extension::ScrollView* view);
	//void scrollViewdidZoom(cocos2d::extension::ScrollView* viw);
};