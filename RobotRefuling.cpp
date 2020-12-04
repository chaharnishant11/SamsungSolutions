#include<iostream>
#include<climits>
using namespace std;
int n;
int ans=100000;
int a[9];
int vis[9];

// ins 0 is continuing ans refuiling same type of cars until fuel>0 
// ins 1 is going back to the gas station 
// int 2 is going to the disel station

void helper(int n,int dis,int remf,int pind,int cars,int ins,int gas){
    if(n==cars){
        if(ans>dis){
            ans=dis;
        }
        return;
    }
    if(remf<=0) return;
    if(ins==0 && gas==0){
        for(int k=1;k<=n;k++){
            if(vis[k]==0 && a[k]==1){
                vis[k]=1;
                helper(n,dis+abs(pind-k),remf-1,k,cars+1,0,0);
                helper(n,dis+abs(pind-k),2,k,cars+1,1,0);
                helper(n,dis+abs(pind-k),2,k,cars+1,2,0);
                vis[k]=0;
            }
        }
    }
    if(ins==0 && gas==1){
        for(int k=n;k>=1;k--){
            if(vis[k]==0 && a[k]==2){
                vis[k]=1;
                helper(n,dis+abs(pind-k),remf-1,k,cars+1,0,1);
                helper(n,dis+abs(pind-k),2,k,cars+1,1,1);
                helper(n,dis+abs(pind-k),2,k,cars+1,2,1);
                vis[k]=0;
            }
        }
    }
    if(ins==1){
        helper(n,dis+pind,2,0,cars,0,0);
    }
    if(ins==2){
        helper(n,dis+(n+1-pind),2,n+1,cars,0,1);
    }
}
 
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ans=100000;
        for(int i=0;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        helper(n,0,2,0,0,0,0);
        if(ans==100000){
            helper(n,n+1,2,n+1,0,0,1);
        }
        cout << ans << endl;
    }
}