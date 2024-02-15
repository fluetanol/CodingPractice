# https://school.programmers.co.kr/learn/courses/30/lessons/49993
# 프로그래머스 lv2 스킬트리
# 2024 - 02 - 15
# 소요시간 20분

def solution(skill, skill_trees):
    answer = 0
    
    #각 스킬을 올려야 하는 순서를 dictionary형태로 일단 저장
    skillindexdic = dict();
    for i,j in enumerate(skill):
        skillindexdic[j] = i

    #skillindex 0번부터 시작
    for skill_tree in skill_trees:
        skillindex = 0
        answer+=1
        
        for s in skill_tree:
            #스킬트리와 관련 없는 스킬은 그냥 무시하고 다음 번지로 넘어가게 하려고 딕셔너리 쓴 것
            if skillindexdic.get(s) == None: continue
            if skillindexdic[s] != skillindex:
                answer-=1
                break
            else:
                skillindex+=1
    
    return answer
