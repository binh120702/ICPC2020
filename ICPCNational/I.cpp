#include <bits/stdc++.h>
using namespace std;

const
    int64_t base=1e9+7;
const
    int maxn=2e6+10;
int n, m;
int64_t gt[maxn], fi[maxn], res, pown[maxn];

int64_t power(int64_t a, int64_t b){
    if (b==0) return 1;
    int64_t c=power(a, b/2);
    c=c*c%base;
    if (b%2==1) c=c*a%base;
    return c;
}

int64_t tohop(int n, int k){
    return gt[n]*pown[k]%base*pown[n-k]%base;
}

int main()
{
    gt[0]=1;
    for(int i=1; i<maxn; ++i) gt[i]=gt[i-1]*i%base;
    fi[0]=0; fi[1]=1;
    for(int i=2; i<maxn; ++i) fi[i]=(fi[i-1]+fi[i-2])%base;
    pown[0]=1;
    for(int i=1; i<maxn; ++i) pown[i]=power(gt[i], base-2);

    cin >> n >> m;
    res=0;
    --n; --m;
    for(int i=0; i<=n; ++i) res+=tohop(m+i, i)*fi[n-i+1]%base;
    for(int i=0; i<=m; ++i) res+=tohop(n+i, i)*fi[m-i+1]%base;

    cout << res%base;

    return 0;
}
