// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const	int mn = 2e5 + 5;
int     n,q,t[mn],u[mn],v[mn],notSeen[mn],ht;

void	enter()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>q;
    FOR(i,1,n)
    {
        cin>>t[i];
        if (t[i]==0) ht=i;
    }
}

void	solve()
{
    int typ, tmp, student_sent=0;
    FOR(i,1,q)
    {
        cin>>typ;
        if (typ==1)
        {
            cin>>u[i]>>v[i];
            if (t[u[i]]==2 && t[v[i]]==1)
            {
                student_sent++;
                notSeen[ht]++;
            } else
            if (t[u[i]]==1 && t[v[i]]==2)
            {
                notSeen[v[i]]++;
                notSeen[ht]++;
            } else notSeen[v[i]]++;
        } else
        if (typ==2)
        {
            cin>>u[i]>>v[i];
            if (t[u[v[i]]]==2 && t[v[v[i]]]==1)
            {
                if (u[i]==ht) notSeen[ht]--; else
                student_sent--;
            } else
            notSeen[u[i]]--;
        } else
        {
            cin>>tmp;
            if (t[tmp]==1) cout << student_sent + notSeen[tmp] << '\n'; else
                cout << notSeen[tmp] << '\n';
        }
    }
}

int 	main()
{
	freopen("z.inp","r",stdin);
	freopen("z.out","w",stdout);

	enter();
	solve();

	return 0;
}
