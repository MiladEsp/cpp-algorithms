#include <iostream>
#include <vector>

template <typename T>
void selectionSort(std::vector<T> &vec)
{
    int n = vec.size();

    for (int i = 0; i < n; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (vec[j] < vec[minIndex])
                minIndex = j;
            std::swap(vec[i], vec[minIndex]);
        }
    }
}

int main()
{
    std::vector<int> vec{5, 2, 4, 7, 1, 3, 2, 6, -5, 10, 0};

    selectionSort(vec);

    for (auto item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    /////////////////////////
    std::vector<double> vec1{-2.3, 0.5, 1.6, -10.5, 13.69};

    selectionSort(vec1);

    for (auto item : vec1)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}