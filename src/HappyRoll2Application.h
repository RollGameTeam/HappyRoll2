
#ifndef _HR2_APPLICATION_H_
#define _HR2_APPLICATION_H_

#include "HappyRoll2Prerequesties.h"

class HappyRoll2Application : Ogre::WindowEventListener
{
public:
	HappyRoll2Application() noexcept;

	bool initialize() noexcept;

	bool go();

	void finalize() noexcept;

	void windowClosed(Ogre::RenderWindow* rw) override;
private:
	Ogre::Root *ogre_root;
	Ogre::OverlaySystem *ogre_overlay_system;
	Ogre::RenderWindow *ogre_window;
	Ogre::SceneManager *ogre_scene_manager;

	Ogre::Overlay *ogre_overlay;
	Ogre::TextAreaOverlayElement *ogre_fps_text;
	
	BaseScene *start_scene;

	int max_z_order = 0;

	friend class BaseScene;
};

#endif
