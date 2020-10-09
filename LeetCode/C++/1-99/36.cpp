#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    bool checkRowValid(vector<vector<char>>& board, int row){
        unordered_set<char> repeat;
        for(int i = 0 ; i < 9;++i){
            if(board[row][i] != '.'){
                if(repeat.count(board[row][i])){
                    return false;
                }
                repeat.insert(board[row][i]);
            }
        }
        return true;
    }
    
    bool checkColValid(vector<vector<char>>& board, int col){
        unordered_set<char> repeat;
        for(int i = 0 ; i < 9;++i){
            if(board[i][col] != '.'){
                if(repeat.count(board[i][col])){
                    return false;
                }
                repeat.insert(board[i][col]);
            }
        }
        return true;
    }
    
    bool checkSquareValid(vector<vector<char>>& board, int leftTopRow, int leftTopCol){
        unordered_set<char> repeat;
        for(int i = leftTopRow ; i < leftTopRow + 3;++i){
            for(int j = leftTopCol; j < leftTopCol + 3;++j){
                if(board[i][j] != '.'){
                    if(repeat.count(board[i][j])){
                        return false;
                    }
                    repeat.insert(board[i][j]);
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool result = true;
        for(int i = 0;i < 9;++i){
            result = checkRowValid(board, i);
            if(!result){
                return result;
            }
        }
        
        for(int i = 0;i < 9;++i){
            result = checkColValid(board, i);
            if(!result){
                return result;
            }
        }
        
        for(int i = 0;i < 9;i+=3){
            for(int j = 0 ; j < 9; j+=3){
                result = checkSquareValid(board, i, j);
                if(!result){
                    return result;
                }
            }
        }
        
        return true;
    }
};

int main()
{
    Solution sol;
	vector<vector<char>> board {{'5','3','.','.','7','.','.','.','.'},
{'6','.','.','1','9','5','.','.','.'},
{'.','9','8','.','.','.','.','6','.'},
{'8','.','.','.','6','.','.','.','3'},
{'4','.','.','8','.','3','.','.','1'},
{'7','.','.','.','2','.','.','.','6'},
{'.','6','.','.','.','.','2','8','.'},
{'.','.','.','4','1','9','.','.','5'},
{'.','.','.','.','8','.','.','7','9'}};
    bool result = sol.isValidSudoku(board);
    cout << result << endl;
    return 0;
}
