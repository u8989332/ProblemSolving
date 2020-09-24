class Solution {
private:
    const int dx[4] = {1,0,-1,0};
    const int dy[4] = {0,1,0,-1};
    int row, col;
    bool** visit;
    void dfs(int r, int c, vector<vector<char>>& grid){
        visit[r][c] = true;
        for(int d = 0 ; d < 4;++d){
            int ny = r + dy[d];
            int nx = c + dx[d];
            if(ny >= 0 && ny < row && nx >= 0 && nx < col && grid[ny][nx] == '1' && !visit[ny][nx]){
                dfs(ny, nx, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        
        int ans = 0;
        row = grid.size();
        col = grid[0].size();
        
        visit = new bool*[row];
        for(int i = 0; i < row; ++i){
            visit[i] = new bool[col];
        }
            
        
        for(int i = 0 ; i < row;++i){
            for(int j = 0 ; j < col;++j){
                visit[i][j] = false;
            }
        }
        
        for(int i = 0 ; i < row;++i){
            for(int j = 0 ; j < col;++j){
                if(grid[i][j] == '1' && !visit[i][j]){
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};