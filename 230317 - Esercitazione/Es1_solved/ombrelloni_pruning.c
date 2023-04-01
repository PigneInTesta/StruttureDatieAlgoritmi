#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static void OmbrelloniPruningRec(int k, int n, int i, bool *vcurr, int cnt, int *nsol, int *ncall) {
    (*ncall)++;
    if (cnt == k) {
        (*nsol)++;
        printf("%4d) ", *nsol);
        for (int j = 0; j < n; ++j) {
            printf("%d ", vcurr[j]);
        }
        /*for (int j = i; j < n; ++j){
            printf("0 ");
        }*/
        puts("");
        return;
    }

    if (i == n) {
        return;
    }


    // Versione con ciclo for
    /*for (int j = 0; j < 2; ++j) {
        vcurr[i] = j;
        if (j == 0 || (i == 0 || !vcurr[i - 1])){
            OmbrelloniPruningRec(k, n, i + 1, vcurr, cnt + j, nsol, ncall);
        }
        vcurr[i] = 0;
    }*/

    // Versione chiamate ricorsive "srotolate"
    vcurr[i] = 0;
    OmbrelloniPruningRec(k, n, i + 1, vcurr, cnt, nsol, ncall);

    if (i == 0 || !vcurr[i - 1]) {
        vcurr[i] = 1;
        OmbrelloniPruningRec(k, n, i + 1, vcurr, cnt + 1, nsol, ncall);
        vcurr[i] = 0;
    }
}


int OmbrelloniPruning(int k, int n, int *ncall) {
    int nsol = 0;
    bool *vcurr = calloc(n, sizeof(bool));

    (*ncall) = 0;
    OmbrelloniPruningRec(k, n, 0, vcurr, 0, &nsol, ncall);

    free(vcurr);
    return nsol;
}
