%include "inc.asm"

str_len:					  ; u64 str_len u64: buffer do
	mov rax, -1				  ; 	rax = -1
	dec rdi					  ; 	rsi--
	str_len_loop:			  ; 	do
		inc rax				  ; 		rax++
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

%ifdef COMMENT
; tmp_con PARAMS u64: string, u16: max, u64: strings, u16: n_strings do
str_cpy:						  ; u64 str_cpy PARAMS do
	psh rdi						  ; 	STACK << string
	psh 0						  ; 	STACK << 0 (i)
	psh 1						  ; 	STACK << 1 (size)
	str_cpy_loop_1:				  ; 	do loop_1
		cmp byte[rsp-8], cx		  ; 		cmp i, n_strings
		jnb str_cpy_loop_1_end	  ; 		break if i >= n_strings
		str_cpy_loop_2:			  ; 		do loop_2
			cmp byte[rsp], si	  ; 			cmp size, max
			jnb str_cpy_loop_2_end; 			break if size >= max
			; *string++ = *strings [i]++
			goto str_cpy_loop_2   ;				again
		str_cpy_loop_2_end:		  ; 			end
		dec rdi				 	  ; 		string--
		goto str_loop_1			  ; 		again
	str_loop_1_end:				  ; 		end
	pop rax						  ; 	rax = STACK.pop
	ret							  ; 	end
%endif

section .text
	global str_len
	global str_rvs
	global u64_tos

