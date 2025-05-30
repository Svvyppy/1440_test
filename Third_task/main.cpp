#include <gmpxx.h> // Используем C++ API для GMP
#include <iostream>
#include <vector>

// Проверка на нечётность
bool isOdd(const mpz_class &num) { return num % 2 != 0; }

int main()
{
    mpz_class F_prev2 = 1; // F(0)
    mpz_class F_prev1 = 3; // F(1)
    mpz_class F_curr;

    std::vector<mpz_class> oddValues;

    if (isOdd(F_prev2))
        oddValues.push_back(F_prev2);
    if (isOdd(F_prev1))
        oddValues.push_back(F_prev1);

    while (oddValues.size() < 40)
    {
        F_curr = 5 * F_prev1 + F_prev2;

        if (isOdd(F_curr))
        {
            oddValues.push_back(F_curr);
        }

        F_prev2 = F_prev1;
        F_prev1 = F_curr;
    }

    std::cout << "A[39] = " << oddValues[39] << std::endl;
    return 0;
}
