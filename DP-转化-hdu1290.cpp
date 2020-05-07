#include <stdio.h>
long long int N;
int main(){
    while(scanf("%d",&N)!=EOF){
        printf("%lld\n",(N*N*N+5*N+6)/6);
    }
}

