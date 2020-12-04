#include <iostream>
using namespace std;

int ans=-1;
int n,m;
int base[13][13];
bool vis[13][13];
int odd[6][2]={{-1,0},{1,0},{0,-1},{0,1},{1,-1},{1,1}};
int even[6][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1}};

bool valid(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m) return true;
    return false;
}

int upperY(int i,int j){
    int temp=base[i][j];
    if(j%2!=0){
        if(valid(i,j-1) && valid(i,j+1) && valid(i+1,j)){
            temp+=base[i][j-1]+base[i][j+1]+base[i+1][j];
            return temp;
        }else{
            return 0;
        }
    }else{
        if(valid(i-1,j-1) && valid(i-1,j+1) && valid(i+1,j)){
            temp+=base[i-1][j-1]+base[i-1][j+1]+base[i+1][j];
            return temp;
        }else{
            return 0;
        }
    }
    return 0; 
}

int lowerY(int i,int j){
    int temp=base[i][j];
    if(j%2!=0){
        if(valid(i+1,j-1) && valid(i+1,j+1) && valid(i-1,j)){
            temp+=base[i+1][j-1]+base[i+1][j+1]+base[i-1][j];
            return temp;
        }else{
            return 0;
        }
    }else{
        if(valid(i,j-1) && valid(i,j+1) && valid(i-1,j)){
            temp+=base[i][j-1]+base[i][j+1]+base[i-1][j];
            return temp;
        }else{
            return 0;
        }
    }
    return 0;
}

void dfs(int i,int j,int depth,int temp){
    vis[i][j]=true;
    temp+=base[i][j];
    if(depth==4){
        vis[i][j]=false;
        if(temp>ans) ans=temp;
        return;
    }
    if(j%2==0){
        for(int k=0;k<6;k++){
            int x=i+even[k][0];
            int y=j+even[k][1];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]){
                dfs(x,y,depth+1,temp);
            }
        }
    }else{
        for(int k=0;k<6;k++){
            int x=i+odd[k][0];
            int y=j+odd[k][1];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]){
                dfs(x,y,depth+1,temp);
            }
        }
    }
    vis[i][j]=false;
}

int main(){
    cin >> n >> m;
    ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> base[i][j];
            vis[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                dfs(i,j,1,0);
                //cout << i << " " << j << " " << ans << endl;
                int iy=upperY(i,j);
                //cout << iy << endl;
                if(iy>ans) ans=iy;
                int y=lowerY(i,j);
                //cout << y << endl;
                if(y>ans) ans=y;
            }
        }
    }
    cout << ans << endl;
}