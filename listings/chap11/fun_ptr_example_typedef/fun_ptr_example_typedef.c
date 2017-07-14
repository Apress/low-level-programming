double doubler (int a) { return a * 2.5; }
typedef double (megapointer_type)( int );

...
double a;
megapointer_type* variable = &doubler;
a = variable(10); /* a = 25.0 */
