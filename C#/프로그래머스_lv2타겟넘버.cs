//https://school.programmers.co.kr/learn/courses/30/lessons/43165
//프로그래머스_lv2타겟넘버
//2024.03.09
//45분
using System;
using System.Collections.Generic;

namespace CodeTest{
    internal class Node
    {
        public int Value;
        public Node? Left = null;
        public Node? Right = null;
        public Node(int value){
            Value = value;
        }
    }

    internal class Tree
    {
        public int Answer = 0;
        public int Target;
        public Node Root;
        public int[] Numbers;
        public Queue<Node> NodeQ;

        public int NodeCount = 0;

        public Tree(Node root, int[] numbers, int target)
        {
            this.Root = root;
            this.Numbers = numbers;
            this.Target = target;
            NodeQ = new Queue<Node>();
        }

        public void LevelOrder(Node node, int idx)
        {
            int tempValue = node.Value;

            if (idx >= Numbers.Length)
            {
                if (tempValue == Target) Answer += 1;
                while (NodeQ.Count != 0)
                {
                    tempValue = NodeQ.Dequeue().Value;
                    if (tempValue == Target) Answer += 1;
                }
                return;
            }
            node.Left = new Node(node.Value - Numbers[idx]);
            node.Right = new Node(node.Value + Numbers[idx]);
            NodeQ.Enqueue(node.Left);
            NodeQ.Enqueue(node.Right);

            NodeCount += 2;
            if (NodeCount == Math.Pow(2, idx + 1))
            {
                NodeCount = 0;
                idx += 1;
            }
            LevelOrder(NodeQ.Dequeue(), idx);
        }
    }


    public class 프로그래머스_lv2타겟넘버
    {
        public int solution(int[] numbers, int target)
        {
            int answer = 0;
            Node Root = new Node(0);
            Tree tree = new Tree(Root, numbers, target);
            tree.LevelOrder(tree.Root, 0);
            answer = tree.Answer;
            return answer;
        }
    }

    //어차피 숫자 순서를 바꿀일은 없고 연산자의 조합만 전부 찾아보면 되는 문제인데,
    //연산자는 운좋게 +, - 두개만 사용하면 되고
    //연산 순서는 반드시 앞에서 뒤를 향하기 때문에
    //트리에 좌노드는 마이너스한 결과, 우노드는 플러스한 결과를 계속 넣으면서
    //level order탐색하면 된다
    //애석하게도 모든 노드 다 뒤져봐야 하는 알고리즘이라 
    //생긴건 트리지만 실제 복잡도는 O(2^n)임...




    public class 프로그래머스_lv2타겟넘버2    {
        static int Dfs(int[] arr, int target, int idx, int num)
        {
            if (idx == arr.Length)
            {
                if (target == num) return 1;
                else return 0;
            }
            else
                return Dfs(arr, target, idx + 1, num + arr[idx]) + Dfs(arr, target, idx + 1, num - arr[idx]);
        }

        public int solution(int[] numbers, int target)
        {
            int answer = 0;
            return Dfs(numbers, target, 0, 0);
        }
    }
    //이게 DFS로 푼방식으로
    //속도가 압도적으로 더 빠르다
    //좀 추가로 DFS, BFS Recursion을 공부할 필요가 있을듯

}


