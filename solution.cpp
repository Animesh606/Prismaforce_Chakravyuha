#include <bits/stdc++.h>
using namespace std;

class Chakravyuha {
    private:
        int initialPower, levelCount, rechargeCount, skippedCount;
        vector<int> enemyPower;

        bool recursionCheck(int remainingPower, int a, int b, int circleIndex, bool isPrevSkipped) {
            // Crossed all circle
            if(circleIndex == levelCount)
                return true;
            
            int curPowerNeed = enemyPower[circleIndex];
            // handle edurable enemies
            if(circleIndex == 3 || circleIndex == 7) {
                if(!isPrevSkipped)
                    curPowerNeed += enemyPower[circleIndex - 1] / 2;
            }

            // Defeat enemies
            if(curPowerNeed <= remainingPower && recursionCheck(remainingPower - curPowerNeed, a, b, circleIndex + 1, false))
                return true;
            
            // Skip the circle
            else if(a > 0 && recursionCheck(remainingPower, a - 1, b, circleIndex + 1, true))
                return true;

            // recharge and defeat enemies
            else if(b > 0 && curPowerNeed <= initialPower && recursionCheck(initialPower - curPowerNeed, a, b - 1, circleIndex + 1, false))
                return true;
            
            // Lost battle
            return false;
        }

    public:
        Chakravyuha(vector<int> &k, int p, int a, int b) {
            enemyPower = k;
            initialPower = p;
            skippedCount = a;
            rechargeCount = b;
            levelCount = k.size();

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