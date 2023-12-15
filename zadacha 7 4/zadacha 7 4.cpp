#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    // Ввод последовательности
    std::vector<int> sequence = { 123, 235, 567, 323, 762, 333 };

    // Удаление чисел, начинающихся и заканчивающихся одной и той же цифрой
    sequence.erase(std::remove_if(sequence.begin(), sequence.end(),
        [](int num) {
            std::string strNum = std::to_string(num);
            return strNum.front() == strNum.back();
        }), sequence.end());

    // Продублировать числа, начинающиеся цифрой 3
    std::vector<int> toDuplicate;
    for (int num : sequence) {
        if (std::to_string(num).front() == '3') {
            toDuplicate.push_back(num);
        }
    }
    sequence.insert(sequence.end(), toDuplicate.begin(), toDuplicate.end());

    // Вывод полученной последовательности
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}