import java.util.*;

public class 백준_P5_1786_찾기 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		char[] t = scan.nextLine().toCharArray();
		char[] p = scan.nextLine().toCharArray();
		
		int plen = p.length;
		
		int[] lps = new int[plen];
		lps[0] = 0;
		
		
		//i = 현재 위치, j = 비교 되는 위치
		for(int i=1, j=0; i<plen; ++i) {
			//서로 일치 하지 않으면 마지막으로 일치 했던 비교 위치로 가는 것.
			while(j > 0 && p[i] != p[j]) {
				j = lps[j-1];
			}
			if(p[i] == p[j]) {
				lps[i] = ++j;
			}
			else {
				lps[i] = 0;
			}
		}

		List<Integer> l = new ArrayList<>();
		int tlen = t.length;
		for(int i=0, j=0; i < tlen; ++i) {
			while(j > 0 && p[j] != t[i]) {
				j = lps[j-1];
			}
			
			if(p[j] == t[i]) {
				if(j == plen-1) {
					//문제 조건이 0base가 아니라 1base라서...
					l.add(i - j + 1);
					j = lps[j];
				}
				else {
					++j;
				}
			}
		}
		
		System.out.println(l.size());
		for(int i : l) {
			System.out.print(i +" ");
		}

	}

}
