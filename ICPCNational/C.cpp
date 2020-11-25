#include <iostream>

using namespace std;

int     n,k;

void    solve()
{
    for(int bl=1; bl<=n; bl++)
    {
        int du = n%bl, num=n/bl;
        int c1 = (bl-1)*num;
        if (du>1) c1+=du-1;
        int c2 = bl*(num-1) + du;
        if (c1>=k && c2>=k)
        {
            cout<<"YES\n";
            int k1=0, k2=0;
            for(int i=1; i<n; i++)
            {
                if (k1==k) break;
                if (i%bl!=0 && i!=n)
                {
                    cout << i << ' '<< i+1 << '\n';
                    k1++;
                }
            }
            for(int i=1; i<=num-1; i++)
            {
                for(int j=(i-1)*bl+1; j<=i*bl; j++)
                {
                    if (k2==k) break;
                    cout << j << ' '<< j+bl << '\n';
                    k2++;
                }
            }
            for(int j=n-du+1; j<=n; j++)
            {
                if (k2==k) break;
                cout << j-bl << ' '<< j << '\n';
                k2++;
            }
            return;
        }
    }
    cout << "NO";
}

int main()
{
    cin>>n>>k;
    solve();
}
