#include <bits/stdc++.h>

#define pb push_back
#define all(E) E.begin(), E.end()
#define lwb lower_bound
#define upb upper_bound

using namespace std;

typedef long long ll;

int main() {
    ll N; cin >> N;
    vector<string> cloud(N); string str;
    for(ll n=0;n<N;n++)
        cin >> cloud[n];
    for(ll n=N-1;n>0;n--) {
        string &u = cloud[n-1];
        string &v = cloud[n];
        ll len = min(v.size(), u.size());
        for(ll i=0;i<len;i++) {
            if(u[i+1]==v[i+1]) continue;
            if(u[i+1]<v[i+1]) break;
            if(u[i+1]>v[i+1]) {
                u.resize(i+1);
                break;
            }
        }
    }
    for(ll n=0;n<N;n++)
        cout << cloud[n] << endl;
    return 0;
}
