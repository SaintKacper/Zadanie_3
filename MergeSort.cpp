#include <iostream>
#include <vector>

// Funkcja mergeSort
std::vector<int> mergeSort(const std::vector<int>& array) {
    if (array.size() <= 1) {
        return array;
    }

    // Dzielenie
    int middle = array.size() / 2;
    std::vector<int> left(array.begin(), array.begin() + middle);
    std::vector<int> right(array.begin() + middle, array.end());

    // Rekurencyjne wywołanie MergeSort dla lewej i prawej połowy
    left = mergeSort(left);
    right = mergeSort(right);

    // Łączenie posortowanych tablic
    return merge(left, right);
}

// Funkcja merge
std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;
    size_t leftIndex = 0;
    size_t rightIndex = 0;

    // Łączenie posortowanych tablic
    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }
    }

    // Dodanie ewentualnych pozostałych elementów z left i right
    result.insert(result.end(), left.begin() + leftIndex, left.end());
    result.insert(result.end(), right.begin() + rightIndex, right.end());

    return result;
}

int main() {
    // Przykładowe użycie
    std::vector<int> unsortedArray = {12, 11, 13, 5, 6, 7};

    std::vector<int> sortedArray = mergeSort(unsortedArray);

    std::cout << "Posortowana tablica: ";
    for (int num : sortedArray) {
        std::cout << num << " ";
    }

    return 0;
}
