#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool hasRow = false;
        bool hasCol = false;
        int r = matrix.size();
        int c = matrix[0].size();
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
};

void printMatrix(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0 ; i < m;++i)
    {
        for(int j = 0 ; j < n;++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
     vector<std::vector<int>> matrix {
				{ 1, 7, 1, 0 },
				{ 5, 1, 6, 2 },
				{ 6, 4, 0, 3 },
				{ 0, 7, 9, 9 }
			};

    Solution s;
    s.setZeroes(matrix);
    printMatrix(matrix);
    return 0;
}
