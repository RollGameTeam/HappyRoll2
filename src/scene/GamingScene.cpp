
#include "GamingScene.h"
#include "../ui/GamingGui.h"

GamingScene::GamingScene(HappyRoll2Application *application)
	: BaseScene("GamingScene", application, new GamingGui()), ogre_camera(nullptr)
{
	ogre_camera = ogre_scene_manager->createCamera("GamingSceneCamera");
	ogre_scene_manager->getRootSceneNode()->createChildSceneNode("GamingSceneCameraNode")->attachObject(ogre_camera);
	ogre_camera->setNearClipDistance(2.0f);
	ogre_camera->setFarClipDistance(2000.0f);
}

GamingScene::~GamingScene()
{
	ogre_scene_manager->destroyCamera(ogre_camera);
}

bool GamingScene::update(float interval_time)
{
	return true;
}

Ogre::Camera * GamingScene::getCamera()
{
	return ogre_camera;
}

int GamingScene::getZOrder()
{
	return 0;
}
