#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <utility>

#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Omega/Log.h"

#ifdef OM_PLATFORM_WINDOWS
	#include <Windows.h>
#endif // OM_PLATFORM_WINDOWS

// Common
using std::string;
using std::stringstream;
using std::shared_ptr;
using std::unique_ptr;
using std::function;
