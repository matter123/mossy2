/*
    Copyright 2014-15 Matthew Fosdick

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
#include <stdint.h>
namespace acpi {
	struct SDT {
		SDT(pointer table);
		char signature[5];
		uint8_t revision;
		char OEM_ID[7];
		char OEM_TABLE_ID[9];
		uint32_t OEM_revision;
		uint32_t creator_ID;
		uint32_t creator_revision;
		void *phys_table_addr;
	};
}