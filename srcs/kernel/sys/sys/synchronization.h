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
#include <arch.h>
namespace kernel {
	class spinlock {
			uint32_t lock;
		public:
			uintptr_t acquire();
			void release(uintptr_t reg);
			bool check();
	};

	class semaphore {
		private:
			spinlock *s;
			int free_count;
		public:
			semaphore(int free_count);
			~semaphore();
			void wait();
			void signal();
			int get_free();
	};

	class mutex {
		private:
			semaphore *s;
		public:
			mutex();
			~mutex();
			void lock();
			void unlock();
	};
}