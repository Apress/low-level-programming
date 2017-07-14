int add(int* p, int add ) {
    bool done = false;
    int value;
    while (!done) {
        value = *p
            done = cas(p, value, value + add );
    }
    return value + add;
}
