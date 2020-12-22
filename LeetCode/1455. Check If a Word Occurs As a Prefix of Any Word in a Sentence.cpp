class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int idx=0;
        
        int i=0;
        int j = 0;
        while(i<sentence.size()){
            if(sentence[i] == searchWord[j]){

                i++;j++;
                if(j>= searchWord.size()){
                    return idx+1;
                }
            }
            else{
                while(i<sentence.size() && sentence[i] !=' '){
                    i++;
                }
                j=0;
                i++;
                idx++;
            }
        }
        
        return -1;
    }
};