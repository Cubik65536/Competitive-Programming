import java.io.*;
import java.util.*;

public class Main {
    private static Kattio io;

    private static void solve(long[] h) {
        long feed = 0;
        long[] temp = new long[h.length];
        while (!Arrays.equals(h, temp)) {
            temp = h.clone();
            for (int i = 0; i < h.length - 1; i++) {
                long a0 = h[i];
                long a1 = h[i + 1];
                long a2 = 0;
                if (i == h.length - 2) {
                    a2 = h[0];
                } else {
                    a2 = h[i + 2];
                }
                if (a1 <= a2) {
                    continue;
                }
                long difference = a1 - a2;
                a0 -= difference;
                a1 -= difference;
                feed += difference * 2;
                if (a0 < 0 || a1 < 0) {
                    io.println("-1");
                    return;
                }
                h[i] = a0;
                h[i + 1] = a1;
            }
        }

        boolean allEquals = true;
        for (int i = 1; i < h.length; i++) {
            allEquals &= h[i] == h[0];
        }

        if (allEquals) {
            io.println(feed);
        } else {
            io.println("-1");
        }

    }

    public static void main(String[] args) {
        io = new Kattio();

        int t = io.nextInt();
        for (int i = 0; i < t; i++) {
            int n = io.nextInt();
            long[] h = new long[n];
            for (int j = 0; j < n; j++) {
                h[j] = io.nextInt();
            }

            if (n == 1) {
                io.println("0");
            } else if (n == 2) {
                if (h[0] == h[1]) {
                    io.println("0");
                } else {
                    io.println("-1");
                }
            } else {
                solve(h);
            }

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