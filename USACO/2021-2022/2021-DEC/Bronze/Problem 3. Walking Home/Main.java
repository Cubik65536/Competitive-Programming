import java.io.*;
import java.util.*;

public class Main {
    private static Kattio io;

    private static void solve() {
        int n = io.nextInt();
        int k = io.nextInt();

        char[][] farm = new char[n][n];
        for (int i = 0; i < n; i++) {
            farm[i] = io.next().toCharArray();
        }

        int ways = 0;

        if (k >= 1) {
            int RD = 1;
            int DR = 1;
            for (int i = 0; i < n; i++) {
                if (RD == 1 && (farm[0][i] == 'H' || farm[i][n - 1] == 'H')) {
                    RD = 0;
                }
                if (DR == 1 &&  (farm[i][0] == 'H' || farm[n - 1][i] == 'H')) {
                    DR = 0;
                }
            }
            ways += DR;
            ways += RD;
        }

        if (k >= 2) {
            for (int j = 1; j < n - 1; j++) {
                int valid = 1;
                for (int i = 0; i < n; i++) {
                    if (farm[i][j] == 'H') {
                        valid = 0;
                    }
                    if (i < j && farm[0][i] == 'H') {
                        valid = 0;
                    } else if (i > j && farm[n - 1][i] == 'H') {
                        valid = 0;
                    }
                }
                ways += valid;
            }

            for (int i = 1; i < n - 1; i++) {
                int valid = 1;
                for (int j = 0; j < n; j++) {
                    if (farm[i][j] == 'H') {
                        valid = 0;
                    }
                    if (j < i && farm[j][0] == 'H') {
                        valid = 0;
                    } else if (j > i && farm[j][n - 1] == 'H') {
                        valid = 0;
                    }
                }
                ways += valid;
            }

        }

        if (k >= 3) {
            for (int i = 1; i < n - 1; i++) {
                for (int j = 1; j < n - 1; j++) {
                    // RDRD
                    int valid = farm[i][j] == '.' ? 1 : 0;
                    for (int a = 0; a < n; a++) {
                        if(a <= i && farm[a][j] == 'H') {
                            valid = 0;
                        }
                        if(a >= i && farm[a][n-1] == 'H') {
                            valid = 0;
                        }
                        if(a <= j && farm[0][a] == 'H') {
                            valid = 0;
                        }
                        if(a >= j && farm[i][a] == 'H') {
                            valid = 0;
                        }
                    }
                    ways += valid;

                    // DRDR
                    valid = farm[i][j] == '.' ? 1 : 0;
                    for (int a = 0; a < n; a++) {
                        if(a <= i && farm[a][0] == 'H') {
                            valid = 0;
                        }
                        if(a >= i && farm[a][j] == 'H') {
                            valid = 0;
                        }
                        if(a <= j && farm[i][a] == 'H') {
                            valid = 0;
                        }
                        if(a >= j && farm[n-1][a] == 'H') {
                            valid = 0;
                        }
                    }
                    ways += valid;

                }
            }
        }

        io.println(ways);

    }

    public static void main(String[] args) {
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
