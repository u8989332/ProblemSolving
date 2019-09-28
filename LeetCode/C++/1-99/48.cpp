#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
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
};

void printMatrix(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    for(int i = 0 ; i < n;++i)
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
				{ 1, 2, 3, 4 },
				{ 5, 6, 7, 8 },
				{ 9, 10, 11, 12 },
				{ 13, 14, 15, 16 }
			};

    Solution s;
    s.rotate(matrix);
    printMatrix(matrix);

    return 0;
}
