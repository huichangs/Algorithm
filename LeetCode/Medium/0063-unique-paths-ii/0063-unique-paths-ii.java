class Solution {
    int[][] arr;
    int[][] og;
    int n, m;
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        n = obstacleGrid.length;
        m = obstacleGrid[0].length;
        arr = new int[n][m];
        og = obstacleGrid;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1){
            return 0;
        }

        return dfs(0, 0);
    }

    public int dfs(int x, int y){
        if(x >= n || y >= m || og[x][y] == 1) return 0;
        if(x == n - 1 && y == m - 1) return 1;
        if(arr[x][y] != 0) return arr[x][y];
        return arr[x][y] = dfs(x + 1, y) + dfs(x, y + 1);
    }
}