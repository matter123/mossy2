;  Copyright 2013 Matthew Fosdick

;  Licensed under the Apache License, Version 2.0 (the "License");
;  you may not use this file except in compliance with the License.
;  You may obtain a copy of the License at

;    http://www.apache.org/licenses/LICENSE-2.0

;  Unless required by applicable law or agreed to in writing, software
;  distributed under the License is distributed on an "AS IS" BASIS,
;  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
;  See the License for the specific language governing permissions and
;  limitations under the License.
[SECTION .text]
%macro push_x86 0
push gs
push fs
push es
push ds
push dword ebp
push dword eax
push dword ebx
push dword ecx
push dword edx
push dword esi
push dword edi
mov  eax, cr0
push eax
mov  eax, cr2
push eax
mov  eax, cr3
push eax
mov  eax, cr4
push eax
%endmacro

%macro pop_x86 0
add esp, 16
pop dword edi
pop dword esi
pop dword edx
pop dword ecx
pop dword ebx
pop dword eax
pop dword ebp
pop ds
pop es
pop fs
pop gs
%endmacro

%macro EXCEPT_C 2
[global exc%1]
exc%1:
	push dword %1
	%ifdef DEBUG
	push dword %2
	%else
	push dword 0
	%endif
	jmp fail_fast
	dd fail_fast ;stores the absolute address of fail_fast so i can properly path the jmp
%endmacro

%macro EXCEPT_NC 2
[global exc%1]
exc%1:
	push dword 0
	push dword %1
	%ifdef DEBUG
	push dword %2
	%else
	push dword 0
	%endif
	jmp fail_fast
	dd fail_fast
%endmacro

[EXTERN _ZN3hal9fail_fastEP9cpu_state]
fail_fast:
	push_x86
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	push esp
	call _ZN3hal9fail_fastEP9cpu_state
	jmp .past
	.blidt:
	dd 0
	dw 0
	.past:
	mov eax, .blidt
	lidt [eax]
	xor bx, bx
	div bx
	iret ;shouldn't get to here, the div should triple fault the cpu

[GLOBAL exc_stub_sched]
[EXTERN _ZN3hal11call_handleEP9cpu_state]
[EXTERN _ZN6kernel8scheduleEP9cpu_state]
exc_stub_sched:
	;xchg bx, bx
	cmp dword [esp + 4], 0xC0
	jne .test_kern
	;xchg bx, bx
	.test_kern:
	push_x86
	;clean up segment selectors
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	;handle interrupt
	push esp
	call _ZN3hal11call_handleEP9cpu_state
	add esp, 4
	;schedule new kernel task
	push esp
	call _ZN6kernel8scheduleEP9cpu_state
	add esp , 4
	mov esp, eax
	;clean up stack
	pop_x86
	add esp, 12
	iretd