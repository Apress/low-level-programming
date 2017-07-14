struct llist_t;

struct llist_t* f() { ... }  /* ok  */
struct llist_t g();          /* ok  */
struct llist_t g()  { ... }  /* bad */
