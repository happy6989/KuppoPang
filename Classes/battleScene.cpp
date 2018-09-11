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

	//����̽� ũ�� ������
	//Director ��������
	auto director = Director::getInstance();

	//OpenGLView��������
	auto glview = director->getOpenGLView();

	//OpenGLView���� DesignResolutionSize ������
	auto winSize = glview->getDesignResolutionSize();

	//===����̹��� (background)
	//Sprite �����Ͽ� �̹��� �ҷ���.
	auto background = Sprite::create("battleImg\\dungeonBack.png");

	//background�� �ش� ����Ʈ�� ��ġ��Ŵ. ȭ���� ���߾�

	background->setPosition(Point(winSize.width / 2, winSize.height / 2));

	//this �� background �� �ڽ� ���� �߰�
	this->addChild(background);


	//�ʵ�
	auto blockBack = Sprite::create("battleImg\\blockbackground.png");

	blockBack->setPosition(Point(winSize.width / 2, winSize.height / 7*2));

	this->addChild(blockBack);

	//������ ���
	auto limitBarBack = Sprite::create("battleImg\\limitbarback.png");
	limitBarBack->setPosition(Point(winSize.width / 2 -10, winSize.height / 32*19));
	this->addChild(limitBarBack);

	auto hpBarBack = Sprite::create("battleImg\\hpbarback.png");
	hpBarBack->setPosition(Point(limitBarBack->getPosition().x -40, limitBarBack->getPosition().y + 80));
	this->addChild(hpBarBack);

	

	//������
	auto limitBar = Sprite::create("battleImg\\limitbar.png");
	limitBar->setPosition(Point(limitBarBack->getPosition().x, limitBarBack->getPosition().y));
	this->addChild(limitBar);

	auto hpBar = Sprite::create("battleImg\\hpbar.png");
	hpBar->setPosition(Point(hpBarBack->getPosition().x, hpBarBack->getPosition().y));
	this->addChild(hpBar);

	auto hpicon = Sprite::create("battleImg\\hpicon2.png");
	hpicon->setPosition(Point(winSize.width/10, hpBarBack->getPosition().y));
	this->addChild(hpicon);


	//���Թ�ư
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

	//menu �� ��ư �߰�
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
