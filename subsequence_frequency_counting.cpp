/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|

*/
#include  <unordered_set>
#include  <unordered_map>
#include  <algorithm>
#include  <iostream> 
#include  <iterator> 
using namespace std;
#include  <sstream> 
#include  <iomanip> 
#include  <utility> 
#include  <cstdlib>
#include  <cstring>
#include  <string> 
#include  <cstdio> 
#include  <cctype> 
#include  <vector> 
#include  <math.h> 
#include  <bitset>
#include  <stack> 
#include  <queue> 
#include  <cmath> 
#include  <ctime>
#include  <map>  
#include  <set>  
#define INF 1e18 
#define fi first 
#define sz size()
#define se second 
#define str string
#define sll set<ll>
#define two(n) 1<<n
#define eif else if
#define ms multiset
#define mm multimap
#define len length()
#define ll long long
#define pb push_back
#define mt make_tuple
#define pf push_front
#define mll map<ll,ll>
#define MOD 1000000007
#define vll vector<ll>
#define ___ cout<<endl
#define popb pop_back()
#define popf pop_front()
#define rf(i,a,n) for(i=a;i>n;i--) 
#define rptr(x) x.rbegin(),x.rend()
#define minof(x) min_element(ptr(x))
#define min3(a,b,c) min2(min2(b,c),a)
#define out2(a,b) cout<<a<<" "<<b<<endl
#define v_in(x,n) vll x(n);for(auto &i:x) cin>>i
#define rpqll priority_queue<ll,vll,greater<int>>
#define ub(x,a) upper_bound(x.begin(),x.end(),a)-x.begin()
#define vp_in(x,n) vpll x(n);for(auto &i:x)cin>>i.fi>>i.se
#define month(y) ll month[]={-1,31,leapyear(y)?29:28,31,30,31,30,31,31,30,31,30,31}
#define v2_in(x,n,m) vvll x(n,vll(m)); f(i,0,n)for(auto &j:x[i]) cin>>j
#define m_in(x,n) mll x; for(i=0,int a,b;i<n, cin>>a>>b;i++) x[a]=b
#define s_in(x,n) sll x;for(ll a,i=0;i<n;cin>>a,i++)x.insert(a)
#define v_in2(x,y,n) vll x(n),y(n); f(i,0,n) cin>>x[i]>>y[i]
#define lb(x,a) lower_bound(x.begin(),x.end(),a)-x.begin()
#define inrange(i,a,b) ((i>=min(a,b))&(i<=max(a,b)))
#define out3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define maxof(x) max_element(x.begin(),x.end())
#define revers(x) reverse(x.begin(),x.end()) 
#define delete(x,a) x.erase(find(ptr(x),a)) 
#define bs(x,a) binary_search(ptr(x),a) 
#define max3(a,b,c) max2(max2(b,c),a) 
#define f(i,a,n) for(i=a;i<n;i++)
#define ptr(x) x.begin(),x.end() 
#define ull unsigned long long 
#define lcm(a,b) a*b/gcd(a,b)
#define tll tuple<ll,ll,ll> 
#define tup(x,i) get<i>(x) 
#define b_s binary_search 
#define vs vector<string>
#define um unordered_map
#define vull vector<ull>
#define u_b upper_bound 
#define l_b lower_bound 
#define vb vector<bool> 
#define vc vector<char> 
#define pll pair<ll,ll> 
#define vpll vector<pll> 
#define us unordered_set 
#define clr(x) x.clear() 
#define vtll vector<tll> 
#define pq priority_queue 
#define mcll map<char,ll>
#define max_of max_element
#define min_of min_element
#define msll map<string,ll>
#define out(a) cout<<a<<endl
#define vvll vector<vector<ll>>
#define vvc vector<vector<char>>
#define str_in(x) string x; cin>>x
#define digit(n) floor(log(n)/2.0)+1
#define srt(x) sort(x.begin(),x.end())
#define _fill(x,a) memset(x,a,sizeof(a)) 
#define rsrt(x) sort(x.rbegin(),x.rend())
#define pi 3.141592653589793238462643383279
#define rotate_l(x,a) rotate(x.bg,x.bg+a,x.ed)
#define vs_in(x,n) vs x(n);for(auto &i:x) cin>>i 
#define rotate_r(x,a) rotate(x.bg,x.bg+x.sz-a,x.ed)
#define ____ ios::sync_with_stdio(0);cin.tie(nullptr);
ll d_sum(ll n){ll s=0;while(n>0)s+=n%10,n/=10;return s;}
template<typename T>T pstv(T x){if(x<0)return 0;return x;}
ll rev(ll n){ll a; while(n) {a=a*10+n%10;n/=10;} return a;}
void vs_out(vector<string> x) { for(auto i:x) cout<<i<<endl;}
template<typename T>T ngtv(T x){if(x<0)return 0; else return x;} 
bool leapyear(ll n){if(n%400==0|(n%4==0&n%100>0))return 1;return 0;}
template<typename T1,typename T2>T1 max2(T1 a,T2 b){return (b>a)?b:a;}
template<typename T1,typename T2>T1 min2(T1 a,T2 b) {return (b<a)? b:a;}
bool issubstr(str x, str y){if(x.find(y)!=string::npos)return 1;return 0;}
void tolwr(string &x){ll i,n=x.size();for(i=0;i<n;i++) x[i]=tolower(x[i]);}
void toupr(string &x){ll i,n=x.size(); for(i=0;i<n;i++) x[i]=toupper(x[i]);}
template<typename T>ull fact(T n){ull i,c=1;for(i=2;i<n+1;i++)c*=i;return c;} 
template<typename T>ll sum(vector<T> x) {ll s=0; for(auto i:x) s+=i; return s;} 
template<typename T1,typename T2>void Swap(T1 *a,T2 *b) {*a^=*b; *b^=*a; *a^=*b;}
template<typename T>void v_out(vector<T> x){for(auto i:x)cout<<i<<" "; cout<<endl;}
bool compare(int a,int b){/* return a<b;//ascending */ return a>b; /* //descending*/}
ll divisor(ll n){ll i,c=0; for(i=1;i*i<n;i++) if(n%i==0) c+=2; if(i*i==n)c++;return c;}
template<typename T>ull lcmof(vector<T> x){T s=x[0]; for(auto i:x) s=lcm(s,i); return s;}
template<typename T>void pre_sum(vector<T>x) { ll i,n=x.size(); for(i=1;i<n;i++)x[i]+=x[i-1];}
template<typename T> void adjdif(vector<T>&x){ll n=x.size(),i;for(i=n-1;i>-1;i++) x[i]-=x[i-1];}
bool palindrome(string x){ll n=x.size(),i; for(i=0;i<n;i++) if(x[i]!=x[n-i-1]) return 0; return 1;}
template<typename T1,typename T2>ull npr(T1 n,T2 r){ull s=1,i;for(i=n-r+1;i<n+1;i++)s*=i;return s;}
template<typename T1,typename T2>void m_out(map<T1,T2>x){for(auto i:x) cout<<i.fi<<" "<<i.se<<endl;}
template<typename T>ull gcdof(vector<T> x){T s=0;for(auto i:x) {s=gcd(s,i); if(s==1)break;} return s;}
bool vowel(char c){c=tolower(c);if((c=='a')|(c=='e')|(c=='i')|(c=='o')|(c=='u')) return 1; else return 0;}
template<typename T1,typename T2>ull _pow(T1 x,T2 n){ull s=1;while(n>0){if(n%2==1)s*=x;x*=x;n/=2;}return s;}
void substr(str x){ll n=x.sz,i,j,k; for(i=0;i<n;i++) for(j=i+1;j<n+1;j++) {for(k=i;k<j;k++) cout<<x[k]; cout<<endl;}} 
template<typename T1,typename T2>ull ncr(T1 n,T2 r){ull s=1,i; if(r>n-r)r=n-r;for(i=1;i<r+1;i++)s=(s*n-r+i)/i; return s;}
void strseq(string x,string y,ll i){if(i==x.size()){if(y.size()>0) out(y);}else{strseq(x,y,i+1);y+=x[i]; strseq(x,y,i+1);}} 
string spell(ll n){vector<string> num={" ","one","two","three","four","five","six","seven","eight","nine"}; return num[n];}
template<typename T>void v2_out(vector<vector<T>> x) {T i,n=x.sz; for(i=0;i<n;i++) { for(auto j:x[i]) cout<<j<<" "; cout<<endl;}}
template<typename T>void subarr(vector<T> x){ll n=x.sz,i,j,k;for(i=0;i<n;i++)for(j=i+1;j<n+1;j++){for(k=i;k<j;k++)cout<<x[k]<<" ";cout<<endl;}}
bool prime(ll n){if(n<=1)return 0;if(n<=3)return 1;if(n%2==0|n%3==0)return 0;for(ll i=5;i*i<=n;i=i+6)if((n%i==0)|(n%(i+2)==0))return 0;return 1;}  
mll ma;


ll minpathsum(vvll x,ll n,ll m){vvll dp(n,vll(m));ll i,j;for(i=0;i<n;i++)for(j=0;j<n;j++)dp[i][j]=x[i][j]+min(i>0?dp[i-1][j]:j==0?0:INF,j>0?dp[i][j-1]:i==0?0:INF);return dp[n-1][m-1];}
template<typename T1,typename T2>ull gcd(T1 a,T2 b) {if(a==0|b==0)return a|b;unsigned shift=__builtin_ctz(a|b);a>>=__builtin_ctz(a);do{b>>=__builtin_ctz(b);if(a>b)Swap(&a,&b);b-=a;}while(b>0);return a<<shift;}

#define MAX 100001
ll t,n,i,j,k,a,b,c,d,m,l,r,p,q,s,ans;
template<typename T>void arrseq(vector<T> x,mll y,ll i,ll m,ll ans)
 {
 	if(i==x.size()) 
 	{
        ma[ans]=(ma[ans]+1)%MOD;
 	} 
 	else
 	{
 		arrseq(x,y,i+1,m,ans);
 		y[x[i]]=(y[x[i]]+1)%MOD; if(y[x[i]]>m) m=y[x[i]],ans=x[i];
 	    arrseq(x,y,i+1,m,ans);
 	}
 }


void dihan()
{
   clr(ma);
   cin>>n; v_in(x,n); mll y; 
   arrseq(x,y,0,0,0);
   f(i,1,n+1) cout<<ma[i]<<" "; ___;
}
int main(){____ cin>>t;while(t--)dihan();}