import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Kattio io = new Kattio();

        char[][] answer = new char[3][3];
        int[] answerCount = new int[26];
        for (int i = 0; i < answer.length; i++) {
            answer[i] = io.next().toCharArray();
            for (int j = 0; j < answer[i].length; j++) {
                answerCount[answer[i][j] - 'A']++;
            }
        }

        char[][] guess = new char[3][3];
        int[] guessCount = new int[26];
        for (int i = 0; i < guess.length; i++) {
            guess[i] = io.next().toCharArray();
            for (int j = 0; j < guess[i].length; j++) {
                guessCount[guess[i][j] - 'A']++;
            }
        }

        int green = 0;
        for (int i = 0; i < answer.length; i++) {
            for (int j = 0; j < answer[i].length; j++) {
                if (answer[i][j] == guess[i][j]) {
                    green++;
                    answerCount[answer[i][j] - 'A']--;
                    guessCount[guess[i][j] - 'A']--;
                }
            }
        }



        int yellow = 0;
        for (int i = 0; i < answerCount.length; i++) {
            if (answerCount[i] > 0 && guessCount[i] > 0) {
                if (answerCount[i] < guessCount[i]) {
                    yellow += answerCount[i];
                } else {
                    yellow += guessCount[i];
                }
            }
        }

        io.println(green);
        io.println(yellow);

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