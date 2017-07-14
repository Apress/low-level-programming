int x = 0;
int y = 0;

void thread1(void) {
    print(y);
    x = 1;
}

void thread2(void) {
    print(x);
    y = 1;
}
