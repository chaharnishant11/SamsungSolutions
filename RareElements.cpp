#include<iostream>
using namespace std;
int n,c;
int ans=100000;
class queue{
    int q[100000];
    int front=0;
    int back=0;
    public:
    bool empty(){
        if(front-back==0) return true;
        return false;
    }
    int top(){
        if(back-front==0) return -1;
        return q[front];
    }
    void push(int x){
        if(back<100000) q[back++]=x;
    }
    void pop(){
        front++;
    }
};

int min(int a,int b){
    if(a>b) return b;
    else return a;
}

int max(int a,int b){
    if(a>b) return a;
    return b;
}

bool valid(int i,int j,int** matrix){
    if(i<0 || i>=n || j<0 || j>=n || matrix[i][j]==0) return false;
    return true;
}

void bfs(int** mat,int** vis,int** res,int x,int y){
    queue q;
    q.push(x);
    q.push(y);
    int temp=100000;
    while(!q.empty()){
        int i=q.top();q.pop();
        int j=q.top();q.pop();
        int cnt=0;
        for(int k=0;k<c;k++){
            if(vis[res[k][0]][res[k][1]]>0) cnt++;
        }
        if(cnt>=c) return;
        int val=vis[i][j];
        if(valid(i+1,j,mat)){
            vis[i+1][j]=val+1;
            q.push(i+1);
            q.push(j);
        }
        if(valid(i-1,j,mat)){
            vis[i-1][j]=val+1;
            q.push(i-1);
            q.push(j);
        }
        if(valid(i,j+1,mat)){
            vis[i][j+1]=val+1;
            q.push(i);
            q.push(j+1);
        }
        if(valid(i,j-1,mat)){
            vis[i][j-1]=val+1;
            q.push(i);
            q.push(j-1);
        }
    }
}

void clear(int** vis){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vis[i][j]=0;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>c;
        int **matrix;
        int **vis;
        queue q;
        int **res=new int*[c];
        for(int i=0;i<c;i++){
            res[i]=new int[2];
            cin >> res[i][0] >> res[i][1];
            res[i][0]--;
            res[i][1]--;
        }
        matrix=new int*[n];
        vis=new int*[n];
        for(int i=0;i<n;i++){
            matrix[i]=new int [n];
            vis[i]=new int[n];
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
                vis[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    bfs(matrix,vis,res,i,j);
                    int temp=0;
                    for(int k=0;k<c;k++){
                        temp=max(temp,vis[res[k][0]][res[k][1]]);
                    }
                    ans=min(temp,ans);
                    clear(vis);
                }
            }
        }
        cout << ans << endl;
    }
}