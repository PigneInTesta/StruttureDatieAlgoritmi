#include "list.h"

// Implementazione "dei poveri" del naive sort. Questa funzione effettua 
// lo swap dei values e non degli Item.
Item *NaiveSort(Item *i){
    Item *tmp_a = i;
    while (!ListIsEmpty(tmp_a)) {
        Item *tmp_b = ListGetTail(tmp_a);
        while (!ListIsEmpty(tmp_b)) {
            if (ElemCompare(ListGetHeadValue(tmp_a), ListGetHeadValue(tmp_b)) > 0) {
                ElemSwap(&(tmp_a->value), &(tmp_b->value));
            }
            tmp_b = ListGetTail(tmp_b);
        }


        tmp_a = ListGetTail(tmp_a);
    }
    return i;
}

// Funzione per il calcolo della lunghezza di una lista
int ListLength(const Item *i){
    int j = 0; 
    while(!ListIsEmpty(i)){
        j++;
        i = ListGetTail(i);
    }
    return j;
}

// Implementazione del bubble sort. Questa funzione effettua 
// lo swap degli Item utilizzando il trick del nodo fittizio 
// per evitare di gestire separatamente il "caso testa".
Item *BubbleSort(Item *i) {
    Item fake_head = { .next = i };
    
    int dim = ListLength(i);
    bool done = false;

    while(!done) {
        done = true;
        Item *prev = &fake_head;
        Item *curr = prev->next; // Item *curr = ListGetTail(prev);
        for (int j = 0; j < dim && !ListIsEmpty(ListGetTail(curr)); ++j){
            Item *foll = ListGetTail(curr);
            Item *follfoll = ListGetTail(foll);
            if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(foll)) > 0){
                // Devo scambiare i due elementi
                // Al momento abbiamo: prev -> curr -> foll -> follfoll 
                // Vogliamo ottenere: prev -> foll -> curr -> follfoll
                prev->next = foll;
                curr->next = follfoll;
                foll->next = curr;
                
                // Aggiorno prev per il prossimo giro (cur è già ok!)
                done = false;
                prev = foll;
            } else {
                // Aggiorno prev e curr per il prossimo giro
                prev = curr;
                curr = foll;
            }
        }
        dim--;
    }

    return fake_head.next;
}

// Bubble Sort con swap degli Item (senza Item fittizio)
static Item *BubbleSortV2(Item *i) {
    Item *head = i;  // Non faccio uso dell'Item fittizio, ma tengo
                     // memoria della testa per poterla ritornare

    size_t dim = ListLength(i);
    bool done = false;

    while (!done) {
        done = true;
        Item *prev = NULL; // Al primo giro prev è NULL
        Item *curr = head; // e curr punta alla testa corrente
        for (size_t j = 0; j < dim && curr->next; j++) {
            Item *foll = curr->next;
            Item *follfoll = foll->next;
            if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(curr->next)) > 0) {
                // Devo scambiare i due elementi, ci sono due casi:
                if (prev == NULL) {
                    // 1. prev == NULL:
                    //    Abbiamo:  curr -> foll -> follfoll 
                    //    Vogliamo: foll -> curr -> follfoll
                    head = foll; // Memorizziamo la testa per il prossimo giro e per
                                 // poterla ritornare al termine dell'ordinamento
                    curr->next = follfoll; // Istr. A
                    foll->next = curr;     // Istr. B
                } else {
                    // 2. prev != NULL;
                    //    Abbiamo:  prev -> curr -> foll -> follfoll 
                    //    Vogliamo: prev -> foll -> curr -> follfoll
                    prev->next = foll;
                    curr->next = follfoll; // Istr. A
                    foll->next = curr;     // Istr. B
                }
                // Le istruzioni A e B sono ripetute in entrambi i blocchi
                // quindi posso spostarle qui ed evitare la ripetizione dentro
                // l'if.

                // Aggiorno prev per il prossimo giro (cur è già ok!)
                prev = foll;
                done = false;
            } else {
                // Aggiorno prev e curr per il prossimo giro
                prev = curr;
                curr = foll;
            }
        }
        dim--;
    }

    return head; // Al termine head contiene l'indirizzo della testa
                 // della lista dopo l'ordinamento
}


Item *Sort(Item *i) {
   //return NaiveSort(i);
   //return BubbleSort(i);
   return BubbleSortV2(i);
}
/*
int main(void) {
    ElemType e[] = {
                { "Michele", "Firenze", 12, "Modena", "MO", "41126" },
                { "Federico", "Peschiera", 54, "Modena", "MO", "41126" },
                { "Massimiliano", "Roma", 23, "Firenze", "FI", "50100" },
                { "Massimiliano", "Newton", 23, "Modena", "MO", "41126" },
                { "Stefano", "Ciro Menotti", 10, "Milano", "MI", "20019" }
    };
    size_t e_size = sizeof(e)/sizeof(ElemType);

    Item *ab = ListCreateEmpty();
    for (size_t i = 0; i < e_size; ++i){
        ab = ListInsertBack(ab, e + i);
    }

    ab = Sort(ab);
    ListDelete(ab);

    return 0;
}
*/