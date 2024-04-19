# https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
# 삼성SW아카데미_d2_백만장자프로젝트
# 2024-04-19
# 1600

q1 = list()
q2 = list()
T = int(input())
s = set()
global answer
answer = 0

def BFS(n, l, idx):
    global answer
    if idx%2 == 1:
        while len(q1) != 0 :
            popq = q1.pop(0)
            m= popq[0]
            b = popq[1]
            if answer< m: answer = m
            if m in s: continue
            s.add(m)
            if idx != n: 
                q2.append([m, b])
                q2.append([m +(l[idx] * b), 0])
                q2.append([m - l[idx] , b+1])
            
    elif  idx%2 == 0:
        while len(q2)!=0 :
            popq = q2.pop(0)
            m = popq[0]
            b = popq[1] 
            
            if answer<m: answer = m
            if m in s: continue
            s.add(m)
            if idx != n: 
                q1.append([m, b])
                q1.append([m +(l[idx] * b), 0])
                q1.append([m - l[idx] , b+1])     
     
    if idx !=n: BFS(n, l ,idx+1)
    
for test_case in range(1, T + 1):
    n = int(input())
    l = list(map(int, input().split()))
    q1.append([0, 0])
    q1.append([-l[0], 1]) 
    BFS(n, l, 1)	   
    print("#{} {}".format(test_case, answer))
    answer =0
    s = set()