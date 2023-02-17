import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Kattio io = new Kattio();

        int n = io.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = io.nextInt();
        }
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = io.nextInt();
        }
        ArrayList<Integer> difference = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            difference.add(p[i] - t[i]);
        }

        int commands = 0;
        while (!difference.isEmpty()) {
            if (difference.get(difference.size() - 1) == 0) {
                difference.remove(difference.size() - 1);
                continue;
            }

            boolean positive = difference.get(difference.size() - 1) > 0;
            int amountChanged = 1;
            int delta = Math.abs(difference.get(difference.size() - 1));
            while (amountChanged < difference.size()) {
                if (difference.get(difference.size() - amountChanged - 1) == 0) {
                    break;
                }
                if ((difference.get(difference.size() - amountChanged - 1) > 0) != positive) {
                    break;
                }
                delta = Math.min(delta, Math.abs(difference.get(difference.size() - amountChanged - 1)));
                amountChanged++;
            }
            commands += delta;
            for (int i = 0; i < amountChanged; i++) {
                if (difference.get(difference.size() - 1 - i) > 0) {
                    difference.set(difference.size() - 1 - i, difference.get(difference.size() - 1 - i) - delta);
                } else {
                    difference.set(difference.size() - 1 - i, difference.get(difference.size() - 1 - i) + delta);
                }
            }
        }

        io.println(commands);

        io.close();
    }
}

class Kattio extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;
    // standard input
    public Kattio() { this(System.in,System.out); }
    public Kattio(InputStream i, OutputStream o) {
        super(o);
        r = new BufferedReader(new InputStreamReader(i));
    }
    // USACO-style file input
    public Kattio(String problemName) throws IOException {
        super(new FileWriter(problemName+".out"));
        r = new BufferedReader(new FileReader(problemName+".in"));
    }
    // read next line
    public String readLine() {
        try {
            return r.readLine();
        } catch (IOException e) {}
        return null;
    }
    // returns null if no more input
    public String next() {
        try {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(r.readLine());
            return st.nextToken();
        } catch (Exception e) {}
        return null;
    }
    public int nextInt() { return Integer.parseInt(next()); }
    public double nextDouble() { return Double.parseDouble(next()); }
    public long nextLong() { return Long.parseLong(next()); }
}
