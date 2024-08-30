#include <bits/stdc++.h>
using namespace std;

class Chakravyuha {
    private:
        int initialPower, levelCount, rechargeCount, skippedCount;
        vector<int> enemyPower;
        vector<vector<vector<vector<vector<int>>>>> dp;

        bool recursionCheck(int remainingPower, int a, int b, int circleIndex, bool isPrevSkipped) {
            // Crossed all circle
            if(circleIndex == levelCount)
                return true;
            
            // If Already solved this case
            if(dp[circleIndex][remainingPower][a][b][isPrevSkipped] != -1)
                return dp[circleIndex][remainingPower][a][b][isPrevSkipped];
            
            int curPowerNeed = enemyPower[circleIndex];
            bool possibility = false;

            // handle edurable enemies
            if(circleIndex == 3 || circleIndex == 7) {
                if(!isPrevSkipped)
                    curPowerNeed += enemyPower[circleIndex - 1] / 2;
            }

            // Defeat enemies
            possibility |= (curPowerNeed <= remainingPower && recursionCheck(remainingPower - curPowerNeed, a, b, circleIndex + 1, false));
            
            // Skip the circle
            possibility |= (a > 0 && recursionCheck(remainingPower, a - 1, b, circleIndex + 1, true));

            // recharge and defeat enemies
            possibility |= (b > 0 && curPowerNeed <= initialPower && recursionCheck(initialPower - curPowerNeed, a, b - 1, circleIndex + 1, false));
            
            // Store result and return
            return dp[circleIndex][remainingPower][a][b][isPrevSkipped] = possibility;
        }

    public:
        Chakravyuha(vector<int> &k, int p, int a, int b) {
            enemyPower = k;
            levelCount = k.size();
            initialPower = p;
            skippedCount = min(a, levelCount);
            rechargeCount = min(b, levelCount);
            dp = vector<vector<vector<vector<vector<int>>>>> (levelCount, vector<vector<vector<vector<int>>>> (initialPower + 1, vector<vector<vector<int>>> (skippedCount + 1, vector<vector<int>> (rechargeCount + 1, vector<int> (2, -1)))));
        }
        
        bool canAbhimanyuCrossChakravyuha() {
            return recursionCheck(initialPower, skippedCount, rechargeCount, 0, false);
        }

        
};

int main() {
    int testCount;
    cin >> testCount;

    while(testCount--) {
        int p, a, b;
        cin >> p >> a >> b;

        vector<int> k(11);
        for(int i = 0; i < 11; i++)
            cin >> k[i];
        
        Chakravyuha *chakravyuha = new Chakravyuha(k, p, a, b);
        cout << (chakravyuha->canAbhimanyuCrossChakravyuha() ? "YES" : "NO") << endl; 
    }
    return 0;
}