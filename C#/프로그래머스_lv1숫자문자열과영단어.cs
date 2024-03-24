//https://school.programmers.co.kr/learn/courses/30/lessons/81301
//프로그래머스_lv1숫자문자열과영단어
//2024.03.22
//15분


using System;
using System.Collections.Generic;
public class 프로그래머스_lv1숫자문자열과영단어 {
    public int solution(string s) {
        int answer = 0;
        
        Dictionary<string, string> dnumber = new Dictionary<string, string>();
        dnumber["zero"] = "0";
        dnumber["one"] = "1";
        dnumber["two"] = "2";
        dnumber["three"] = "3";
        dnumber["four"] = "4";
        dnumber["five"] = "5";
        dnumber["six"] = "6";
        dnumber["seven"] = "7";
        dnumber["eight"] = "8";
        dnumber["nine"] = "9";
        
        
        string n = "";
        string answern = "";
        
        foreach(var i in s){
            if(i-'0'>=0 && i-'0'<=9){
               answern +=i;
               continue; 
            } 
            else n += i;
            
            if(dnumber.ContainsKey(n)){
                 answern += dnumber[n];
                 n = "";
             }
        }
        answer = int.Parse(answern);
        
        return answer;
    }
}

//이상하게 카카오톡 문제들은 딕셔너리나 해쉬셋을 이용한 데이터 처리, 정리 문제가 개많이 나온다...
//이유가 뭘까 대체

//암튼 딕셔너리 써서 해당 문자를 숫자에 대응시키는 방식이 가장 좋다.
//안그러면 여러개의 if문으로 더러운 코드를 볼 수 있음.
