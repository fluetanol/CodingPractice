//https://school.programmers.co.kr/learn/courses/30/lessons/42839
//프로그래머스_lv2소수찾기
//2024.03.07
//1200


using System;
using System.Collections.Generic;

public class 프로그래머스_lv2소수찾기
{
    public int solution(string numbers)
    {
        int answer = 0;
        int[] count = new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

        List<int> l_numbers = new List<int>();
        Dictionary<int, int> d_numbers = new Dictionary<int, int>();

        foreach (var i in numbers)
        {
            int num = int.Parse(i.ToString());
            l_numbers.Add(num);
            if (d_numbers.ContainsKey(num)) d_numbers[num] += 1;
            else d_numbers[num] = 1;
        }

        l_numbers.Sort();
        int max = 0;
        for (int i = 0; i < l_numbers.Count; i++) max += l_numbers[i] * (int)Math.Pow(10, i);

        HashSet<int> s_nonprime = new HashSet<int>();
        for (int i = 2; i <= max; i++)
        {
            if (!s_nonprime.Contains(i))
            {
                string si = i.ToString();
                bool check = true;
                foreach (var k in si)
                {
                    int ik = int.Parse(k.ToString());
                    if (!d_numbers.ContainsKey(ik))
                    {
                        check = false;
                        break;
                    }
                    else
                    {
                        if (d_numbers[ik] <= count[ik])
                        {
                            check = false;
                            break;
                        }
                        else count[ik]++;
                    }
                }
                if (check) answer += 1;
                count = new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
                int j = 2;
                while (i * j <= max)
                {
                    s_nonprime.Add(i * j);
                    j++;
                }
            }
        }
        return answer;
    }
}

//어차피 완전탐색 문제여서 시간 오래걸리는게 당연한거고,
//이에 따라 공간복잡도랑 시간복잡도를 적당히 타협보면서 풀어야 한다.
// 나는 이렇게 풀었다

// 1. 일단 string으로 만들 수 있는 정수 최댓값을 구한다
// 2. string에 있는 각 숫자들의 갯수를 기록해둔다 (위에선 딕셔너리를 이용함)
// 3. 그 정수 최댓값까지의 소수들을 에라토스테네스의 체를 이용해서 모두 구한다
// 4. 그 소수들 중 string에서 주어진 숫자의 조합으로 충분히 만들 수 있는 소수들만 선별한다
// 5. 선별한 소수들의 갯수를 count해준다.



//근데 아래 방식은 이보다 훨씬 더 빠른 방법이였다.

public class 프로그래머스_lv2소수찾기2
{

    List<string> lstNums = new List<string>();
    List<long> lstNums2 = new List<long>();

    public int solution(string numbers)
    {
        int answer = 0;
        Perm(numbers.ToArray(), 0);
        lstNums = lstNums.Distinct().ToList();
        for (int i = 0; i < numbers.Length; i++)
        {
            foreach (long lNum in lstNums.Select(x => long.Parse(x.Substring(i))))
            {
                lstNums2.Add(lNum);
            }
        }
        lstNums2 = lstNums2.Distinct().ToList();
        foreach (long lNum in lstNums2)
        {
            //Console.WriteLine(lNum.ToString());
            if (IsPrime(lNum)) answer++;
        }
        return answer;
    }

    public bool IsPrime(long candidate) // 소수 판정
    {
        if ((candidate & 1) == 0)
        {
            if (candidate == 2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        for (int i = 3; (i * i) <= candidate; i += 2)
        {
            if ((candidate % i) == 0)
            {
                return false;
            }
        }
        return candidate != 1;
    }

    public void Perm(char[] a, int k)   // 순열하기
    {
        if (k == a.Length - 1)//순열을 출력
        {
            lstNums.Add(new string(a));
        }
        else
        {
            for (int i = k; i < a.Length; i++)
            {
                //a[k]와 a[i]를 교환
                char temp = a[k];
                a[k] = a[i];
                a[i] = temp;

                Perm(a, k + 1); //a[k+1],…,a[n-1]에 대한 모든 순열
                //원래 상태로 되돌리기 위해 a[k]와 a[i]를 다시 교환
                temp = a[k];
                a[k] = a[i];
                a[i] = temp;
            }
        }
    }
}


//쉽게 말하면 그냥 string의 순열들을 모두 구하고 구한 값들에 대해 소수판정을 각각 하는 방식이였다.
//이 방식이 이 문제에서 효율이 좋았던 이유는 다음과 같다.

//1. 순열할 갯수가 생각보다 많지 않음 (nPr = n! / (n-r)!)인데 문제 조건에 따라 n이 최대 7개밖에 안되서 생각보다 많지 않음.
//적어도 내가 푼 방식인 최댓값까지 for문을 돌리는 횟수보다 훨씬 적은 수의 조합이 나올 것이다.

//2. 소수 각각에 대한 판정은 O(sqrt(n))의 아주 좋은 시간복잡도를 갖는다.

//3. 따라서 전체 복잡도가 생각보다 크지 않다.

//(근데 소신발언하는데 n이 조금이라도 커지면 팩토리얼 특성때문에 비슷해지거나 내쪽이 더 효율 좋아지는 특이점이 올듯?)

