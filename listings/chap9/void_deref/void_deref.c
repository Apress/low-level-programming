int a = 10;
void* pa = &a;

printf("%d\n", *( (int*) pa) );
