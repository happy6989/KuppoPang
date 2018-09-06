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

	auto backLayer = Layer::create();
	auto worldmap = Sprite::create("worldImg\\worldmap.png");

	backLayer->setPosition(Point(winSize.width / 2, winSize.height / 2));
	backLayer->setContentSize(winSize);

	backLayer->addChild(worldmap);

	//scrollView = ScrollView::create(winSize, backLayer);
	//scrollView->retain();
	//scrollView->setDirection(ScrollView::Direction::BOTH);
	//scrollView->setContentSize(backLayer->getContentSize());
	//scrollView->setPosition(Point(winSize.width / 2, winSize.height / 2));
	//scrollView->setContentOffset(Point::ZERO, false);
	//scrollView->setContainer(backLayer);
	//scrollView->setDelegate(this);

	this->addChild(backLayer);

	return true;
}


void WorldScene::scrollViewDidScroll(cocos2d::extension::ScrollView* view)
{}
void WorldScene::scrollViewdidZoom(cocos2d::extension::ScrollView* viw)
{}