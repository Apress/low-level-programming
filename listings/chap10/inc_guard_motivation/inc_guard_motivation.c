/* a.h */
void a(void);

/* b.h */
#include "a.h"
void b(void);


/* main.c */
#include "a.h"
#include "b.h"

