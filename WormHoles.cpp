#include <iostream>
using namespace std;
int n;
int x[13];
int y[13];
int w[5];
int g[13][13];
int vis[13];

int abs(int a){
    if(a<0) return -1*a;
    return a;
}

int min(int a,int b){
    if(a<b) return a;
    return b;
}

int minind(int* dist,int k){
    int ans=-1;
    int minval=100000;
    for(int i=0;i<k;i++){
        if(!vis[i] && dist[i]<minval){
            ans=i;
            minval=dist[i];
        }    
    }
    return ans;
}

int dijkstra(int k){
    int dist[k];
    for(int i=0;i<k;i++) dist[i]=100000;
    dist[0]=0;
    for(int i=0;i<k;i++){
        int index=minind(dist,k);
        vis[index]=1;
        for(int j=0;j<k;j++){
            if(!vis[j] && g[index][j]!=0 && dist[j]>dist[index]+g[index][j]){
                dist[j]=dist[index]+g[index][j];
            }
        }
    }
    return dist[1];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    cin >> n;
	    cin >> x[0] >> y[0] >> x[1] >> y[1] ;
	    int k=2;
	    for(int j=0;j<n;j++){
	        cin >> x[k] >> y[k];
	        k++;
	        cin >> x[k] >> y[k];
	        cin >> w[k-1];
	        k++;
	    }
	    for(int i=0;i<k;i++) vis[i]=0;
	    for(int i=0;i<k;i++){
	        for(int j=i+1;j<k;j++){
	            g[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
	            g[j][i]=g[i][j];
	            if(i%2==0 && j==i+1 && i!=0){
	                g[i][j]=min(g[i][j],w[i]);
	                g[j][i]=min(g[j][i],w[i]);
	            }
	        }
	    }
	    cout << dijkstra(k) << endl;
	}
	return 0;
}