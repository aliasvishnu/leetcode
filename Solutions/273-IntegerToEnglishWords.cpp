class Solution {
public:

    string helper(int num){
        vector<string> lt20 = {" One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen", " Twenty"};
        vector<string> gt20 = {" Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        vector<string> gt100 = {" Hundred", " Thousand", " Million", " Billion"};
        string answer = "";

         if(num%100 <= 20){
            if(num%100 != 0){
                answer += lt20[num%100-1];
            }
            num /= 100;
        }else{
            if(num %10 != 0) answer = lt20[num%10-1] + answer;
            num /= 10;
            answer = gt20[num%10-1] + answer;
            num /= 10;
        }

        // 3rd digit
        if(num % 10 != 0){
            answer = lt20[num%10-1] + " Hundred" + answer;
        }

        return answer;
    }

    string numberToWords(int num) {


        string answer = "";

        if(num == 0) return "Zero";
        // first 2 digits
        answer = helper(num);
        num /= 1000;
        if(num%1000 != 0) answer = helper(num) + " Thousand" + answer;
        num /= 1000;
        if(num%1000 != 0) answer = helper(num) + " Million" + answer;
        num /= 1000;
        if(num%1000 != 0) answer = helper(num) + " Billion" + answer;

        return answer.substr(1, answer.size()-1);
    }
};
