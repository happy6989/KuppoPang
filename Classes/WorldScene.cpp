#include "WorldScene.h"

USING_NS_CC;

WorldScene::WorldScene()
{
}


WorldScene::~WorldScene()
{
}

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

	//code

	return true;
}