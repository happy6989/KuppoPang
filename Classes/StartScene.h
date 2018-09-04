//
// Created by happy on 2018-09-03.
//

#ifndef PROJ_ANDROID_STARTSCENE_H
#define PROJ_ANDROID_STARTSCENE_H

#include "cocos2d.h"

class StartScene : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(StartScene);

};


#endif //PROJ_ANDROID_STARTSCENE_H
