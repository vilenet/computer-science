#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // Метод для поиска комбинаций с использованием backtracking
    void backtrack(int start, int n, int k, vector<int>& combination, vector<vector<int>>& result) {
        // Если комбинация собрана, добавляем её в результат
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }

        // Перебираем числа от текущего `start` до `n`
        for (int i = start; i <= n; ++i) {
            // Добавляем число в текущую комбинацию
            combination.push_back(i);

            // Рекурсивно продолжаем собирать комбинацию
            backtrack(i + 1, n, k, combination, result);

            // Возврат к предыдущему состоянию (убираем последнее число)
            combination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;

        // Запуск backtracking с начальным индексом 1
        backtrack(1, n, k, combination, result);

        return result;
    }
};


int main() 
{
    Solution solution;
    int n = 4, k = 2;

    vector<vector<int>> combinations = solution.combine(n, k);

    for (const auto& comb : combinations) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
