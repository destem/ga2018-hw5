#pragma once

/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

// Compilers.
#if defined(_MSC_VER)
#define GA_MSVC
#elif defined(__MINGW32__)
#define GA_MINGW
#endif

// Architecture.
#if defined(GA_MSVC)
#if defined(_WIN64)
#define GA_64_BIT
#elif defined(_WIN32)
#define GA_32_BIT
#endif
#endif

#if defined(__MINGW32__)
#include <_mingw.h>
#if defined(__MINGW64_VERSION_MAJOR)
#define GA_64_BIT
#else
#define GA_32_BIT
#endif
#endif
