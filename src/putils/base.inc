
%macro psh 1
	push %1
	%endmacro

%macro cll 1
	call %1
	%endmacro

%macro ext 1		  ; mac ext code do
	mov rax, 60		  ; 	rax = SYS_EXIT
	mov dil, %1 	  ; 	dil = code
	syscall			  ; 	SYS_EXIT code
	%endmacro		  : 	end

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

; pointer registers
; 64-bit | 32-bit | 16-bit | description
; rip    | eip    | ip     | instruction pointer

