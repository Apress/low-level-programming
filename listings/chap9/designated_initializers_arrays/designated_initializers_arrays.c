int whitespace[256] = { 
    [' ' ] = 1, 
    ['\t'] = 1, 
    ['\f'] = 1, 
    ['\n'] = 1, 
    ['\r'] = 1 };

enum colors {
    RED,
    GREEN,
    BLUE,
    MAGENTA,
    YELLOW 
};

int good[5] = { [ RED ] = 1, [ MAGENTA ] = 1 };
