#define x1 "Hello"
#define x2 " World"

#define str(i) x##i

puts( str(1) );  /* str(1) -> x1 -> "Hello" */
puts( str(2) );  /* str(2) -> x2 -> " World" */
