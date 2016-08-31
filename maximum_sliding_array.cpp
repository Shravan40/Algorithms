#include <iostream>
#include <vector>

using namespace std;

void find_max(vector<int> data, int k)
{
    int len = data.size();
    vector<int> pre_max(len);
    vector<int> post_max(len);
    for(int i = 0; i < len; i++)
    {
        if(i % k == 0)
            pre_max[i] = data[i];
        else
            pre_max[i] = max(pre_max[i-1],data[i]);
    }
    for(int i = len-1; i >= 0; i--)
    {
        if(i%k == (k-1) || i == len-1)
           post_max[i] = data[i];
        else
           post_max[i] = max(post_max[i+1],data[i]);
    }
    for(int i = k-1; i < len; i++)
       cout<<max(pre_max[i],post_max[i-k+1])<<" ";
    cout<<"\n";
}

int main()
{
    int n,k;
    cin>>n >>k;
    vector<int> data(n);
    for(int i = 0; i < n; i++)
        cin>>data[i];
    find_max(data,k);
    return 0;
}
