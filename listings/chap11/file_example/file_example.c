int smth[]={1,2,3,4,5};
FILE* f = fopen( "hello.img", "rwb" ); 

fread( smth, sizeof(int), 1, f); 

/* This line is optional. By means of `fseek` function we can 
   navigate the file */
fseek( f, 0, SEEK_SET ); 

fwrite(smth, 5 * sizeof( int ), 1, f); 
fclose( f ); 

