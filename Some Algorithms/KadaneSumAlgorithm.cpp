#include<iostream>
using namespace std;
#include<vector>


int main() {
    int n; // Minimun number => 1
    cin>>n;
    vector<int> L;
    while(n--) {
        int x;
        cin>>x;
        L.push_back(x);
    }
    int maxSum = L[0], actualSum = L[0];
    for(int i = 1; i < (int)L.size(); i++) {
        actualSum += L[i];
        if (actualSum < 0) {
            actualSum = 0;
        }
        maxSum = max(maxSum, actualSum);
    }
    cout<<maxSum<<'\n';
    
    return 0;
}