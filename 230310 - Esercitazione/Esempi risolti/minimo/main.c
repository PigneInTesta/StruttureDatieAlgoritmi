extern int Minimo(const int *v, int v_size);

int main(void) {
    int v[] = {1, 2, 3, 4};
    int v_size = sizeof(v)/sizeof(int);

    int min = Minimo(v, v_size);

}