void f(void) {
    g();   /* What is `g`, asks mr. Compiler? */
}

void g(void) {
    f();
}
