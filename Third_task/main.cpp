#include <iostream>
#include <vector>

std::vector<double> map;
double Recursive(int n)
{
    if (n != map.size())
    {
        return map[n];
    }
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 3;
    }

    return map[n] = 5 * Recursive(n - 1) + Recursive(n - 2);
}

int main()
{
    std::vector<double> arr;
    int n = 0;
    double value = 0;
    while (arr.size() < 11)
    {
        value = Recursive(n);

        if ((int)value % 2 != 0)
        {
            arr.push_back(value);
        }
        n++;
    }
    std::cout << arr[10] << std::endl;
    return 0;
}