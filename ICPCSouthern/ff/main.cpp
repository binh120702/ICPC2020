// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const	int mn = 2e6+5;
const   int base = 50;
const long long md = 1e9+17;
int     n, nc;
long long h[mn], pw[mn];
char    a[mn], b[mn], c[mn];

void	enter()
{
    cin >> n;
    int dem = 0;
    int c = getchar();
    while (dem<n)
    {
        c = getchar();
        for(; c!='\n'; c=getchar()) a[++dem]= c;
    }
    dem=0;
    while (dem<n)
    {
        c=getchar();
        for(; c!='\n'; c=getchar()) b[++dem]= c;
    }
}

int     getHas(int l, int r)
{
    return (h[r]-h[l-1]*pw[r-l+1]+md*md)%md;
}

void    min_string()
{
    int n = strlen(c+1);
    FOR(i,n+1,n+n) c[i]=c[i-n];
    n*=2; c[n+1]='\0';
    int i = 1, ans = 0;
    while (i<=n/2)
    {
        ans = i;
        int j= i+1, k= i;
        while (j<=n && c[k]<=c[j])
        {
            if (c[k]<c[j]) k=i; else k++;
            j++;
        }
        while (i<=k) i+=j-k;
    }
    FOR(i,ans,ans+n/2-1) cout<<c[i];
}

void	solve()
{
    FOR(i,1,n)
    {
        if (a[i]<'A' || a[i]>'z' || (a[i]>'Z' && a[i]<'a')) continue;
        if (a[i]<'a') a[i]+='a'-'A';
        if (b[i]<'a') b[i]+='a'-'A';
        int tmp = b[i]-a[i];
        if (tmp<=0) tmp+=26;
        c[++nc]=char(tmp+'a'-1);
    }
    pw[0]=1;
    FOR(i,1,nc) h[i] = (h[i-1]*base+c[i]-'a'+1)%md,
        pw[i]=pw[i-1]*base%md;

    int res;
    FOR(len,1,nc)
    {
        int head = getHas(1,len);
        int diff = 0;
        FOR(i,2,nc/len) if (getHas((i-1)*len+1,i*len)!=head){
            diff=1; break;
        }
        if (nc%len>0)
        {
            int num=nc/len;
            int u=getHas(num*len+1,nc);
            int v=getHas(1,nc%len);
            if (u!=v) diff=1;
        }
        if (!diff)
        {
            c[len+1]='\0';
            res = len;
            break;
        }
    }
   min_string();
}

int 	main()
{
 //   freopen("z.txt", "r", stdin);
 //   freopen("z.out", "w", stdout);
	enter();
	solve();

	return 0;
}
