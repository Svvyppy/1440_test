#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Segment
{
    int left, right;
};

bool compareSegments(const Segment &a, const Segment &b)
{
    return a.right < b.right;
}

int minPointsCover(vector<Segment> &segments)
{
    if (segments.empty())
    {
        return 0;
    }

    sort(segments.begin(), segments.end(), compareSegments);

    int points = 0;
    int last_point = -1e9;

    for (const auto &seg : segments)
    {
        if (seg.left > last_point)
        {
            points++;
            last_point = seg.right;
        }
    }

    return points;
}

int main()
{
    cout << "Текущая папка: " << filesystem::current_path() << endl;

    ifstream file("First_task/data_prog_contest_problem_1.txt");

    if (!file.is_open())
    {
        cout << "File not open " << endl;
        return 1;
    }

    int n;
    cout << n << endl;

    vector<Segment> segments(n);

    for (int i = 0; i < n; ++i)
    {

        file >> segments[i].left >> segments[i].right;
    }

    file.close();

    int result = minPointsCover(segments);

    cout << "Минимальное количество точек: " << result << endl;

    return 0;
}