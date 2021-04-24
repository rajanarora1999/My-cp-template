// Author:: rajanarora1999
//stay low -> go fast -> kill first -> die last!!!!
//one shot -> one kill -> no luck -> all skill!!!!!
#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mid(l,r) l+(r-l)/2
#define int long long
#define ld long double
#define mp make_pair
#define mt make_tuple
#define tc int t;cin>>t;for(int x=1;x<=t;x++)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define mem(a, b) memset(a, (b), sizeof(a))
#define f(i,s,e,jump) for(int i=s;i<e;i+=jump)
#define rf(i,s,e,jump) for(int i=s;i>=e;i-=jump)
#define pb emplace_back
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define fi first
#define se second
#define pq_max priority_queue <int>
#define pq_min priority_queue <int, vector <int> , greater <int> >
#define printarr(arr) for(auto p:arr)cout<<p<<" ";
#define print_pair_arr(arr) for(auto p:arr)cout<<p.fi<<" "<<p.se<<endl;
#define present(c,x) ((c).find(x) != (c).end())
#define to_string to_strings
#define rsort(a) sort(all(a),greater <int>())
// cmnt out all definitions when using boost lib
/*#include<boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
*/
#define MAX 1e13
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector< pii > vpi;
typedef vector< vi > vvi;
typedef vector <vpi> vvpi;
typedef unordered_map<int,int> umapii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef map<int,int> mapii;
const double pi=acos(-1.0);
const int INF=1e9;

int ceil(int a,int b)
{

    return (a+b-1)/b;
}
int pow(int a,int b)
{
    int ans=1;
    int x=a;
    while(b!=0)
    {
        if(b&1)
        {
            ans=ans*x;
        }
        x=x*x;
        b/=2;
    }
    return ans;
}
pair <int,int> extended_euclid(int a,int b)
{
    if(b==0)
        return {1,0};
    auto p=extended_euclid(b,a%b);
    int x1=p.fi;
    int y1=p.se;
    int x=y1;
    int y=x1-(a/b)*y1;
    return {x,y};
}
int modinverse(int a,int p)
{// use if p is not prime.. if p is prime use fermat theorem
    if(__gcd(a,p)!=1)
        return -1;
    return (extended_euclid(a,p).fi+p)%p;
}
string to_strings(int num)
{
    ostringstream str1;
  str1 << num;
  return str1.str();
}

int moddedpower(int a,int b,int p)
{
    int ans=1;
    int x=a%p;
    if(x==0)
        return 0;
    while(b!=0)
    {
        if(b&1)
        {
            ans=(ans%p*x%p)%p;
        }
        x=(x%p*x%p)%p;
        b/=2;
    }
    return ans;
}
//Fermat Theorem
int modinv(int a,int p)
{// use when p is a prime
    return moddedpower(a,p-2,p);
}
//Wilson Theorem
/*
int n_fact_modp(int n,int p)
{// only if p is a prime
    if(n>=p)
        return 0;
    if(n==p-1)
        return p-1;
   if(n>=p/2)
   {
       int ans=-1;
    for(int i=n+1;i<=p-1;i++)
    {
        ans=(ans*i)%p;
    }
    return (modinv(ans,p)+p)%p;
}
    else
    {
        int ans=1;
        f(i,1,n+1,1)
        {
            ans=(ans*i)%p;

        }
        return ans;
    }
}
int ncr_modp(int n,int r,int p)
{// Lucas Theorem
    int ans=1;
    f(i,n-r+1,n+1,1)
    {
        ans=(ans%p*i%p)%p;
    }
    int ans1=1;
    f(i,1,r+1,1)
    {
        ans1=(ans1%p*i%p)%p;
    }
    return (ans*modinv(ans1,p))%p;
}

pair <int,int> linear_diophantine(int a,int b,int c)
{
    // checks if ax+by=c has integral solns
    if(c%__gcd(a,b)==0)
    {
        int k=c/__gcd(a,b);
        auto p=extended_euclid(a,b);
        int x0=p.fi*k,y0=p.se*k;
        // these are initial solns it has infinite solutions
        // other solns are x=x0+bt/g & y=y0-at/g => put t and get answers.(g is gcd(a,b))
        return {x0,y0};
    }
    else
        return {-1,-1};
}
int modeoflargenums(string x,int p)
{int ans=0;
    for(int i=0;i<x.length();i++)
    {
        ans=(ans*10+(x[i]-'0'))%p;
    }
    return ans;
}
int CRT(vi nums,vi rem)
{
    int prod=1;
    int n=nums.size();
    f(i,0,n,1)
    {
        prod*=nums[i];
    }
    int ans=0;
    f(i,0,n,1)
    {
        ans=ans+(rem[i]*(prod/nums[i])*modinverse(prod/nums[i],nums[i]))%prod;
    }
    return ans;
}
vvi multiply_matrix(vvi &a,vvi  &b)
{
    int r1=a.size();
    int c1=a[0].size();
    int c2=b[0].size();
    vvi ans(r1,vector <int>(c2,0));
    f(i,0,r1,1)
    f(j,0,c2,1)
    f(k,0,c1,1)
    {
        ans[i][j]+=a[i][k]*b[k][j];
    }
    return ans;
}
vvi pow(vvi &trans,int n)
{
    if(n==1)
        return trans;
    if(n==0)
    {
       vvi a(trans.size(),vi (trans[0].size(),1));
        return a;
    }
    vvi ans=pow(trans,n/2);
    ans=multiply_matrix(ans,ans);
    if(n%2==1)
    {
        return multiply_matrix(trans,ans);
    }
    return ans;
}
int matrix_exp(vi &coeff,vi &init_vals,int constt,int n)
{
    if(n==1)
        return init_vals[0];
    int k=coeff.size();
    int l=init_vals.size();
    vvi init2(l,vi (1));
    f(i,0,l,1)
    init2[i][0]=init_vals[i];
    if(constt==0){
    vvi trans(k,vi (k,0));
    f(i,0,k-1,1)
    {
        trans[i][i+1]=1;
    }
    f(i,0,k,1)
    {
        trans[k-1][k-1-i]=coeff[i];
    }
    vvi y=pow(trans,n-1);
    vvi x= multiply_matrix(y,init2);
    return x[0][0];
    }
    else
    {
        vvi trans(k+1,vi (k+1,0));
    f(i,0,k-1,1)
    {
        trans[i][i+1]=1;
    }
    f(i,0,k,1)
    {
        trans[k-1][k-1-i]=coeff[i];
    }
    trans[k][k]=1;
    trans[k-1][k]=1;
    vvi y=pow(trans,n-1);
    vvi x= multiply_matrix(y,init2);
    return x[0][0];
    }
}
bool primecheck(int p)
{// does check in log n time
if(p==2||p==3||p==5||p==7)
return true;
    int arr[4]={2,3,5,7};
    f(i,0,4,1)
    {
        if(moddedpower(arr[i],p-1,p)!=1)
            return false;
    }
    return true;
}
vector <bool> prime(1000001,true);
vi primes;
void sieve()
{
    prime[0]=prime[1]=false;
    f(i,2,1000001,1)
    {
        if(prime[i])
        {
            f(j,i*i,1000001,i)
                prime[j]=false;
        }
    }
    f(i,2,1000001,1)
    if(prime[i])
        primes.push_back(i);
}
class node{
public:
    char data;
    unordered_map <char,node*> children;
    int maxwt;
    node(char d)
    {

        data=d;
    }
};
class trie{
public :
    node* head;
    trie()
    {
        head=new node(NULL);
    }
    void insert(string x,int wt)
    {

        node *temp=head;
        for(int i=0;i<x.length();i++)
        {
            if(temp->children.count(x[i]))
            {
                temp=temp->children[x[i]];
                temp->maxwt=max(temp->maxwt,wt);
            }
            else
            {
                temp->children[x[i]]= new node(x[i]);
                temp=temp->children[x[i]];
                temp->maxwt=wt;
            }
        }
    }
    int finds(string k)
    {
        node *temp=head;
        for(int i=0;i<k.length();i++)
        {if(temp->children.count(k[i]))
        {
                temp=temp->children[k[i]];
        }
        else
            return -1;
        if(i==k.length()-1)
            return temp->maxwt;}

    }
};
*/
void solve(){

}
int32_t main(){

 fastio
 tc
 solve();
}
