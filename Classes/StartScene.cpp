//
// Created by happy on 2018-09-03.
//

#include "StartScene.h"
#include "battleScene.h"

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


    //����̽� ũ�� ������
	//Director ��������
	auto director = Director::getInstance();

	//OpenGLView��������
	auto glview = director->getOpenGLView();

	//OpenGLView���� DesignResolutionSize ������
	auto winSize = glview->getDesignResolutionSize();

	//===����̹��� (background)
	//Sprite �����Ͽ� �̹��� �ҷ���.
	auto background = Sprite::create("titleImg\\titleBack.png");

	//background�� �ش� ����Ʈ�� ��ġ��Ŵ. ȭ���� ���߾�

	background->setPosition(Point(winSize.width/2,winSize.height/2));

	//this �� background �� �ڽ� ���� �߰�
	this->addChild(background);



	//===���� �ø���
	//
	//Sprite �����Ͽ� �̹��� �ҷ���.
	auto title = Sprite::create("titleImg\\title.png");

	//�߽��� �ٲ�
	title->setAnchorPoint(Point(0.5f,1));
	// �ش� ����Ʈ�� ��ġ��Ŵ. ȭ���� ���߾�

	title->setPosition(Point(winSize.width / 2, winSize.height / 8*6));

	//this �� title �� �ڽ� ���� �߰�
	this->addChild(title);


	//==���۹�ư �ø���
	//
	auto sBtn = MenuItemImage::create("titleImg\\startBtn.png", "titleImg\\startBtn_on.png", [&](Ref *sender) {
		log("onClickButton1");
		auto Scene = BattleScene::createScene();
		Director::getInstance()->pushScene(Scene);
	});

	//�߽ɹٲ�
	sBtn->setAnchorPoint(Point(0.5f,0));

	//�ش� ����Ʈ�� ��ġ��Ŵ. ȭ���� ���߾�

	sBtn->setPosition(Point(winSize.width / 2, 0));

	//menu �� ��ư �߰�
	auto menu = Menu::create(sBtn, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);



    return true;
}

void StartScene::onClickButton1(Ref *object)
{
	log("onClickButton1");
}