#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T> &vec, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    T *L = new T[n1];
    T *R = new T[n2];

    int i, j, k;

    for (i = 0; i < n1; i++)
    {
        L[i] = vec[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = vec[q + j + 1];
    }

    i = j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) //extra element in left vecay
    {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) //extra element in right vecay
    {
        vec[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

template <typename T>
void mergeSort(std::vector<T> &vec, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(vec, p, q);
        mergeSort(vec, q + 1, r);
        merge(vec, p, q, r);
    }
}

int main()
{
    std::vector<int> vec{5, 2, 4, 7, 1, 3, 2, 6, -5, 10, 0};

    mergeSort(vec, 0, vec.size() - 1);

    for (auto item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    /////////////////////////
    std::vector<double> vec1{-2.3, 0.5, 1.6, -10.5, 13.69};

    mergeSort(vec1, 0, vec1.size() - 1);

    for (auto item : vec1)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}