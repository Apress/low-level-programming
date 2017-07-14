struct sa {
    int x;
    char y;
    char z;
};

struct sb {
    int x;
    char y;
    int notz;
};

union test {
    struct sa as_sa;
    struct sb as_sb;
};
