int x; 
int y;

int const* px = &x;
int * py = &y;

py = px; /* Error, const qualifier is discarded */
px = py; /* OK */
