%macro pushr 1
%ifidn %1, rflags
pushf 
%else 
push %1
%endif
%endmacro

pushr rax
pushr rflags
