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

void *__dso_handle;

int __cxa_atexit(void (*destructor)(void *), void *arg, void *dso) {
	return 0;
}
void __cxa_finalize(void *f) {
}
void __cxa_pure_virtual() {
}
void __cxa_guard_acquire() {
}
void __cxa_guard_release() {
}
