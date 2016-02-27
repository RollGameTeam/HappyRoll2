
#include "GamingGui.h"

GamingGui::GamingGui() : BaseGuiScreen("GamingGuiOverlay")
{
	Ogre::OverlayManager &overlayManager = Ogre::OverlayManager::getSingleton();

	Ogre::OverlayContainer *panel = static_cast<Ogre::OverlayContainer*>(
		overlayManager.createOverlayElement("Panel", "GamingGuiPanel"));
	panel->setMetricsMode(Ogre::GMM_PIXELS);
	panel->setPosition(10, 10);
	panel->setDimensions(100, 100);

	ogre_text_area = static_cast<Ogre::TextAreaOverlayElement*>
		(overlayManager.createOverlayElement("TextArea", "GamingGuiTextArea"));
	ogre_text_area->setMetricsMode(Ogre::GMM_PIXELS);
	ogre_text_area->setPosition(0, 0);
	ogre_text_area->setDimensions(100, 100);
	ogre_text_area->setCharHeight(24);
	ogre_text_area->setFontName("Arial");
	ogre_text_area->setColourBottom(Ogre::ColourValue(0.3f, 0.5f, 0.3f));
	ogre_text_area->setColourTop(Ogre::ColourValue(0.5f, 0.7f, 0.5f));

	ogre_overlay->add2D(panel);

	panel->addChild(ogre_text_area);
}

bool GamingGui::update(float interval_time)
{
	static float counter = 0.0f;

	counter += interval_time;

	if (counter > 0.5f)
	{
		char output[16];
		sprintf(output, "FPS: %d", static_cast<int>(1.0 / (interval_time > 1e-6 ? interval_time : 1e-6)));
		ogre_text_area->setCaption(output);
		counter = 0.0f;
	}
	return true;
}

GamingGui::~GamingGui()
{
	Ogre::OverlayManager &overlayManager = Ogre::OverlayManager::getSingleton();
	overlayManager.destroyOverlayElement("GamingGuiPanel");
	overlayManager.destroyOverlayElement("GamingGuiTextArea");
}
