#include<bits/stdc++.h>
using namespace std;

int Merging(int ar[] , int start , int last , int mid)
{
    int p = mid;
    int q = last ;
    int i = start ;
    int j = mid + 1 ;
    int tmp[last - start +5];
    int k = 0;
    while(i<=p||j<=q)
    {
        if(i>p)
            tmp[k++] = ar[j++];
        else if(j>q)
            tmp[k++] = ar[i++];
       else if(ar[j]>ar[i])
            tmp[k++] = ar[j++];
        else
        {
            tmp[k++] = ar[i++];
        }
    }
    i = start ;
    j = 0;
    while( j < k)
    {
        ar[start++]= tmp[j++];
    }
    return 0;
}


Merge_sort(int ar[], int start  , int last)
{
    if(start >= last)
        return 0;
    int mid = ( start + last )/2;
    Merge_sort(ar , start , mid);
    Merge_sort(ar , mid+1 , last);
    return Merging(ar , start , last , mid);
}

int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    for(int i = 0 ; i < n ; i++)
    {
        cin>>ar[i];
    }
   /* for(int i = 0 ; i < n ; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;*/
    Merge_sort(ar , 0 , n-1);
    for(int i = 0 ; i < n ; i++)
    {
        cout<<ar[i]<<" ";
    }
}
