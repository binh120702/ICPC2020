// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const	int mn = 5e5 + 5;
int     n, m, vs[mn], visited, tree[mn];
vector<int> edge[mn];

struct 	Point {
	int x,y,id;
	Point(){};
	bool operator < (const Point &B){
		if (x!=B.x) return x<B.x;
		return y<B.y;
	}
} p[mn];

struct 	line {
	int x,y1,y2,typ;
	line(){};
	line(int _x, int _y1, int _y2, int _typ){
		x=_x;
		y1=_y1; 
		y2=_y2;
		typ=_typ;
	}
	bool operator < (const line &B)
	{
		return x<B.x;
	}
}	;

void	add_edge(int u, int v)
{
	edge[u].push_back(v);
	edge[v].push_back(u);
}

void	prepareDfs()
{
	visited = 0;
	FOR(i,1,n) vs[i] = 0;
}

void 	dfs(int u)
{
	if (vs[u]) return;
	vs[u]=1; visited++;
	for(int v: edge[u]) dfs(v);
}

void 	update(int i, int pl)
{
	i++;
	while (i<=m) 
	{
		tree[i]+=pl;
		i+=i&-i;
	}
}

int 	getS(int i)
{
	int s=0;
	while (i)
	{
		s+=tree[i];
		i-=i&-i;
	}
	return s;
}

int  	get(int l, int r)
{
	l++;
	r++;
	if (l>r) return 0;
	return getS(r)-getS(l-1);
}

void	solve()
{
	FOR(i,1,n) edge[i].clear();
	vector<int> cor;
	vector<line> line_arr;
	FOR(i,1,n)
	{
		cor.push_back(p[i].x);
		cor.push_back(p[i].y);
		p[i].id=i;
	}
	
	sort(cor.begin(), cor.end());
	cor.resize(unique(cor.begin(), cor.end())-cor.begin());
	m = cor.size();
	FOR(i,1,m) tree[i]=0;
	
	sort(p+1, p+1+n);
	for(int i=1; i<=n;)
	{
		int j = i;
		while (p[j].x==p[i].x && j<=n) j++;
		if ((j-i)%2==1)
		{
			cout << "NO\n"; return;
		}
		for(int k=i; k<j; k+=2)
		{
			add_edge(p[k].id, p[k+1].id);
			line_arr.push_back({p[k].x,p[k].y,p[k+1].y,0});
		}
		i = j;
	}
	FOR(i,1,n) swap(p[i].x, p[i].y);
	sort(p+1, p+1+n);
	for(int i=1; i<=n;)
	{
		int j = i;
		while (p[j].x==p[i].x && j<=n) j++;
		if ((j-i)%2==1)
		{
			cout << "NO\n"; return;
		}
		for(int k=i; k<j; k+=2)
		{
			add_edge(p[k].id, p[k+1].id);
			line_arr.push_back({p[k].y,p[k].x,0,1});
			line_arr.push_back({p[k+1].y,p[k].x,0,-1});
		}
		i = j;
	}
	prepareDfs();
	dfs(1); 
	if (visited<n) 
		{
			cout << "NO\n"; return;
		}
	sort(line_arr.begin(),line_arr.end());
	int nn = line_arr.size();
	for(int i=0; i<nn;)
	{
		int j = i;
		while (j<nn && line_arr[j].x==line_arr[i].x) j++;
		FOR(k,i,j-1) if (line_arr[k].typ == 0)
		{
			int ll = upper_bound(cor.begin(), cor.end(), line_arr[k].y1) - cor.begin();
			int rr = lower_bound(cor.begin(), cor.end(), line_arr[k].y2) - cor.begin() - 1;
			int intersect = get(ll,rr);
			if (intersect>0) {
				cout<<"NO\n"; return;
			}
		}
		FOR(k,i,j-1) if (line_arr[k].typ!=0)
		{
			int ll = lower_bound(cor.begin(), cor.end(), line_arr[k].y1) - cor.begin();
			update(ll,line_arr[k].typ);
		}
		i = j;
	}
	cout << "YES\n";
}

void	enter()
{
    int ts;
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>ts;
    while (ts--	)
    {
        cin>>n;
        FOR(i,1,n) cin >> p[i].x >> p[i].y;
        solve();
    }
}

int 	main()
{
	enter();
	return 0;
}
