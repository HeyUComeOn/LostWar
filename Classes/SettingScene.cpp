#include "SettingScene.h"

USING_NS_CC;
using namespace ui;
Scene* SettingLayer::createScene()
{
	// 'scene' is an autorelease Ref
	auto scene = Scene::create();

	// 'layer' is an autorelease Ref
	auto layer = SettingLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SettingLayer::init()
{
	//////////////////////////////
	// 1. super init first
	/*if ( !BaseLayer::init() )
	{
	return false;
	}*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bg = TMXTiledMap::create("map/red_bg.tmx");
	addChild(bg);	

	Layout*layout = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("SettingUI_1/SettingUI_1.ExportJson"));
	layout->setPosition(Vec2(visibleSize.width/2-layout->getContentSize().width/2,visibleSize.height/2-layout->getContentSize().height/2));
	this->addChild(layout);

	Layout* root = static_cast<Layout*>(layout->getChildByName("Panel_6"));

	Button* button1 = static_cast<Button*>(Helper::seekWidgetByName(root, "Button_5"));
	button1->addTouchEventListener(CC_CALLBACK_2(SettingLayer::touchEvent, this));

	auto CheckBox_9 = static_cast<CheckBox*>(Helper::seekWidgetByName(root, "CheckBox_9"));
	CheckBox_9->addEventListener(CC_CALLBACK_2(SettingLayer::selectedEvent1, this));
	if(UserDefault::getInstance()->getBoolForKey(SOUND_KEY))
	{
		CheckBox_9->setSelectedState(true);
	}
	else
	{
		CheckBox_9->setSelectedState(false);
	}
	auto CheckBox_10 = static_cast<CheckBox*>(Helper::seekWidgetByName(root, "CheckBox_10"));
	CheckBox_10->addEventListener(CC_CALLBACK_2(SettingLayer::selectedEvent2, this));
	if(UserDefault::getInstance()->getBoolForKey(MUSIC_KEY))
	{
		CheckBox_10->setSelectedState(true);
	}
	else
	{
		CheckBox_10->setSelectedState(false);
	}

	/*auto top = Sprite::createWithSpriteFrameName("setting-top.png");
	top->setPosition(Vec2(visibleSize.width/2, visibleSize.height - top->getContentSize().height /2));
	addChild(top);


	//音效.
	auto soundOnSprite  = Sprite::createWithSpriteFrameName("setting.check-on.png");
	auto soundOffSprite  = Sprite::createWithSpriteFrameName("setting.check-off.png");
	auto soundOnMenuItem = MenuItemSprite::create(soundOnSprite, NULL);
	auto soundOffMenuItem = MenuItemSprite::create(soundOffSprite, NULL);
	auto soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingLayer::menuSoundToggleCallback, this), soundOnMenuItem,soundOffMenuItem, NULL);

	//音乐.
	auto musicOnSprite  = Sprite::createWithSpriteFrameName("setting.check-on.png");
	auto musicOffSprite  = Sprite::createWithSpriteFrameName("setting.check-off.png");
	auto musicOnMenuItem = MenuItemSprite::create(musicOnSprite, NULL);
	auto musicOffMenuItem = MenuItemSprite::create(musicOffSprite, NULL);
	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingLayer::menuMusicToggleCallback, this), musicOnMenuItem,musicOffMenuItem, NULL);

	auto  menu = Menu::create(soundToggleMenuItem, musicToggleMenuItem, NULL);

	menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height /2) + Vec2(70, 50));
	menu->alignItemsVerticallyWithPadding(20.0f);
	addChild(menu, 1);

	auto lblSound = Label::createWithTTF(MyUtility::getUTF8Char("lblSound"), "fonts/hanyi.ttf", 36);
	lblSound->setColor(Color3B(14,83,204));	
	lblSound->setPosition(menu->getPosition() - Vec2(100, -30));
	log("%f,%f",menu->getPosition().x, menu->getPosition().y);
	addChild(lblSound, 1);

	auto lblMusic = Label::createWithTTF(MyUtility::getUTF8Char("lblMusic"), "fonts/hanyi.ttf", 36);
	lblMusic->setColor(Color3B(14,83,204));	
	lblMusic->setPosition(lblSound->getPosition() - Vec2(0, 60));
	addChild(lblMusic, 1);

	//设置音效和音乐选中状态
	UserDefault *defaults  = UserDefault::getInstance();
	if (defaults->getBoolForKey(MUSIC_KEY)) {
	musicToggleMenuItem->setSelectedIndex(0);
	} else {
	musicToggleMenuItem->setSelectedIndex(1);		
	}
	if (defaults->getBoolForKey(SOUND_KEY)) {
	soundToggleMenuItem->setSelectedIndex(0);
	} else {
	soundToggleMenuItem->setSelectedIndex(1);
	}
	*/

	return true;
}

void SettingLayer::selectedEvent1(Ref* pSender, CheckBox::EventType type)
{
	switch (type)
	{
	case CheckBox::EventType::SELECTED:
		UserDefault::getInstance()->setBoolForKey(SOUND_KEY, true);
		SimpleAudioEngine::getInstance()->playEffect(sound_1);
		break;

	case CheckBox::EventType::UNSELECTED:
		log(String::createWithFormat("Unselected")->getCString());
		UserDefault::getInstance()->setBoolForKey(SOUND_KEY, false);
		break;

	default:
		break;
	}
}

void SettingLayer::selectedEvent2(Ref* pSender, CheckBox::EventType type)
{
	switch (type)
	{
	case CheckBox::EventType::SELECTED:
		UserDefault::getInstance()->setBoolForKey(MUSIC_KEY, true);
		SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_2);
		break;

	case CheckBox::EventType::UNSELECTED:
		log(String::createWithFormat("Unselected")->getCString());
		UserDefault::getInstance()->setBoolForKey(MUSIC_KEY, false);
		SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
		break;

	default:
		break;
	}

}

void SettingLayer::touchEvent(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::BEGAN) 
	{
		log("Touch Down");
		Director::getInstance()->popScene();
		if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY)) {
			SimpleAudioEngine::getInstance()->playEffect(sound_1);
		}
	}
}