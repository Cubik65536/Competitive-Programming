import java.io.*;
import java.util.*;

public class Main {
    private static char[][] blocks = new char[4][];
    private static boolean[] used = new boolean[4];

    private static String word;

    private static boolean solve(int index) {
        for (int block = 0; block < 4; block++) {
            if (used[block]) continue;
            for (int i = 0; i < blocks[block].length; i++) {
                if (blocks[block][i] == word.charAt(index)) {
                    used[block] = true;
                    if (index == word.length() - 1) return true;
                    if (solve(index + 1)) return true;
                    used[block] = false;
                }
            }
        }
        return false;
    } 

    public static void main(String[] args) throws IOException {
        Kattio io = new Kattio();

        int n = io.nextInt();

        for (int i = 0; i < 4; i++) {
            blocks[i] = io.next().toCharArray();
        }

        for (int i = 0; i < n; i++) {
            word = io.next();
            boolean result = solve(0);
            if (result) {
                io.println("YES");
            } else {
                io.println("NO");
            }
            used = new boolean[4];
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
