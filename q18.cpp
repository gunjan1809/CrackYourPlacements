class Solution {
public:

    bool find(vector<vector<char>>& board,int i,int j,int idx,string word,vector<pair<int,int>>& directions,int m , int n ){
        if(idx==word.length()) return true;
        if(i<0||j<0||j>=n||i>=m||board[i][j]=='$'){
            return false;
        }
        if(board[i][j]!=word[idx]) return false;

        char temp=board[i][j];
        board[i][j]='$';

        for(auto &dir:directions){
           int new_i=i+dir.first;
           int new_j=j+dir.second;

           if(find(board,new_i,new_j,idx+1,word,directions,m,n))
            return true;
        }
        board[i][j]=temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int,int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && find(board,i,j,0,word,directions,m,n)) return true;
            }
        }
        return false;
    }
};