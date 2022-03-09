
%ifndef _INC_ASM_
%define _INC_ASM_

%macro psh 1		  ; mac psh register do
	push %1			  ; 	push register
	%endmacro		  ; 	end

%macro cll 1		  ; mac cll function do
	call %1			  ; 	call function
	%endmacro		  ; 	end

%macro ext 1		  ; mac ext code do
	mov rax, 60		  ; 	rax = SYS_EXIT
	mov dil, %1 	  ; 	dil = code
	syscall			  ; 	SYS_EXIT code
	%endmacro		  ; 	end

%endif

; general purpose registers
; 64-bit | 32-bit | 16-bit | 8h-bit | 8l-bit | description
; rax    | eax    | ax     | ah     | al     | accumulator
; rbx    | ebx    | bx     | bh     | bl     | base
; rcx    | ecx    | cx     | ch     | cl     | counter
; rdx    | edx    | dx     | dh     | dl     | data
; rsi    | esi    | si     | n/a    | sil    | source
; rdi    | edi    | di     | n/a    | dil    | destination
; rsp    | esp    | sp     | n/a    | spl    | stack pointer
; rbp    | ebp    | bp     | n/a    | bpl    | stack base pointer

; parameter registers
; function call: rdi, rsi, rdx, rcx, r8, r9
; system call: rdi, rsi, rdx, r10, r8, r9

