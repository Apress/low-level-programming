
%line 73+1 macro_arg_types/macro_arg_types.asm

myhello: db 'hello', 10, 0
_start:
 mov rdi, myhello
%line 76+0 macro_arg_types/macro_arg_types.asm
 call print_string

%line 77+1 macro_arg_types/macro_arg_types.asm

%line 77+0 macro_arg_types/macro_arg_types.asm
 mov rdi, 42
 call print_uint

%line 78+1 macro_arg_types/macro_arg_types.asm
 mov rax, 60
 syscall

