#include "WorldScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

Scene* WorldScene::createScene()
{
	auto scene = Scene::create();
	auto layer = WorldScene::create();

	scene->addChild(layer);

	return scene;
}

bool WorldScene::init() {
	if (!Layer::init()) {
		return false;
	}

	//디바이스 크기 가져옴
	//Director 가져오기
	auto director = Director::getInstance();

	//OpenGLView가져오기
	auto glview = director->getOpenGLView();

	//OpenGLView에서 DesignResolutionSize 가져옴
	auto winSize = glview->getDesignResolutionSize();

	//auto backLayer = Layer::create();
	map = Sprite::create("worldImg\\worldmap.png");
	map->setScale(2.0f);
	map->setAnchorPoint(Point(0.5f, 0.5f));
	map->setPosition(Point(winSize.width / 2, winSize.height / 2));

	//backLayer->addChild(map);

	//scrollView = ScrollView::create(backLayer->getContentSize(), backLayer);
	//scrollView->retain();
	//scrollView->setBounceable(false);
	//scrollView->setDirection(ScrollView::Direction::BOTH);
	//scrollView->setPosition(Point::ZERO);
	//scrollView->setDelegate(this);
	//scrollView->setContentOffset(Point::ZERO, false);

	this->addChild(map);

	return true;
}


/*void WorldScene::scrollViewDidScroll(cocos2d::extension::ScrollView* view)
{}
void WorldScene::scrollViewdidZoom(cocos2d::extension::ScrollView* viw)
{}*/

void WorldScene::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(WorldScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(WorldScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(WorldScene::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void WorldScene::onExit()
{
	_eventDispatcher->removeEventListenersForType(EventListener::Type::TOUCH_ONE_BY_ONE);

	Layer::onExit();
}
bool WorldScene::onTouchBegan(Touch* touch, Event* event)
{
	sTouch = touch->getLocation();
	//bool bTouch = map->getBoundingBox().containsPoint(sTouch);
	//if (bTouch)
	//{
	//}

	return true;
}
void WorldScene::onTouchMoved(Touch* touch, Event* event)
{
	eTouch = touch->getLocation();
	Point moved = Point(eTouch.x - sTouch.x , eTouch.y - sTouch.y);
	//map->setPosition(map->getPosition() + moved);
	
	Point pos = map->getPosition() + moved;
	Size content = map->getBoundingBox().size;
	Size win = Director::getInstance()->getWinSize();
	float lx = (content.width - win.width) / 2;
	float ly = (content.height - win.height) / 2;

	if (pos.x < win.width/2 - lx)
		pos.x = win.width/2 - lx;
	else if (pos.x > win.width / 2 + lx)
		pos.x = win.width / 2 + lx;
	
	if (pos.y < win.height/2 - ly)
		pos.y = win.height/2 - ly;
	else if (pos.y > win.height/2 + ly)
		pos.y = win.height / 2 + ly;

	map->setPosition(pos);

	sTouch.set(eTouch);
}
void WorldScene::onTouchEnded(Touch* touch, Event* event)
{
	eTouch = touch->getLocation();
}
void WorldScene::onTouchCancelled(Touch* touch, Event* event)
{}