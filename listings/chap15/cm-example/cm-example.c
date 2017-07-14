char glob_small[100] = {1};
char glob_big[10000000] = {1};
static char loc_small[100] = {1};
static char loc_big[10000000] = {1};

int global_f(void) { return 42; }
static int local_f(void) { return 42; }

int main(void) {
    glob_small[0] = 42;
    glob_big[0] = 42;
    loc_small[0] = 42;
    loc_big[0] = 42;
    global_f();
    local_f();
    return 0;
}
