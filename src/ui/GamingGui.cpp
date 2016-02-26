
#include "GamingGui.h"

GamingGui::GamingGui() : BaseGuiScreen("GamingGuiOverlay")
{
	Ogre::OverlayManager &overlayManager = Ogre::OverlayManager::getSingleton();

	Ogre::OverlayContainer *panel = static_cast<Ogre::OverlayContainer*>(
		overlayManager.createOverlayElement("Panel", "GamingGuiPanel"));
	panel->setMetricsMode(Ogre::GMM_PIXELS);
	panel->setPosition(10, 10);
	panel->setDimensions(100, 100);

	Ogre::TextAreaOverlayElement *textArea = static_cast<Ogre::TextAreaOverlayElement*>(
		overlayManager.createOverlayElement("TextArea", "GamingGuiTextArea"));
	textArea->setMetricsMode(Ogre::GMM_PIXELS);
	textArea->setPosition(0, 0);
	textArea->setDimensions(100, 100);
	textArea->setCaption("Gaming Gui Test");
	textArea->setCharHeight(24);
	textArea->setFontName("Arial");
	textArea->setColourBottom(Ogre::ColourValue(0.3, 0.5, 0.3));
	textArea->setColourTop(Ogre::ColourValue(0.5, 0.7, 0.5));

	ogre_overlay->add2D(panel);

	panel->addChild(textArea);
}

GamingGui::~GamingGui()
{
	Ogre::OverlayManager &overlayManager = Ogre::OverlayManager::getSingleton();
	overlayManager.destroyOverlayElement("GamingGuiPanel");
	overlayManager.destroyOverlayElement("GamingGuiTextArea");
}
