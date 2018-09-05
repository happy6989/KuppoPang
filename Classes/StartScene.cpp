//
// Created by happy on 2018-09-03.
//

#include "StartScene.h"
#include "WorldScene.h"

USING_NS_CC;


Scene* StartScene::createScene() {
    auto scene = Scene::create();

    auto layer = StartScene::create();

    scene->addChild(layer);

    return  scene;
}

bool StartScene::init() {
    if(!Layer::init()){
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
	auto background = Sprite::create("titleImg\\titleBack.png");

	//background를 해당 포인트에 위치시킴. 화면의 정중앙

	background->setPosition(Point(winSize.width/2,winSize.height/2));

	//this 에 background 를 자식 노드로 추가
	this->addChild(background);



	//===제목 올리기
	//
	//Sprite 생성하여 이미지 불러옴.
	auto title = Sprite::create("titleImg\\title.png");

	//중심점 바꿈
	title->setAnchorPoint(Point(0.5f,0.5f));
	// 해당 포인트에 위치시킴. 화면의 정중앙

	title->setPosition(Point(winSize.width / 2, winSize.height / 16*9.5));
	
	auto to = title->getScale();
	auto from = 0;

	title->setScale(from);
	auto action = ScaleTo::create(1.0f, to);
	auto sequence = Sequence::create(action, CallFunc::create(CC_CALLBACK_0(StartScene::enableStartButton, this)), NULL);
	title->runAction(sequence);

	//this 에 title 를 자식 노드로 추가
	this->addChild(title);
	
	//==시작버튼 올리기
	//
	auto sBtn = MenuItemImage::create("titleImg\\startBtn.png", "titleImg\\startBtn_on.png", [&](Ref *sender) {
		log("onClickButton1");
		auto Scene = WorldScene::createScene();
		Director::getInstance()->pushScene(Scene);
	});

	//중심바꿈
	sBtn->setAnchorPoint(Point(0.5f, 0));

	//해당 포인트에 위치시킴. 화면의 정중앙

	sBtn->setPosition(Point(winSize.width / 2, 0));

	//menu 에 버튼 추가
	this->menu = Menu::create(sBtn, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	menu->setVisible(false);

    return true;
}

void StartScene::onClickButton1(Ref *object)
{
	log("onClickButton1");
}

void StartScene::enableStartButton()
{
	if(menu != NULL)
		menu->setVisible(true);
}