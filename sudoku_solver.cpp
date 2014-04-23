/*The idea of this problem is just the searching (either DFS or BFS). In my code below
 * I used BFS, tried to use more space less time. BFS is conducted according to 
 * each blank ('.' in this problem) cell, assign a valid number (char actually) 
 * satisfying no duplicates in the same row, column, as well as the local block.
 * Then push the new status of the board into the BFS queue, keep searching until
 * no blank cell exists.*/
class Solution {
public:
    bool find(vector<vector<char> > &cur, int &i, int &j){
        for (int ii=0;ii<9;ii++){
            for (int jj=0;jj<9;jj++){
                if (cur[ii][jj]=='.'){
                    i=ii;
                    j=jj;
                    return true;
                }
            }
        }
        return false;
    }
     
    unordered_set<char> valid(int i, int j, vector<vector<char> > &cur){
        unordered_set<char> se({'1','2','3','4','5','6','7','8','9'});
        for (int ii=0;ii<9;ii++){
            se.erase(cur[ii][j]);
            se.erase(cur[i][ii]);
        }
         
        for (int ii=0;ii<3;ii++){
            for (int jj=0;jj<3;jj++){
                se.erase(cur[(i/3)*3+ii][(j/3)*3+jj]);
            }
        }
         
        return se;
         
    }
    void solveSudoku(vector<vector<char> > &board) {
        queue<vector<vector<char> > > que;
        que.push(board);
        vector<vector<char> > cur;
        unordered_set<char> se;
        int i=0;
        int j=0;
        while (!que.empty()){
            cur = que.front();
            que.pop();
            if (find(cur,i,j)==false){
                board = cur;
                return;
            }else{
                se = valid(i,j,cur);
                for (const char& x: se){
                    cur[i][j]=x;
                    que.push(cur);  
                }
            }
        }
    }
};
