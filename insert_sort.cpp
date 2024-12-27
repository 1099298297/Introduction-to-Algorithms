#include <cstdio>
#include <iostream>
using namespace std;

int n;
int a[1000];
void insert_sort(){
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++){
            if(a[i]<a[j]) {
                int temp = a[i];
                for(int k=i;k>j;k--){
                    a[k] = a[k-1];
                }
                a[j] = temp;
                break;
            }
        }
    }
}
void out(){
    for(int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
}

int main(){
    cout << "请输入n的大小" << endl;
    cin >> n;
    cout << "请输入" << n <<"个数" << endl;
    for(int i = 0 ; i<n;i++) cin >> a[i];
    insert_sort();
    out();
    return 0;
}
