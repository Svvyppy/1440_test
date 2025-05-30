#include <fstream>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ifstream file("Second_task/data_prog_contest_problem_2.txt");

    int n;
    file >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; ++i)
    {
        file >> sequence[i];
    }

    if (sequence.size() < 26)
    {
        cout << "NONE" << endl;
        return 0;
    }
    int required = 26;
    unordered_map<int, int> freq;
    int count = 0;

    int left = 0;
    int minLen = numeric_limits<int>::max();

    for (int right = 0; right < n; ++right)
    {
        int val = sequence[right];
        if (val >= 1 && val <= 26)
        {
            freq[val]++;
            if (freq[val] == 1)
                count++;
        }

        while (count == required)
        {
            minLen = min(minLen, right - left + 1);

            int leftVal = sequence[left];
            if (leftVal >= 1 && leftVal <= 26)
            {
                freq[leftVal]--;
                if (freq[leftVal] == 0)
                    count--;
            }
            left++;
        }
    }

    if (minLen == numeric_limits<int>::max())
    {
        cout << "NONE" << endl;
    }
    else
    {
        cout << minLen << endl;
    }

    return 0;
}
