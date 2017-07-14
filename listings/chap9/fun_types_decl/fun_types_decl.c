typedef double (proc)(int);

/* declaration */
proc myproc;

/* ... */

/* definition */
double myproc( int x ) { return 42.0 + x; }
