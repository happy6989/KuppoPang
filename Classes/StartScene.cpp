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
	title->setAnchorPoint(Point(0.5f,0.5f));
	// �ش� ����Ʈ�� ��ġ��Ŵ. ȭ���� ���߾�

	title->setPosition(Point(winSize.width / 2, winSize.height / 16*9.5));
	
	auto to = title->getScale();
	auto from = 0;

	title->setScale(from);
	auto action = ScaleTo::create(1.0f, to);
	auto sequence = Sequence::create(action, CallFunc::create(CC_CALLBACK_0(StartScene::enableStartButton, this)), NULL);
	title->runAction(sequence);

	//this �� title �� �ڽ� ���� �߰�
	this->addChild(title);
	
	//==���۹�ư �ø���
	//
	auto sBtn = MenuItemImage::create("titleImg\\startBtn.png", "titleImg\\startBtn_on.png", [&](Ref *sender) {
		log("onClickButton1");
		auto Scene = WorldScene::createScene();
		Director::getInstance()->pushScene(Scene);
	});

	//�߽ɹٲ�
	sBtn->setAnchorPoint(Point(0.5f, 0));

	//�ش� ����Ʈ�� ��ġ��Ŵ. ȭ���� ���߾�

	sBtn->setPosition(Point(winSize.width / 2, 0));

	//menu �� ��ư �߰�
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