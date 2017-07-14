int i;
int j;
for (i = 0; i < 100; i++ )
for( j = 0; j < 100; j++ ) {
    if (i * j == 432)
        goto end;
    else 
        printf("%d * %d != 432\n", i, j );
}
end:
