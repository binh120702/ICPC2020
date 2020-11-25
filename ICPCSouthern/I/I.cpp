// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const	int mn = 2e5+5;
char    a[mn], b[mn], nex[mn][105];
int     n,m;

void	enter()
{
    scanf("%s%s",a+1,b+1);
}

void    init()
{
    FORD(i,m*2,1)
        FOR(j,1,n) if (a[j]==b[i])
            nex[i][j]= i; else
            nex[i][j]= nex[i+1][j];
}

bool    check(int l, int r, int u, int v)
{
    FOR(i,u,v) if (a[i]!='*')
    {
        if (nex[l][i]==0) return 0;
        l=nex[l][i]+1;
    }
    if (l>r+1) return 0; else return 1;
}

void	solve()
{
    n = strlen(a+1);
    m = strlen(b+1);
    if (n==0 && m==0) {cout<<1; return;}
    int csao=0;
    int res=0;
    FOR(i,1,m) b[i+m]=b[i];
    // khong co dau *
    FOR(i,1,n) if (a[i]=='*') csao++;
    if (csao==0){
        if (n!=m)
        {
            cout<<0;
            return;
        }
        FOR(i,1,m)
        {
            int mark=0;
            FOR(j,1,n) if (b[i+j-1]!=a[j]) mark=1;
            if (!mark) res++;
        }
        cout<<res;
        return;
    }
    // co it nhat mot dau *
    init();
    FOR(i,1,m)
    {
        int l = i;
        int r = i+m-1;
        int go = 1,u,v;
        FOR(j,1,n)
        {
            u=j;
            if (a[j]=='*') break;
            if (a[j]!=b[l])
            {
                go = 0;
                break;
            }
            l++;
        }
        FORD(j,n,1)
        {
            v=j;
            if (a[j]=='*') break;
            if (a[j]!=b[r])
            {
                go = 0;
                break;
            }
            r--;
        }
        if (!go) continue;
        if (check(l,r,u,v)) res++;
    }
    cout<<res;
}

int 	main()
{
	freopen("z.inp","r",stdin);
	freopen("z.out","w",stdout);

	enter();
	solve();

	return 0;
}
