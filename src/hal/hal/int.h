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
#include "../arch/arch.h"
#include <struct.h>
namespace hal {
	uint16_t get_max_interrupt();

	typedef bool (*int_callback)(int level,cpu_state *cpu);

	enum interrupt_type {
		NON_REENTRANT,
		REENTRANT,
	};

	void register_only_int(uint16_t int_num,int_callback callback,interrupt_type type,bool user);

	void register_chain_int(uint16_t int_num,int_callback callback,interrupt_type type,bool user);

	void register_asm_sub_int(uint16_t int_num,uintptr_t addr,interrupt_type type,bool user);

	struct idt_range
	{
		uint16_t start;
		uint16_t len;
	}FULL;

	void a();
	idt_range reserve_range(uint16_t count, uint16_t min_count, bool aligned);

	bool release_range(idt_range range);

	void wait_for_int();
}