#pragma once

// Four ordinary register arguments. The three addresses belong to the action
// context, command node and skill record; each translation unit binds its own
// verified local view. The target returns the action zero-extended from 16 bits.
extern "C" unsigned short func_ov024_021eaa50(void* context, void* command,
                                            void* skill, unsigned char noCost);
