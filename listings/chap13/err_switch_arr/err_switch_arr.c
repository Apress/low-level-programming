enum error_code {
    ERROR1, 
    ERROR2 
};
...
enum error_code err;
...
switch (err) {
    case ERROR1: ... break;
    case ERROR2: ... break;
    default: ... break;
}

/* alternatively */

static const char* const messages[] = {
    "It is the first error\n",
    "The second error it is\n"
};

fprintf( stderr, messages[err] );
