#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

long long distance(const Point &a, const Point &b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

long long bruteForce(vector<Point> &points) {
    long long ans = LLONG_MAX;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            ans = min(ans, distance(points[i], points[j]));
        }
    }
    return ans;
}

long long stripClosest(vector<Point> &strip, long long d) {
    long long ans = d;
    sort(strip.begin(), strip.end(), [](const Point &a, const Point &b) {
        return a.y < b.y;
    });
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].y -
                 strip[i].y) * (strip[j].y - strip[i].y) < ans; j++) {
            ans = min(ans, distance(strip[i], strip[j]));
        }
    }
    return ans;
}
long long closestUtil(vector<Point> &points, int left, int right) {
    if (right - left <= 3) {
        vector<Point> temp(points.begin() + left, points.begin() + right);
        return bruteForce(temp);
    }
    int mid = left + (right - left) / 2;
    long long dl = closestUtil(points, left, mid);
    long long dr = closestUtil(points, mid, right);
    long long d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i < right; i++) {
        if ((points[i].x - points[mid].x) * (points[i].x - points[mid].x) < d) {
            strip.push_back(points[i]);
        }
    }
    return min(d, stripClosest(strip, d));
}