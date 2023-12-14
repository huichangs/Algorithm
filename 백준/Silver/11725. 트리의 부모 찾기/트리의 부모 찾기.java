import java.util.*;
import java.io.*;

public class Main {
    static ArrayList<Integer>[] conn;
    static int n;
    static int[] parent;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = Integer.parseInt(br.readLine());
        parent = new int[n + 1];
        conn= new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            conn[i] = new ArrayList<>();
        }        

        for(int i = 0; i < n - 1; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int tmp1 = Integer.parseInt(st.nextToken());
            int tmp2 = Integer.parseInt(st.nextToken());

            conn[tmp1].add(tmp2);
            conn[tmp2].add(tmp1);
        }

        dfs(1);

        for(int i = 2; i <= n; i++){
            System.out.println(parent[i]);
        }
    }

    static int dfs(int start){
        Deque<Integer> stack = new ArrayDeque<>();
        boolean[] visited = new boolean[n + 1];

        stack.push(start);
        visited[start] = true;

        while (!stack.isEmpty()) {
            int p = stack.pop();

            for(int i = 0; i < conn[p].size(); i++){
                int nextP = conn[p].get(i);
                if(!visited[nextP]){
                    parent[nextP] = p;
                    visited[nextP] = true;
                    stack.push(nextP);
                }
            }
        }
        return 0;
    }
}
