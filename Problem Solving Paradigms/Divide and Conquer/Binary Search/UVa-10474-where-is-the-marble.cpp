/* Para este problema é suficiente ordenar a sequência e 
procurar o valor dado usando lower_bound. */

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

int main(){ 
	ll N, Q, number,  sol; int counter; 
	vector<ll>::iterator it;
	vector<ll> marble, querie;

	counter = 0;
	while(cin >> N >> Q) {
		if(N || Q) {
			printf("CASE# %d:\n", ++counter);
			while(N--) {
				cin >> number;
				marble.push_back(number);
			}
			while(Q--) {
				cin >> number;
				querie.push_back(number);
			}
			sort(marble.begin(), marble.end());
			for(ll i = 0; i < querie.size(); i++) {
				sol = lower_bound(marble.begin(), marble.end(), querie.at(i)) - marble.begin();
				if(sol < marble.size()) {
					if(marble.at(sol) == querie.at(i)) 
						printf("%d found at %d\n", querie.at(i), sol + 1);
					else
						printf("%d not found\n", querie.at(i));
				}
				else
					printf("%d not found\n", querie.at(i));
			}			
		} else return 0;
		querie.clear(); marble.clear();
	}
}