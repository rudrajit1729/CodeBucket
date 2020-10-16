import java.util.Scanner;

// You can find the problem statement at https://codeforces.com/contest/1430/problem/D

public class string_deletion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            double n = sc.nextDouble();
            sc.nextLine();
            String s = sc.nextLine();
            char[] ch = s.toCharArray();
            int cnt = 1, samecnt = 0;
            for (int j = 0; j < n-1; j++) {
                if (ch[j] != ch[j+1])
                    cnt++;
                else {
                    samecnt++;
                    samecnt = Math.min(samecnt, cnt);
                }
            }
            System.out.println(samecnt + (cnt-samecnt+1)/2);
        }
        sc.close();
    }
}