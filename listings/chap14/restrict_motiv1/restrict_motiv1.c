void f(int* restrict x, int* restrict add) {
    *x += *add;
    *x += *add;
}
