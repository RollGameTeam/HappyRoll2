
#ifndef _HR2_BASE_SCENE_H_
#define _HR2_BASE_SCENE_H_

#include "../HappyRoll2Prerequesties.h"
#include "../HappyRoll2Application.h"

class BaseScene : public Ogre::FrameListener
{
public:
	BaseScene(const Ogre::String name, HappyRoll2Application *application, BaseGuiScreen *gui);

	virtual void attach_display();

	virtual void detach_display();

	virtual bool update(float interval_time) = 0;

	virtual ~BaseScene();

	bool frameStarted(const Ogre::FrameEvent& evt) override;

protected:
	virtual Ogre::Camera *getCamera() = 0;

	virtual int getZOrder() = 0;

	Ogre::Root *ogre_root;
	Ogre::RenderWindow *ogre_window;
	Ogre::SceneManager *ogre_scene_manager;
	Ogre::OverlaySystem *ogre_overlay_system;
	Ogre::Viewport *ogre_viewport;

private:
	BaseGuiScreen *gui;
};

#endif
