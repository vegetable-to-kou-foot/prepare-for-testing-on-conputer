#include <stdio.h>
#include <algorithm>
using namespace std;

int T,N;
int a[105][105];
int b[105][105];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for (int i=1;i<=N;i++){
            for (int j=1;j<=i;j++){
                scanf("%d",&a[i][j]);
            }
        }
        b[1][1] = a[1][1];
        for (int i=2;i<=N;i++){
            for (int j=1;j<=i;j++){
                b[i][j] = max(b[i-1][j-1],b[i-1][j])+a[i][j];
            }
        }
        int ans = 0;
        for (int i=1;i<=N;i++){
            ans = max(ans,b[N][i]);
        }
        printf("%d\n",ans);
    }

}

