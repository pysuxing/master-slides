typedef out_type (*scalar_op) (in_type);
int map(in_type* in, size_t inlen,
        out_type* out, size_t outlen,
        scalar_op sop) {
    size_t inl , outl, size = outlen;
    while (inl = partition(in, PARTITION_SIZE)) {
        outl = solve_part(in, inl, out, outlen);
        in += inl;
        out += outl;
        outlen -= outl;
    }
    return (size-outlen);
}
