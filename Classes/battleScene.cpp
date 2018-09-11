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

	//디바이스 크기 가져옴
	//Director 가져오기
	auto director = Director::getInstance();

	//OpenGLView가져오기
	auto glview = director->getOpenGLView();

	//OpenGLView에서 DesignResolutionSize 가져옴
	auto winSize = glview->getDesignResolutionSize();

	//===배경이미지 (background)
	//Sprite 생성하여 이미지 불러옴.
	auto background = Sprite::create("battleImg\\dungeonBack.png");

	//background를 해당 포인트에 위치시킴. 화면의 정중앙

	background->setPosition(Point(winSize.width / 2, winSize.height / 2));

	//this 에 background 를 자식 노드로 추가
	this->addChild(background);


	//필드
	auto blockBack = Sprite::create("battleImg\\blockbackground.png");

	blockBack->setPosition(Point(winSize.width / 2, winSize.height / 7*2));

	this->addChild(blockBack);

	//게이지 배경
	auto limitBarBack = Sprite::create("battleImg\\limitbarback.png");
	limitBarBack->setPosition(Point(winSize.width / 2 -10, winSize.height / 32*19));
	this->addChild(limitBarBack);

	auto hpBarBack = Sprite::create("battleImg\\hpbarback.png");
	hpBarBack->setPosition(Point(limitBarBack->getPosition().x -40, limitBarBack->getPosition().y + 80));
	this->addChild(hpBarBack);

	

	//게이지
	auto limitBar = Sprite::create("battleImg\\limitbar.png");
	limitBar->setPosition(Point(limitBarBack->getPosition().x, limitBarBack->getPosition().y));
	this->addChild(limitBar);

	auto hpBar = Sprite::create("battleImg\\hpbar.png");
	hpBar->setPosition(Point(hpBarBack->getPosition().x, hpBarBack->getPosition().y));
	this->addChild(hpBar);

	auto hpicon = Sprite::create("battleImg\\hpicon2.png");
	hpicon->setPosition(Point(winSize.width/10, hpBarBack->getPosition().y));
	this->addChild(hpicon);


	//리밋버튼
	auto posiX = blockBack->getPosition().x + blockBack->getContentSize().width / 2;
	auto posiY = blockBack->getPosition().y + blockBack->getContentSize().height / 2;
	auto limitBtnBack = Sprite::create("battleImg\\limitbtnback.png");
	limitBtnBack->setAnchorPoint(Point(0.5f,0.0f));
	limitBtnBack->setPosition(Point(posiX - winSize.width / 9, posiY -20));
	this->addChild(limitBtnBack);

	auto limitBtn = MenuItemImage::create("battleImg\\limitbtn.png", "battleImg\\limitbtn.png", [&](Ref *sender) {
		log("onClickButton1");
		//Scene Change
		//auto Scene = WorldScene::createScene();

	});

	limitBtn->setAnchorPoint(Point(0.5f, 0));
	limitBtn->setPosition(Point(limitBtnBack->getPosition().x, limitBtnBack->getPosition().y));

	//menu 에 버튼 추가
	this->menu2 = Menu::create(limitBtn, NULL);
	menu2->setPosition(Point::ZERO);
	this->addChild(menu2);



	return true;
}

void BattleScene::onClickButton2(Ref *object)
{
	log("onClickButton1");
}

void BattleScene::enableStartButton()
{
	if (menu2 != NULL)
		menu2->setVisible(true);
}
