%include "cor.inc"

fil_put:				  ; nil fil_put u64:fil u64:str dos
	psh rdi				  ; 	STK.psh fil
	mov rdi, rsi		  ; 	__0  =  str
	cll str_len			  ; 	out  =  str_len.cll __0
	mov rdx, rax		  ; 	__2  =  out
	pop rdi				  ; 	__0  =  STK.pop
	mov rax, SYS_WRT	  ; 	out  =  SYS_WRT
	syscall				  ; 	SYS_WRT.cll __0 __1 __2
	ret					  ; 	ret

fil_put_chr:			  ; nil fil_put_chr u64:fil u08:chr dos
	psh rsi				  ; 	STK.psh __1
	mov rsi, rsp		  ; 	__1  =  STK.lst
	mov rdx, 1			  ; 	__2  =  1
	mov rax, SYS_WRT	  ; 	out  =  SYS_WRT
	syscall				  ; 	sys_cll SYS_WRT __0 __1 __2
	pop rsi				  ; 	__1  =  STK.pop
	ret					  ; 	ret

fil_put_arr:				  ; nil fil_put_arr u64:fil u16:len u64:arr dos
	mov r8, rdi				  ; 	__4  =  fil
	mov r9w, si				  ; 	__5  =  len
	mov r10, rdx			  ; 	__6  =  arr
	fil_put_arr_loop:		  ; 	dos
		mov rdi, [r10]		  ; 		__0  =  __6.val
		cll str_len			  ; 		out  =  str_len.cll __0
		mov rdx, rax		  ; 		__2  =  out
		mov rsi, [r10]		  ; 		__1  =  __6.val
		mov rdi, r8			  ; 		__0  =  __4
		mov rax, SYS_WRT	  ; 		out  =  SYS_WRT
		syscall				  ; 		sys_cll SYS_WRT __0 __1 __2
		add r10, 8			  ; 		__6.inc
		dec r9w				  ; 		__5.dec
		cmp r9w, 0			  ; 		cmp __5 0
		jne fil_put_arr_loop  ; 		utl __5 equ 0
	ret						  ; 	ret

section .text			  ; sec txt
	extern str_len		  ; 	ext str_len u64:str
	global fil_put		  ; 	exp fil_put u64:fil u64:str
	global fil_put_chr	  ; 	exp fil_put_chr u64:fil u08:chr
	global fil_put_arr	  ; 	exp fil_put_arr u64:fil u16:len u64:arr

