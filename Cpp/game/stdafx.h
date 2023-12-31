// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

// The following macros define the minimum required platform.  The minimum required platform
// is the earliest version of Windows, Internet Explorer etc. that has the necessary features to run 
// your application.  The macros work by enabling all features available on platform versions up to and 
// including the version specified.

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef _WIN32_WINNT            // Specifies that the minimum required platform is Windows Vista.
#define _WIN32_WINNT 0x0600     // Change this to the appropriate value to target other versions of Windows.
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// TODO: reference additional headers your program requires here

#include <string>
#include <vector>
#include <list>
#include <map>
#include <hash_map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

#include "common/Service.h"
#include "common/Logger.h"
#include "common/lua.h"
#include "Config.h"

//#if defined(_DEBUG)
//#include "external/vld-2.4.2/include/vld.h"
//#endif	//_DEBUG
