#pragma once

#include "../includes.hpp"

inline bool (__thiscall* cocos2d_CCKeyboardDispatcher_dispatchKeyboardMSG)(CCKeyboardDispatcher* self, enumKeyCodes key, bool isDown);
bool __fastcall cocos2d_CCKeyboardDispatcher_dispatchKeyboardMSG_H(CCKeyboardDispatcher* self, void*, enumKeyCodes key, bool isDown);