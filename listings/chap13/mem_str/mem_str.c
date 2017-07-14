struct mem {
    struct mem* next;
    size_t capacity;
    bool is_free;
};
