#include "KeybindingsLayer.hpp"

void* __fastcall KeybindingsLayer_addKeyPair_H(KeybindingsLayer* self, void*, const char* action, const char* key) {
    void* result = KeybindingsLayer_addKeyPair(self, action, key);
    
    if (std::string(action) == "Gameplay Keys") {
        KeybindingsLayer_addKeyPair(self, "Beat Pulse", "Tab");
    }

    return result;
}