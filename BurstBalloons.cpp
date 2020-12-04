class Solution {
public:
    int dp[502][502];
    vector<int> balloons;
    int helper(int l,int r,int n){
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=0;
        for(int i=l+1;i<r;i++){
            int curr=helper(l,i,n)+helper(i,r,n);
            if(l==0 && r==n+1){
                curr=curr+balloons[i];
            }else{
                curr=curr+balloons[l]*balloons[r];
            }
            ans=max(ans,curr);
        }
        dp[l][r]=ans;
        return ans;
    }
    
    int maxCoins(vector<int>& nums) {
        balloons=nums;
        memset(dp,-1,sizeof(dp));
        balloons.insert(balloons.begin(),1);
        balloons.push_back(1);
        int n=nums.size();
        int ans=helper(0,n+1,n);
        return ans;
    }
};