#include <stdio.h>
#include <algorithm>
using namespace std;

int a,b,T;
long long int f[55];

int main(){
    scanf("%d",&T);
    while(T--){
        fill(f,f+55,0);
        scanf("%d%d",&a,&b);
        f[a] = 1;
        for (int i=a+1;i<=b;i++){
            f[i] = f[i-1]+f[i-2];
        }
        printf("%lld\n",f[b]);
    }
}

