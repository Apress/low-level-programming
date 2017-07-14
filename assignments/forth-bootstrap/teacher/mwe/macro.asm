%define _lw 0
%macro native 3
    section .data
    wh_ %+ %2 : dq _lw
    %define _lw wh %+ %2
    db %1, 0
    db 0 | %3
    xt_ %+ %2 :  dq i_ %+ %2 
    section .text
    i_ %+ %2:
    %define _lw wh_%+ %2 

%endmacro

%macro native 2
native %1, %2, 0
%endmacro

%macro colon 3
section .data 
    wh_ %+ %2 : dq _lw
    %define _lw wh_ %+ %2 
    db %1, 0
    db 0 | %3
    
    
    xt_ %+ %2 : dq i_docol
%endmacro

%macro colon 2
colon %1, %2, 0
%endmacro

