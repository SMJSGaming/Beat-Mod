#include "CCKeyboardDispatcher.hpp"

bool __fastcall cocos2d_CCKeyboardDispatcher_dispatchKeyboardMSG_H(CCKeyboardDispatcher* self, void*, enumKeyCodes key, bool isDown) {
    if (key == enumKeyCodes::KEY_Tab && isDown) {
        pulseEnabled = !pulseEnabled;
    }

    return cocos2d_CCKeyboardDispatcher_dispatchKeyboardMSG(self, key, isDown);
}