// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const	int mn = 1e5+5;
int     n, a[mn], bit[mn], pos, b[mn], n2;
vector<int> res;

void	enter()
{
    cin>>n;
    FOR(i,1,n) scanf("%d", &a[i]);
}

void    update(int i)
{
    while (i<=n){
        bit[i]++;
        i+=i&-i;
    }
}

int     get(int i)
{
    int s=0;
    while (i){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}

int     getSum(int l, int r){
    if (l>r) return 0;
    return get(r)-get(l-1);
}

void    push_min()
{
    sort(b+1, b+1+n2);
    res.push_back(b[1]);
    int i = 3;
    while (i<=n2)
    {
        res.push_back(b[i]);
        res.push_back(b[i-1]);
        i+=2;
    }
    if (i==n2+1) res.push_back(b[n2]);
    FOR(i,1,n) cout<<res[i-1]<<' ';
}

void	solve()
{
    if (n==1)
    {
        cout << 1;
        return;
    }
    if (n==2)
    {
        swap(a[1], a[2]);
        cout<<a[1]<<' '<<a[2];
        return;
    }
    update(a[n]);
    update(a[n-1]);
    FORD(i,n-2,1)
    {
        int sumUp = getSum(a[i+1]+1,n);
        int sumDown = getSum(a[i+1]+1,a[i]);
        if (a[i+1]>a[i])
        {
            if (sumUp)
            {
                pos = i;
                break;
            }
        }
        if (a[i+1]<a[i])
        {
            if (sumDown>0 && sumUp>1)
            {
                pos = i;
                break;
            }
        }
        if (i==1 && getSum(max(a[i],a[i+1]+1),n)){
            pos=i;
            break;
        }

        update(a[i]);
    }
    if (pos == 0)
    {
        if (a[1]==n)
        {
            FOR(i,1,n) b[++n2]=i;
            push_min();
        } else
        {
            a[1]++; res.push_back(a[1]);
            FOR(i,1,n) if (i!=a[1]) b[++n2]=i;
            push_min();
        }
        return;
    }
    FOR(i,1,pos) res.push_back(a[i]);
    int tmp = n+1 , tmp2 = n+1;
    FOR(i,pos+1,n) if (a[i]>a[pos+1] && a[i]<tmp) tmp=a[i];
    res.push_back(tmp);
    if (tmp<a[pos]){
        FOR(i,pos+1,n) if (a[i]>tmp && a[i]<tmp2) tmp2=a[i];
        res.push_back(tmp2);
    }
    FOR(i,pos+1,n) if (a[i]!=tmp && a[i]!=tmp2) b[++n2]=a[i];
    push_min();
}

int 	main()
{
	//freopen("z.inp","r",stdin);
	//freopen("z.out","w",stdout);

	enter();
	solve();

	return 0;
}
