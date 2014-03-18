/*
 * Copyright 2013 Matthew Fosdick

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
#if ARCH = x64
#define X64
#ifndef asm
typedef uint64_t uintReg_t;
#endif
#elif ARCH = x86
#define X86
#ifndef asm
typedef uint32_t uintReg_t;
#endif
#endif