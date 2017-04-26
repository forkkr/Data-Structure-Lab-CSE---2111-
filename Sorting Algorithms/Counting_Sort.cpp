#include<bits/stdc++.h>
using namespace std;

void counting_sort(int ar[] , int n)
{
    int mxN = ar[1];
    for(int i  =2 ; i <= n; i++)
        mxN = max(mxN, ar[i]);

    int cnt[mxN+2];
    memset(cnt , 0 , sizeof(cnt));
    cnt[0]= 0;
for(int i = 1; i <=n ; i++)
        {
            cnt[ar[i]]++;
        }

    for(int i = 1 ; i <= mxN; i++)
    {
        cnt[i]= cnt[i] + cnt[i-1];
    }
    int sorted[n+1];
    for(int i = n ; i >0 ; i--)
    {
        sorted[cnt[ar[i]]]= ar[i];
        cnt[ar[i]]-=1;
    }
    for(int i = 1; i <= n ; i++)
        ar[i] = sorted[i];
}
void print(int ar[] , int n)
{
    if(n<=0)
        return ;
    print(ar ,n-1);
    cout<<ar[n]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    for(int i = 1; i <= n ; i++)
        cin>>ar[i];
    counting_sort(ar , n);
    print(ar , n);
    return 0;
}
