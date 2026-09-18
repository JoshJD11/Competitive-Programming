#include<iostream>
using namespace std;
#include<vector>

int ManacherAlgorithm(string& s) {
    vector<int>P((int)s.size());
    int center = 0, limit = 0, ans = 0;

    for(int i = 1; i < (int)s.size() - 1; i++) {
        if (i < limit) {
            int simetric = center * 2 - i;
            P[i] = min(limit - i, P[simetric]);
        }

        int gap = P[i] + 1;
        while (s[i - gap] == s[i + gap]) {
            P[i] ++;
            gap ++;
        }
        if (i + P[i] > limit) {
            limit = i + P[i];
            center = i;
        }

        ans = max(ans, P[i]);
    }
    return ans;
}


int main() {

    string word;
    cin>>word;

    string newWord = "@";
    for(int i = 0; i < (int)word.size(); i++) {
        newWord += "$";
        newWord += word[i];
    }
    newWord += "$#";

    cout<<ManacherAlgorithm(newWord)<<'\n';

    return 0;
}

// g++ ManacherAlgorithm.cpp -o programa
// ./programa