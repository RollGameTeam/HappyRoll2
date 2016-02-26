
#ifndef _HR2_BASE_GUI_SCREEN_H_
#define _HR2_BASE_GUI_SCREEN_H_

#include "../HappyRoll2Prerequesties.h"

class BaseGuiScreen
{
public:
	BaseGuiScreen(const Ogre::String name);

	virtual ~BaseGuiScreen();

	void show();

	void hide();

protected:
	Ogre::Overlay *ogre_overlay;
};

#endif
