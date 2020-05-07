#include <stdio.h>
int n,T;
long long int f[10005];
int main(){
    scanf("%d",&T);
    f[0] = 1;
    for (int i=1;i<=10000;i++)
        f[i] = f[i-1]+4*i-3;
    while(T--){
        scanf("%d",&n);
        printf("%lld\n",f[n]);
    }
}

