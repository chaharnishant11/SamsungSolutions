#include <iostream>
using namespace std;
int n,m;
int s_x,s_y,l;
int arr[50][50];
int vis[50][50];
int directions[8][4];
int answer[50][50];

void setDirections(){
    // 0 left 1 top 2 right 3 bottom
    directions[0][0]=0;
    directions[0][1]=0;
    directions[0][2]=0;
    directions[0][3]=0;
    directions[1][0]=1;
    directions[1][1]=1;
    directions[1][2]=1;
    directions[1][3]=1;
    directions[2][0]=0;
    directions[2][1]=1;
    directions[2][2]=0;
    directions[2][3]=1;
    directions[3][0]=1;
    directions[3][1]=0;
    directions[3][2]=1;
    directions[3][3]=0;
    directions[4][0]=0;
    directions[4][1]=1;
    directions[4][2]=1;
    directions[4][3]=0;
    directions[5][0]=0;
    directions[5][1]=0;
    directions[5][2]=1;
    directions[5][3]=1;
    directions[6][0]=1;
    directions[6][1]=0;
    directions[6][2]=0;
    directions[6][3]=1;
    directions[7][0]=1;
    directions[7][1]=1;
    directions[7][2]=0;
    directions[7][3]=0;
}

bool isvalid(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m) return true;
    return false;
}

void dfs(int i,int j,int cl){
    if(cl==l) return;
    vis[i][j]=true;
    answer[i][j]=1;
    if(isvalid(i,j-1) && directions[arr[i][j]][0] && directions[arr[i][j-1]][2] && !vis[i][j-1]){
        dfs(i,j-1,cl+1);
        vis[i][j-1]=false;
    }
    if(isvalid(i+1,j) && directions[arr[i][j]][3] && directions[arr[i+1][j]][1] && !vis[i+1][j]){
        dfs(i+1,j,cl+1);
        vis[i+1][j]=false;
    }
    if(isvalid(i,j+1) && directions[arr[i][j]][2] && directions[arr[i][j+1]][0] && !vis[i][j+1]){
        dfs(i,j+1,cl+1);
        vis[i][j+1]=false;
    }
    if(isvalid(i-1,j) && directions[arr[i][j]][1] && directions[arr[i-1][j]][3] && !vis[i-1][j]){
        dfs(i-1,j,cl+1);
        vis[i-1][j]=false;
    }
}

int main(){
    int t;
    cin >> t;
    setDirections();
    while(t--){
        cin >> n >> m;
        cin >> s_x >> s_y >> l;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> arr[i][j];
                vis[i][j]=false;
                answer[i][j]=0;
            }
        }
        int ans=0;
        if(arr[s_x][s_y]==0) cout << ans << endl;
        else{
            dfs(s_x,s_y,0);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    ans+=answer[i][j];
                }
            }
            cout << ans << endl;
        }
    }
}