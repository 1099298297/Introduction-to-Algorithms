#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int a[200010];
long long sum[200010];
int n;
const double T = 2e4,A=0.98,eps=1e-5;
const int fire = 15000,alpha = 1;
int low,high;
long long ans = -0x7fffffffffffffff;
// 模拟退火
long long simulated_annealing() {
    srand(rand()+clock());
    for(int i = 1 ; i<= fire; i++){
        double t = T, p;
        long long res,dis,delta;
        int operation;
        // 初始随机范围
        low = rand()%n+1;
        high = rand()%n+1;
        if(low > high) {
            int temp = high;
            high = low;
            low = temp;
        }
        res = sum[high] - sum[low-1];
        // 退火
        while(t > eps) {
            t*=A;
            operation = rand()%4;
            dis = rand() * 1ll * t * alpha/RAND_MAX + 1;
            p = 1.0;
            switch (operation)
            {
            case 0:
                if(low - dis < 1) break;
                delta = sum[low-1] - sum[low-dis-1];
                if(delta <= 0) p = rand() /(double) RAND_MAX;
                if(p < (exp((double)delta / t))) {
                    res += delta;
                    low -= dis;
                }
                break;
            case 1:
                if(low + dis > high) break;
                delta = sum[low-1] - sum[low + dis -1];
                if(delta <= 0) p = rand() /(double) RAND_MAX;
                if(p < (exp((double)delta / t))) {
                    res += delta;
                    low += dis;
                }
                break;
            case 2:
                if(high - dis < low) break;
                delta = sum[high-dis] - sum[high];
                if(delta <= 0) p = rand() /(double) RAND_MAX;
                if(p < (exp((double)delta / t))) {
                    res += delta;
                    high -= dis;
                }
                break;
            case 3:
                if(high + dis > n) break;
                delta = sum[high + dis] - sum[high];
                if(delta <= 0) p = rand() /(double) RAND_MAX;
                if(p < (exp((double)delta / t))) {
                    res += delta;
                    high += dis;
                }
                break;
            }
            if(res > ans) ans = res;
        }
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
    };
    cout << simulated_annealing();
    return 0;
}