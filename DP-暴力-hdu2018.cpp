#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int f[60][5];

int main(){
    f[1][1] = 1;
    for (int i=2;i<=55;i++){
        f[i][3] = f[i-1][0]+f[i-1][1];
        f[i][2] = f[i-1][3];
        f[i][1] = f[i-1][2];
        f[i][0] = f[i-1][0]+f[i-1][1];
    }
    while(scanf("%d",&N)&&N){
        printf("%d\n",f[N][0]+f[N][1]+f[N][2]+f[N][3]);
    }
}

