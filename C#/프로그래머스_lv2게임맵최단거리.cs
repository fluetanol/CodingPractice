//https://school.programmers.co.kr/learn/courses/30/lessons/1844
//프로그래머스_lv2게임맵최단거리
//2024.04.13
//하루 (시간초과...)

using System;
using System.Collections.Generic;

class 프로그래머스_lv2게임맵최단거리
{
    Queue<(int, int)> q1 = new Queue<(int, int)>();
    Queue<(int, int)> q2 = new Queue<(int, int)>();
    HashSet<(int, int)> h = new HashSet<(int, int)>();

    int Q(Queue<(int, int)> q1, Queue<(int, int)> q2, ref int[,] paths, int row, int col, int depth)
    {
        while (q1.Count != 0)
        {
            var pos = q1.Dequeue();
            int i = pos.Item1;
            int j = pos.Item2;
            paths[i, j] = depth;

            if (i == row - 1 && j == col - 1) return paths[i, j];

            if ((i + 1) < row && paths[i + 1, j] == -2 && !h.Contains((i + 1, j)))
            {
                q2.Enqueue((i + 1, j));
                h.Add((i + 1, j));
            }
            if ((i - 1) >= 0 && paths[i - 1, j] == -2 && !h.Contains((i - 1, j)))
            {
                q2.Enqueue((i - 1, j));
                h.Add((i - 1, j));
            }

            if ((j + 1) < col && paths[i, j + 1] == -2 && !h.Contains((i, j + 1)))
            {
                q2.Enqueue((i, j + 1));
                h.Add((i, j + 1));
            }
            if ((j - 1) >= 0 && paths[i, j - 1] == -2 && !h.Contains((i, j - 1)))
            {
                q2.Enqueue((i, j - 1));
                h.Add((i, j - 1));
            }
        }
        return -1;
    }


    public int solution(int[,] maps)
    {
        int answer = 0;
        int row = maps.GetLength(0);
        int col = maps.Length / row;
        int[,] paths = maps;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (maps[i, j] == 0) paths[i, j] = -1;
                else paths[i, j] = -2;
            }
        }
        h.Add((0, 0));
        q1.Enqueue((0, 0));
        int depth = 1;

        while (true)
        {
            if (depth % 2 == 1)
            {
                int k = Q(q1, q2, ref paths, row, col, depth);
                if (k != -1) return k;
                else if (q2.Count == 0) return -1;
            }
            else
            {
                int k = Q(q2, q1, ref paths, row, col, depth);
                if (k != -1) return k;
                else if (q1.Count == 0) return -1;
            }
            depth += 1;
        }
    }
}

//dfs로 풀면 코딩은 쉽지만 시간초과 나고
//bfs로 풀어야 효율성 검사에서 제대로 풀리는 짜증나는 문제.
//확실히 bfs가 구현은 큐를 활용하는 구현때문에 조금 까다로워도 
//완전탐색의 면에 있어선 좀 더 빠른 면이 있다.
