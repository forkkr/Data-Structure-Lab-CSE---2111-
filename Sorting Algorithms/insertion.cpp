#include<bits/stdc++.h>
using namespace std;

int maxofArray(int ar[] , int n)
{
    if(n==0)
        return 0;
    int  x = maxofArray(ar , n-1);
     if(ar[n]>ar[x])
        return n;
     else
        return x;
}


void selection_sort(int ar[] , int n)
{
    if(n-1==0)
        return;
    int x = maxofArray(ar, n-2);
   // cout<<x<<endl;
    if(ar[n-1]< ar[x])
    swap(ar[n-1],ar[x]);
    selection_sort(ar, n-1);
}


int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    for(int i = 0; i<n ;i++)
        cin>>ar[i];
    selection_sort(ar , n);
    for(int i = 0; i< n ; i++)
        cout<<ar[i]<<" ";
    return 0;
}
