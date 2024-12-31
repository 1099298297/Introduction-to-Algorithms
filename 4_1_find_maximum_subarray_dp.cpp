#include <cstdio>
#include <iostream>
using namespace std;
int a[200010];
int sum[200010]; //从low到当前i的和
int n;

int find_max_subarray() {
    int low=0,high=0,max_sum=a[0];
    sum[0] = a[0];
    for(int i = 1;i<n;i++){
        sum[i] = sum[i-1] + a[i];
        if(a[i] > sum[i]) {
            low = i;
            high = i;
            sum[i] = a[i];
        }     
        if(sum[i] >= max_sum) {
            high = i;
            max_sum = sum[i];
        }
    }
    return max_sum;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cout << find_max_subarray();
    return 0;
}