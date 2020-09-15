#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int iterativeBinarySearch(std::vector<T> &vec, int v, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (v == vec[mid])
        {
            return mid;
        }
        else if (v > vec[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

template <typename T>
int recursiveBinarySearch(std::vector<T> &vec, int v, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (v == vec[mid])
        return mid;
    else if (v > vec[mid])
        return recursiveBinarySearch(vec, v, mid + 1, high);
    else
        return recursiveBinarySearch(vec, v, low, mid - 1);
}

template <typename T>
void printVector(std::vector<T> &vec)
{
    for (auto value:vec)
        std::cout << value << " ";
    std::cout<<std::endl;
}

int main()
{
    std::vector<int> A{5, 2, 4, 7, 1, 3, 2, 6};

    std::sort(A.begin(), A.end());

    std::cout << "The sorted vector A is as ";
    printVector(A);

    std::cout << "Perform ITERATIVE-BINARY-SEARCH(A, 6, 0, 7)\n"
              << "The index of 6 is " << iterativeBinarySearch(A, 6, 0, 7) << std::endl;

    std::cout << "Perform ITERATIVE-BINARY-SEARCH(A, 8, 0, 7)\n"
              << "The index of 8 is " << recursiveBinarySearch(A, 8, 0, 7) << std::endl;
    return 0;
}