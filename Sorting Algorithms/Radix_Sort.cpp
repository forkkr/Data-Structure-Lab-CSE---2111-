#include<bits/stdc++.h>
using namespace std;

void radix_sort(int ar[] , int n)
{
    int mx = ar[0];
    for(int i = 1; i <= n; i++)
        mx = max(mx , ar[i]);
    int mxLength = 0;
    while(mx)
    {
        mx/=10;
        mxLength++;
    }
    int tmp[n+1];
    int p  = 1;
    for(int i = 1 ; i <= mxLength; i++)
    {
        int sz = 0;
        for(int j = 0; j <= 9; j++)
        {
            for(int ik = 0; ik <=n ; ik++)
            {
                int md = ar[ik]/p;
                md %=10;
                if(md==j)
                {
                    tmp[sz++] = ar[ik];
                }
            }
        }
        for(int ik = 0; ik <=n ; ik++)
        {
            ar[ik] = tmp[ik];
        }
        p *=10;
    }
}
void print(int ar[]  , int n)
{
    if(n <0)
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
    radix_sort(ar , n-1);
    print(ar , n-1);
    return 0;
}
