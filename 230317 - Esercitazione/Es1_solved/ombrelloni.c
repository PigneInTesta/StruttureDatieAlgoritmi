#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static void OmbrelloniRec(int k, int n, int i, bool *vcurr, int *nsol, int *ncall) {
    
    (*ncall)++;
    if (i == n) {
        int cnt = vcurr[0];
        for(int j = 1; j <n; ++j){
            if (vcurr[j]){
                cnt++;
            }

            if (vcurr[j] && vcurr[j - 1]) {
                return;
            }
        }

        if (cnt == k){
            (*nsol)++;
            printf("%4d) ", *nsol);
            for (int j = 0; j < n; ++j) {
                printf("%d ", vcurr[j]);
            }
            puts("");
        }
        return;
    }

    // Versione con ciclo for
    /*for(int j = 0; j < 2; ++j){
        vcurr[i] = j;
        OmbrelloniRec(k, n, i + 1, vcurr, nsol, ncall);
    }*/

    // Versione chiamate ricorsive "srotolate"
    vcurr[i] = 0;
    OmbrelloniRec(k, n, i + 1, vcurr, nsol, ncall);

    vcurr[i] = 1;
    OmbrelloniRec(k, n, i + 1, vcurr, nsol, ncall);

}


int Ombrelloni(int k, int n, int *ncall) {
    int nsol = 0;
    bool *vcurr = calloc(n, sizeof(bool));

    (*ncall) = 0;
    OmbrelloniRec(k, n, 0, vcurr, &nsol, ncall);

    free(vcurr);
    return nsol;
}
