// LeetCode: 134. Gas Station
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total_gas  = 0;
    int total_cost = 0;
    int curr_tank  = 0;
    int start      = 0;

    for (int i = 0; i < gas.size(); ++i) {
        total_gas  += gas[i];
        total_cost += cost[i];
        curr_tank  += gas[i] - cost[i];

        if (curr_tank < 0) {
            start = i + 1;
            curr_tank = 0;
        }
    }
    
    if (total_gas < total_cost) return -1;

    return start;
}

int main()
{
    vector<int> gas1  = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    assert(canCompleteCircuit(gas1, cost1) == 3);

    vector<int> gas2  = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    assert(canCompleteCircuit(gas2, cost2) == -1);

    return 0;
}