#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> data(n);
    for(int i = 0; i < n; i++)
        cin>>data[i];
    vector<int> diff(n-1);
    for(int i = 1; i < n; i++)
        diff[i-1] = data[i]-data[i-1];
    int res = 1;
    if( n < 2)
        cout<<res<<"\n";
    else
    {
        int temp_idx = 0;
        for(int i = 1; i < n-1; i++)
        {
            if(diff[i]*diff[i-1] < 0)
            {
                temp_idx++;
                res++;
            }
            else
            {
                res = max(res,temp_idx);
                temp_idx = 1;
            }
        }
        cout<<res+1<<"\n";
    }
    return 0;
}
