int x = 0;
int* p = &x;
...
/* there are no writes to `p` in these lines */ 
int** z = &p;
*z = NULL; /* Still not a direct write to `p` */
...
*p = 10; /* this pointer can not be NULL */
