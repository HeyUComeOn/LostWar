//
//  Created by 关东升 on 2014-5-18.
//  本书网站：http://www.cocoagame.net
//  智捷iOS课堂在线课堂：http://v.51work6.com
//  智捷iOS课堂新浪微博：http://weibo.com/u/3215753973
//  作者微博：http://weibo.com/516inc
//  QQ：1575716557 邮箱：jylong06@163.com
//  QQ交流群：389037167/327403678
//
#ifndef __Setting_SCENE_H__
#define __Setting_SCENE_H__

#include "cocos2d.h"
#include "SystemHeader.h"
#include "MyUtility.h"

#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
//#include "BaseLayer.h"

class SettingLayer :public Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	void selectedEvent1(cocos2d::Ref* pSender,cocos2d::ui::CheckBox::EventType type);
	void selectedEvent2(cocos2d::Ref* pSender,cocos2d::ui::CheckBox::EventType type);

	// implement the "static create()" method manually
	CREATE_FUNC(SettingLayer);

	void touchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
};

#endif // __Setting_SCENE_H__
