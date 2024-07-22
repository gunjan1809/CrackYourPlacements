class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int> mpp;
        int preSum=0 , count =0;
        mpp.insert({0,1});
        for(int i = 0;i<n;i++){
            preSum+=nums[i];
            if(mpp.find(preSum-k) !=mpp.end()){
                count+=mpp[preSum-k];
            }
            mpp[preSum]++;
        }
        return count;
    }
};