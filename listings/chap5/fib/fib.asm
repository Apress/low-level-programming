fibonacci: 
%assign a 0 
%assign b 1 
%rep 100 
%if b > 65535 
    %exitrep 
%endif 
        dq b 
%assign t a+b 
%assign a b
%assign b t
%endrep 

