#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
        return;

        int cols = board[0].size();
        int rows = board.size();

       for(int i =0 ;i < cols;i++){
           if(board[0][i]== 'O')
           bfsBoundary(board,0,i);

           if(board[rows-1][i] == 'O')
           bfsBoundary(board,rows-1,i);
       }

       for(int i = 0;i <rows;i++){
           if(board[i][0] == 'O')
           bfsBoundary(board,i,0);

           if(board[i][cols-1] == 'O')
           bfsBoundary(board,i,cols-1);
       }

       for(int i = 0;i < rows;i++){
           for(int j = 0;j < cols;j++){
               if(board[i][j] == 'O')
               board[i][j] = 'X';
                else  if(board[i][j] == 'B')
               board[i][j] = 'O';
           }
       }

        
    }

    void bfsBoundary(vector<vector<char> >& board, int w, int l){
        int With = board.size();
        int Height = board[0].size();

        board[w][l] = 'B';

        stack<pair<int,int> > q;
        q.push(make_pair(w,l));

        while(!q.empty()){
            pair<int ,int> cur = q.top();
            q.pop();
            pair<int,int> ajs[4] = {{cur.first-1,cur.second},{cur.first+1,cur.second},
                                    {cur.first,cur.second-1},{cur.first,cur.second+1}};
            
            for(int i = 0;i < 4;i++){
                int wt = ajs[i].first;
                int ht = ajs[i].second;

                if(wt>= 0 && wt< With && ht>= 0 && ht < Height && board[wt][ht] == 'O'){
                    board[wt][ht] ='B';
                    q.push(make_pair(wt,ht));
                }
            }
        }
    }
};