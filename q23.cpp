//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void help(vector<int> &arr ,int n ,vector<vector<int>> &ans ,map<vector<int>,int> &mpp ,int index){
        if(index==n){
            if(!mpp[arr]){
                ans.push_back(arr);
                mpp[arr]++;
            }
            return;
        }
        for(int i=index;i<n;i++){
            swap(arr[i],arr[index]);
            help(arr,n,ans,mpp,index+1);
            swap(arr[i],arr[index]);
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>> ans;
        map<vector<int>,int> mpp;
        help(arr,n,ans,mpp,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends