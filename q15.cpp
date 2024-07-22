class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lSum=0 , rSum=0 , maxSum=0 ;
        for(int i=0;i<=k-1;i++){
            lSum=lSum+cardPoints[i];
        }

        maxSum=lSum;
        int rightIndex=n-1;
        for(int i=k-1;i>=0;i--){
            lSum=lSum-cardPoints[i];
            rSum=rSum+cardPoints[rightIndex];
            rightIndex=rightIndex-1;
            maxSum=max(maxSum,lSum+rSum);
        }
        return maxSum;
    }
};