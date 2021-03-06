/*
	Copyright 2016 Matthew Fosdick
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
namespace hal {
	//multiboot2 version 1.6
	struct multiboot_header {
		uint32_t size;
		uint32_t resv;
	} PACKED;
	struct multiboot_tag {
		uint32_t type;
		uint32_t size;
	} PACKED;
	struct multiboot_command {
		multiboot_tag head;
		char string[1]; //extends past end
	} PACKED;
	struct multiboot_module {
		multiboot_tag head;
		uintptr_t mod_start;
		uintptr_t mod_end;
		char string[1];
	} PACKED;
	struct multiboot_module_int {
		multiboot_tag head;
		uint32_t mod_start;
		uint32_t mod_end;
		char string[1];
	} PACKED;
	struct multiboot_mmap_ent {
		uint64_t addr;
		uint64_t len;
		uint32_t type;
		uint32_t resv;
	} PACKED;
	struct multiboot_vbe {
		multiboot_tag head;
		uint16_t vbe_mode;
		uint16_t vbe_interface_seg;
		uint16_t vbe_interface_off;
		uint16_t vbe_interface_len;
		uint8_t vbe_control_info[512];
		uint8_t vbe_mode_info[256];
	} PACKED;
	struct multiboot_fb {
		multiboot_tag head;
		uint64_t addr;
		uint32_t pitch;
		uint32_t width;
		uint32_t height;
		uint8_t bpp;
		uint8_t type;
		uint8_t rsv;
	} PACKED;
	struct multiboot_palette {
		uint8_t red;
		uint8_t green;
		uint8_t blue;
	} PACKED;
	struct multiboot_ci_1 {
		uint8_t red_pos;
		uint8_t red_mask;
		uint8_t green_pos;
		uint8_t green_mask;
		uint8_t blue_pos;
		uint8_t blue_mask;
	} PACKED;
	struct multiboot_mmap {
		multiboot_tag head;
		uint32_t entry_size;
		uint32_t entry_version;
		multiboot_mmap_ent entries[1];
	} PACKED;
	struct multiboot_ci_0 {
		uint32_t num_color;
		multiboot_palette palette[1];
	} PACKED;
	void init_mboot(multiboot_header *mboot)RUN_ONCE;
	//multiboot_header *get_header(); //not sure if relevant
	int get_tag_count();
	multiboot_tag *get_tag(int count);

	const int t_end_marker  = 0;
	const int t_cmd_line    = 1;
	const int t_bootloader  = 2;
	const int t_module      = 3;
	const int t_basic_mem   = 4;
	const int t_boot_device = 5;
	const int t_memory_map  = 6;
	const int t_vbe_info    = 7;
	const int t_framebuffer = 8;
	const int t_elf_symbols = 9;
	const int t_apm_table   = 10;
}
