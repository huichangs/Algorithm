import java.io.*;
import java.util.*;

public class J2110 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];

        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr);

        int low = 1;
        int high = arr[arr.length - 1] - arr[0];
        int answer = 0;

        while(low <= high){
            int mid = (low + high) / 2;
            
            
            int count = 1;
            int bef_house = arr[0];

            for(int i = 1; i < arr.length; i++){
                if(arr[i] - bef_house >= mid){
                    count++;
                    bef_house = arr[i];
                }
            }

            if(count >= c){
                answer = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }

        }


        bw.write(String.valueOf(answer));
        bw.flush();
        bw.close();
    }

}
