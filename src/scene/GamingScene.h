
#ifndef _HR2_GAMING_SCENE_H_
#define _HR2_GAMING_SCENE_H_

#include "BaseScene.h"

class GamingScene : public BaseScene
{
public:
	explicit GamingScene(HappyRoll2Application *application);

	~GamingScene();

	bool update(float interval_time) override;

protected:
	Ogre::Camera *getCamera() override;
	int getZOrder() override;

	Ogre::Camera *ogre_camera;
};

#endif
