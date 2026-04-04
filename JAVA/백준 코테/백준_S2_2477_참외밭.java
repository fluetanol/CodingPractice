import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Pair{
    int a, b;
    public Pair(int a, int b){
        this.a = a;
        this.b = b;
    }
}


public class 백준_S2_2477_참외밭{

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int k = Integer.parseInt(br.readLine());

        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for(int i=0; i<5; ++i){
            arr.add(new ArrayList<>());
        }

        Queue<Pair> q = new ArrayDeque<>();
        int nsMax = -1;
        int weMax = -1;
        int nsMaxDir = 3;
        int entire = 0;
        for(int i=0; i<6; ++i){
            StringTokenizer st =  new StringTokenizer(br.readLine());
            int dir = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());


            if(nsMax < dist && dir >= 3){
                nsMax = dist;
                nsMaxDir = dir;
            }
            else if(weMax < dist && dir < 3){
                weMax = dist;
            }

            q.offer(new Pair(dir, dist));
        }

        entire = weMax * nsMax;



        //재정렬
        while(!q.isEmpty() && q.peek().a != nsMaxDir){
            q.offer(q.poll());
        }


        Pair prev_prev = null;
        Pair prev = null;

        while(!q.isEmpty()){
            if(prev_prev == null){
                prev_prev = q.poll();
            }
            else if(prev == null){
                prev = q.poll();
            }
            else{
                if(prev_prev.a == q.peek().a){
                    break;
                }
                prev_prev = prev;
                prev = q.poll();
            }
        }

        int tiny = 0;
        if(q.peek() != null)
            tiny= q.peek().b * prev.b;

        System.out.println((entire - tiny) * k);



    }
}