#include <stdio.h>
#include <math.h>
using namespace std;

#define ll long long int

const int M = 25000000;
int a[6];
int cnt = 0;
int mul[105];
short mp[M*2+5];

int main(){
    for (int i=1;i<=5;i++)scanf("%d",&a[i]);
    for (int i=-50;i<=50;i++)mul[i+50] = i*i*i;
    for (int i=-50;i<=50;i++){
        for (int j=-50;j<=50;j++){
            if (i==0||j==0)continue;
            ll tmp = -a[4]*mul[i+50]-a[5]*mul[j+50];
            mp[M+tmp]++;
        }
    }
    for (int i=-50;i<=50;i++){
        for (int j=-50;j<=50;j++){
            for (int k=-50;k<=50;k++){
                if (i==0||j==0||k==0)continue;
                ll tmp = a[1]*mul[i+50]+a[2]*mul[j+50]+a[3]*mul[k+50];
                cnt+=mp[M+tmp];
            }
        }
    }
    printf("%d",cnt);
}

