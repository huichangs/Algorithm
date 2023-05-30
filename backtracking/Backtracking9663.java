import java.util.*;
import java.io.*;
import java.lang.Math;

public class Backtracking9663 {
    static int count;
    static int n;
    static int[] queen;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        queen = new int[n];

        chess(0);

        System.out.println(count);
    }

    public static void chess(int depth){
        if(depth == n){
            count++;
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(check(depth, i)){
                queen[depth] = i;
                chess(depth + 1);
            }
        }
    }

    public static boolean check(int depth, int location){

        for(int i = 0; i < depth; i++){
            if(queen[i] == location || Math.abs(depth - i) == Math.abs(location - queen[i])){
               return false;
            }
        }

        return true;
    }
}
