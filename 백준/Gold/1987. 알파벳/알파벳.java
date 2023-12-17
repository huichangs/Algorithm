import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 알파벳
// DFS
public class Main {
	static int r, c, maxStepCount = 1;
	static char[][] map;
	static int[][] dp;
	static int[] moveX = {0, 1, 0, -1};
	static int[] moveY = {-1, 0, 1, 0};
	static final int A = 'A';
	static boolean[] visited = new boolean[26];	// A-Z 중 방문했던 알파벳
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.valueOf(st.nextToken());
		c = Integer.valueOf(st.nextToken());
		map = new char[r][c];
		dp = new int[r][c];
		
		// 입력
		for(int i = 0; i < r; i++) {
			String line = br.readLine();
			map[i] = line.toCharArray();
		}
		
		dp[0][0] = 1;
		dfs(0, 0, 1);
		System.out.println(maxStepCount);
	}
	
	// 알파벳 사용여부 배열로 
	private static int dfs(int x, int y, int count) {
		visited[map[y][x] - A] = true;
		
		for(int i = 0; i < 4; i++) {
			int nextX = x + moveX[i];
			int nextY = y + moveY[i];
			
			// map 범위 체크
			if(nextX < 0 || nextX >= c || nextY < 0 || nextY >= r) {
				continue;
			}
			
			char alphabet = map[nextY][nextX];
			if(visited[alphabet - A]) {
				continue;
			}
			
			int result = dfs(nextX, nextY, count + 1);
			maxStepCount = Math.max(maxStepCount, result);
		}
		
		visited[map[y][x] - A] = false;
		return count;
	}
}