using System;

namespace LeetCode48
{
    public class Solution {
        public void Rotate(int[][] matrix) {
            int n = matrix.Length;
            int temp;
            int minRow, maxRow;
            for(int i = 0 ; i < n / 2;++i)
            {
                minRow = i;
                maxRow = n - i - 1;
                for(int j = i , k = 0 ; j < maxRow;++j,++k)
                {
                    temp = matrix[minRow][minRow+k];
                    matrix[minRow][minRow+k] = matrix[maxRow-k][minRow];
                    matrix[maxRow-k][i] = matrix[maxRow][maxRow-k];
                    matrix[maxRow][maxRow-k] = matrix[minRow+k][maxRow];
                    matrix[minRow+k][maxRow] = temp;
                }
            }
        }
    }
    class Program
    {
        static void PrintMatrix(int[][] matrix)
        {
            int n = matrix.Length;
            for(int i = 0 ; i < n;++i)
            {
                for(int j = 0 ; j < n;++j)
                {
                    Console.Write(matrix[i][j] + " ");
                }
                Console.WriteLine();
            }
        }
        static void Main(string[] args)
        {
            int[][] matrix  = new int[][] {
				new int[] { 1, 2, 3, 4 },
				new int[] { 5, 6, 7, 8 },
				new int[] { 9, 10, 11, 12 },
				new int[] { 13, 14, 15, 16 }
			};

            Solution s = new Solution();
            s.Rotate(matrix);
            PrintMatrix(matrix);
        }
    }
}
