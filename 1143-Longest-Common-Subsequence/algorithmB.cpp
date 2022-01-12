class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        vector<int> L1(text2.size()+1, 0);
        vector<int> L2(text2.size()+1, 0);

        for(int i=1; i<=text1.size(); i++){
            L1 = L2;

            for(int j=1; j<=text2.size(); j++){
                if(text1[i-1] == text2[j-1]){
                    L2[j] = L1[j-1] + 1;
                }
                else{
                    L2[j] = (L1[j]>=L2[j-1]) ? L1[j]:L2[j-1];
                }
            }
        }

        return L2[text2.size()];
    }
};
