class Solution {
public:
    string justify(vector<string> &words, int start, int end, int maxWidth, int curLen, bool withSpaces){
        string result = "";
        int numWords = end-start+1;
        int freeSpace = maxWidth-curLen;

        if(withSpaces){
            if(numWords != 1){
                int spacePerWord = freeSpace/(numWords-1); // last word will be right justified
                 int remainingSpace = freeSpace - (numWords-1)*spacePerWord;
                cout << curLen << " " << freeSpace << " " << remainingSpace;
                for(int i = start; i < end; i++){
                    result = result + words[i];
                    for(int j = 0; j < spacePerWord; j++) result += " ";
                    if(remainingSpace-- > 0) result += " ";
                }
                result = result + words[end];
            }else{
                result += words[start];
                int freeSpace = maxWidth-curLen;
                while(freeSpace-- > 0) result += " ";
            }
        }else{
            int numWords = end-start+1;
            int freeSpace = maxWidth-curLen;
            for(int i = start; i <= end; i++){
                result = result + words[i];
                if(freeSpace) {
                    result = result + " ";
                    freeSpace--;
                }
            }
            while(freeSpace-- > 0){
                result += " ";
            }
        }


        return result;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> answer;

        int len = words.size();

        if(maxWidth == 0){
            answer.push_back("");
            return answer;
        }
        int i = 0, curLen = 0, numWords = 0;
        while(i < len){
            if((curLen + words[i].size() + numWords) <= maxWidth){
                curLen += words[i].size();
                numWords += 1;
                i += 1;
            }else{
                answer.push_back(justify(words, i-numWords, i-1, maxWidth, curLen, true));
                curLen = 0;
                numWords = 0;
            }
        }
        answer.push_back(justify(words, i-numWords, i-1, maxWidth, curLen, false));
        return answer;

    }
};
