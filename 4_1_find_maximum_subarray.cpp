#include <cstdio>
#include <iostream>
using namespace std;
int a[200010];
int n;

struct sub_list
{
    int low;
    int high;
    int sum;
};

sub_list find_max_cross_subarray(int low ,int mid, int high){
    int left_sum=a[mid];
    int right_sum = a[mid+1];
    int sum = 0;
    int max_left_index,max_right_index;
    for(int i=mid;i>=low;i--) {
        sum += a[i];
        if(sum >= left_sum) {
            left_sum = sum;
            max_left_index = i;
        }
    }
    sum = 0;
    for(int i = mid+1;i<=high;i++) {
        sum += a[i];
        if(sum >= right_sum) {
            right_sum = sum;
            max_right_index = i;
        }
    }
    sub_list l;
    l.high = max_right_index;
    l.low = max_left_index;
    l.sum = left_sum+right_sum;
    return l;
}

sub_list find_max_subarray(int low,int high) {
    if (low == high) {
        sub_list l;
        l.high = high;
        l.low = low;
        l.sum = a[low];
        return l;
    }else{
        int mid = (low+high)/2;
        sub_list left = find_max_subarray(low,mid);
        sub_list right = find_max_subarray(mid+1,high);
        sub_list cross = find_max_cross_subarray(low,mid,high);
        sub_list temp;
        if(left.sum >= right.sum) temp = left;
        else temp = right;
        if(temp.sum >= cross.sum) return temp;
        else return cross;
        
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sub_list l = find_max_subarray(0,n-1);
    cout << l.sum;
    return 0;
}