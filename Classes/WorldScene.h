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

	cocos2d::extension::ScrollView* scrollView;

	void scrollViewDidScroll(cocos2d::extension::ScrollView* view);
	void scrollViewdidZoom(cocos2d::extension::ScrollView* viw);

	
};