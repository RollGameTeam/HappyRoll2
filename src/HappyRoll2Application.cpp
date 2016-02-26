
#include "HappyRoll2Application.h"
#include <exception>
#include "scene/GamingScene.h"
#include "util/Logger.h"

HappyRoll2Application::HappyRoll2Application() noexcept
	: ogre_root(nullptr), ogre_overlay_system(nullptr), ogre_window(nullptr),
	ogre_scene_manager(nullptr), ogre_overlay(nullptr), ogre_fps_text(nullptr), start_scene(nullptr)
{
}

bool HappyRoll2Application::initialize() noexcept
{
	try
	{
		// Create the Root.
		ogre_root = new Ogre::Root("", "", "test_ogre.log");

		// Load plugins.
		ogre_root->loadPlugin("RenderSystem_GL" OGRE_BUILD_SUFFIX);
		ogre_root->loadPlugin("RenderSystem_Direct3D9" OGRE_BUILD_SUFFIX);

		// Set the render system.
		{
			Ogre::RenderSystemList render_system_list = ogre_root->getAvailableRenderers();
			if (!render_system_list.size())
			{
				HR2_ERROR("No available render system. Initialization failing.");
				return false;
			}
			ogre_root->setRenderSystem(render_system_list[0]);
		}

		ogre_overlay_system = new Ogre::OverlaySystem();

		// Initialise the Root without creating an window.
		ogre_root->initialise(false, "", "");

		// Create the RenderWindow.
		{
			Ogre::NameValuePairList lParams;
			lParams["FSAA"] = "0";
			lParams["vsync"] = "true";
			ogre_window = ogre_root->createRenderWindow("Happy Roll 2", 800, 600, false, &lParams);
			ogre_window->setActive(true);
			ogre_window->setAutoUpdated(true);
		}
		Ogre::ResourceGroupManager& resource = Ogre::ResourceGroupManager::getSingleton();
		resource.addResourceLocation("./res", "FileSystem", "General");
		resource.initialiseResourceGroup("General");

		Ogre::FontPtr arial = Ogre::FontManager::getSingleton().create("Arial", "General");
		arial->setType(Ogre::FT_TRUETYPE);
		arial->setSource("arial.ttf");
		arial->setTrueTypeSize(24);
		arial->setTrueTypeResolution(96);

		(start_scene = new GamingScene(this))->attach_display();

		Ogre::WindowEventUtilities::addWindowEventListener(ogre_window, this);

		ogre_root->clearEventTimes();
	}
	catch (std::exception e)
	{
		std::string error = "Exception caught: ";
		error += e.what();
		HR2_ERROR(error.c_str());
		return false;
	}

	return true;
}

bool HappyRoll2Application::go()
{
	try
	{
		ogre_root->startRendering();
	}
	catch (std::exception e)
	{
		std::string error = "Exception caught: ";
		error += e.what();
		HR2_ERROR(error.c_str());
		return false;
	}
	return true;
}

void HappyRoll2Application::finalize() noexcept
{
	//delete start_scene;
	ogre_window->destroy();
	delete ogre_overlay_system;
	delete ogre_root;
}

void HappyRoll2Application::windowClosed(Ogre::RenderWindow *rw)
{
	ogre_root->queueEndRendering();
}
