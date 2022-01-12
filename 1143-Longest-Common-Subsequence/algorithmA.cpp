class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>> L(text1.size()+1, vector<int>(text2.size()+1, 0));

        for(int i=1; i<=text1.size(); i++){
            for(int j=1; j<=text2.size(); j++){
                if(text1[i-1] == text2[j-1]){
                    L[i][j] = L[i-1][j-1] + 1;
                }
                else if(L[i-1][j] >= L[i][j-1]){
                    L[i][j] = L[i-1][j];
                    //cout<<"Here"<<endl;
                }
                else{
                    L[i][j] = L[i][j-1];
                }
            }
        }

        return L[text1.size()][text2.size()];
    }
};
