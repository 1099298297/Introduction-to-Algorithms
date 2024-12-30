#include <cstdio>
#include <iostream>
using namespace std;

int n;
int a[100010];
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
    cin >> n;
    for(int i = 0 ; i<n;i++) cin >> a[i];
    insert_sort();
    out();
    return 0;
}
