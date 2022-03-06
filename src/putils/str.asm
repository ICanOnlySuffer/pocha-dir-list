%include "base.inc"

str_len:					  ; u16 str_len u64: buffer do
	mov ax, -1				  ; 	ax = -1
	dec rdi					  ; 	rsi--
	str_len_loop:			  ; 	do
		inc ax				  ; 		ax++
		inc rdi				  ; 		rsi++
		cmp [rdi], byte 0	  ; 		cmp *rsi, 0
		jne str_len_loop	  ; 		until *rsi == 0
	ret						  ; 	ret

str_rvs:					  ; nil str_rvs u64: string do
	mov rax, 0				  ; 	rax = 0
	psh rdi					  ; 	STACK << string
	call str_len 			  ; 	ax = str_len string
	mov rcx, [rsp]			  ; 	rcx = STACK.last
	add rcx, rax			  ; 	rcx += rax
	mov rdx, 0				  ; 	rdx = 0
	mov rdi, 2				  ; 	rdi = 2
	div rdi					  ; 	rax, rdx = div_mod rdx:rax, rdi
	pop rdi					  ; 	rdi = STACK.pop
	dec rdi					  ; 	rdi--
	str_rvs_loop:			  ; 	do
		dec rax				  ; 		rax--
		mov dl, [rdi]		  ; 		dl = *rdi
		mov dh, [rcx]		  ; 		dh = *rcx
		mov [rdi], dh		  ; 		*rdi = dh
		mov [rcx], dl		  ; 		*rcx = dl
		inc rdi				  ; 		rdi++
		dec rcx				  ; 		dec rcx
		cmp rax, -1			  ; 		cmp rax, -1
		jne str_rvs_loop	  ; 		until rax == -1
	ret

%ifdef COMMENT
str_tou:					  ; u64 str_tou u64: string do
	psh rdi					  ; 	STACK << string
	pop rdi
	mov rax, 69
	ret						  ; 	ret
%endif

u64_tos:					  ; nil u64_tos u64: number, u64: buffer do
	psh rsi					  ; 	STACK << buffer
	mov rax, rdi			  ; 	rax = number
	u64_tos_loop:			  ; 	do
		mov rdx, 0			  ; 		rdx = 0
		mov rdi, 10			  ; 		rdi = 10
		div rdi				  ; 		rax, rdx = div_mod rdx:rax, rdi
		add dl, 48			  ; 		dl += 48
		mov [rsi], dl		  ; 		*rsi = dl
		inc rsi				  ; 		rsi++
		cmp rax, 0			  ; 		cmp rax, 0
		jne u64_tos_loop	  ; 		until rax == 0
	mov [rsi], byte 0		  ; 	*rsi = 0
	pop rdi					  ; 	rdi = STACK.pop
	cll str_rvs				  ; 	str_rvs rdi
	ret						  ; 	ret

section .text
	global str_len
	global str_rvs
	global u64_tos

