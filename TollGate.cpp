#include<iostream>
#include<climits>
using namespace std;
int n;
int tc[25];
int th[25];
int ans;
 
void dfs(int i,int a,int b,int c,int cost){
    if(cost>ans) return;
    int tot=a+b+c;
    if(i==n-1){
        if(tot<th[i]) cost+=tc[i];
        if(cost<ans) ans=cost;
        return;
    }
    dfs(i+1,a,b,c,cost+tc[i]);
    dfs(i+1,a+th[i],b,c,cost+2*tc[i]);
    if(tot>th[i]){
        if(th[i]>b+c) a=tot-th[i];
        if(th[i]>c) b=th[i]-c>=b?0:b+c-th[i];
        dfs(i+1,0,a,b,cost);
    }
} 
 
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ans=100000;
        for(int i=0;i<n;i++){
            cin >> th[i] >> tc[i];
        }
        dfs(0,0,0,0,0);
        cout << ans << endl;
    }
}