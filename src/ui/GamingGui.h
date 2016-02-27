
#ifndef _HR2_GAMING_GUI_H_
#define _HR2_GAMING_GUI_H_

#include "BaseGuiScreen.h"

class GamingGui : public BaseGuiScreen
{
public:
	GamingGui();

	bool update(float interval_time) override;

	~GamingGui();

private:
	Ogre::TextAreaOverlayElement *ogre_text_area;
};

#endif
