#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>

#define pb push_back
#define pp pop_back
#define mp make_pair
#define lwb lower_bound
#define upb upper_bound
#define all(E) E.begin(), E.end()
#define e_min min_element
#define e_max max_element 
#define bin_s binary_search 
#define ff find

using namespace std;
typedef long int ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 8> VL;

class Cmd
{
public:
	Cmd(ll n);
	double consumed, consume, leak, pos, num, _max;
	string str;

	bool get_cmd() {
		cin >> num >> str;

		consumed += (num - pos) * (consume/100.0 + leak); 
		_max = max(consumed, _max);
		pos = num;
		if(str == "Fuel") cin >> str >> consume;
		if(str == "Gas") {
			consumed = 0;
			cin >> str;
		}
		if(str == "Mechanic") leak = 0;
		if(str == "Goal") return false;
		if(str == "Leak") leak++;
		return true;
	}
};

Cmd::Cmd(ll n = 0) {
	consumed = 0, consume = n, leak = 0, pos = 0, _max = 0;
}

int main(){ 
	ll n; string str;
	Cmd *car;

	while(cin >> n) {
		cin >> str >> str >> n;
		if(n) {
			car = new Cmd(n);
			while(car->get_cmd());
			printf("%.3lf\n", car->_max);
		}
		else break;
	}
}