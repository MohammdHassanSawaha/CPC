// Computational Geometry: Convex Hull, Point-in-Polygon, Closest Pair
// All coordinates use long long to avoid floating point for integer inputs.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point;

ll cross(Point O, Point A, Point B) {
    return (A.first - O.first) * (B.second - O.second)
         - (A.second - O.second) * (B.first - O.first);
}

ll dist2(Point A, Point B) {
    return (A.first - B.first) * (A.first - B.first)
         + (A.second - B.second) * (A.second - B.second);
}

// Convex Hull (Andrew's monotone chain)
// Returns hull vertices in counter-clockwise order.
// Time: O(N log N), Space: O(N)
vector<Point> convex_hull(vector<Point> pts) {
    int n = pts.size();
    if (n < 2) return pts;
    sort(pts.begin(), pts.end());

    vector<Point> hull;
    // Lower hull
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }
    // Upper hull
    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while ((int)hull.size() > lower_size && cross(hull[hull.size()-2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }
    hull.pop_back();
    return hull;
}

// Point-in-Polygon (ray casting algorithm)
// Works for any simple polygon (convex or not).
// Returns true if point P is strictly inside the polygon.
// Uses integer arithmetic to avoid floating-point precision issues.
bool point_in_polygon(const vector<Point>& poly, Point P) {
    int n = poly.size();
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        ll xi = poly[i].first, yi = poly[i].second;
        ll xj = poly[j].first, yj = poly[j].second;
        ll px = P.first, py = P.second;
        if ((yi > py) != (yj > py)) {
            // Integer-arithmetic test: is x_intersection > px?
            // x_int = xi + (xj-xi)*(py-yi)/(yj-yi) > px
            // Multiply both sides by (yj-yi), flipping if negative:
            ll lhs = (xj - xi) * (py - yi);
            ll rhs = (px - xi) * (yj - yi);
            bool crosses = (yj > py) ? (lhs > rhs) : (lhs < rhs);
            if (crosses) inside = !inside;
        }
    }
    return inside;
}

// Closest Pair of Points
// Time: O(N log N), Space: O(N)
double closest_pair_rec(vector<Point>& pts, int l, int r) {
    if (r - l <= 3) {
        double d = 1e18;
        for (int i = l; i < r; i++)
            for (int j = i + 1; j < r; j++)
                d = min(d, (double)dist2(pts[i], pts[j]));
        sort(pts.begin() + l, pts.begin() + r, [](const Point& a, const Point& b) {
            return a.second < b.second;
        });
        return sqrt(d);
    }

    int mid = (l + r) / 2;
    ll mid_x = pts[mid].first;
    double d = min(closest_pair_rec(pts, l, mid), closest_pair_rec(pts, mid, r));

    vector<Point> strip;
    inplace_merge(pts.begin() + l, pts.begin() + mid, pts.begin() + r,
                  [](const Point& a, const Point& b) { return a.second < b.second; });
    for (int i = l; i < r; i++) {
        if (abs(pts[i].first - mid_x) <= d)
            strip.push_back(pts[i]);
    }

    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i + 1; j < (int)strip.size() && strip[j].second - strip[i].second < d; j++) {
            d = min(d, sqrt((double)dist2(strip[i], strip[j])));
        }
    }
    return d;
}

double closest_pair(vector<Point>& pts) {
    sort(pts.begin(), pts.end());
    return closest_pair_rec(pts, 0, pts.size());
}

int main() {
    // Convex hull example
    vector<Point> points = {{0,0},{1,1},{2,2},{0,2},{2,0},{1,0},{0,1}};
    auto hull = convex_hull(points);
    cout << "Convex hull vertices:\n";
    for (auto [x, y] : hull) cout << "(" << x << "," << y << ") ";
    cout << "\n";

    // Point in polygon
    vector<Point> polygon = {{0,0},{4,0},{4,4},{0,4}};
    Point p = {2, 2};
    cout << "Point (2,2) in polygon: " << (point_in_polygon(polygon, p) ? "YES" : "NO") << "\n";

    return 0;
}
