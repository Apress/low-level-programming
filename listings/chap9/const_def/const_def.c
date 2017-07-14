int a;
a = 42 ;  /* ok */

...

const int a; /* compilation error */

... 

const int a = 42; /* ok */
a = 99;  /* compilation error, should not change constant value */



int const a = 42;  /* ok */
const int b = 99;  /* ok, const int === int const */
