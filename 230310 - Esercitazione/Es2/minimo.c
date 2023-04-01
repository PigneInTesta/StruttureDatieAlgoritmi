// Versione che controlla il minimo dalla testa del vettore
// min(1, 2, 3, 4) = min(1, min(2, 3, 4)))
//								|
//						min(1, min(2, 3))
//								|
//						 min(1, min(2))
//								|
//							min(1, 2)
//								|
//								1

extern int Minimo(const int* v, int v_size);

int MinimoRec(const int* v, int v_size, int i) {	//il qualificatore const si applica alla zona di memoria puntata dal puntatore, quindi è un'area di memoria non modificabile

	if (v_size - 1 == i) {
		return v[v_size - 1]; //return v[i]
	}

	int min = MinimoRec(v, v_size, i + 1);

	if (v[i] < min) {
		return v[i];
	}
	else {
		return min;
	}
}

int Minimo(const int* v, int v_size) {
	return MinimoRec(v, v_size, 0);
}

// Versione che controlla il minimo dalla coda
// min(1, 2, 3, 4) = min(min(1, 2, 3), 4))
//							|
//					min(min(1, 2), 4)
//							|
//						min(min(1), 4)
//							|
//						min(1, 4)
//							|
//							1
/*
int Minimo(const int* v, int v_size) {
	v_size--;

	if (v_size == 0) {
		return v[0];
	}

	int min = Minimo(v, v_size);

	if (v[v_size] < min) {
		return v[v_size];
	}
	else {
		return min;
	}
}
*/
/*
int main(void) {

	int v[] = { 1, 2, 3, 4 };
	int v_size = sizeof(v) / sizeof(int);

	int min = Minimo(v, v_size);
}
*/
