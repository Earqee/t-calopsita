#include <bits/stdc++.h>

#define pb push_back
#define pp pop_back
#define mp make_pair
#define mt make_tuple
#define bin_s binary_search
#define all(E) E.begin(), E.end()

using namespace std;
typedef int ll;
typedef vector<ll> vct;
typedef vector<vct> vvct;

#define INV -1
#define LEFT 0
#define RIGHT 1

bitset<1200> ans;
vct cars, best;
vvct dp;
ll T, max_l, new_car, optmal;

ll solve(ll idx, ll left, ll right) {
	if(idx==cars.size())
		return 0;
	ll &ref = dp[idx][left];

	if(ref==-1) {
		ll put_left=0, put_right=0;

		if(left-cars[idx]>=0)
			put_left = 1+solve(idx+1,left-cars[idx],right);
		if(right-cars[idx]>=0)
			put_right = 1+solve(idx+1,left, right-cars[idx]);

		ref = max(put_left,put_right);
		if(ref > best[idx]) {
			best[idx] = ref;
			ans[idx] = put_left>=put_right?LEFT:RIGHT;
		}
	}

	return ref;
}

int main() {
	cin>>T; bool prt_l = false;
	while(T--) {
		if(prt_l)
			cout<< endl;
		prt_l=true;
		cin>>max_l;
		max_l *= 100;
		while(cin>>new_car, new_car!=0) {
			cars.pb(new_car);
			vct new_l(10010, -1);
			dp.pb(new_l);
		}
		best.assign(cars.size(), INV);
		if(!cars.size()) {
			cout << 0 << endl;
			continue;
		}
		optmal = solve(0, max_l, max_l);
		cout << optmal << endl;
		for(ll i=0;i<optmal;i++)
			cout << (ans[i]==LEFT?"port":"starboard") << endl;

		cars.clear();
		dp.clear();
	}
	return 0;
}
