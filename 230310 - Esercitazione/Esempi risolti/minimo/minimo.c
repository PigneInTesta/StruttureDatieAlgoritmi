// min(1, 2, 3, 4) =  min(1, min(2, 3, 4))
//                            |
//                     min(2, min(3, 4))
//                            |
//                         min(3, min(4))
//                            |
//                            4
//

//static int MinimoRec(const int *v, int v_size, int i) { 
//
//    if (v_size - 1 == i) {
//        return v[v_size - 1]; // return v[i];
//    }
//    
//    int min = MinimoRec(v, v_size, i + 1);
//
//    if (v[i] < min) {
//        return v[i];
//    } else {
//        return min;
//    }
//
//}
//
//int Minimo(const int *v, int v_size) {
//    return MinimoRec(v, v_size, 0);
//}
//                            0  1  2   3
// min(1, 2, 3, 4) =  min(min(1, 2, 3), 4)
//                            |
//                     min(min(1, 2), 3)
//                            |
//                         min(min(1), 2)
//                            |
//                            1
//
 
int Minimo(const int *v, int v_size) {
    v_size--;
    
    if (v_size == 0) {
        return v[0];
    }

    int min = Minimo(v, v_size);

    if (v[v_size] < min) {
        return v[v_size];
    } else {
        return min;
    }

}

