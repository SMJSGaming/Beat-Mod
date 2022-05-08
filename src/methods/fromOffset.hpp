#pragma once

template<typename T1, typename T2>
T1& fromOffset(T2 object, unsigned int offset) {
    return *reinterpret_cast<T1*>(reinterpret_cast<uintptr_t>(object) + offset);
}