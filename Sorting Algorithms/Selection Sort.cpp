#include<bits/stdc++.h>
using namespace std;

void insertion(int ar[], int n)
{
    if(n==0)
        return;
    if(ar[n] < ar[n-1])
    {
        swap(ar[n], ar[n-1]);
        insertion(ar , n-1);
    }
    return;
}

void insertion_sort(int ar[] , int n)
{
    if(n==0)
        return ;
    insertion_sort(ar , n-1);
    insertion(ar , n);
}
void print(int ar[] , int n)
{
    if(n<0)
        return;
    print(ar , n-1);
    cout<<ar[n]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    for(int i = 0; i < n ; i++)
        cin>>ar[i];
    insertion_sort(ar , n - 1);
    print(ar ,n - 1);
    return 0;
}
