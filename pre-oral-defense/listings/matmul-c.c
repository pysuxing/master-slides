float A[X][Y], B[Y][Z], C[X][Z];
init_matrix(A, B);
for (int i = 0; i < X; ++i) {
    for (int j = 0; j < Z; ++j) {
        c[i][j] = 0;
        for (int k = 0; k < Y; ++k) {
            C[i][j] += A[i][k] * B[k][j];
        }
    }
}
