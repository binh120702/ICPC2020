#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int oo=1e7;
const
    pii path[]={{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
int n, m;
vector<vector<int> > a, d;

bool inA(int x, int y){
    if (x<0 || y<0 || x>=n || y>=m) return false;
    return true;
}

int dijkstra(){
    d.clear();
    for(int i=0; i<n; ++i){
        d.push_back(vector<int>(m));
        for(int j=0; j<m; ++j) d[i][j]=oo;
    }

    priority_queue<piii, vector<piii>, greater<piii> > q;

    for(int i=0; i<n; ++i){
        d[i][0]=a[i][0];
        q.push(piii(d[i][0], pii(i, 0)));
    }

    for(int j=0; j<m; ++j){
        d[n-1][j]=a[n-1][j];
        q.push(piii(d[n-1][j], pii(n-1, j)));
    }

    while (!q.empty()){
        int w=q.top().first, x=q.top().second.first, y=q.top().second.second;
        q.pop();
        if (w!=d[x][y]) continue;
        for(int k=0; k<8; ++k){
            int x1=x+path[k].first, y1=y+path[k].second;
            if (inA(x1, y1) && d[x1][y1]>w+a[x1][y1]){
                d[x1][y1]=w+a[x1][y1];
                q.push(piii(d[x1][y1], pii(x1, y1)));
            }
        }
    }

    int res=oo;
    for(int i=0; i<n; ++i) res=min(res, d[i][m-1]);
    for(int j=0; j<m; ++j) res=min(res, d[0][j]);

    //for(int i=0; i<n; ++i) { for(int j=0; j<m; ++j) cout << a[i][j]<< ' '; cout << '\n';}
    //for(int i=0; i<n; ++i) { for(int j=0; j<m; ++j) cout << d[i][j]<< ' '; cout << '\n';}

    if (res==oo) return -1; else return res;
}

int main()
{
    //freopen("a.inp", "r", stdin);

    string s;
    while (cin >> n >> m){
        if (n==0 && m==0) break;
        a.clear();
        for(int i=0; i<n; ++i){
            cin >> s;
            a.push_back(vector<int>(m));
            for(int j=0; j<m; ++j)
                if (s[j]=='#') a[i][j]=0;
                else if (s[j]=='.') a[i][j]=1;
                else a[i][j]=oo;
        }
        cout << dijkstra() << '\n';
    }
    return 0;
}
