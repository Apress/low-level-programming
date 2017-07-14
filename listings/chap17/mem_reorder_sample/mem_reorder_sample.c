int x = 0;
int y = 0;

void thread1(void) {
    x = 1;
    print(y);
}

void thread2(void) {
    y = 1;
    print(x);
}
