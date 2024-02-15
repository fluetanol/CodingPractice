# https://school.programmers.co.kr/learn/courses/30/lessons/154538
# 프로그래머스 lv2 숫자 변환하기
# 2024-02-13
# 소요시간 약 4시간

def solution(x, y, n):
    answer = -1
    if x == y: return 0
    
    
    #1 곱하기는 서로 묶여도 순서가 상관 없음 ex) n+n+n+...n = kn, x*2*2*3*3*2 = x*2^3*3^2
    #2 더하기가 한번 끼는 순간 순서가 중요해짐 ex) x*2+n*2*3+n+n+3*2 ..... 무조건 순서대로
    l = list()
    l.append(x)
    idx = 0
    nextidx = 1
    count = 1
    find = True
    
    tset = set(l)
    while find:
        checkcount = 0
        for i in range(0, nextidx):
            l.append(l[i]*2)
            l.append(l[i]*3)
            l.append(l[i]+n)
            
            if l[i] * 2 > y: checkcount +=1
            if l[i] * 3 > y: checkcount +=1
            if l[i] + n > y: checkcount +=1
                
            if (l[i] * 2 == y or l[i] * 3 == y or l[i]+n == y):
                find = False
                answer = count
                break
                
            if checkcount >= len(tset)*3:
                find = False
                break  
        
        tset = set(l) - tset   
        l = list(tset)
        nextidx = len(l)
        count += 1
        
    return answer