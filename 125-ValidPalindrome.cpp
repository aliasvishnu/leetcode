// Two pointers, O(n) time, O(1) space
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int i = 0, j = len-1;
        cout << isalnum(',') << isalnum('.') << endl;
        while(i < j){
            while(!isalnum(s[i])) i++;
            while(!isalnum(s[j])) j--;


            if(i < j && tolower(s[i]) != tolower(s[j])){
                cout << s[i] << " did not match with " << s[j] << endl;
                return false;
            }

            i++; j--;
        }


        return true;
    }
};
