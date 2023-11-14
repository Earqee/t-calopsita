/* É suficiente procurar posição limite em anos (atual + período) e subtrair os índices
índice(atual + periodo) - índice(atual) para achar a quantidade de papas eleitos. Daí
resta selecionar a menor.
Como tal distância pode ser muito grande, use upper_bound ou lower_bound. */

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

ll conquer(ll Y, ll P, vector<ll> const popes, vector<ll> &sol) {
	ll i_final, elected, b_electd;
	i_final = elected = b_electd = 0;

	for(ll i = 0; i < P; i++) {
		i_final = lwb(popes.begin() + i, popes.end(), 
			popes.at(i) + Y) - popes.begin();
		elected = i_final - i;
		if(b_electd < elected) {
			b_electd = elected;
			sol.clear();
			sol.pb(popes.at(i));
			sol.pb(popes.at(i_final-1));
		}
	}
	return b_electd;
}

int main(){ 
	ll Y, P, year;
	vector<ll> popes, sol;
	while(cin >> Y >> P) {		
		for(ll i = 0; i < P; i++) {
			cin >> year;
			popes.pb(year);
		}
		printf("%ld ", conquer(Y, P, popes, sol));
		printf("%ld %ld\n", sol.front(), sol.back());
		popes.clear(); sol.clear();
	}
	return 0;
}