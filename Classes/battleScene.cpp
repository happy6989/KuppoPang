#include "battleScene.h"

USING_NS_CC;

Scene* BattleScene::createScene()
{
	auto scene = Scene::create();
	auto layer = BattleScene::create();

	scene->addChild(layer);

	return scene;
}

bool BattleScene::init() {
	if (!Layer::init()) {
		return false;
	}

	//code

	return true;
}
