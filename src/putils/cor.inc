
%ifndef COR_INC
%define COR_INC

STD_INN equ 0		  ; con STD_INN 0
STD_OUT equ 1		  ; con STD_OUT 1
STD_ERR equ 2		  ; con STD_ERR 2

SYS_RED equ 0		  ; con SYS_RED 0
SYS_WRT equ 1		  ; con SYS_WRT 1
SYS_QUT equ 60		  ; con SUS_QUT 60

%macro psh 1		  ; mac psh val dos
	push %1			  ; 	push val
	%endmacro		  ; 	end

%macro cll 1		  ; mac cll fun dos
	call %1			  ; 	call fun
	%endmacro		  ; 	end

%macro mvz 2		  ; mac mvz reg val dos
	movzx %1, %2	  ; 	movz reg val
	%endmacro		  ; 	end

%macro qut 1		  ; mac qut u08:cde dos
	mov rax, SYS_QUT  ; 	u64 sys <-- SYS_QUT
	mov dil, %1 	  ; 	u08 __0 <-- cde
	syscall			  ; 	SYS_QUT.cll __0
	%endmacro		  ; 	end

%macro psh_all 0	  ; mac psh_all nil dos
	psh rax
	psh rdi
	psh rsi
	psh rdx
	psh rcx
	psh r8
	psh r9
	%endmacro		  ; 	end

%macro pop_all 0	  ; mac pop_all nil dos
	pop r9
	pop r8
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	pop rax
	%endmacro		  ; 	end

%endif ; COR_INC

; registers
; 64bit | 32bit | 16bit | 8hbit | 8lbit | keep | description
; rax   | eax   | ax    | ah    | al    | no   | returned
; rcx   | ecx   | cx    | ch    | cl    | no   | parameter #4 (cmp out)
; rdx   | edx   | dx    | dh    | dl    | no   | parameter #3
; rbx   | ebx   | bx    | bh    | bl    | yes  | -
; rsp   | esp   | sp    | n/a   | spl   | yes  | stack pointer
; rbp   | ebp   | bp    | n/a   | bpl   | yes  | stack base pointer
; rsi   | esi   | si    | n/a   | sil   | no   | parameter #2
; rdi   | edi   | di    | n/a   | dil   | no   | parameter #1
; r8    | r8d   | r8w   | n/a   | r8b   | no   | parameter #5
; r9    | r9d   | r9w   | n/a   | r9b   | no   | parameter #6
; r10   | r10d  | r10w  | r10w  | r10b  | no   | parameter #7

; parameter registers
; fun cll: rdi, rsi, rdx, rcx, r8, r9
; sys cll: rdi, rsi, rdx, r10, r8, r9

