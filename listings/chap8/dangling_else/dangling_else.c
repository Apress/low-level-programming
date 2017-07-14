if (x == 0)   if (y == 0) { puts("A"); }  else { puts("B"); }

/* You might have considered one of the following interpretations.
 * The compiler can issue a warning to prevent you */

if (x == 0) { 
    if (y == 0) { printf("A"); }  
    else { puts("B"); } 
}

if (x == 0) {
    if (y == 0) { puts("A"); } 
} else { puts("B"); }
