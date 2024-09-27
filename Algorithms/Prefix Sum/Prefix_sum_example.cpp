#include <iostream>
#include <vector>
using namespace std;
 
vector<int> PrefixSum(const vector<int>& arr) {
    if (arr.empty()) return {};
    vector<int> prefixSum(arr.size());
    prefixSum[0] = arr[0];
 
    for (int i = 1; i < arr.size(); i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];

    return prefixSum;
}
 
int main()
{
    vector<int> arr = { 1, 2, 3, 4 };
    vector<int> prefixSum = PrefixSum(arr);

    for (int i = 0; i < prefixSum.size(); i++)
        cout << prefixSum[i] << " ";
    cout << endl;
    
    return 0;
}