section .data
w_plus:
	dq w_mul		; previous
	db '+',0
	db 0
xt_plus:		
	dq plus_impl
section .text
	plus_impl:
		pop rax
		add [rsp], rax
		jmp next
