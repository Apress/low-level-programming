union dword {
    int integer; 
    short shorts[2]; 
};

...
dword test;
test.integer = 0xAABBCCDD;
