#include "GamingScene.h"
#include "../ui/GamingGui.h"

GamingScene::GamingScene(HappyRoll2Application *application)
	: BaseScene("GamingScene", application, new GamingGui()), ogre_camera(nullptr)
{
	ogre_camera = ogre_scene_manager->createCamera("GamingSceneCamera");
	ogre_scene_manager->getRootSceneNode()->createChildSceneNode("GamingSceneCameraNode")->attachObject(ogre_camera);
	ogre_camera->setNearClipDistance(2.0f);
	ogre_camera->setFarClipDistance(2000.0f);
	ogre_camera->setPosition(10.0f, 10.0f, 10.0f);
	ogre_camera->rotate(Ogre::Vector3(-1, 1, 0), Ogre::Degree(45));

	ogre_scene_manager->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));

	Ogre::ManualObject *_manual_object = ogre_scene_manager->createManualObject("MeshCubeAndAxis");
	_manual_object->setDynamic(false);

	float _size = 0.7f;
	_manual_object->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
	{
		float cp = 1.0f * _size;
		float cm = -1.0f * _size;

		_manual_object->position(cm, cp, cm);
		_manual_object->colour(Ogre::ColourValue(0.0f, 1.0f, 0.0f, 1.0f));
		_manual_object->position(cp, cp, cm);
		_manual_object->colour(Ogre::ColourValue(1.0f, 1.0f, 0.0f, 1.0f));
		_manual_object->position(cp, cm, cm);
		_manual_object->colour(Ogre::ColourValue(1.0f, 0.0f, 0.0f, 1.0f));
		_manual_object->position(cm, cm, cm);
		_manual_object->colour(Ogre::ColourValue(0.0f, 0.0f, 0.0f, 1.0f));

		_manual_object->position(cm, cp, cp);
		_manual_object->colour(Ogre::ColourValue(0.0f, 1.0f, 1.0f, 1.0f));
		_manual_object->position(cp, cp, cp);
		_manual_object->colour(Ogre::ColourValue(1.0f, 1.0f, 1.0f, 1.0f));
		_manual_object->position(cp, cm, cp);
		_manual_object->colour(Ogre::ColourValue(1.0f, 0.0f, 1.0f, 1.0f));
		_manual_object->position(cm, cm, cp);
		_manual_object->colour(Ogre::ColourValue(0.0f, 0.0f, 1.0f, 1.0f));

		_manual_object->triangle(0, 1, 2);
		_manual_object->triangle(2, 3, 0);
		_manual_object->triangle(4, 6, 5);
		_manual_object->triangle(6, 4, 7);

		_manual_object->triangle(0, 4, 5);
		_manual_object->triangle(5, 1, 0);
		_manual_object->triangle(2, 6, 7);
		_manual_object->triangle(7, 3, 2);

		_manual_object->triangle(0, 7, 4);
		_manual_object->triangle(7, 0, 3);
		_manual_object->triangle(1, 5, 6);
		_manual_object->triangle(6, 2, 1);
	}
	_manual_object->end();

	_manual_object->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_LIST);
	{
		float lAxeSize = 2.0f * _size;
		_manual_object->position(0.0f, 0.0f, 0.0f);
		_manual_object->colour(Ogre::ColourValue::Red);
		_manual_object->position(lAxeSize, 0.0f, 0.0f);
		_manual_object->colour(Ogre::ColourValue::Red);
		_manual_object->position(0.0f, 0.0f, 0.0f);
		_manual_object->colour(Ogre::ColourValue::Green);
		_manual_object->position(0.0, lAxeSize, 0.0);
		_manual_object->colour(Ogre::ColourValue::Green);
		_manual_object->position(0.0f, 0.0f, 0.0f);
		_manual_object->colour(Ogre::ColourValue::Blue);
		_manual_object->position(0.0, 0.0, lAxeSize);
		_manual_object->colour(Ogre::ColourValue::Blue);

		_manual_object->index(0);
		_manual_object->index(1);
		_manual_object->index(2);
		_manual_object->index(3);
		_manual_object->index(4);
		_manual_object->index(5);
	}
	_manual_object->end();
	_manual_object->convertToMesh("MeshCubeAndAxis", "General");

	ogre_scene_manager->getRootSceneNode()->createChildSceneNode("CubeNode")->attachObject(ogre_scene_manager->createEntity("Cube", "MeshCubeAndAxis", "General"));
}

GamingScene::~GamingScene()
{
	ogre_scene_manager->destroyCamera(ogre_camera);
}

bool GamingScene::update(float interval_time)
{
	return true;
}

Ogre::Camera *GamingScene::getCamera()
{
	return ogre_camera;
}

int GamingScene::getZOrder()
{
	return 0;
}

