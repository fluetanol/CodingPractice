//lv0 언어 적응 + 머리 풀기 용 너무 쉬운 문제는 별다른 설명없이 넘어가겠음
// 2024/03/02

using System;
using System.Collections.Generic;
public class Solution
{
    public int solution(int[] array)
    {
        bool isRepeat = false;
        Dictionary<int, int> count = new Dictionary<int, int>();
        foreach (var i in array)
        {
            if (count.ContainsKey(i)) count[i] += 1;
            else count[i] = 1;
        }

        List<int> counts = new List<int>(count.Values);
        List<int> keys = new List<int>(count.Keys);
        int max = -1;
        int idx = -1;
        for (int i = 0; i < counts.Count; i++)
        {
            if (max < counts[i])
            {
                max = counts[i];
                idx = i;
                isRepeat = false;
            }
            else if (max == counts[i]) isRepeat = true;
        }

        if (isRepeat) return -1;
        return keys[idx];
    }
}