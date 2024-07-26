class Solution {
public:

    void countPairs(vector<int>& nums,int s,int mid,int e,long long &cnt){
        int left = s;
        int right = mid + 1;
        while (left <= mid && right <= e){
            if((long long)nums[left]>(long long)2*nums[right]){
                cnt+=mid-left+1;
                right++;
            }
            else{
                left++;
            }
        }
        merge(nums,s, mid, e);
    }

    void merge(vector<int>& nums, int s, int mid, int e) {
        int left = s;
        int right = mid + 1;
        vector<long long> temp;
        
        while (left <= mid && right <= e) {
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            //right is smaller
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=e){
            temp.push_back(nums[right]);
            right++;
        }
        
        for(int i=s;i<=e;i++){
            nums[i]=temp[i-s];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e,long long &cnt) {
        if (s < e) {
            int mid = s + (e - s) / 2;
            mergeSort(nums,s, mid,cnt);
            mergeSort(nums,mid + 1, e,cnt);
            countPairs(nums,s,mid,e,cnt);
        }
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        long long int cnt=0;
        mergeSort(nums,0,n-1,cnt);
        return cnt;
    }
};