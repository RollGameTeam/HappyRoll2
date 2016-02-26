
#include "BaseGuiScreen.h"

BaseGuiScreen::BaseGuiScreen(const Ogre::String name)
{
	ogre_overlay = Ogre::OverlayManager::getSingleton().create(name);
}

BaseGuiScreen::~BaseGuiScreen()
{
	Ogre::OverlayManager::getSingleton().destroy(ogre_overlay);
}

void BaseGuiScreen::show()
{
	ogre_overlay->show();
}

void BaseGuiScreen::hide()
{
	ogre_overlay->hide();
}

