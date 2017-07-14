int a = 42;         /* Assume this integer's address is 1000 */
int* p_a = &a;     
p_a += 42;          /* 1000 + 42 * sizeof( int ) */
p_a = p_a + 1;      /* 1168 + 1 * sizeof( int ) */
p_a --;             /* 1172 - 1 * sizeof( int ) */
