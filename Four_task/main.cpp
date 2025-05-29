/*
Такая хитрая функция))))) будет принимать значение 1, если в числе нет нулей на
конце, если же нули на конце есть, то они будут "перебрасываться" в наш ответ и
будет получаться 0,1 0,01 и тд. у числа 10^30 в предельном случае будет 29
нулей, так как равенство строгое, значений будет 30.
*/
#include <iostream>

int FirstFunction(int numb)
{

    int temp = 0, rev_numb = 0;
    // rev_numb = numb % 10;
    // numb = numb / 10;
    while (numb > 0)
    {
        temp = numb % 10;
        numb = numb / 10;
        rev_numb = rev_numb * 10;
        rev_numb += temp;
    }
    return rev_numb;
}

float SecondFunction(int n)
{
    float res = 0.0;
    int f_out = FirstFunction(n);
    res = (float)FirstFunction(f_out) / n;
    return res;
}

int main()
{
    int n = 0;
    std::cout << "введите верхнюю границу";
    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        std::cout << i << " " << FirstFunction(i) << " "
                  << " " << FirstFunction(FirstFunction(i)) << " "
                  << SecondFunction(i) << std::endl;
    }

    return 0;
}