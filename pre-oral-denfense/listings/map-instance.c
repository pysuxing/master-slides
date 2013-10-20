typedef float (*scalar_op13) (float);
int map27(float* in, size_t inlen,
        float* out, size_t outlen,
        scalar_op13 sop) { ... }

int main() {
    ...
    sop = sqrt;
    map27(in, ilen, out, olen, sop);
}
