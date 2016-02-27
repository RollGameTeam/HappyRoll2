
#include "BaseGuiScreen.h"

BaseGuiScreen::BaseGuiScreen(const Ogre::String name)
{
	ogre_overlay = Ogre::OverlayManager::getSingleton().create(name);
}

BaseGuiScreen::~BaseGuiScreen()
{
	Ogre::OverlayManager::getSingleton().destroy(ogre_overlay);
}

bool BaseGuiScreen::update(float interval_time)
{
	return true;
}

void BaseGuiScreen::show()
{
	ogre_overlay->show();
}

void BaseGuiScreen::hide()
{
	ogre_overlay->hide();
}

