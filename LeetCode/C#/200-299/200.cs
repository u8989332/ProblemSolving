public class Solution {
    
    private readonly static int[] dx = new int[]{1,0,-1,0};
    private readonly static int[] dy = new int[]{0,1,0,-1};
    private int row, col;
    private bool[][] visit;
    
    private void dfs(int r, int c, char[][] grid){
        visit[r][c] = true;
        for(int d = 0 ; d < 4;++d){
            int ny = r + dy[d];
            int nx = c + dx[d];
            if(ny >= 0 && ny < row && nx >= 0 && nx < col && grid[ny][nx] == '1' && !visit[ny][nx]){
                dfs(ny, nx, grid);
            }
        }
    }
    public int NumIslands(char[][] grid) {
        if(grid.Length == 0){
            return 0;
        }
        
        int ans = 0;
        row = grid.Length;
        col = grid[0].Length;
        
        visit = new bool[row][];
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
}