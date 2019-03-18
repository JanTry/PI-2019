#include<stdio.h>
#include<stdlib.h>

int digit(char* number, int position) {
    return (int)(number[position] - '0');
}


/*NOT DONE!!!!!!!*/



/*void countingSort(int* tab, int n, int k) {
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
*/


void sortByPosition(char** tab, int n, int pos) {
    int k = 10;
    int i;
    int *counters = malloc(k*sizeof(int));
    char** result = malloc(n*sizeof(char*));

    for(i=0;i<n;i++)
        counters[digit(tab[i],pos)]++;
    for(i=0;i<k-1;i++)
        counters[i+1]+=counters[i];

    for(i=n-1;i>=0;i--)
    {
        int p=digit(tab[i],pos);
        result[counters[p]--]=tab[i];
    }

    for(i=0;i<n;i++)
        tab[i]=result[i];
}

void radixSort(char** tab, int n, int length) {
    int i;
    for(i=length;i>0;i--)
        sortByPosition(tab, n, i);
}

int main() {
    /*
    int Z;
    scanf("%d", &Z);

	while (Z--) {

		int n, length;
		scanf("%d", &n);
        scanf("%d", &length);
		char **tab = malloc(n*sizeof(char*));
		for(int i=0; i<n; i++) {
			tab[i] = malloc((length+1)*sizeof(char));
            int read_len = scanf("%s", tab[i]);
		}
        radixSort(tab, n, length);
        for(int i=0; i<n; i++) {
            printf("%s\n", tab[i]);
            free(tab[i]);
        }
        free(tab);
    } */
    int i,n,L;
    scanf("%d", &n);
    scanf("%d", &L);
    int *tab=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d", &tab[i]);
    }
    radixSort(tab,n,L);
    for(i=0;i<n;i++)
    {
        printf("%d ", tab[i]);
    }
}
