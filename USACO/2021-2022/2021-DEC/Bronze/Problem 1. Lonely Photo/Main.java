import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        long n = Integer.parseInt(in.readLine());
        String line = in.readLine();

        long lonely = 0;
        for (int i = 0; i < n; i++) {
            long gCount = 0;
            long hCount = 0;
            for (int j = i; j < n; j++) {
                if (line.charAt(j) == 'G') {
                    gCount++;
                } else {
                    hCount++;
                }
                if (gCount > 1 && hCount > 1) {
                    break;
                }
                if ((j - i > 1) && (gCount == 1 || hCount == 1)) {
                    lonely++;
                }
            }
        }

        out.println(lonely);
        out.close();
    }
}
