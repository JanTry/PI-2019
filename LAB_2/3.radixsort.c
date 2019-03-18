#include<stdio.h>
#include<stdlib.h>

int digit(char* number, int position) {
    return (int)(number[position] - '0');
}

void sortByPosition(char** tab, int n, int pos) {

    int k = 10;
    int i;
    int *counters = malloc(k*sizeof(int));
    char** result = malloc(n*sizeof(char*));

    for(i=0;i<k;i++) counters[i]=0;
    for(i=0;i<n;i++) counters[digit(tab[i],pos)]++;
    for(i=0;i<k-1;i++) counters[i+1]+=counters[i];
    for(i=n-1;i>=0;i--){
        int p=digit(tab[i],pos);
        result[counters[p]-1]=tab[i];
        counters[p]--;
    }
    for(i=0;i<n;i++) tab[i]=result[i];
}

void radixSort(char** tab, int n, int length) {
    int i;
    for(i=length-1;i>=0;i--)sortByPosition(tab, n, i);
}

int main() {
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
    }
}

