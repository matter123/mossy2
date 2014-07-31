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
#include <stdint.h>
#include <arch.h>
#include <struct.h>
namespace hal {
	class mem_type {
		public:
			bool avil:1;
			bool resv_mem:1;
			bool kernel:1;
			bool bootinfo:1;
			bool firmware:1;
			bool videobuffer:1;
			bool dma:1;
			bool no_exist:1;
			bool pci_mmap:1;
			bool save_on_hib:1;
			//VMMAP only
			bool heap:1;
			bool userspace:1;
			bool kthread_stacks:1;
			bool paging_struct:1;
			bool is_more_restrictive(mem_type other) const;
			bool can_adjust_start() const;
			bool can_shrink() const;
			bool can_grow() const;
			bool operator==(const mem_type &other) const;
			uint64_t to_u64() const;
			mem_type(mem_type &other);
			mem_type();
		private:
			uint resv_n:2;
			uint16_t resv_2=0;
			uint32_t resv_1=0;
	} PACKED;
	struct mem_region {
		uint64_t start;
		uint64_t end;
		mem_type type;
	} PACKED;
	struct mem_regs {
		mem_region *regions;
		uint64_t tag_count;
	};
	mem_regs *remove_invalid(mem_regs *regs);
	mem_regs *sort(mem_regs *regs);
	mem_regs *split(mem_regs *regs);
	mem_regs *page_align(mem_regs *regs);
	mem_regs *fill(mem_regs *regs);
}