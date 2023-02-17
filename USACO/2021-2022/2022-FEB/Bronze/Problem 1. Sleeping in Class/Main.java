import java.io.*;
import java.util.*;

public class Main {
    private static Kattio io;

    private static void solve() {
        int n = io.nextInt();
        int[] a = new int[n];
        int sumA = 0;
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
            sumA += a[i];
        }
        for (int r = n; r >= 1; r--) {
            if (sumA % r == 0) {
                int targetSum = sumA / r;
                int currentSum = 0;
                boolean found = true;
                for (int i = 0; i < n; i++) {
                    currentSum += a[i];
                    if (currentSum > targetSum) {
                        found = false;
                        break;
                    }
                    if (currentSum == targetSum) {
                        currentSum = 0;
                    }
                }
                if (found) {
                    io.println(n - r);
                    return;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        io = new Kattio();

        int t = io.nextInt();
        for (int i = 0; i < t; i++) {
            solve();
        }

        io.close();
    }
}

class Kattio extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;

    // standard input
    public Kattio() {
        this(System.in, System.out);
    }

    public Kattio(InputStream i, OutputStream o) {
        super(o);
        r = new BufferedReader(new InputStreamReader(i));
    }

    // USACO-style file input
    public Kattio(String problemName) throws IOException {
        super(new FileWriter(problemName + ".out"));
        r = new BufferedReader(new FileReader(problemName + ".in"));
    }

    // read next line
    public String readLine() {
        try {
            return r.readLine();
        } catch (IOException e) {
        }
        return null;
    }

    // returns null if no more input
    public String next() {
        try {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(r.readLine());
            return st.nextToken();
        } catch (Exception e) {
        }
        return null;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}
