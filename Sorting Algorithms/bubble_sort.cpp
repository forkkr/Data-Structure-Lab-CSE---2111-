#include<bits/stdc++.h>
using namespace std;

void sorting(int ar[], int n)
{
    if(n==0)
        return;
    sorting(ar , n-1);
    if(ar[n-1]>ar[n])
        swap(ar[n-1], ar[n]);
}

void bubble_sort(int ar[] , int n)
{
    if(n==1)
        return;
    sorting(ar , n-2);
    if(ar[n-1]<ar[n-2])
        swap(ar[n-1],ar[n-2]);
    bubble_sort(ar, n-1);
}

int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    for(int i = 0; i<n ;i++)
        cin>>ar[i];
    bubble_sort(ar , n);
    for(int i = 0; i< n ; i++)
        cout<<ar[i]<<" ";
    return 0;
}
