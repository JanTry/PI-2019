#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) do { int tmp = a; a = b; b = tmp; } while (0)

int partition(int* tab, int left, int right) {
    int x = tab[right];
    int j = left-1;
    int i;
    for(i=left;i<=right-1;i++){
        if(tab[i]<=x){
            j=j+1;
            SWAP(tab[j],tab[i]);
        }
    }
    SWAP(tab[j+1],tab[right]);
    return j+1;
}

void quickSort(int* tab, int left, int right) {
    if(left<right)
    {
        int q=partition(tab,left,right);
        quickSort(tab, left,q-1);
        quickSort(tab,q+1,right);
    }
}

int main() {
    int Z;

    scanf("%d", &Z);

    int val;

	while (Z--) {

		int n;
		scanf("%d", &n);
        int *tab = malloc(n*sizeof(n));
		for(int i=0; i<n; i++) {
			scanf("%d", &tab[i]);
		}

        quickSort(tab, 0, n-1);
        for(int i=0; i<n; i++) {
            printf("%d\n", tab[i]);
        }
        free(tab);
    }

    /*int i;
    int *tab=malloc(Z*sizeof(int));
    for(i=0;i<Z;i++)
    {
        scanf("%d", &tab[i]);
    }
    quickSort(tab,0,Z-1);
    for(i=0;i<Z;i++)
    {
        printf("%d ", tab[i]);
    }*/
}
