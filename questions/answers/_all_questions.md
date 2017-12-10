# Questions

1. It is time to make a first research based on the documentation
[Intel 64 and IA-32 Architectures Software Developer's Manual]. Refer to the section 3. 4. 3 of the first volume to learn
about register `rflags`. What is the meaning of flags `CF`,
`AF`, `ZF`, `OF`, `SF`? What is the difference
between `OF` and `CF`? 

2. What are the key principles of von Neumann architecture? 

3. What are registers?

4. What is the hardware stack?

5. What are the interrupts?

6. What are the main problems that the modern extensions of von Neumann
model are trying to solve?

7. What are the main general purpose registers of Intel 64?

8. What is the purpose of stack pointer?

9. Can the stack be empty?

10. Can we count elements in stack?

11. What does instruction `xor rdi, rdi` do?

12. What is the program return code?

13. What is the first argument of the `exit` system call?


14. Check that the ASCII codes mentioned in the last example are correct.


15. What is the difference between `sar` and `shr`? Check Intel docs.

16. How to write numbers in different number systems in a way understandable to
NASM? Check NASM documentation.

17. What is the difference between `je` and `jz`?

18. What is `test` equal to after each of these instructions?

```asm
section .data
test: dq -1

section .text

mov byte[test], 1	;1
mov word[test], 1	;2
mov dword[test], 1	;4
mov qword[test], 1	;8
```


19. Can you spot a bug or two in Listing `strlen_bug1. asm`?
When will they occur?

```asm
global _start

section .data

test_string: db "abcdef", 0

section .text

strlen:                       
.loop:                        
cmp byte [rdi+r13], 0     
je .end                   
inc r13                   
jmp .loop
.end:
mov rax, r13
ret                       

_start:
mov rdi, test_string
call strlen
mov rdi, rax

mov rax, 60
syscall
```


20. \labelq:tail_call_asm
Try to rewrite `print_newline` without calling `print_char` nor
copying its code.

Hint:  read about tail call optimization.

21. Try to rewrite `print_int` without calling `print_uint` nor
copying its code.

Hint:  read about tail call optimization.

22. Try to rewrite `print_int` without calling `print_uint` nor
copying its code, nor using `jmp`. You will only need one instruction
and a careful code placement.

Read about co-routines.


23. What is the connection between `rax`, `eax`, `ax`, `ah` and `al`?


24. How to gain access to the parts of `r9`?


25. How can you work with hardware stack? Describe the instructions you can use.

26. Which ones of these instructions are incorrect and why?
```asm
mov [rax], 0
cmp [rdx], bl
mov bh, bl
mov al, al
add bpl, 9
add [9], spl
mov r8d, r9d
mov r3b, al
mov r9w, r2d
mov rcx, [rax + rbx + rdx]
mov r9, [r9 + 8*rax]
mov [r8+r7+10], 6
mov [r8+r7+10], r6
```

27. Enumerate the Callee Saved Registers

28. Enumerate the Caller Saved Registers

29. What is the meaning of `rip` register?

30. What is the SF flag?

31. What is the ZF flag?

32. Describe the effects of the following instructions:
\beginitemize
\item `sar `
\item `shr`
\item `xor`
\item `jmp`
\item `ja`, `jb` and similar ones.
\item `cmp`
\item `mov`
\item `inc`,`dec`
\item `add`
\item `imul, mul`
\item `sub`
\item `idiv, div`
\item `call, ret`
\item `push, pop`
\enditemize


33. What is a label and does it have a size?

34. How to check whether an integer number is contained in a certain range $(x,y)$?

35. What is the difference between `ja`/`jb` and `jg`/`jl`?

36. What is the difference `je` and `jz`?

37. How to test whether `rax` is zero without `cmp` command?

38. What is the program return code?

39. How do we multiply `rax` by 9 using exactly one instruction?

40. By using exactly two instructions (first one is `neg`), take an absolute
value of an integer stored in `rax`.

41. What is the difference between Little and Big Endian?

42. What is the most complex type of addressing?

43. Where does the program execution start?

44. `rax` = `0x1122334455667788`. We have performed `push rax`.
What will be the contents of byte at address `[rsp+3]` ?

45. Decypher this segment selector: `0x08`.

46. Read about microcode in general and processor pipelines.

47. Read about different replacement strategies. What other strategies exist?

48. Read about meaning of the fourth (`08:01`) and fifth
(`144225`) column in `man procfs`.

49. What is associative cache? Why is TLB one?

50. What is virtual memory region?

51. What will happen if you try to modify the program execution code during its
execution?

52. What are forbidden addresses?

53. What is a canonical address?

54. What are the translation tables?

55. What is a page frame?

56. What is a memory region?

57. What is the virtual address space? How is it different from the
physical one?

58. What is a Translation Lookaside Buffer? 
59. What makes the virtual memory mechanism performant?

60. How is the address space switched?

61. Which protection mechanisms does the virtual memory incorporate?

62. What is the purpose of `EXB` bit?

63. What is the structure of the virtual address?

64. Does virtual and physical address have a part in common?

65. Can we write a string in `.text` section? What happens if we read it?
And if we overwrite it?

66. Write a program that will call `stat`, `open` and `mmap`
system calls (check the system calls table in Appendix~C). It should
output the file length and its contents.

67. Write the following programs, that all map a text file `input.txt`
containing an integer $x$ in memory using `mmap` system call, and output
the following:
\beginenumerate
    \item $x!$ (factorial, $x!= 1 \cdot 2 \cdot \dots \cdot (x-1) \cdot x$).
        It is guaranteed that $x \geq 0$.
    \item 0 if the input number is prime, 1 otherwise.
    \item Sum of all number's digits.
    \item $x$-th Fibonacci number.
    \item Checks if $x$ is a Fibonacci number.
\endenumerate


68. Find more examples of `%define` and `%macro` usage in NASM
documentation.

69. Check the preprocessor output on file, shown in Listing
`defining_in_cla.asm`:
```asm
%ifdef flag
hellostring: db "Hello",0
%endif 
```

70. Modify the macro the way it would produce a bit table, taking 8 times less
space in memory. Add a function that will check number for primarity and return
0 or 1, based on this precomputed table.

Hint: for the macro you will probably have to copy and paste a lot.

71. Why `ld` issues a warning if `_start` is not marked global?
Look the entry point address in this case by using `readelf` with
appropriate arguments.

72. Find out the `ld` option to automatically strip symbol table after linking.

73. Study the symbol tables for an obtained shared object using
`readelf --dyn-syms` and `objdump -ft`

74. What is the meaning behind the environment variable `LD_LIBRARY_PATH`?

75. Separate the first assignment into two modules. The first module will
store all functions defined in `lib.inc`. The second will have the
entry point and will call some of these functions.

76. Take one of the standard Linux utilities (from coreutils). Study its
object file structure using `readelf` and `objdump`.

77. What is the linked list?

78. What are the compilation stages?

79. What is preprocessing?

80. What is a macro instantiation?

81. What is the `%define` directive?

82. What is the `%macro` directive?

83. What is the difference between  `%define`, `%xdefine` and
    `%assign`?

84. Why do we need the `%%` operator inside macro?

85. What types of conditions are supported by NASM macroprocessor? Which
directives are used for it?

86. What are the three types of ELF object files?

87. What kind of headers are present in an ELF file?

88. What is relocation?

89. What sections can be present in ELF files?

90. What is a symbol table? What kind of information does it store?

91. Is there a connection between sections and segments?

92. Is there a connection between assembly sections and ELF sections?

93. What symbol marks the program entry point?

94. Which are the two different kind of libraries?

95. Is there a difference between a static library and a relocatable object file?

96. What are non-maskable interrupts? What is their connection with the interrupt
with code 2 and `IF` flag?

97. Is the `TF` flag cleared automatically when entering interrupt handlers?
Refer to [Intel 64 and IA-32 Architectures Software Developer's Manual].

98. What is an interrupt?

99. What is IDT?

100. What does setting IF change?

101. In which situation does the #GP error occur?

102. In which situations does the #PF error occur?

103. How is #PF error related to the swapping? How does the operating system
use it?

104. Can we implement system calls using interrupts?

105. Why do we need a separate instruction to implement system calls?

106. Why does the interrupt handler need a DPL field?

107. What is the purpose of interrupt stack tables?

108. Does a single thread application have only one stack?

109. What kinds of input and output mechanism does Intel 64  provide?

110. What is a model specific register?

111. What are the shadow registers?

112. How are the model specific registers used in the system call mechanism?

113. Which registers are used by `syscall` instruction?

114. Draw a finite state machine to count the words in the input string. The input
length is no more than 8 symbols.

115. Draw a finite state machine to check whether there is an even or an odd word
count.

116. Draw and implement a finite state machine to answer, whether a string should
be trimmed from left, right, or both, or should not be trimmed at all.  A string
should be trimmed if it starts or ends with consecutive spaces.

117. Using any language you know, implement a `grep` analogue
    based on __NFA__ construction. You can refer to
    [Regular Expression Matching Can Be Simple And Fast] for additional information.

118. Study this regular expression:
    `^1?$|^(11+?)\1+$` . What might be its purpose? Imagine that the
    input is a string consisting of characters `1` uniquely. How
    does the result of this regular expression matching correlate with
    the string length?


119. Read [Moving Forth]. What is the difference between our approach
(Indirect Threaded Code) and Direct Threaded Code, Subroutine
Threaded Code? What advantages and disadvantages can you name?

120. Look the documentation for commands `sete`, `setl` and their counterparts.


121. What does `cqo` instruction do? Refer to [Intel 64 and IA-32 Architectures Software Developer's Manual].

122. Should we allocate Forth cells in `.data` section, or are there better
options?

123. Why do we need a separate case for `branch` and  `0branch`?

124. What is a model of computation?

125. Which models of computation do you know?

126. What is a finite state machine?

127. When are the finite state machines useful?

128. What is a finite automaton?

129. What is a regular expression?

130. How are regular expressions and finite automatons connected?

131. What is the structure of the Forth abstract machine?

132. What is the structure of the dictionary in Forth?

133. What is an execution token?

134. What is the implementation difference between embedded and colon words?

135. Why are two stacks used in Forth?

136. Which are two distinct modes that Forth is operating in?

137. Why does the immediate flag exist?

138. Describe the colon word and the semicolon word.

139. What is the purpose of `PC` and `W` registers?

140. What is the purpose of `next`?

141. What is the purpose of `docol`?

142. What is the purpose of `exit`?

143. When an integer literal is encountered, do interpreter and compiler
behave alike?

144. Add an embedded word to check the remainder of a division of two numbers.
Write a word to check that one number is divisible by another.

145. Add an embedded word to check the remainder of a division of two numbers.
Write a word to check the number for primarity.

146. Write a Forth word to output the first $n$ numbers of the Fibonacci sequence.

147. Write a Forth word to perform system calls (it will take the register
contents from stack). Write a word that will print "Hello, world!" in
`stdout`.

148. What is a literal?

149. What are lvalue and rvalue?

150. What is the difference between the statements and expressions?

151. What is a block of statements?

152. How do you define a preprocessor symbol?

153. Why is `break` necessary at the end of each `switch` case? 

154. How are truth and false values encoded in C89?

155. What is the first argument of `printf` function?

156. Is `printf` checking the types of its arguments?

157. Where can you declare variables in C89?

158. What will be the value of $k$? Try to compile and see in your own computer. 

159. Create sample programs to study the values of these expressions:

\beginitemize
\item `sizeof(void)`
\item  `sizeof(0)`
\item `sizeof('x')`
\item `sizeof("hello")`
\enditemize 

160. What will be the value of `x`?

```c
int x = 10;
size_t t = sizeof(x=90);
```

161. How to compute how many elements does an array store using `sizeof`?

162. Why do these shorts seem reversed? Will it always be the case, or is it architecture dependent? 

163. What is the purpose of `&` and `*` operators?

164. How do we read an integer from an address `0x12345`?

165. What type does the literal `42` have?

166. How do we create a literal of types `unsigned long`, `long` and `long long`?

167. Why do we need `size_t` type?

168. How do we convert values from one type to another?

169. Is there a boolean type in C89?

170. What is a pointer type?

171. What is `NULL`?

172. What is the purpose of the `void*` type? 

173. What is an array?

174. Can any consecutive memory cells be interpreted as an array?

175. What happens when trying to access an element outside of the array's bounds?

176. What is the connection between arrays and pointers?

177. Is it possible to declare a pointer to a function?

178. How to create an alias for a certain type?

179. How are the arguments passed to the `main` function?

180. What is the purpose of the `sizeof` operator?

181. Is `sizeof` evaluated during the program execution?

182. Why is the `const` keyword important?

183. What are structure  types and why do we need them? 

184. What are union types? What is their difference from the structure types?

185. What are enumeration types? What is their difference from the structure types?

186. What kinds of typing exist?

187. What kinds of polymorphism exist and what is the difference between them?

188. Compile the file `main` by using `gcc -o main main_square.o square.o`
    line. Study its object table using `objdump -t main`.  What can you
    tell about functions `main` and `square`?  

189. Try to find the same symbols using `nm` utility instead of
            `readelf`.
        
190. What is the difference between a declaration and a definition?

191. What is a forward declaration? 

192. When are function declarations needed? 

193. When are structure declarations needed?

194. How the functions defined in other files can be called?

195. What effect does a function declaration make on the symbol table?

196. How to access data defined in other files? 

197. What is the concept of header files? What are they typically used for?

198. Which parts does the standard C library consist of?

199. How does the program accept command line arguments?

200. Write a program in assembly that will display all command line arguments each
        on a separate line.

201. How can we use the functions from the standard C library? 

202. Describe the machinery that allows the programmer to use external functions
        by including relevant headers.

203. Read about `ld-linux`.

204. What are the main directives of the C preprocessor?

205. What is the Include Guard used for and how to write it?

206. What is the effect of `static` global variables and functions on the symbol table?

207. What are static local variables? 

208. Where are static local variables created?

209. What is linkage? Which types of linkage exist?

210. Why did we allocate 25 bytes for a 24-characters string? 

211. Read `man` for the functions: `memcpy`, `memset`, `strcpy`.

212. Read `man` for functions: `fread`, `fread`, `fwrite`,
    `fprintf`, `fscanf`, `fopen`, `fclose`, `fflush`.


213. Make a research and find out, what will happen if the `fflush` function is 
    applied to a bidirectional stream (opened for both reading and writing),
    when the last action on the stream before it was reading.

214. Read `man  qsort`.

215. In languages such as C#, the code like the following is possible:

    ```c
var count = 0;
mylist.Foreach( x => count += 1 );
    ```

    Here we launch an anonymous function (that is, a function which has no
    name, but whose address can be manipulated, for example, passed to other
    function) for each element of a list.  The function is written as `x => count += 1` and is
    equivalent of:
    
    ```c
        void no_name( int x )  count += 1;  
    ```
    The interesting thing about it is,
    that this function is aware of some of the local variables of the caller
    and thus can modify them. 

    Can you rewrite the function `forall` so that it accept a pointer to 
    a "context" of sorts, which can hold an arbitrary number of variables
    addresses, and then pass the context to the function called for each element? 

216. What arithmetic operations can you perform with pointers, and on what 
        conditions?

217. What is the purpose of `void*`?

218. What is the purpose of `NULL`?

219. What is the difference between 0 in pointer context and 0 as an integer value?

220. What is `ptrdiff_t` and how is it used?

221. What is the difference between `size_t` and `ptrdiff_t`?

222. What are first class objects?

223. Are functions first class objects in C?

224. What data regions does the C abstract machine contain? 

225. Is the constant data region usually write-protected by hardware? 

226. What is the connection between pointers and arrays?

227. What is the dynamic memory allocation? 

228. What is the `sizeof` operator? When is it computed?

229. When are the string literals stored in __.rodata__? 

230. What is the string interning? 

231. Which data model are we using? 

232. Which header does contain platform independent types?

233. How to concatenate string literals in compile time?

234. What is the data stream?

235. is there a difference between a data stream and a descriptor?
    
236. How to get the descriptor from stream?

237. Are there any streams opened when program starts?

238. What is the difference between binary and text streams? 

239. How to open a binary stream? A text stream?

240. Write a recursive descent parser for floating point arithmetic with
multiplication, subtraction and addition. For this assignment, we consider
no negative literals exist (so instead of writing `-1. 20` we will write
`0-1. 20`.


241. What is the language syntax? 

242. What are grammars used for?

243. What does a grammar consist of? 

244. What is BNF?

245. How to write a recursive descent parser having the grammar description in BNF?

246. How to incorporate priorities in grammar description?

247. What are the levels of Chomsky hierarchy? 

248. Why are regular languages less expressive than context-free grammars?

249. What is the lexical analysis?

250. What is the language semantic?

251. What is the undefined behavior?

252. What is unspecified behavior and how is it different from undefined behavior?

253. What are the cases of undefined behavior in C?

254. What are the cases of unspecified behavior in C?

255. What are sequence points?

256. What is pragmatics?

257. What is the data structure padding? Is it portable?

258. What is the alignment? How can it be controlled in C11?

259. Read BMP file specification to identify what these fields
 are responsible for: 

 ```c
#include <stdint.h>
struct __attribute__((packed))
bmp_header 
    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;

    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
;
 ```

260. Implement blurring. It is done in a very simple way: for each pixel you compute
    its new components as an average in a $3 \times 3$ pixels window (called 
    __kernel__). The border
    pixels are left untouched. 

261. Implement rotation to an arbitrary angle (not only 90 or 180 degrees).

262. Implement "dilate" and "erode" transformations. They are similar to the 
    blur, but instead of doing an average in a window, you have to compute the
    minimal (erode) or maximal  (dilate) component values.

263. Read about the `movq`, `movdqa` and `movdqu` instructions in
[Intel 64 and IA-32 Architectures Software Developer's Manual].  

264. Can you imagine a situation, when a function, not a macro, accepts a
    variable by name (syntactically) and changes it? What should be the 
    type of such variable?

265. How do you implement "try--catch"-alike constructions using 
    `setjmp` and `longjmp`? 

266. What will be the result of launching the code shown in
            Listing~`printf_vuln.c` on input 
            `"%s %s %s %s %s"`?
        
267. What are `xmm` registers? How many are they? 

268. What are SIMD instructions? 

269. Why do some SSE instructions require the memory operands to be aligned?

270. What registers are used to pass arguments to functions? 

271. When passing arguments to the function, why is `rax` sometimes 
        used?

272. How is `rbp` register used?

273. What is a stack frame?

274. Why aren't we addressing the local variables relative to `rsp`?

275. What are prologue and epilogue?

276. What is the purpose of `enter` and `leave` instructions?

277. Describe in details, how is the stack frame changing during the function 
        execution.

278. What is the red zone?

279. How to declare and use a function with variable number of arguments?

280. Which kind of context is `va_list` holding?

281. Why are functions such as `vfprintf` used?

282. What is the purpose of `volatile` variables?

283. Why only `volatile` stack variables persist after `longjmp`?

284. Are all local variables allocated on stack?

285. What is `setjmp` used for? 

286. What is the return value of `setjmp`?

287. What is the use of `restrict`?  

288. Can `restrict` be ignored by the compiler? 

289. How can we achieve the same result without using `restrict` keyword?

290. Explain the mechanism of exploiting stack buffer overrun.

291. When is the `printf` usage unsafe?

292. What is a security cookie? Does it solve program crashes on buffer overflow? 

293. Read in `man ld.so` about environment variables (such as
    `LD_BIND_NOT`), which can alter the loader behavior.

294. Refer to the assignment Use this technique to test your `malloc`
    implementation against some standard utilities from `coreutils`.


295. Read about `dlopen`, `dlsym`, `dlclose` functions. 

296. Perform an experiment. Omit the `wrt ..plt` construction for the call
    and recompile everything. Then use `objdump -D -Mintel-mnemonic` on
    the resulting `main` executable to check, whether the PLT is still in
    game or not. Try to launch it.

297. What is the difference between static and dynamic linkage? 

298. What does the dynamic linker do? 

299. Can we resolve all dependencies at the link time? What kind of system should 
we be working with in order for this to be possible?

300. Should we always relocate __.data__ section?  

301. Should we always relocate __.text__ section? 

302. What is PIC? 

303. Can we share __.text__ section between processes when it is being relocated?

304. Can we share __.data__ section between processes when it is being relocated?

305. Can we share __.data__ section when it is being relocated?

306. Why are we compiling dynamic libraries with `-fPIC` flag? 

307. Write a simple dynamic library in C from scratch and demonstrate calling function from it. 

308. What is `ldd` used for? 

309. Where are the libraries searched? 

310. What is the environment variable `LD_LIBRARY_PATH` for? 

311. What is GOT? Why is it needed? 

312. What makes GOT usage effective? 

313. How comes that position independent code can address GOT directly, but can not address global variables directly? 

314. Is GOT unique for each process? 

315. What is PLT?

316. Why do not we use GOT to call functions from different objects (or do we)?  

317. What does the initial GOT entry for a function point at? 

318. How to preload a library and what can it be used for? 

319. In assembly, how is the symbol addressed if 
    it is defined in the executable and accessed from there?

320. In assembly, how is the symbol addressed if 
    it is defined in the library and accessed from there?

321. In assembly, how is the symbol addressed if 
    it is defined in the executable and accessed from everywhere?

322. In assembly, how is the symbol addressed if 
    it is defined in the library and accessed from everywhere? 

323. How to control visibility of a symbol in dynamic library? How to make it private
    for the library, but accessible from anywhere in it?

324. Why do people sometimes write wrapper functions for those used in library? 

325. How to link against a library that is stored in `libdir`? 

326. What is a code model and why do we care about them? 

327. What limitations impose the small code model? 

328. Which overhead does the large code model carry?

329. What is the compromise between large and small code model? 

330. When is the medium model most useful? 

331. How do large code models differ for PIC and non-PIC code? 

332. How do medium code models differ for PIC and non-PIC code?  

333. What is the instruction pipeline and superscalar architecture?

334. Take a look at the GCC `man` pages, section "Optimizations".

335. Read about methods of calculating the confidence interval and calculate the
    95\% confidence interval for a reasonably high number of measurements.


336. What GCC options control the optimization options globally?

337. What kinds of optimizations can potentially bring the most benefits? 

338. What kinds of benefits and disadvantages can omitting frame pointer bring?

339. How a tail recursive function is different from an ordinary recursive function?

340. Can any recursive function be rewritten as a tail recursive without using
        additional data structures?

341. What is common subexpression elimination? How does it affect our code writing?
        

342. What is constant propagation? 

343. Why should we mark functions `static` whenever we can to help the compiler
        optimizations?

344. What benefits does named return value optimization bring? 

345. What is a branch prediction?  

346. Read about Dynamic Branch Prediction, Global and Local History Tables. 

347. Check the notes on branch prediction for your CPU in [Intel  64 and IA-32 Architectures Optimization Reference Manual].

348. What is an execution unit and why do we care about them? 

349. How are AVX instruction speed and the amount of execution units related? 

350. What kinds of memory accessing patterns are good? 

351. Why do we have many cache levels? 

352. In which cases might `prefetch` bring performance gains and why? 

353. What SSE instructions are used for? 

354. Why most SSE instructions require aligned operands? 

355. How to copy data from general purpose registers to `xmm` registers? 

356. In which cases using SIMD instructions is worth it?

357. Read `man` pages for the functions listed above.

358. What will `sysconf(_SC_NPROCESSORS_ONLN)` return?

359. Experiment with the number of threads and find the optimal one in your own
    environment.  

360. Read about functions: `pthread_self` and `pthread_equal`. Why can not we
        compare threads with a simple equality operator `==`?

361. What is a recursive mutex? How is it different from an ordinary one?

362. What are Coffman's conditions? How can they be used to diagnose deadlocks? 

363. How to use `Helgrind` to detect deadlocks?

364. What is a named semaphore? Why should it be mandatory unlinked even if the
process is terminated?  

365. What is the ABA problem?

366. Read the description of `cmpxchg` in Intel docs [Intel 64 and IA-32 Architectures Software Developer's Manual].

367. Read `man` pages for `atomic_flag_test_and_set` and
    `atomic_flag_clear`.


368. Which problems emerge from multithreading usage? 

369. What makes multiple threads worth it?

370. Should we use multithreading even if the program does not perform many 
        computations? If yes, give a use case. 

371. What is compiler reordering? Why are they performed?
 
 
372. Why the single threaded program have no means to observe compiler memory 
            reorderings?
    
373. What are some kinds of memory models? 

374. How to write the code that is sequentially consistent with regards to manipulation
        of two shared variables?  

375. Are `volatile` variables sequentially consistent?

376. Show an example when memory reorderings can lead to a very unexpected program behavior. 

377. What are the arguments against usage of volatile variables? 

378. What is a memory barrier? 

379. What kind of memory barriers do you know? 

380. What is acquire semantics? 

381. What is release semantics? 

382. What is a data dependency? Can you write code where data dependency does not
        force an order on operations? 

383. What is the difference between `mfence`, `sfence` and `lfence`? 

384. Why do we need other instructions than `mfence`? 

385. Which function calls act as compiler barriers? 

386. Are `inline` function calls compiler barriers? 

387. What is a thread?  

388. What is the difference between threads and processes? 

389. What constitutes the state of a process? 

390. What constitutes the state of a thread? 

391. Why the `-pthread` flag should be used when compiling with `pthreads`? 

392. Is `pthreads` a static or dynamic library? 

393. How do we know in which order will the scheduler execute the threads? 

394. Can one thread get an access to the stack of the other thread?  

395. What does `pthread_join` do and how to use it? 

396. What is a mutex? Why do we need them? 

397. Should every shared constant variable be associated with a mutex?

398. Should every shared mutable variable which is never changed be associated with a mutex?

399. Should every shared mutable variable which is changed be associated with a mutex?

400. Can we work with a shared variable without ever using a  mutex? 

401. What is a deadlock? 

402. How to prevent deadlock? 

403. What is a livelock? How is it different from deadlock? 

404. What is a spinlock? How is it different from livelock and deadlock? 

405. Should spinlocks be used on a single core system? Why? 

406. What is a condition variable? 

407. Why do we need condition variables if we have mutexes? 

408. Which guarantees does Intel 64  provide for memory reorderings? 

409. Which important guarantees does Intel 64  not provide for memory reorderings? 

410. Correct the program shown in Listing~`reordering_cpu_mwe.c` so that
    no memory reordering occurs.

411. Correct the program shown in Listing~`reordering_cpu_mwe.c` so that
    no memory reordering occurs by using atomic variables.

412. What is lock-free programming? Why is it harder than traditional multithreaded programming with locks?

413. What is a CAS operation? How can it be implemented in Intel 64 ?

414. How strong is C memory model? 

415. Can the strength of C memory model be controlled? 

416. What is an atomic variable? 

417. Can any data type be atomic? 

418. Which atomic variables should be initialized explicitly? 

419. Which memory orderings does C11 recognize? 

420. How are the atomic variables manipulation functions with `_explicit` suffix different from their ordinary counterparts?

421. How to perform an atomic increment on an atomic variable? 

422. How to perform an atomic XOR on an atomic variable? 

423. What is the difference between weak and strong versions of `compare_exchange`?

