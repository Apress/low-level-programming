%assign x 1
%assign a 0
%rep 10
%assign a x + a
%assign x x + 1
%endrep

result: dq a
