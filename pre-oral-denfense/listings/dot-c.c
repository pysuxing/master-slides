float dot(float* v1, float* v2, size_t len) {
    float retval = 0;
    for (int i = 0; i < len; ++i) {
        retval += v1[i] * v2[i];
    }
    return retval;
}
