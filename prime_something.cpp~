# include <cstdio>
# include <iostream>
# include <cstdlib>

using namespace std;

const int MAXNOS = 101;

int IsComposite[MAXNOS + 1];
int PrimeList[MAXNOS];
int MaxLocPIndex;

int Sieve() 
{
    int i,M,j;

    for (i=2; i*i <= MAXNOS; i++) 
    {
        if(!IsComposite[i]) 
	{
            PrimeList[MaxLocPIndex++]=i;
            M=MAXNOS/i;
            for(j=i; j<=M; j++) 
	    {
                IsComposite[j*i]=1;
            }
        }
    }
    for ( ; i <= MAXNOS; i++) 
    {
        if (!IsComposite[i]) 
	{
            PrimeList[MaxLocPIndex++]=i;
        }
    }
    return 0;
}

int isPrimeSqr(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) 
	    {
		return 0;
	    }
    }
    return 1;
}

int powerMod(int a, int x, int n)
{
    long long int power = a, ans = 1;
    for (int i = 0; x >> i ; i++)
    {
        if (x & (1 << i))
	{
            ans *= power;
            ans %= n;
        }
        power *= power ;
        power %= n;
    }
    return ans;
}

int isPrimeMR(int n)
{
    long long int temp ;
    if (n % 2 == 0) 
	return 0;
    int m = n - 1, k = 0;
    while (m %2 == 0)
    {
        m /= 2; k++;
    }
    int a[10]; 
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    a[3] = 7;
    a[4] = 11;
    for (int i = 5; i < 10; i++) 
	a[i] = rand() % n;

    for (int i = 0; i < 10; i++)
    {
        int j;
        long long int ad = powerMod(a[i], m, n);
        if (ad == 1) 
	    continue;
        for (j = 0; j < k; j++)
	{
            if (ad == n-1) 
		break;
            if (ad == 1) 
		return 0;
            temp = ad*ad;
            ad = temp % n;
        }
        if (ad != 1 && j == k) 
		return 0;
    }
    return 1;
}

int main()
{
    Sieve();
    for(int i = 0 ; i < MaxLocPIndex; i++)
    {
        printf("%d ", PrimeList[i]);
    }
    int n = 100007;
    printf("\n\n %d %d %d\n", n, isPrimeMR(n), isPrimeSqr(n));
    return 0;
}
