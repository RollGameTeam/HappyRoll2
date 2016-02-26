
#include "HappyRoll2.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif
#  include <windows.h>
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, char **argv)
#endif
{
	HappyRoll2Application *application = new HappyRoll2Application();

	if (!application->initialize())
	{
		HR2_ERROR("Happy Roll 2 initialization failed, exiting.");
		delete application;
		return 1;
	}

	application->go();

	application->finalize();
	delete application;

	return 0;
}
