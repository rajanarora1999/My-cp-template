// Author:: rajanarora1999
//stay low -> go fast -> kill first -> die last!!!!
//one shot -> one kill -> no luck -> all skill!!!!!
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define endl "\n"
#define fastio this_thread::sleep_for(-9999999999999ms);ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mid(l,r) l+(r-l)/2
#define int long long
#define mp make_pair
#define tc int t;cin>>t;for(int x=1;x<=t;x++)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define mod 1000000007
#define mem(a, b) memset(a, (b), sizeof(a))
#define f(i,s,e,jump) for(int i=s;i<e;i+=jump)
#define rf(i,s,e,jump) for(int i=s;i>=e;i-=jump)
#define pb emplace_back
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define sort(a) sort(all(a));
#define rsort(a) sort(all(a),greater <int>())
#define fi first
#define se second
#define pq_max priority_queue <int>
#define pq_min priority_queue <int, vector <int> , greater <int> >
#define print(arr) for(auto p:arr)cout<<p<<" ";cout<<endl;
#define print_pair(arr) for(auto p:arr)cout<<p.fi<<" "<<p.se<<endl;
#define present(c,x) ((c).find(x) != (c).end())
#define umap unordered_map
struct fhash {int operator() (auto x) const { return 7; }};
// cmnt out all definitions when using boost lib
/*#include<boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
*/
#define INF 1e18
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector< pii > vpi;
typedef vector< vi > vvi;
typedef vector <vpi> vvpi;
typedef unordered_map<int,int,fhash> umapii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef map<int,int> mapii;
const double PI=acos(-1.0);
int ceil(int a,int b){return (a+b-1)/b;}
int pow(int a,int b){int ans=1;int x=a;while(b!=0){if(b&1){ans=ans*x;}x=x*x;b/=2;}return ans;}
int moddedpower(int a,int b,int p){int ans=1;int x=a%p;if(x==0)return 0;while(b!=0){if(b&1){ans=(ans*x)%p;}x=(x*x)%p;b/=2;}return ans;}
//Fermat Theorem
int modinv(int a,int p){return moddedpower(a,p-2,p);}
// for ax+by=gcd(a,b)
//pair <int,int> extended_euclid(int a,int b){if(b==0)return {1,0}; auto p=extended_euclid(b,a%b);int x1=p.fi;int y1=p.se;int x=y1;int y=x1-(a/b)*y1;return {x,y};}
// use modinverse if p is not prime.. if p is prime use fermat theorem
//int modinverse(int a,int p){if(__gcd(a,p)!=1)return -1;return (extended_euclid(a,p).fi+p)%p;}
//Euler Totent fn finds number of coprime numbers less than n. also modinv(a,p) is power(a,euler_totent(p)-1)%p
//int euler_totent_fn(int n){vi prime_factors;int x=n;for(int i=2;i*i<=x;i++){if(x%i==0){prime_factors.pb(i);while(x%i==0)x/=i;}}if(x!=1)prime_factors.pb(x);int ans=n;for(auto p:prime_factors)ans/=p;for(auto p:prime_factors)ans*=(p-1);return ans;}
//vi primes;
//void sieve(){vector <bool> prime(100001,true);prime[0]=prime[1]=false;f(i,2,100001,1){if(prime[i]){f(j,i*i,100001,i)prime[j]=false;}}f(i,2,100001,1)if(prime[i])primes.push_back(i);}
//vi lf(10001,0);
// using linear sieve we can also calculare factors in log n time
//void linear_sieve(){f(i,2,10001,1){if(lf[i]==0){lf[i]=i;primes.pb(i);}for(int j=0;j<primes.size()&&primes[j]<=lf[i]&& primes[j]*i<=10000;j++)lf[i*primes[j]]=primes[j];}/* for factors of n int n;cin>>n;vi factors;while(lf[n]!=n){factors.pb(lf[n]);n/=lf[n];}factors.pb(lf[n]);*/}
//vi fact(100001);
//vi invfact(100001);
//void precompute_fact(){fact[0]=1;f(i,1,100001,1){fact[i]=(i*fact[i-1])%mod;} }
//void precompute_inv_fact(){invfact[100000]=modinv(fact[100000],mod);for(int i=100000;i>0;i--){invfact[i-1]=(i*invfact[i])%mod;} }
//int ncr_modp(int n,int r,int p){return (((fact[n]*invfact[r])%p)*invfact[n-r])%p;}
// check if ax+by=c has integral solns
//pair <int,int> linear_diophantine(int a,int b,int c){if(c%__gcd(a,b)==0){int k=c/__gcd(a,b);auto p=extended_euclid(a,b);int x0=p.fi*k,y0=p.se*k; /* these are initial solns it has infinite solutions other solns are x=x0+bt/g & y=y0-at/g => put t and get answers.(g is gcd(a,b))*/return {x0,y0};}else return {-1,-1};}
//int modeoflargenums(string x,int p){int ans=0;for(int i=0;i<x.length();i++){ans=(ans*10+(x[i]-'0'))%p;}return ans;}
//int CRT(vi nums,vi rem){int prod=1;int n=nums.size();f(i,0,n,1){prod*=nums[i];}int ans=0;f(i,0,n,1){ans=ans+(rem[i]*(prod/nums[i])*modinverse(prod/nums[i],nums[i]))%prod;}return ans;}
//vvi multiply_matrix(vvi &a,vvi  &b){int r1=a.size();int c1=a[0].size();int c2=b[0].size();vvi ans(r1,vector <int>(c2,0));f(i,0,r1,1)f(j,0,c2,1)f(k,0,c1,1){ans[i][j]+=a[i][k]*b[k][j];}return ans;}
//vvi pow_of_matrix(vvi &trans,int n){if(n==1)return trans;if(n==0){vvi a(trans.size(),vi (trans[0].size(),1));return a;}vvi ans=pow_of_matrix(trans,n/2);ans=multiply_matrix(ans,ans);if(n%2==1){return multiply_matrix(trans,ans);}return ans;}
//int matrix_exp(vi &coeff,vi &init_vals,int constt,int n){if(n==1)return init_vals[0];int k=coeff.size();int l=init_vals.size();vvi init2(l,vi (1));f(i,0,l,1)init2[i][0]=init_vals[i];if(constt==0){vvi trans(k,vi (k,0));f(i,0,k-1,1){trans[i][i+1]=1;}f(i,0,k,1){trans[k-1][k-1-i]=coeff[i];}vvi y=pow_of_matrix(trans,n-1);vvi x= multiply_matrix(y,init2);return x[0][0];}else{vvi trans(k+1,vi (k+1,0));f(i,0,k-1,1){trans[i][i+1]=1;}f(i,0,k,1){trans[k-1][k-1-i]=coeff[i];}trans[k][k]=1;trans[k-1][k]=1;vvi y=pow_of_matrix(trans,n-1);vvi x= multiply_matrix(y,init2);return x[0][0];}}
// does check in log n time  fermat primality test
//bool primecheck(int p){if(p==0||p==1)return false;if(p==2||p==3||p==5||p==7)return true;int arr[4]={2,3,5,7};f(i,0,4,1){if(moddedpower(arr[i],p-1,p)!=1)return false;}return true;}
void solve()
{

}
int32_t main(){
fastio;
tc
solve();
}
