
#ifndef _HR2_LOGGER_H_
#define _HR2_LOGGER_H_

#include <OgrePlatform.h>

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif
#  include <windows.h>
#  define HR2_ERROR(msg) MessageBox(NULL, msg, "ERROR!", MB_ICONERROR | MB_OK);
#else
#  include <iostream>
#  define HR2_ERROR(msg) std::cerr << "ERROR: " << msg << std::endl;
#endif

#endif
