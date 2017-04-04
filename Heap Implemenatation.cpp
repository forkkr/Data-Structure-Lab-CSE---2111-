#include<bits/stdc++.h>
using namespace std;

struct Heap
{
    struct data
    {
        string name;
        int roll;
        int marks;
        data()
        {
            //name = NULL;
            roll = 0;
            marks = 0;
        }
    };
    // const int MXN = 100005;
    data ar[10005] , temp[1005];
    int sz = 0;
    Heap()
    {
    }
    data Make_data(string str , int roll , int marks)
    {
        data ret;
        ret.name = str;
        ret.roll = roll;
        ret.marks = marks;
        return ret;
    }
    void shiftdown(int i)
    {
        int left = i*2;
        int right = left + 1;
        if( left > sz)
            return;
        if(left == sz)
        {
            if( ar[left].marks > ar[i].marks)
            {
                swap(ar[left], ar[i]);
            }
            else if(ar[left].marks == ar[i].marks && ar[i].roll > ar[left].roll)
            {
                swap(ar[left] , ar[i]);
            }
            return;
        }
        else
        {
            if(ar[left].marks > ar[right].marks)
            {
                if( ar[left].marks > ar[i].marks)
                {
                    swap(ar[left], ar[i]);
                    shiftdown(left);
                }
                else if(ar[left].marks == ar[i].marks && ar[left].roll < ar[i].roll)
                {
                    swap(ar[left] , ar[i]);
                    shiftdown(left);
                }

            }
            else if(ar[right].marks > ar[left].marks)
            {
                if( ar[right].marks > ar[i].marks)
                {
                    swap(ar[right] , ar[i]);
                    shiftdown(right);
                }
                else if(ar[right].marks == ar[i].marks && ar[right].roll < ar[i].roll )
                {
                    swap( ar[right] , ar[i]);
                    shiftdown(right);
                }

            }
            else
            {
                if(ar[left].roll < ar[right].roll)
                {
                    if( ar[left].marks > ar[i].marks)
                    {
                        swap(ar[left], ar[i]);
                        shiftdown(left);
                    }
                    else if(ar[left].marks == ar[i].marks && ar[left].roll < ar[i].roll)
                    {
                        swap(ar[left] , ar[i]);
                        shiftdown(left);
                    }
                }
                else
                {
                    if( ar[right].marks > ar[i].marks)
                    {
                        swap(ar[right] , ar[i]);
                        shiftdown(right);
                    }
                    else if(ar[right].marks == ar[i].marks && ar[right].roll < ar[i].roll )
                    {
                        swap( ar[right] , ar[i]);
                        shiftdown(right);
                    }
                }
            }
        }
        return;
    }
    void shiftup(int i)
    {
        if( i/2 == 0 )
            return;
        int parent = i/2;
        if(ar[parent].marks < ar[i].marks)
        {
            swap(ar[parent] , ar[i]);
            shiftup(parent);
        }
        else if(ar[parent].marks== ar[i].marks)
        {
            if(ar[parent].roll > ar[i].roll)
            {
                swap(ar[parent] , ar[i]);
                shiftup(parent);
            }
        }
        return;
    }
    void init( data d)
    {
        sz++;
        ar[sz] = d;
        shiftup(sz);
    }
    data top()
    {
        return ar[1];
    }
    data topDelete()
    {
        data ret = ar[1];
        swap( ar[sz] , ar[1]);
        sz--;
        shiftdown(1);
        return ret;
    }
    void inser( data d)
    {
        sz++;
        ar[sz] = d;
        shiftup(sz);
    }
    void hsort()
    {
        int rnk = 0 , prev = -1 , cnt;
        cnt = sz;
        for(int i = 1 ; i<= sz ; i++)
        {
            temp[i] = ar[i];
        }
        while(sz!=1)
        {
            data ret = topDelete();
            if(ret.marks != prev)
            {
                rnk++;
                prev = ret.marks;
            }
            cout<<rnk<<" "<<ret.name<<" "<<ret.roll<<" "<<ret.marks<<endl;
        }
        if(ar[1].marks != prev)
        {
            rnk++;
            prev = ar[1].marks;
        }
        cout<<rnk<<" "<<ar[1].name<<" "<<ar[1].roll<<" "<<ar[1].marks<<endl;
        sz = cnt;
        for(int i = 1; i <= cnt; i++)
        {
            swap(ar[i] , temp[i]);
        }
        return;
    }
    void Menu()
    {
        cout<<"Enter command:"<<endl;
        cout<<"insert: 1 Name Roll Marks"<<endl;
        cout<<"showTop: 2"<<endl;
        cout<<"deleteTop: 3"<<endl;
        cout<<"showRank: 4"<<endl;
    }
};

int main()
{
    Heap h;
    freopen("intput.txt","r", stdin);
    int cmd;
    h.Menu();
    while(scanf("%d",&cmd)==1)
    {
        if(cmd==1)
        {
            string name;
            int roll , marks;
            cin>>name>>roll>>marks;
            //cout<<name<<roll<<marks<<endl;
            h.inser(h.Make_data(name , roll , marks));
        }
        else if(cmd==2)
        {
            string name = h.top().name;
            int roll = h.top().roll;
            int marks = h.top().marks;
            cout<<name<<" "<<roll<<" "<<marks<<endl;
        }
        else if(cmd==3)
        {
            h.topDelete();
        }
        else if(cmd==4)
        {
            h.hsort();
        }
    }
}
