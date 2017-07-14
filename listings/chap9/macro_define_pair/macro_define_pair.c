struct pair_int {
    int fst;
    int snd;
};
bool pair_int_any(struct pair_int pair, bool (*predicate)(int)) {
    return predicate(pair.fst) || predicate(pair.snd); 
}
