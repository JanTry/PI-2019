#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool pierwsza(int n){
    if(n<2)return false;
    int i;
    for(i=2;i*i<=n;i++)if(n%i==0)return false;
    return true;
}

bool niemalejacy(int n){
    int p=n%10;
    n=n/10;
    while(n>0){
        if(n%10>p)return false;
        p=n%10;
        n=n/10;
    }
    return true;
}

void wypisz(int n){
    int i;
    for(i=0;i<n;i++)if(niemalejacy(i) && pierwsza(i))printf("%d\n",i);
}


int main(){
int n;
scanf("%d",&n);
wypisz(n);
}
