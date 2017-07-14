struct p {
    long x;
    long y;
    long z;
};

__attribute__((noinline))
    struct p f(void) {
        struct p copy;
        copy.x = 1; 
        copy.y = 2;
        copy.z = 3;
        return copy;
    }

int main(int argc, char** argv) {
    volatile struct p inst = f();
    return 0;
}
