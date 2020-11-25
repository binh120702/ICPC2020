// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const	int mn = 5e5 + 5;
int     n;

struct 	Point {
	int x,y,id;
	Point(){};
	bool operator < (const Point &B){
		if (x!=B.x) return x<B.x;
		return y<B.y;
	}
} ;
Point 	p[mn];

void	solve()
{
	vector<int> cor;
	FOR(i,1,n)
	{
		cor.push_back(p[i].x);
	}
}

void	enter()
{
    int ts;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>ts;
        cout << "Hello";
    while (ts--)
    {
        cin>>n;
        FOR(i,1,n) cin >> p[i].x >> p[i].y;
        solve();
    }
}

int 	main()
{
	freopen("l.inp","r",stdin);
	freopen("l.out","w",stdout);
	enter();
	solve();

	return 0;
}
