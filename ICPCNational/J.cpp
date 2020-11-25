#include <bits/stdc++.h>
using namespace std;

int n;
int64_t K, a[20], b[20], c[20];
int64_t res=0;

void tinh(){
    for(int i=1; i<=n; ++i) c[i]=b[i];
    sort(c+1, c+n+1);
    int64_t sum=0;
    for(int ih=2; ih<=n; ++ih){
        int64_t del=c[ih]-c[ih-1];
        int pos=0;
        for(int i=1; i<=n; ++i)
        if (b[i]>=c[ih]){
            if (pos!=0) sum+=del*(i-pos-1);
            pos=i;
        }
    }
    res=max(res, sum);
}

void dequy(int i, int64_t K, int64_t gmax){
    if (i>n+1 || K==0){
        for(int j=i; j<=n; ++j) b[j]=a[j];
        tinh();
        return;
    }
    b[i]=a[i];
    dequy(i+1, K, max(gmax, a[i]));

    b[i]=a[i]+K;
    dequy(i+1, 0, gmax);

    for(int k=max(int64_t(1), gmax-a[i]); k<=K; ++k){
        b[i]=a[i]+k;
        dequy(i+1, K-k, max(gmax, b[i]));
    }
    /*if (a[i]>=gmax) return;
    else{
        int64_t del=min(K, gmax-a[i]);
        b[i]=a[i]+del;
        dequy(i+1, K-del, gmax);
    }*/
}

int main()
{
    freopen("a.inp", "r", stdin);
    cin >> n >> K;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i)
    for(int k=1; k<=K; ++k){
        int64_t gmax=0;
        for(int t=1; t<=i; ++t) b[t]=a[t];
        b[i]+=k;
        for(int t=1; t<=i; ++t) gmax=max(gmax, b[t]);
        dequy(i+1, K-k, gmax);
    }
    cout << res;
    return 0;
}
