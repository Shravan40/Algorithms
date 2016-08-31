#include <iostream>
#include <vector>
using namespace std;

int bst(vector<int> data, int low, int high, int x)
{
    int mid = (low+hight-1)/2;
    if(high < low)
        return -1;
    if(data[mid]==x)
        return mid;
    else if(data[mid] > x)
        return(data,low,mid-1,x);
    else if(data[mid] < x)
        return (data,mid+1,high,x);
}


int bst_left(vector<int> data, int low, int high, int x)
{

}
int main()
{
    ios_base::sync_with_stdio(false);

}
