#include "includes.hpp"
#include "hooks/CCKeyboardDispatcher.hpp"
#include "hooks/PlayLayer.hpp"
#include "hooks/KeybindingsLayer.hpp"

DWORD WINAPI thread_func(void* hModule) {
    MH_Initialize();

    // CCKeyboardDispatcher
    MH_CreateHook(
        reinterpret_cast<void*>(gd::cocosBase + 0x99F30),
        reinterpret_cast<void*>(&cocos2d_CCKeyboardDispatcher_dispatchKeyboardMSG_H),
        reinterpret_cast<void**>(&cocos2d_CCKeyboardDispatcher_dispatchKeyboardMSG)
    );

    // PlayLayer
    MH_CreateHook(
        reinterpret_cast<void*>(gd::base + 0x2029C0),
        reinterpret_cast<void*>(&PlayLayer_update_H),
        reinterpret_cast<void**>(&PlayLayer_update)
    );

    // KeybindingsLayer
    MH_CreateHook(
        reinterpret_cast<void*>(gd::base + 0x153670),
        reinterpret_cast<void*>(&KeybindingsLayer_addKeyPair_H),
        reinterpret_cast<void**>(&KeybindingsLayer_addKeyPair)
    );

    MH_EnableHook(MH_ALL_HOOKS);

    return 0;
}

BOOL APIENTRY DllMain(HMODULE handle, DWORD reason, LPVOID reserved) {
    #ifdef SHOW_CONSOLE
        if (AllocConsole()) {
            freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
            freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
        }
    #endif
    
    if (reason == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0x100, thread_func, handle, 0, 0);
    }

    return TRUE;
}