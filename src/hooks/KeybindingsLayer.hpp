#pragma once

#include "../includes.hpp"

inline void* (__thiscall* KeybindingsLayer_addKeyPair)(KeybindingsLayer* self, const char* action, const char* key);
void* __fastcall KeybindingsLayer_addKeyPair_H(KeybindingsLayer* self, void*, const char* action, const char* key);