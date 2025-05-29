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

    for (size_t i = 0; i < segments.size(); i++)
    {
        if (segments[i].left > last_point)
        {
            points++;
            last_point = segments[i].right;
        }
    }

    return points;
}

int main()
{
    ifstream file("First_task/data_prog_contest_problem_1.txt");

    if (!file.is_open())
    {
        cout << "File not open " << endl;
        return 1;
    }

    int n;
    file >> n;

    vector<Segment> segments(n);

    for (int i = 0; i < n; ++i)
    {

        file >> segments[i].left >> segments[i].right;
    }

    file.close();

    int result = minPointsCover(segments);

    cout << result << endl;

    return 0;
}