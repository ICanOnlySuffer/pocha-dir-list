%include "cor.inc"

str_len:					  ; u64 str_len u64:str dos
	mov rax, -1				  ; 	u64 out  =  -1
	dec rdi					  ; 	str.dec
	str_len_loop:			  ; 	dos
		inc rax				  ; 		out.inc
		inc rdi				  ; 		str.inc
		cmp [rdi], byte 0	  ; 		cmp rsi.val 0
		jne str_len_loop	  ; 		utl rsi.val equ 0
	ret						  ; 	ret

str_chp:					  ; nil str_chp u64:str dos
	cll str_len				  ; 	u64 len  =  str_len.cll str
	mov [rdi-1], byte 0		  ; 	str.dec.val  =  0
	ret						  ; 	end

str_cmp:					  ; s16 str_cmp u64:s_1 u64:s_2 dos
	mvz ax, byte [rdi]		  ; 	s16 out  =  ( s16 ) s_1.val
	test al, al				  ; 	tst out.low out.low
	je str_cmp_end			  ; 	gto end iff out[0:8]
	str_cmp_loop:			  ; 	dos
		cmp byte [rsi], al	  ; 		cmp s_2.val s_1.val
		jne str_cmp_end		  ; 		gto end iff s_2.val neq s_1.val
		inc rdi				  ; 		s_1.inc
		inc rsi				  ; 		s_2.inc
		mvz ax, byte [rdi]	  ; 		out  =  ( s16 ) s_1.val
		test al, al			  ; 		tst out.low out.low
		jne str_cmp_loop	  ; 		utl out.low
	str_cmp_end:			  ; 	end:
	movsx dx, byte [rsi]	  ; 	s16 lst  =  ( s16 ) s_2.val
	sub ax, dx				  ; 	out <-< lst
	ret						  ; 	end

str_rvs:					  ; nil str_rvs u64:str dos
	mov rax, 0				  ; 	u64 out  =  0
	psh rdi					  ; 	STK <<< string
	call str_len 			  ; 	out[0:2]  =  str_len.cll str
	mov rcx, [rsp]			  ; 	u64 rcx  =  STK.lst.val
	add rcx, rax			  ; 	rcx  =  len
	mov rdx, 0				  ; 	rdx  =  0
	mov rdi, 2				  ; 	rdi  =  2
	div rdi					  ; 	out rdx  =  div_mod rdx:rax rdi
	pop rdi					  ; 	rdi  =  STK.pop
	dec rdi					  ; 	rdi.dec
	str_rvs_loop:			  ; 	dos
		dec rax				  ; 		rax.dec
		mov dl, [rdi]		  ; 		dl  =  rdi.val
		mov dh, [rcx]		  ; 		dh  =  rcx.val
		mov [rdi], dh		  ; 		rdi.val  =  dh
		mov [rcx], dl		  ; 		rcx.val  =  dl
		inc rdi				  ; 		rdi.inc
		dec rcx				  ; 		dec rcx
		cmp rax, -1			  ; 		cmp rax -1
		jne str_rvs_loop	  ; 		utl rax equ -1
	ret						  ; 	ret

str_cpy:						  ; u64 str_cpy u64:str u16:len u64:arr dos
	psh rdi						  ; 	STK.psh str
	str_cpy_loop_1:				  ; 	dos
		mov r8, [rdx]			  ; 		u64 tmp  =  arr.val
		str_cpy_loop_2:			  ; 		dos
			mov r9b, [r8]		  ; 			u08 chr  =  tmp.val
			cmp r9b, 0			  ; 			cmp chr 0
			je str_cpy_loop_2_end ; 			brk iff chr equ 0
			mov [rdi], r9b		  ; 			str.val  =  c
			inc rdi				  ; 			str.inc
			inc r8				  ; 			tmp.inc
			jmp str_cpy_loop_2	  ;				agn
		str_cpy_loop_2_end:		  ; 			end
		add rdx, 8				  ; 		arr.inc
		dec sil					  ; 		len.dec
		cmp sil, 0				  ; 		cmp len 0
		jnz str_cpy_loop_1		  ; 		utl len equ 0
	mov [rdi], byte 0			  ; 	str.val  =  0
	pop rax						  ; 	u64 out  =  STK.pop ### start
	ret							  ; 	end

str_frm_u64:				  ; nil str_frm_u64 u64:bff u64:num dos
	psh rdi					  ; 	STK.psh bff
	mov rax, rsi			  ; 	u64 out  =  num
	u64_tos_loop:			  ; 	dos
		mov rdx, 0			  ; 		u64 rdx  =  0
		mov rsi, 10			  ; 		u64 rdi  =  10
		div rsi				  ; 		rax rdx  =  div_mod rdx:rax rdi
		add dl, 48			  ; 		rdx [0 : 8] ++= 48
		mov [rdi], dl		  ; 		rsi.val  =  rdx [0 : 8]
		inc rdi				  ; 		rsi.inc
		cmp rax, 0			  ; 		cmp rax 0
		jne u64_tos_loop	  ; 		utl rax equ 0
	mov [rdi], byte 0		  ; 	rsi.val  =  0
	pop rdi					  ; 	rdi  =  STK.pop
	cll str_rvs				  ; 	str_rvs.cll rdi
	ret						  ; 	ret

section .text					  ; sec txt
	global str_len				  ; 	exp str_len u64:str
	global str_chp				  ; 	exp str_chp u64:str
	global str_rvs				  ; 	exp str_rvs u64:str
	global str_cmp				  ; 	exp str_cmp u64:s_1 u64:s_2
	global str_cpy				  ; 	exp str_cpy u64:str u16:len u64:arr
	global str_frm_u64			  ; 	exp str_frm_u64 u64:bff u64:num

