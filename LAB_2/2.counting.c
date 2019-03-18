#include<stdio.h>
#include<stdlib.h>

void countingSort(int* tab, int n, int k) {
    int *counters = malloc(k*sizeof(int));
    int* result = malloc(n*sizeof(int*));
    int i;
    for(i=0;i<k;i++)
    {
        counters[i]=0;
    }
    for(i=0;i<n;i++)
    {
        counters[tab[i]]++;
    }
    i=0;
    int j=0;
    while(i<k){
        while(counters[i]>0)
        {
            result[j]=i;
            j++;
            counters[i]--;
        }
        i++;
    }
    for(i=0;i<n;i++)
        tab[i]=result[i];
}

int main() {
    int Z;
    scanf("%d", &Z);

	while (Z--) {

		int n, k;
		scanf("%d", &n);
        scanf("%d", &k);
		int *tab = malloc(n*sizeof(int*));
		for(int i=0; i<n; i++) {
			scanf("%d", &tab[i]);
		}

        countingSort(tab, n, k);
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
