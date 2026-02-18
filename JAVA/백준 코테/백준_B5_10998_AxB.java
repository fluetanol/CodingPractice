import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class 백준_B5_10998_AxB {
     public static void main(String[] args) {
        //입력 방법 1
        Scanner scan = new Scanner(System.in);

        int a = scan.nextInt();
        int b = scan.nextInt();

        System.out.println(a * b);


        //입력 방법 2
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        //try catch가 싫다면 main 메소드에 throws Exception을 붙여도 된다.
        try {
            String line = bf.readLine();
            StringTokenizer st = new StringTokenizer(line);
            int val = 1;
            while(st.hasMoreTokens()){
                int token = Integer.parseInt(st.nextToken());
                val*=token;
            }

            System.out.println(val);

        }catch(Exception e){
            System.err.println(e.getMessage());
            System.err.println(e.getMessage());
        }



    }



}
