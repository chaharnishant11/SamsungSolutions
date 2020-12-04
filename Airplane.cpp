#include <iostream>
using namespace std;
int a[13][5],b[5][5];

void detonate(int row){
    for(int i=row;i>=row-5;i--){
        for(int j=0;j<5;j++){
            b[row-i][j]=0;
            if(i>=0 && a[i][j]==2){
                a[i][j]=0;
                b[row-i][j]=2;
            }
        }
    }
}

void undetonate(int row){
    for(int i=row;i>=row-5;i--){
        for(int j=0;j<5;j++){
            if(i>=0 && b[row-i][j]==2){
                a[i][j]=2;
            }
        }
    }
}

void getMax(int pos,int coins,int n,int& maxCoins){
   if(pos<0 || pos>4 || coins<0) return;
   if(a[n-1][pos]==1) coins++;
   if(a[n-1][pos]==2) coins--;
   if(n==1){
       if(coins>maxCoins) maxCoins=coins;
       return;
   }
   else{
       getMax(pos-1,coins,n-1,maxCoins);
       getMax(pos+1,coins,n-1,maxCoins);
       getMax(pos,coins,n-1,maxCoins);
   }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int ans=-1;
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin >> a[i][j];
            }
        }
        for(int i=0;i<5;i++) a[n][i]=0;
        a[n][2]=3;
        for(int i=n-1;i>=0;i--){
            int coins=-1;
            detonate(i);
            getMax(2,0,n,coins);
            if(coins>ans) ans=coins;
            undetonate(i);
            // getMax(2,0,n,coins);
            // if(coins>ans) ans=coins;
        }
        if(ans<0) cout << -1 << endl;
        else cout << ans << endl;
    }
}