class Solution {
public:

    string add(string num1, string num2){
        string answer = "";
        int i = num1.size()-1;
        int j = num2.size()-1, carry = 0;

        while(i >= 0 && j >= 0){
            int sum = (num1[i]-48 + num2[j]-48 + carry)%10;
            carry = (num1[i]-48 + num2[j]-48 + carry)/10;
            answer = to_string(sum) + answer;
            i--; j--;
            // cout << "Here1";
        }

        while(i >= 0){
            int sum = (num1[i]-48 + carry)%10;
            carry = (num1[i]-48 + carry)/10;
            answer = to_string(sum) + answer;
            i--;
            // cout << "Here2";
        }

        while(j >= 0){
            int sum = (num2[j]-48 + carry)%10;
            carry = (num2[j]-48 + carry)/10;
            answer = to_string(sum) + answer;
            j--;
            // cout << "Here3";
        }

        while(carry > 0){
            int sum = (carry)%10;
            carry = (carry)/10;
            answer = to_string(sum) + answer;
            // cout << "Here4";
        }

        return answer;
    }


    string multiply(string num1, int d){

        string answer = "";
        int len = num1.size(), carry = 0;

        for(int i = len-1; i >= 0; i--){
            int sum = ((num1[i]-48)*d+carry)%10;
            carry = ((num1[i]-48)*d+carry)/10;
            answer = to_string(sum) + answer;
            // cout << "Here";
        }

        if(carry > 0) answer = to_string(carry) + answer;
        return answer;
    }

    string multiply(string num1, string num2) {
        string answer = "";
        int len = num2.size();
        for(int i = len-1; i >= 0; i--){
            string mult =  multiply(num1, num2[i]-48);
            for(int j = len-1; j > i ; j--) mult += "0";
            answer = add(answer, mult);
        }

        int i = 0;
        while(i < answer.size()-1 && answer[i] == '0') i++;
        return answer.substr(i, answer.size()-i+1);
    }
};
