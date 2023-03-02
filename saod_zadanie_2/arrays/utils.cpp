void rotate_clockwise(int* a, int n, bool clockwise = false) {

    if (clockwise) {
        int x = *(a + n - 1);
        for (int i = n - 1; i > 0; i--) {
            *(a + i) = *(a + i - 1);
        }
        *(a) = x;
    }
    else {
        int x = *a;
        for (int i = 1; i < n; i++) {
            *(a + i - 1) = *(a + i);
        }
        *(a + n - 1) = x;
    }
}