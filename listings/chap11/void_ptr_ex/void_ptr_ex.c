void* a = (void*)4; 
short* b = (short*) a;
b ++; /* correct, b = 6 */
b = a; /* correct */
a = b; /* correct */
