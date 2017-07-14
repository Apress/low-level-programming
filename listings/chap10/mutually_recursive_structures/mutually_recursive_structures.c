struct b; /* forward declaration */
struct a { 
    int value;
    struct b* next;
};

/* no need to forward declare struct a because it is already defined */
struct b {
    struct a* other;
};
