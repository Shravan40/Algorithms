#include<iostream>
#include <string>

using namespace std;

void compute_table(int* data, string s)
{
    int len = s.length();
    int idx = 0;
    data[0] = 0;
    for(int i = 1; i < len; )
    {
        if(s[i] == s[idx])
        {
            idx++;
            data[i] = idx;
            i++;
        }
        else
        {
            if(idx != 0)
            {
                idx = data[idx-1];
            }
            else
            {
                data[i] = 0;
                i++;
            }
        }
    }
}


void kmp_search(string text, string pat)
{
    int len1 = text.length();
    int len2 = pat.length();
    int data[len2];
    int j = 0;
    compute_table(data,pat);
    for(int i = 0; i < len1;)
    {
        if(pat[j] == text[i])
        {
            i++;
            j++;
        }
        if(j == len2)
        {
            cout<<"Pattern found at index "<<i-j<<"\n";
            j = data[j-1];
        }
        else if(pat[j] != text[i])
        {
            if(j != 0)
                j = data[j-1];
            else
                i++;
        }
    }
}

int main()
{
    string text, pat;
    cout<<"Enter the text : ";
    getline(cin,text);
    cout<<"Enter the pattern : ";
    cin>>pat;
    kmp_search(text,pat);
    return 0;
}
