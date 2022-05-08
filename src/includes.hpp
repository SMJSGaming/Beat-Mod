#pragma once

// Shut up
#pragma warning( push )
#pragma warning( disable : 4251 )

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <MinHook.h>
#include <gd.h>
#include <cocos2d.h>

using std::uintptr_t;
using namespace gd;
using namespace cocos2d;

#pragma warning( pop )

extern inline bool pulseEnabled = true;

namespace gd {
    inline uintptr_t cocosBase = reinterpret_cast<uintptr_t>(GetModuleHandleA("libcocos2d.dll"));
}