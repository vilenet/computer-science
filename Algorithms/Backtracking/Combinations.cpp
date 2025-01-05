// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
#include <iostream>
#include <vector>
using namespace std;


// Метод для поиска комбинаций с использованием backtracking
void backtrack(int start, int n, int k, vector<int>& combination, vector<vector<int>>& result) {
    
    if (combination.size() == k) {                   // Если комбинация собрана, добавляем её в результат
        result.push_back(combination);
        return;
    }
         
    for (int i = start; i <= n; ++i) {               // Перебираем числа от текущего `start` до `n`
        combination.push_back(i);                    // Добавляем число в текущую комбинацию
        backtrack(i + 1, n, k, combination, result); // Рекурсивно продолжаем собирать комбинацию
        combination.pop_back();                      // Возврат к предыдущему состоянию (убираем последнее число)
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> combination;
    backtrack(1, n, k, combination, result);         // Запуск backtracking с начальным индексом 1
    return result;
}


int main() 
{
    int n = 4, k = 2;

    vector<vector<int>> combinations = combine(n, k);

    for (const auto& comb : combinations) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
