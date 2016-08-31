#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<unsigned int> > d(n+1,vector<unsigned int>(m+1));
    for(int i = 0; i <= n; i++)
        d[i][0] = i;
    for(int j = 0; j <= m; j++)
        d[0][j] = j;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1])
                d[i][j] = d[i-1][j-1];
            else
                d[i][j] = 1 + min(min(d[i][j-1],d[i-1][j]),d[i-1][j-1]);
        }
    }
    return d[n][m];
}


int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cout<<"Input two string \n";
        string s1,s2;
        cin>>s1 >>s2;
        cout<<count(s1,s2)<<"\n";
    }
    return 0;
}


void main()
{
  
}
