import java.io.*;
import java.util.*;

public class Main {
    private static Kattio io;
    private static int[] dice1 = new int[4];
    private static int[] dice2 = new int[4];
    private static int[] dice3 = new int[4];

    private static boolean winner(int[] diceA, int[] diceB) {
        int win = 0;
        int losses = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (diceA[i] > diceB[j]) {
                    win++;
                } else if (diceA[i] < diceB[j]) {
                    losses++;
                }
            }
        }
        return win > losses;
    }

    private static boolean valid() {
        boolean firstWinsSecond = winner(dice1, dice2);
        boolean firstWinsThird = winner(dice1, dice3);
        boolean secondWinsFirst = winner(dice2, dice1);
        boolean secondWinsThird = winner(dice2, dice3);
        boolean thirdWinsFirst = winner(dice3, dice1);
        boolean thirdWinsSecond = winner(dice3, dice2);

        return (firstWinsSecond != firstWinsThird)
                && (secondWinsFirst != secondWinsThird)
                && (thirdWinsFirst != thirdWinsSecond);

    }
    
    private static boolean resolve(int i) {
        if (i == dice3.length) {
            return valid();
        }

        for (int j = 1; j <= 10; j++) {
            dice3[i] = j;
            if (resolve(i + 1)) {
                return true;
            }
        }

        return false;

    }

    public static void main(String[] args) {
        Kattio io = new Kattio();

        int t = io.nextInt();
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < 4; j++) {
                dice1[j] = io.nextInt();
            }
            for (int j = 0; j < 4; j++) {
                dice2[j] = io.nextInt();
            }
            if (resolve(0)) {
                io.println("yes");
            } else {
                io.println("no");
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