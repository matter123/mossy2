/*
    Copyright 2014 Matthew Fosdick

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#pragma once

/**
    @file
    @brief header included into every file
    @details this header contains #%defines and typedefs
    that should be in every single file
    @note never manually include this file
*/
#ifndef ASM
#include <stdint.h>
#include "include/struct.h"

#ifdef __cplusplus
#include "include/panic.h"
#endif
typedef uint8_t *pointer;
#endif
