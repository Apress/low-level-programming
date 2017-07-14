int demo (void) 
{
    static int a = 42;
    printf("%d\n", a++); 
}

...

demo(); //outputs 42
demo(); //outputs 43
demo(); //outputs 44

