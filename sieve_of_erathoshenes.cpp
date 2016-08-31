#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
using namespace std;

#define Max_T 100000

void gen_prime(vector<bool>& prime)
{
    int lim = sqrt(Max_T);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i < lim; i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j < Max_T;j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    vector<bool> prime(Max_T,true);
    gen_prime(prime);
    int count = 0;
    for(int i = 0; i < Max_T; i++)
    {
        if(prime[i])
            count++;
    }
    cout<<count<<"\n";
    return 0;
}
