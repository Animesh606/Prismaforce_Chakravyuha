# Abhimanyu in the Chakravyuha Problem
## Problem Statement
Abhimanyu, a warrior from the epic Mahabharata, is trapped in a Chakravyuha—a complex military formation consisting of 11 concentric circles. His goal is to cross all 11 circles to reach the Pandavas' army safely.

### Given:
 - **p :** The initial power of Abhimanyu.
 - **a :** The number of times Abhimanyu can skip fighting an enemy.
 - **b :** The number of times Abhimanyu can recharge his power.
 - **k :** An array of integers k1, k2, ..., k11, where each integer represents the power of the enemy guarding each circle. There are 11 enemies in total.

### Rules:
1. Abhimanyu starts at the innermost circle with power `p`.
2. Battling an enemy reduces Abhimanyu's power by the power of that enemy.

3. If Abhimanyu's power is less than the enemy's power when entering a circle, he will lose the battle unless he uses a skip or recharge.

4. Abhimanyu can skip fighting an enemy `a` times without losing power.

5. Abhimanyu can recharge himself `b` times, fully restoring his power to the initial value `p`.

6. The enemies at the `3rd` and `7th` circles can regenerate once with half their initial power and attack Abhimanyu from behind if he is battling in the next iterative circle.

### Objective:
Write an algorithm to determine if Abhimanyu can successfully cross all 11 circles and reach the Pandavas' army.

## Solution Approach

### Strategy:

The problem of determining whether Abhimanyu can successfully cross all 11 circles of the Chakravyuha has been tackled using a recursive approach. The solution involves evaluating each possible move at every level of the Chakravyuha, considering the available resources (skips and recharges) and the power of enemies in each circle.

### Detailed Explanation

#### Class Structure

The solution is encapsulated in a class Chakravyuha, which maintains the following attributes:

- `initialPower`: The initial power level of Abhimanyu.
- `enemyPower`: A vector storing the power of enemies in each of the 11 circles.
- `levelCount`: The total number of levels (circles) Abhimanyu needs to cross (11 in this case).
- `rechargeCount`: The number of times Abhimanyu can fully recharge his power.
- `skippedCount`: The number of times Abhimanyu can skip a circle without fighting.

#### Recursive Function recursionCheck
The core of the solution is a recursive function recursionCheck, which attempts to determine whether Abhimanyu can successfully cross the current circle given his remaining power and the number of skips and recharges left.

The function operates as follows:

- **Base Case:** If circleIndex is equal to levelCount, it means Abhimanyu has successfully crossed all circles, so the function returns true.

- **Enemy Power Calculation:** The current power required to defeat the enemy in the current circle is stored in curPowerNeed.

- **Endured level Handling:** If the current circle is the *3rd* or *7th*, and the previous circle was *not skipped*, the power required to defeat the current enemy is increased by half the power of the previous enemy. This simulates the regenerating enemies' attack from behind.

- **Defeat Enemy:** If Abhimanyu has enough power to defeat the enemy, the function checks whether he can move on to the next circle with reduced power. If this recursive call returns true, it means Abhimanyu can cross all circles from this point.

- **Skip Circle:** If Abhimanyu doesn't have enough power, the function checks if a skip is available (a > 0). If so, the function attempts to skip the current circle and move on to the next one.

- **Recharge Power:** If skipping isn't an option or isn't sufficient, the function checks if a recharge is available (b > 0). If Abhimanyu recharges, he regains his initial power and attempts to defeat the enemy with the newly recharged power.

- **Lost Battle:** If none of the above options are feasible, the function returns false, indicating that Abhimanyu cannot cross the Chakravyuha with the given resources.

#### Public Function canAbhimanyuCrossChakravyuha
This function initiates the recursive check starting from the first circle (circleIndex = 0) and returns whether Abhimanyu can cross all 11 circles.


### Time Complexity
- **Worst-Case Time Complexity:** The recursive approach could potentially explore all possible combinations of skips, recharges, and battles across the 11 circles. Since each circle has 3 potential actions (fight, skip, recharge), the time complexity in the worst case could be approximated as `O(3^n)`, where n is the number of circles (in this case, n = 11), making it `O(3^11)`. However, many branches may terminate early due to infeasibility, reducing the actual complexity.

### Space Complexity
- **Space Complexity:** The space complexity is primarily determined by the depth of the recursion stack, which is at most `O(n)` where n is the number of circles (n = 11), leading to `O(11)` or `O(1)` in constant space, as no additional space is required except for the recursion stack.



## Sample Test Cases
To ensure the correctness of the solution, a set of sample test cases has been provided in `testcases.txt`. Below is the description and expected output for each test case:

### Test Case 1
```
p: 50
a: 2
b: 1
k: 46 5 4 10 9 8 6 1 40 30 20

Expected Output: YES
```
#### Explanation:

- **Circle 1 (Enemy Power = 46) :** Abhimanyu can skip this circle (1 skip used, 1 remaining).

- **Circle 2-8 :** Abhimanyu defeats this enemy, reducing his power to 2.

- **Circle 9 (Enemy Power = 40) :** bhimanyu can skip this circle (1 skip used, 0 remaining).
Abhimanyu recharges (1 recharge used, 0 remaining), restoring his power to 50, and defeats the enemy.

- **Circle 10 (Enemy Power = 30) :** Abhimanyu recharges (1 recharge used, 0 remaining), restoring his power to 50, and defeats the enemy.

- **Circle 11 (Enemy Power = 20) :** With enough remaining power, Abhimanyu defeats the final enemy.

Therefore, Abhimanyu successfully crosses all circles, resulting in the output `YES`.

### Test Case 2
```
p: 150
a: 2
b: 2
k: 110 100 90 80 70 60 50 40 30 20 10

Expected Output: NO
```

#### Explanation:

There is no way to cross the Chakravyuha with this `initialPower`, `skipCount` and `rechargeCount`.