#include <iostream>
#include <vector>

template <typename T>
void heapify(std::vector<T>& vec, int heap_size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < heap_size && vec[l] > vec[largest])
        largest = l;

    if (r < heap_size && vec[r] > vec[largest])
        largest = r;

    if (largest != i) {
        std::swap(vec[i], vec[largest]);
        heapify(vec, heap_size, largest);
    }
}

template <typename T>
void heapSort(std::vector<T>& vec, int heap_size) {
    // build the max heap
    for (int i = heap_size / 2 - 1; i >= 0; i--)
        heapify(vec, heap_size, i);

    //extract elements from the heap
    for (int i = heap_size - 1; i > 0; i--) {
        std::swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

int main() {
    std::vector<int> vec{10, 15, 23, 45, 68, -10};

    heapSort(vec, vec.size());

    std::cout << "The sorted array is" << std::endl;
    for (auto value : vec)
        std::cout << value << " ";
    std::cout << std::endl;

    return 0;
}

