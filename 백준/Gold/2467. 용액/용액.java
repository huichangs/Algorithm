import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        
        int liquid[] = new int[n];
        for(int i = 0; i < n; i++){
            liquid[i] = Integer.parseInt(st.nextToken());
        }

        int left = 0;
        int right = n - 1;
        int concen = Integer.MAX_VALUE;
        int ans_left = 0;
        int ans_right = right;

        while(left != right){
            int tmp = liquid[left] + liquid[right];
            if(Math.abs(tmp) < concen){
                concen = Math.abs(tmp);
                ans_left = left;
                ans_right = right;
            }
            
            if(tmp < 0){
                left++;
            }else{
                right--;
            }
        }

        System.out.print(liquid[ans_left] + " " + liquid[ans_right]);


    }
}
