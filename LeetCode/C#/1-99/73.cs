using System;

public class Solution {
    public void SetZeroes(int[][] matrix) {
        bool hasRow = false;
        bool hasCol = false;
        int r = matrix.Length;
        int c = matrix[0].Length;
        for(int i = 0 ; i < r;++i)
        {
            if(matrix[i][0] == 0)
            {
                hasRow = true;
                break;
            }
        }
        
        for(int i = 0 ; i < c;++i)
        {
            if(matrix[0][i] == 0)
            {
                hasCol = true;
                break;
            }
        }
        
        for(int i = 1 ; i < r;++i)
        {
            for(int j = 1 ; j < c;++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1 ; i < r;++i)
        {
            for(int j = 1; j < c;++j)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(hasRow)
        {
            for(int i = 0 ; i < r;++i)
            {
                matrix[i][0] = 0;
            }
        }
        
        if(hasCol)
        {
            for(int i = 0 ; i < c;++i)
            {
                matrix[0][i] = 0;
            }
        }
    }
}

namespace LeetCode73
{
    class Program
    {
        static void PrintMatrix(int[][] matrix)
        {
            int m = matrix.Length;
            int n = matrix[0].Length;
            for(int i = 0 ; i < m;++i)
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
                new int[] { 1, 7, 1, 0 },
				new int[] { 5, 1, 6, 2 },
				new int[] { 6, 4, 0, 3 },
				new int[] { 0, 7, 9, 9 }
			};

            Solution s = new Solution();
            s.SetZeroes(matrix);
            PrintMatrix(matrix);
        }
    }
}
