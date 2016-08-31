#include <bits/stdc++.h>

using namespace std;

void permutation(string prefix, string inp)
{
    int len = inp.length();
    if(len == 0)
        cout << prefix << "\n";
    else
    {
        for(int i = 0; i < len; i++)
        {
            permutation(prefix + inp[i] , inp.substr(0,i) + inp.substr(i+1,len));
        }
    }
}

int main()
{
    string prefix = "";
    string inp;
    cout << "Enter the string : ";
    cin >> inp;
    permutation(prefix, inp);
    return 0;
}
