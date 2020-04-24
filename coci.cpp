/*
 * let mn[i] is the minimum number in i,i+1,i+2...i+x-1 use two pointers 
 * by finding the maximum mn[i] from i-x+1 i-x+2 .. i you can know the max amount of paint the ith plank could be painted with , use two pointers
 * use greedy to know the second number 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , x ;
ll sum ;
int a [1000009] , mn [1000009] ;
void tp(){
	mset < int > s ;
	for ( int i = 0 ; i < x ; i ++ ) s.ins ( a[i] ) ;
	for ( int l = 0 ; l < n ; l ++ ) {
		mn [l] = *s.begin() ;
		int r = l + x  ;
		if ( r >= n ) break ;
		s .era ( s.find ( a[l] ) ) ;
		s .ins ( a[r] ) ;
	}
	s.clear () ;
	for ( int r = 0 ; r < n ; r ++ ) {
		s.ins ( mn[r] ) ;
		int l = r - x ;
		if ( l >= 0 ) s.era ( s.find ( mn[l] ) ) ;
		sum += a[r] - ( *s.rbegin() ) ;
	}
}
int main () {
	scanf("%d%d",&n,&x);
	for ( int i = 0 ; i < n ; i ++ ) scanf("%d",&a[i]);
	tp () ;
	int last = 0 , crnt = 0 , num = 0 ;
	for ( int i = 0 ; i < n-x+1 ; i ++ ) {
		if (  i - last >= x || mn [i] > crnt || mn[i] > mn[i+1] ) {
			num ++ ;
			crnt = mn [i] ;
			last = i ;
		}
	}
	cout << sum << endl << num << endl ;
}
