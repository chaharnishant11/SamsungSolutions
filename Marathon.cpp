#include<iostream>
#include<climits>
using namespace std;
int time1[5];
int enrgy_spent[5];
 
int main(){
    int t,energy,distance,minutes,seconds;
    cin>>t;
    for(int i=0;i<t;i++){ 
        cin>>energy>>distance;
        for(int j=0;j<5;j++){
            cin>>minutes>>seconds>>enrgy_spent[j];
            time1[j]=minutes*60+seconds;
        }
        int arr[distance+1][energy+1];
        for(int j=0;j<distance+1;j++){
          for(int k=0;k<energy+1;k++){
            if(j==0)
                arr[j][k]=0;
            else
                arr[j][k]=INT_MAX;
          }
        }
        for(int j=1;j<distance+1;j++){
          for(int k=1;k<energy+1;k++){
                int min1=INT_MAX;
                for(int q=0;q<5;q++){ 
                    if(k-enrgy_spent[q]<0)
                        continue;
                    int temp;
                    if(arr[j-1][k-enrgy_spent[q]]!=INT_MAX){ 
                        temp=arr[j-1][k-enrgy_spent[q]]+time1[q];
                        min1=min(temp,min1);
                    }
                }
                arr[j][k]=min1;
          }
        }
        int ans=INT_MAX ;
        for(int j=0;j<energy+1;j++)
            ans=min(ans,arr[distance][j]);
        cout<<ans/60<<" "<<ans%60<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
 
int d,e;
int a[5][2];
int dp[1000][1000]; // dp array of dist , energy
 
int solve(int d, int e){
    // base case
    if(d == 0)return 0;
    if(dp[d][e] != 99999)return dp[d][e];
    // recursive case
    int ans = INT_MAX - 100000;
    for(int i =0; i<5; i++){
        if(e >= a[i][1]){
           int temp = a[i][0] + solve(d-1, e - a[i][1]);
           ans = min(ans,temp);
        }
    }
    return dp[d][e] = ans;
}
 
int main(){
   
    cin>>d>>e;
   
    for(int i = 0; i<5; i++)
    cin>>a[i][0]>>a[i][1]; // corresponds to time and energy
   
    for(int i = 0; i<1000; i++)for(int j =0; j<1000; j++)dp[i][j] = 99999;
   
     cout<<solve(d,e)<<endl;
   
    return 0;
}