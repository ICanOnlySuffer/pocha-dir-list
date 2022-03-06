%include "base.inc"

IOE_IPT equ 0				  ; con IOE_IPT 0
IOE_OPT equ 1				  ; con IOE_OPT 1
IOE_ERR equ 2				  ; con IOE_ERR 2

get_str:					  ; nil get_str u64: buffer, u64: length do
	mov rax, 0				  ; 	rax = SYS_READ
	mov rdx, rsi			  ; 	rdx = length
	mov rsi, rdi			  ; 	rsi = buffer
	mov rdi, IOE_IPT		  ; 	rdi = IOE_IPT
	syscall					  ; 	SYS_READ rdi, rsi, rdx
	ret						  ; 	ret

get_chr:					  ; u08 get_chr do
	psh 0					  ; 	STACK << 0
	mov rax, 0				  ; 	rax = SYS_READ
	mov rdx, 1				  ; 	rdx = 1
	mov rsi, rsp			  ; 	rsi = STACK.ptr
	mov rdi, IOE_IPT		  ; 	rdi = IOE_IPT
	syscall					  ; 	SYS_READ rdi, rsi, rdx
	pop rax					  ; 	al = STACK.pop
	ret						  ; 	ret

put_str:					  ; nil put_str u64: string, u16: length do
	mov rdx, rsi			  ; 	rdx = rax
	mov rsi, rdi			  ; 	rsi = STACK.pop
	mov rdi, IOE_OPT		  ; 	rdi = IOE_OPT
	mov rax, 1				  ; 	rax = SYS_WRITE
	syscall					  ; 	SYS_WRITE rdi, rsi, rdx
	ret						  ; 	ret

put_chr:					  ; nil put_chr u08: char do
	psh rdi					  ; 	STACK << char
	mov rax, 1				  ; 	rax = SYS_WRITE
	mov rdi, IOE_OPT		  ; 	rdi = IOE_OPT
	mov rsi, rsp			  ; 	rsi = STACK.ptr
	mov rdx, 1				  ; 	rdx = 1
	syscall					  ; 	SYS_WRITE rdi, rsi, rdx
	pop rdi					  ; 	char = STACK.pop
	ret						  ; 	ret

section .text
	global get_str
	global get_chr
	global put_str
	global put_chr

