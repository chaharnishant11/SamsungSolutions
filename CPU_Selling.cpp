#include <iostream>
#define max(a,b) (a>b)?a:b
using namespace std;

int prod[8][4];
int dp[100][100][100]={-1};

int helper(int ncpu,int pcpu,int nmem,int pmem,int nboard,int n){
    if(dp[ncpu][nmem][nboard]!=-1) return dp[ncpu][nmem][nboard];
    else{
        int temp1=0;
        int temp2=ncpu*pcpu+nmem*pmem;
        for(int i=0;i<n;i++){
            if(ncpu-prod[i][0]>=0 && nmem-prod[i][1]>=0 && nboard-prod[i][2]>=0){
                temp1=max(temp1,helper(ncpu-prod[i][0],pcpu,nmem-prod[i][1],pmem,nboard-prod[i][2],n)+prod[i][3]);
            }
        }
        dp[ncpu][nmem][nboard]=max(temp1,temp2);
        return dp[ncpu][nmem][nboard];
    } 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int ncpu,nmem,nboard,pcpu,pmem,n;
        cin >> ncpu >> nmem >> nboard >> pcpu >> pmem >> n;
        for(int i=0;i<n;i++){
            cin >> prod[i][0] >> prod[i][1] >> prod[i][2] >> prod[i][3];
        }
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                for(int k=0;k<100;k++)
                    dp[i][j][k]=-1;
        cout << helper(ncpu,pcpu,nmem,pmem,nboard,n) << endl;
    }
}
