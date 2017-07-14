int x = 10;
int* px = &x; /* Took address of `x` and assigned it to `px` */

*px = 42; /* We modified `x` here! */
printf( "*px = %d\n", *px ); /* outputs: '*px = 42' */
printf( "x = %d\n", x ); /* outputs: 'x = 42' */
