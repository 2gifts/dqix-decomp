#pragma once
#define ARM _Pragma("thumb off")
#define THUMB _Pragma("thumb on")
#define NULL 0 // appeases vs code
#define SDK_ASSERT(exp) ((void)0)
#define SDK_NULL_ASSERT(exp) ((void)0)
