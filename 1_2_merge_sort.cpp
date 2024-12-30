#include <cstdio>
#include <iostream>
using namespace std;

int n;
int a[100010];
int b[100010];

void merge(int s, int m, int e) {
    int l1 = m-s+1;
    int l2 = e-m;
    int i = 0;
    int q=s;
    int p=m+1;
    while (q <= m && p <= e) {
        if(a[q] <= a[p]) b[i++] = a[q++];
        else b[i++] = a[p++];
    }
    while (q <= m ) b[i++] = a[q++];
    while (p <= e ) b[i++] = a[p++];
    for(int j=0;j<i;j++) a[s+j] = b[j];
}

void merge_sort(int s,int e) {
    if(s<e) {
        int m = (s+e)/2;
        merge_sort(s,m);
        merge_sort(m+1,e);
        merge(s,m,e);
    }
}

void out(){
    for(int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int  main (){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    merge_sort(0,n-1);
    out();
    return 0;
}