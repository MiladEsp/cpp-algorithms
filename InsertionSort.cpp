#include <iostream>
#include <vector>

template <typename T>
void insertionSort(std::vector<T> &vec, bool ascending)
{
    int i, j;
    T key;

    for (j = 1; j < vec.size(); j++)
    {
        key = vec[j];
        i = j - 1;

        if (ascending)
        {
            while (i >= 0 && vec[i] > key)
            {
                vec[i + 1] = vec[i];
                i = i - 1;
            }
        }
        else
        {
            while (i >= 0 && vec[i] < key)
            {
                vec[i + 1] = vec[i];
                i = i - 1;
            }
        }
        vec[i + 1] = key;
    }
}

int main()
{
    std::vector<int> vec{5, 2, 4, 7, 1, 3, 2, 6, -5, 10, 0};

    insertionSort(vec, true);

    for (auto item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    /////////////////////////
    std::vector<double> vec1{-2.3, 0.5, 1.6, -10.5, 13.69};

    insertionSort(vec1, true);

    for (auto item : vec1)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}