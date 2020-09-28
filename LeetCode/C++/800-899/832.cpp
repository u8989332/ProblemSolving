#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> ans;
 
        for(int i = 0 ;i < n;++i){
            vector<int> row(n);
            for(int j = 0;j < n;++j){
                row[n-j-1] = A[i][j] == 1 ? 0 : 1;
            }
 
            ans.push_back(row);
        }
 
        return ans;
    }
};
 
int main() {
	vector<vector<int>> A;
	vector<int> row1{1,1,0,0};
	vector<int> row2{1,0,0,1};
	vector<int> row3{0,1,1,1};
	vector<int> row4{1,0,1,0};
	A.push_back(row1);
	A.push_back(row2);
	A.push_back(row3);
	A.push_back(row4);
 
	Solution sol;
	vector<vector<int>> ans = sol.flipAndInvertImage(A);
	for(int i = 0 ; i < ans.size();++i){
		for(int j = 0 ; j < ans[i].size();++j){
			cout << " " << ans[i][j];
		}
		cout << endl;
	}
 
	return 0;
}