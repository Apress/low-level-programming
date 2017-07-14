%assign limit 15
is_prime: db 0, 0, 1
%assign n 3
%rep limit 
    %assign current 1
    %assign i 1
        %rep n/2
           %assign i i+1
           %if n % i = 0
                %assign current 0
                %exitrep
           %endif
        %endrep
db current ; n
    %assign n n+1
%endrep
