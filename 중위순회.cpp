#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string s;
char tree[40001];

void travel(int node)
{
    cout << tree[node];
    
    if(tree[node*2]!=0) 
    {
        travel(node*2);
    }
    
    
    if(tree[node*2+1]!=0)  
    {
        travel(node*2+1);
    }
}

int main()
{
     cin >> s;
     
     for(int i=0; i<40001; i++)
     {
         tree[i]=0;
     }

     for(int i=0; i<s.size(); i++)
     {
     tree[i+1]=s[i]; 
     }

     travel(1);

     return 0;
}

