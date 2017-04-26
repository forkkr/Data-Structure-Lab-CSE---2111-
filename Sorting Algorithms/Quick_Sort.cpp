#include<bits/stdc++.h>
using namespace std;
void Sort(int ar[] , int beg , int endd )
{
    if(beg > endd)
        return;
    if(endd-beg+1 == 1)
        return;
    if(endd-beg+1 == 2)
    {
        if(ar[beg] > ar[endd])
            swap(ar[beg] , ar[endd]);
        return;
    }
    int left = beg+1;
    int right = endd;
    int pivot = ar[beg];
    int pivot_index = beg;
    while(right > left)
    {
        while(ar[left] <= pivot)
        {
            left++;
        }
        while(ar[right] > pivot)
        {
            right--;
        }
        if(left < right)
        swap(ar[left] , ar[right]);
    }
    swap(ar[right], ar[pivot_index]);
    Sort(ar , beg, right-1 );
    Sort(ar , right+1,endd);
}

void quick_sort(int ar[] ,int n)
{
    Sort(ar , 0, n-1);
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
    {
        cin>>ar[i];
    }
    if(n==1)
    {
        cout<<ar[0]<<endl;
    }
    else if(n==2)
    {
        if(ar[0] > ar[1])
            swap(ar[0] , ar[1]);
    }
    else
    {
        quick_sort(ar , n);
        print(ar, n-1);
    }
    return 0;
}
