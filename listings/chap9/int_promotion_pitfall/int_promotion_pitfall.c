/* The lesser types */
unsigned char x = 100, y = 100, z = 100;
unsigned char r = x + y + z; /* will give you 300 % 256 = 44 */

unsigned int r_int = x + y + z; /* equals to 300, because the promotion to
                                   integers is performed first */

/* Now with the greater types */

unsigned int x = 1e9, y = 2e9, z = 3e9;

unsigned int r_int = x + y + z;   /* 1705032704 equals 6000000000 % (2^32) */

unsigned long r_long = x + y + z;   /* the same result: 1705032704 */
