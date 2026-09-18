#include<iostream>
using namespace std;
#include<unordered_map>


int main() {
    string s;
    cin>>s;
    unordered_map<char, int> positions;

    int ans = 0, actualSum = 0;

    for(int i = 0; i < (int)s.size(); i++) {
        if(!positions.count(s[i])) {
            actualSum ++;
        } else {
            actualSum = min(actualSum + 1,i - positions[s[i]]);
        }
        positions[s[i]] = i;
        ans = max(ans, actualSum);
    }

    cout<<ans<<'\n';

    return 0;
}

