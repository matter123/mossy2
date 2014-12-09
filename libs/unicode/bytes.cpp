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
#include <stdint.h>
namespace unicode {
	bytes::bytes(char * string) {
		this->data=string;
		this->begin=string;
		this->end=NULL;
	}
	uint8_t bytes::next() {
		return (uint8_t)*++data;
	}
	uint8_t bytes::prev() {
		return (uint8_t)*--data;
	}
	uint8_t bytes::value() {
		return (uint8_t)*data;
	}
	uint8_t bytes::begin() {
		data=begin;
		return (uint8_t)*data;
	}
	uint8_t bytes::end() {
		if(end==NULL) {
			while(*data)data++;
			data--;
			end=data;
		}
		return (uint8_t)*data;
	}

	bool bytes::has_next() {
		if(*(data+1)) {
			return true;
		}
		end=data;
		return false;
	}
	bool bytes::has_prev() {
		return data>begin;
	}
}