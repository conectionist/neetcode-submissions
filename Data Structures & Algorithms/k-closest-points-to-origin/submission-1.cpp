struct Point
{
    int x;
    int y;
};

bool operator<(const Point& p1, const Point& p2)
{
    double dist1 = sqrt(pow(p1.x,2) + pow(p1.y,2));
    double dist2 = sqrt(pow(p2.x,2) + pow(p2.y,2));

    return dist1 < dist2;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point> maxHeap;

        for(const auto& point : points)
        {
            maxHeap.push({point[0], point[1]});

            if(maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<vector<int>> results;

        while(!maxHeap.empty())
        {
            auto [x, y] = maxHeap.top();
            maxHeap.pop();

            vector<int> point = {x,y};
            results.push_back(point);
        }

        return results;
    }
};
