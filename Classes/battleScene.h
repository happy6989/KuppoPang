#include "cocos2d.h"

class BattleScene: public cocos2d::Layer
{
public:
	cocos2d::Menu* menu2;
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(BattleScene);

	cocos2d::Point sTouch;
	cocos2d::Point eTouch;

	//virtual void onEnter();
	//virtual void onExit();
	//virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	//virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	//virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	//virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

	void onClickButton2(Ref *object);
	void enableStartButton();
};
