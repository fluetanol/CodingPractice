# https://school.programmers.co.kr/learn/courses/30/lessons/258712
# 프로그래머스 lv1 가장많이받은선물
# 2024-02-05
# 소요시간 약 2시간
# 대체 왜 레벨 1인건지 모르겠는 구현 문제;;

def solution(friends, gifts):
    answer = 0
    
    #배열, 딕셔너리 초기화
    
    #주고 받은 선물의 수 정리한 배열
    l_givereceive = list(list(0 for j in range(0, len(friends))) for i in range(0,len(friends))) 
    #다음에 받을 선물의 수 정리하는 배열
    l_nextgive =list(0 for j in range(0, len(friends)))
    
    d_name = dict()     # 이름 - 인덱스 딕셔너리, d_name[이름] = 배열 인덱스
    d_give = dict()     # 준 선물 딕셔너리, d_name[이름] = 자기가 준 선물의 수
    d_receive = dict()  # 받은 선물 딕셔너리, d_receive[이름] = 자기가 받은 선물의 수
    
    
    #빠른 인덱스 접근을 위한 이름-인덱스 딕셔너리화 + 받은 선물 목록 딕셔너리 초기화
    for idx, i in enumerate(friends):
        d_name[i] = idx
        d_receive[i] = 0;
    
    #주고 받은 선물 정리 + 받은 선물 정리
    for i in gifts:
        #문자 전처리
        giftsplit = i.split(" ")
        giver = giftsplit[0]
        receiver = giftsplit[1]
        
        giveridx = d_name[giver]              #준 사람 이름에 따른 인덱스
        receiveridx = d_name[receiver]        #받은 사람 이름에 따른 인덱스
        
        l_givereceive[giveridx][receiveridx] += 1   #주고 받은 선물 수 추가 (입출력 예 표 보면 이해 할수 있음)
        d_receive[receiver] += 1                    #받은 사람의 받은 선물 수 추가
    
    #준 선물 딕셔너리화
    for i in range(0, len(l_givereceive)):
        d_give[friends[i]] = sum(l_givereceive[i])  #주고받은 선물 표에서 한 행의 합이 곧 그 사람이 준 선물의 총 수임
        
        
    #위 데이터들을 바탕으로 다음에 받아야 할 선물의 수 총 정리
    for i in range(0, len(l_givereceive)):
        for j in range(i, len(l_givereceive[i])):
            if i == j: continue
            a = l_givereceive[i][j]
            b = l_givereceive[j][i]
            
            if a > b: l_nextgive[i] += 1            #선물 더 많이 줬으면 많이 준 놈이 1개 더 받기
            elif a < b: l_nextgive[j] += 1
            else:                                   #동일한 값만큼 서로 줬으면
                pa = d_give[friends[i]] - d_receive[friends[i]]     #선물지수 계산
                pb = d_give[friends[j]] - d_receive[friends[j]]
                if pa > pb: l_nextgive[i] += 1                      #선물지수 더 높은 쪽이 1개 더 받기
                elif pa < pb: l_nextgive[j] += 1
        
    answer = max(l_nextgive)      #계산한 각 사람의 선물의 수 중 가장 높은 값 선택

    
    return answer