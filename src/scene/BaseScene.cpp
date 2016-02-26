
#include "BaseScene.h"
#include "../ui/BaseGuiScreen.h"

BaseScene::BaseScene(const Ogre::String name, HappyRoll2Application *application, BaseGuiScreen *gui)
	: ogre_root(application->ogre_root), ogre_window(application->ogre_window), 
	ogre_scene_manager(nullptr), ogre_overlay_system(application->ogre_overlay_system), ogre_viewport(nullptr), gui(gui)
{
	ogre_scene_manager = ogre_root->createSceneManager(Ogre::ST_GENERIC, name);
}

void BaseScene::attach_display()
{
	ogre_viewport = ogre_window->addViewport(this->getCamera(), this->getZOrder());
	ogre_viewport->setAutoUpdated(true);
	ogre_viewport->setBackgroundColour(Ogre::ColourValue(0, 0, 0));
	this->getCamera()->setAspectRatio(float(ogre_viewport->getActualWidth()) / float(ogre_viewport->getActualHeight()));

	//ogre_root->addFrameListener(this);
	ogre_scene_manager->addRenderQueueListener(ogre_overlay_system);

	gui->show();
}

void BaseScene::detach_display()
{
	gui->hide();
	ogre_scene_manager->removeRenderQueueListener(ogre_overlay_system);
	ogre_window->removeViewport(ogre_viewport->getZOrder());
	ogre_root->removeFrameListener(this);
}

BaseScene::~BaseScene()
{
	ogre_root->destroySceneManager(ogre_scene_manager);
	delete gui;
}

bool BaseScene::frameStarted(const Ogre::FrameEvent &evt)
{
	return update(evt.timeSinceLastFrame);
}
