#include <bits/stdc++.h>

#define pb push_back
#define pp pop_back
#define lwb lower_bound
#define upb upper_bound
#define all(E) E.begin(), E.end()
#define frt(E) get<0>(E)
#define scd(E) get<1>(E)
#define trd(E) get<2>(E)

using namespace std;
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef tuple<ll,ll,ll> tt;
typedef vector<tt> vtt;
typedef bitset<1 << 20> VL;

ll N;
vtt arr;

//some dp problems becomes easier if input is sorted
//this is one of them
bool comp(tt a, tt b) {
    if(frt(a)==frt(b))
        return scd(a) < scd(b);
    return frt(a) < frt(b);
}

ll botup() {
    ll opt = 0; //answer
    sort(all(arr)); //put small blocks first
    vct lis(arr.size());
    lis[0] = trd(arr[0]);
    for(ll i=1;i<arr.size();i++) {
        //minimum optimal of itself is trd(arr[i])
        lis[i] = trd(arr[i]);
        //check if it is possible to put any boxes above
        //the current boxes, if possible, put it
        for(ll j=0;j<i;j++)
            if(frt(arr[j])<frt(arr[i]) && scd(arr[j])<scd(arr[i]))
                lis[i] = max(lis[i], lis[j]+trd(arr[i]));
        opt = max(opt, lis[i]);
    }
    return opt; //pretty easy, huh?
}

int main() {
    ll counter = 0;
    while(cin >> N, N != 0) {
        arr.clear();
        vct temp(3);
        for(ll i=0;i<N;i++) {
            cin>>temp[0]>>temp[1]>>temp[2];
            sort(all(temp));
            do { arr.pb({temp[0], temp[1], temp[2]});}
                while(next_permutation(all(temp)));
        }
        printf("Case %lld: maximum height = %lld\n",++counter,botup());
    }
    return 0;
}
