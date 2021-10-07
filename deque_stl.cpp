/*
 ______   _________ _      _       _
|  ____ \|___   ___| |    | |     | |
| |    \ \   | |   | |____| |     | |
| |    | |   | |   |  ____  |     | |
| |____/ /___| |___| |    | |_____| |
|_______/|_________|_|    |_________|

*/
#include<bits/stdc++.h>
using namespace std;
#define pf push_front
#define mt make_tuple
#define p_b pop_back()
#define ___ cout<<endl
#define bc(x) x.back()
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define fr(x) x.front()
#define p_f pop_front()
#define u_b upper_bound
#define l_b lower_bound
#define vull vector<ull>
#define vpii vector<pii>
#define vpll vector<pll>
#define mii map<int,int>
#define msll multiset<ll>
#define u_s unordered_set
#define u_m unordered_map
#define pii pair<int,int>
#define mci map<char,int>
#define vd vector<double>
#define mci map<char,int>
#define max_of max_element
#define min_of min_element
#define gcd(a,b) __gcd(a,b)
#define out(a) cout<<a<<endl
#define usi unordered_set<int>
#define ptr(x) x.begin(),x.end()
#define vvc vector<vector<char>>
#define str_in(x) string x; cin>>x
#define minof(x)  min_element(ptr(x))
#define srt(x) sort(x.begin(),x.end())
#define rsrt(x) sort(x.rbegin(),x.rend())
#define delete(x,a) x.erase(find(ptr(x),a))
#define pre_sum(x) f(i,1,x.size()) x[i]+=x[i-1]
#define out3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define FOR(i,x) for(auto i=x.begin();i!=x.end();i++)
#define vp_in(x,n) vpll x(n); for(auto &i:x) cin>>i.fi>>i.se
#define month(y) ll month[]={-1,31,leapyear(y)?29:28,31,30,31,30,31,31,30,31,30,31}
#define v2_out(x) f(i,0,x.sz) {for(auto j:x[i]) cout<<j<<" "; cout<<endl;}
#define v2_in(x,n,m) vvll x(n,vll(m)); f(i,0,n)for(auto &j:x[i]) cin>>j
#define m_in(x,n) mll x; for(i=0,int a,b;i<n, cin>>a>>b;i++) x[a]=b
#define s_in(x,n) sll x;for(i=0,int a;i<n,cin>>a;i++)x.insert(a)
#define v_in2(x,y,n) vll x(n),y(n); f(i,0,n) cin>>x[i]>>y[i]
#define invr(n) ull a; while(n) {a=a*10+n%10; n/=10;} n=a
#define v_out(x) for(auto i:x) cout<<i<<" "; cout<<endl
#define ____ ios::sync_with_stdio(0);cin.tie(nullptr);
#define m_out(x) visit(x) cout<<i.fi<<" "<<i.se<<endl
#define inrange(i,a,b) ((i>=min(a,b))&(i<=max(a,b))) 
#define rotate_r(x,a) rotate(x.bg,x.bg+x.sz-a,x.ed)
#define rpqll priority_queue<ll,vll,greater<int>>
#define v_in(x,n) vll x(n);for(auto &i:x) cin>>i
#define lb(x,a) lower_bound(ptr(x),a)-x.begin()
#define ub(x,a) upper_bound(ptr(x),a)-x.begin()
#define rotate_l(x,a) rotate(x.bg,x.bg+a,x.ed)
#define vs_out(x,n) visit(x) cout<<i<<endl
#define adjdif(x) rf(i,n-1,0)x[i]-=x[i-1]
#define vs_in(x,n) vs x(n);read(x)cin>>i
#define _fill(x,a) memset(x,a,sizeof(a))
#define bs(x,a) binary_search(ptr(x),a)
#define out2(a,b) cout<<a<<" "<<b<<endl
#define maxof(x)  max_element(ptr(x))
#define umci unordered_map<char,int>
#define umii unordered_map<int,int>
#define mx(a,b,c) max(a,max(b,c))
#define f(i,a,n) for(i=a;i<n;i++)
#define mn(a,b,c) min(a,min(b,c))
#define pqi priority_queue<int>
#define tiii tuple<int,int,int>
#define vvll vector<vector<ll>>
#define ull unsigned long long
#define rev(x) reverse(ptr(x))
#define len(x) (ll)x.length()
#define sz(x) (ll)x.size()
#define b_s binary_search
#define ti(x,i) get<i>(x)
#define vs vector<string>
#define msi multiset<int>
#define vb vector<bool>
#define vc vector<char>
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define spii set<pii>
#define m_s multiset
#define dbl double
#define bg begin()
#define se second
#define fi first
#define ed end()
#define INF 1e18
#define flt float
#define str string
#define si set<int>
#define sll set<ll>
#define two(n) 1<<n
#define eif else if
#define m_m multimap
#define ll long long
#define pb push_back
#define pi 3.14159265
#define MOD 1000000007
#define ui unsigned int
#define bit(a) bitset<a>
#define clr(x) x.clear()
#define mii map<int,int>
#define vtiii vector<tiii>
#define p_q priority_queue
#define lcm(a,b) a*b/gcd(a,b)
#define read(x) for(auto &i:x)
#define visit(x) for(auto i:x)
#define pqll priority_queue<ll>
#define srtd(x) is_sorted(ptr(x))
#define rf(i,a,n) for(i=a;i>n;i--)
#define rptr(x) x.rbegin(),x.rend()
ll t,n,i,j,k,a,b,c,d,m,l,r,p,q,s,ans;
ll pstv(ll x){if(x<0)return 0;return x;} 
ll ngtv(ll x){if(x<0)return 0;else return x;} 
ll fact(ll n){ll i,c=1;f(i,2,n+1)c*=i;return c;}
ll sum(vll x){ll s=0; for(ll i:x)s+=i;return s;}
ll npr(ll n,ll r){ll s=1,i;f(i,n-r+1,n+1)s*=i;return s;}  
ll d_sum(ll n){ll s=0;while(n>0)s+=n%10,n/=10;return s;}
ll lcmof(vll x){ll s=x[0];for(ll i:x)s=lcm(s,i);return s;}
void tolwr(str &x){ll i,n=sz(x);f(i,0,n)x[i]=tolower(x[i]);}
void toupr(str &x){ll i,n=sz(x);f(i,0,n)x[i]=toupper(x[i]);}
bool leapyear(ll n){if(n%400==0|(n%4==0&n%100>0))return 1;return 0;}
ll gcdof(vll x){ll s=0;for(ll i:x){s=gcd(s,i);if(s==1)break;}return s;}
ll _pow(ll x,ll n){ll s=1;while(n>0){if(n%2==1)s*=x;x*=x;n/=2;}return s;}
bool issubstr(str x, str y){if(x.find(y)!=string::npos)return 1;return 0;}
ll ncr(ll n,ll r){ll s=1,i;if(r>n-r)r=n-r;f(i,1,r+1)s=(s*n-r+i)/i;return s;}
bool palindrome(str x){ll n=sz(x),i;f(i,0,n)if(x[i]!=x[n-i-1])return 0;return 1;}
ll divisor(ll n){ll i,c=0;for(i=1;i*i<n;i++)if(n%i==0)c+=2;if(i*i==n)c++;return c;}
void subarr(vll x){ll n=sz(x),i,j,k;f(i,0,n)f(j,i+1,n+1){f(k,i,j)cout<<x[k]<<" ";___;}}
void substr(str x){ll n=sz(x),i,j,k;f(i,0,n)f(j,i+1,n+1){f(k,i,j)cout<<x[k];cout<<endl;}} 
bool vowel(char c){c=tolower(c);if((c=='a')|(c=='e')|(c=='i')|(c=='o')|(c=='u'))return 1;return 0;}
void strseq(str x,str y,ll i){if(i==sz(x)){if(sz(y)>0){out(y);}}else{strseq(x,y,i+1);y+=x[i];strseq(x,y,i+1);}} 
void arrseq(vll x,vll y,ll i){if(i==sz(x)){if(sz(y)>0){v_out(y);}}else{arrseq(x,y,i+1);y.pb(x[i]);arrseq(x,y,i+1);}}
bool prime(ll n){if(n<=1)return 0;if(n<=3)return 1;if(n%2==0||n%3==0)return 0;for(ll i=5;i*i<=n;i=i+6)if((n%i==0)|(n%(i+2)==0))return 0;return 1;}  
ll minpathsum(vvll x){vvll dp(n,vll(m));ll i,j;f(i,0,n)f(j,0,n)dp[i][j]=x[i][j]+min(i>0?dp[i-1][j]:j==0?0:INF,j>0?dp[i][j-1]:i==0?0:INF);return dp[n-1][m-1];}
#define MAX 100001
void dihan()
{
    cin>>n>>k; v_in(x,n);

    ans=*max_element(x.bg,x.bg+k);
    cout<<ans<<" ";

    for(i=0,j=k;j<n;j++,i++)
    {
    	if(x[i]==ans) ans=*max_element(x.bg+i+1,x.bg+j);
        ans=max(ans,x[j]); cout<<ans<<" ";
    }
}
int main(){____ cin>>t;while(t--){dihan();___;}}












