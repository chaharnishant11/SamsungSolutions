#include<iostream>
using namespace std;
int starti,endi;
int n;
int arr[100000];
//QUEUE 
void push(int x){
  arr[endi]=x;
  endi++;
}

int pop(){
  starti++;
  return arr[starti-1];
}

int size(){
  return endi-starti;
}
 
int maxi(int countall[5]){
  int minindex;
  int min=0;
  for(int i=0;i<5;i++){
    if(countall[i]>=min){
      min=countall[i];
      minindex=i;
    }
  }
  return minindex+1;
}
 
void dfs1(int ** matrix,int **visited,int value,int i,int j){
    visited[i][j]=1;
    int x[4]={1,-1,0,0};
    int y[4]={0,0,-1,1};
    for(int k=0;k<4;k++){
        int l=i+x[k];
        int m=j+y[k];
        if(l>=0 && l<n && m>=0 && m<n && matrix[l][m]==value && !visited[l][m]){
            dfs1(matrix,visited,value,l,m);
        }
    }
}
void dfs(int **matrix,int **visited,int i,int j,int value){
    matrix[i][j]=value;
    visited[i][j]=1;
    int x[4]={1,-1,0,0};
    int y[4]={0,0,-1,1};
    for(int k=0;k<4;k++){
        int l=i+x[k];
        int m=j+y[k];
        if(l>=0 && l<n && m>=0 && m<n && matrix[l][m]==0 && !visited[l][m]){
            dfs(matrix,visited,l,m,value);
        }
    }
}
 
int bfs(int **matrix,int **visited,int x,int y){ 
    int countall[4];
    for(int i=0;i<5;i++)
        countall[i]=0;
    push(x);
    push(y);
    visited[x][y]=1;
    int l[4]={-1,0,1,0};
    int t[4]={0,1,0,-1};
    //cout << "inside BFS" << endl;
    while(size()>0){
        x=pop();
        y=pop();
        if(matrix[x][y]==0){
            //cout << x << " " << y << endl;
            for(int k=0;k<4;k++){
                int i=x+l[k];
                int j=y+t[k];
                if(i>=0 && i<n && j>=0 && j<n && !visited[i][j]){
                    push(i);
                    push(j);
                    visited[i][j]=1;
                }
            }
        }
        else{ 
            //cout << x << " " << y << " " << matrix[x][y] <<  endl;
            countall[matrix[x][y]-1]++;
            for(int k=0;k<4;k++){
                int i=x+l[k];
                int j=y+t[k];
                if(i>=0 && i<n && j>=0 && j<n && !visited[i][j] && (matrix[i][j]==matrix[x][y])){
                    push(i);
                    push(j);
                    visited[i][j]=1;
                }
            }
        }
    }
    // for(int i=0;i<5;i++){
    //     cout << countall[i] << " ";
    // }
    // cout << "BFS Comp"  << endl;
    return maxi(countall);
}
 
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int **matrix;
        int **visited;
        starti=0;
        endi=0;
        matrix=new int*[n];
        visited=new int*[n];
        for(int i=0;i<n;i++){
            matrix[i]=new int [n];
            visited[i]=new int[n];
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
                visited[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    int temp=bfs(matrix,visited,i,j);
                    //cout<<temp<<" replace "<< i << " "  << j << endl;
                    for(int a=0;a<n;a++)
                        for(int b=0;b<n;b++)
                            visited[a][b]=0;
                    dfs(matrix,visited,i,j,temp+5);
                    for(int a=0;a<n;a++)
                        for(int b=0;b<n;b++)
                            visited[a][b]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]>5)
                    matrix[i][j]=matrix[i][j]-5;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //cout<<matrix[i][j]<<" ";
                if(visited[i][j]==0){ 
                    count++;
                    dfs1(matrix,visited,matrix[i][j],i,j);
                }
            }
            //cout << endl;
        }
        cout<<count<<endl;
    }
}