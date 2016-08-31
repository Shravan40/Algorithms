#include <iostream>
#include <vector>
#include <list>

using namespace std;

long long int mypow(long long int a,long long  int b)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    if(b%2)
        return ((a*mypow(a*a,b/2)));
    return(mypow(a*a,b/2));
}

int main()
{
    cout<<"Enter two number a and b \n";
    long long int a,b;
    cin>>a >>b;
    cout<<"calculating pow(a,b) = "<<mypow(a,b)<<"\n";
    return 0;
}
