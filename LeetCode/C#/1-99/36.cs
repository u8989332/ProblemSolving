using System;
using System.Collections.Generic;

namespace LeetCode36
{
    public class Solution {
		private bool CheckRowValid(char[][] board, int row){
			HashSet<char> repeat = new HashSet<char>();
			for(int i = 0 ; i < 9;++i){
				if(board[row][i] != '.'){
					if(repeat.Contains(board[row][i])){
						return false;
					}
					repeat.Add(board[row][i]);
				}
			}
			return true;
		}
		
		private bool CheckColValid(char[][] board, int col){
			HashSet<char> repeat = new HashSet<char>();
			for(int i = 0 ; i < 9;++i){
				if(board[i][col] != '.'){
					if(repeat.Contains(board[i][col])){
						return false;
					}
					repeat.Add(board[i][col]);
				}
			}
			return true;
		}
		
		private bool CheckSquareValid(char[][] board, int leftTopRow, int leftTopCol){
			HashSet<char> repeat = new HashSet<char>();
			for(int i = leftTopRow ; i < leftTopRow + 3;++i){
				for(int j = leftTopCol; j < leftTopCol + 3;++j){
					if(board[i][j] != '.'){
						if(repeat.Contains(board[i][j])){
							return false;
						}
						repeat.Add(board[i][j]);
					}
				}
			}
			return true;
		}
		public bool IsValidSudoku(char[][] board) {
			bool result = true;
			for(int i = 0;i < 9;++i){
				result = CheckRowValid(board, i);
				if(!result){
					return result;
				}
			}
			
			for(int i = 0;i < 9;++i){
				result = CheckColValid(board, i);
				if(!result){
					return result;
				}
			}
			
			for(int i = 0;i < 9;i+=3){
				for(int j = 0 ; j < 9; j+=3){
					result = CheckSquareValid(board, i, j);
					if(!result){
						return result;
					}
				}
			}
			
			return true;
		}
	}
	
    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            char[][] board = new char[9][];
			board[0] = new char[]{'5','3','.','.','7','.','.','.','.'};
			board[1] = new char[]{'6','.','.','1','9','5','.','.','.'};
			board[2] = new char[]{'.','9','8','.','.','.','.','6','.'};
			board[3] = new char[]{'8','.','.','.','6','.','.','.','3'};
			board[4] = new char[]{'4','.','.','8','.','3','.','.','1'};
			board[5] = new char[]{'7','.','.','.','2','.','.','.','6'};
			board[6] = new char[]{'.','6','.','.','.','.','2','8','.'};
			board[7] = new char[]{'.','.','.','4','1','9','.','.','5'};
			board[8] = new char[]{'.','.','.','.','8','.','.','7','9'};
            bool result = sol.IsValidSudoku(board);
            Console.Write(result);
            Console.Read();
        }
    }
}
