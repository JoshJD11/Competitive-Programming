#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n; // minimun => 1
    vector<int> L;
    while(n--) {
        int x;
        cin >> x;
        L.push_back(x);
    }
    
    int maxProd = L[0];
    int actualMax = L[0];
    int actualMin = L[0];
    
    for(int i = 1; i < (int)L.size(); i++) {
        int candidate1 = actualMax * L[i];
        int candidate2 = actualMin * L[i];
        
        actualMax = max(L[i], max(candidate1, candidate2));
        actualMin = min(L[i], min(candidate1, candidate2));
        
        maxProd = max(maxProd, actualMax);
    }
    
    cout << maxProd << '\n';
    
    return 0;
}