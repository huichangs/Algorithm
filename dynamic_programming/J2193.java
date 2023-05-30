import java.io.*;
import java.util.*;

public class J2193 {

    static long[] zero = new long[91];
    static long[] one = new long[91];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(br.readLine());
        zero[0] = 0;
        one[0] = 1;

        for(int i = 1; i < n; i++){
            zero[i] = zero[i - 1] + one[i - 1];
            one[i] = zero[i - 1];
        }

        bw.write(String.valueOf(zero[n - 1] + one[n - 1]));
        bw.close();

    }

}
