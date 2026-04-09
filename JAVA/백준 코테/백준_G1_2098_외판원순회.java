import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class 백준_G1_2098_외판원순회{

    static int n;
    static int[][] arr;
    static int[][] dp;
    static final int MAX = 999999999;

    static int TSP(int cur, int visited){

        if(visited == (1 << n) - 1){
            return arr[cur][0] > 0 ? arr[cur][0] : MAX;
        }

        if(dp[cur][visited] != -1){
            return dp[cur][visited];
        }

        dp[cur][visited] = MAX;

        for(int next=0; next<n; ++next){
            if(arr[cur][next] != 0 && (visited & (1 << next)) == 0){
                dp[cur][visited] = Math.min(
                        dp[cur][visited],
                        arr[cur][next] + TSP(next, visited | (1 << next))
                );
            }
        }

        return dp[cur][visited];
    }


    public static void main(String[] args) throws Exception {

        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        dp = new int[n][1<<n];

        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                int val = Integer.parseInt(st.nextToken());
                arr[i][j] = val;
            }
        }

        for(int i=0; i < n; ++i){
            for(int j=0; j < (1<<n); ++j){
                dp[i][j] = -1;
            }
        }

        int tsp = TSP(0, 1);

        System.out.println(tsp);

    }
}