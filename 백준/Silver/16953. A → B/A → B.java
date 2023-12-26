import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int result = -1;

        if (a == b) {
            System.out.println(1);
            return;
        }

        Deque<Pair> q = new ArrayDeque<>();
        q.add(new Pair(1, a));

        while (!q.isEmpty()) {
            Pair tmp = q.poll();

            long calc1Result = calc1(tmp.num);
            long calc2Result = calc2(tmp.num);
            if (calc1Result == b || calc2Result == b) {
                result = tmp.depth + 1;
                break;
            }

            if (calc1Result < b) {
                q.add(new Pair(tmp.depth + 1, calc1Result));
            }
            if (calc2Result < b) {
                q.add(new Pair(tmp.depth + 1, calc2Result));
            }
        }

        System.out.println(result);
    }

    static long calc1(long a) {
        return (a * 2);
    }

    static long calc2(long a) {
        return ((a * 10) + 1);
    }

    static class Pair {
        int depth;
        long num;

        Pair(int depth, long num) {
            this.depth = depth;
            this.num = num;
        }
    }
}
