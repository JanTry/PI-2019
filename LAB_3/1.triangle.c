#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_triangular(int** tab, int n) {
    bool is=true;
    int i, j;
    for(i=0;i<n && is;i++){
        for(j=0;j<n && is;j++){
            if(i+j>n && tab[i][j]!=0)is=false;
        }
    }
    return is;
}

int main() {
    int n;
    scanf("%d", &n);
    int** tab;
    tab = malloc(n*sizeof(int*));
    int i,j;
    for(i=0;i<n;i++){
        tab[i]=malloc(n*sizeof(int*));
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &tab[i][j]);
        }
    }

    printf(is_triangular(tab, n) ? "YES\n" : "NO\n");

    for(i=0;i<n;i++){
        free(tab[i]);
    }
    free(tab);
}

