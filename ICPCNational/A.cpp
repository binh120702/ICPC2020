#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
string a[]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
string b[]={"Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius"};
pii c[]={{1, 21}, {2, 20}, {3, 21}, {4, 21}, {5, 21}, {6, 22}, {7, 23}, {8, 23}, {9, 22}, {10, 23}, {11, 23}, {12, 22}};

int getm(string &s){
    for(int i=0; i<12; ++i)
        if (a[i]==s) return i+1;
}

int check(pii p){
    for(int i=0; i<12; ++i)
        if (p<c[i]) return i;
    return 0;
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T, n, m;
    string month;
    cin >> T;
    while (T--){
        cin >> n >> month;
        m=getm(month);
        cout << b[check(pii(m, n))] << '\n';
    }
    return 0;
}
