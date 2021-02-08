#include "iostream"
#include "vector"
#include "algorithm"
using namespace std; 

struct Point {
    int x, y;
    bool operator < (const Point& oth) const {
        return (x < oth.x);
    }
}mid;

int quad(Point p) { 
    if (p.x >= 0 && p.y >= 0) 
        return 1; 
    if (p.x <= 0 && p.y >= 0) 
        return 2; 
    if (p.x <= 0 && p.y <= 0) 
        return 3; 
    return 4; 
} 

int orientation(Point a, Point b, Point c) { 
    int res = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x); 
    if (res == 0) 
        return 0; 
    if (res > 0) 
        return 1; 
    return -1; 
} 

bool compare(Point p1, Point q1) { 
    Point p, q;
    p.x = p1.x - mid.x;
    p.y = p1.y - mid.y;
    q.x = q1.x - mid.x;
    q.y = q1.y - mid.y;

    int one = quad(p); 
    int two = quad(q); 

    if (one != two) return (one < two); 
    return (p.y * q.x < q.y * p.x); 
} 

vector<Point> combine(vector<Point> a, vector<Point> b) { 
    int n1 = a.size(), n2 = b.size(); 

    int ia = 0, ib = 0; 
    for (int i=1; i<n1; i++) 
        if (a[i].x > a[ia].x) 
            ia = i; 

    for (int i=1; i<n2; i++) 
        if (b[i].x < b[ib].x) 
            ib=i; 

    int inda = ia, indb = ib; 
    bool done = 0; 
    while (!done) 
    { 
        done = 1; 
        while (orientation(b[indb], a[inda], a[(inda+1)%n1]) >=0) 
            inda = (inda + 1) % n1; 

        while (orientation(a[inda], b[indb], b[(n2+indb-1)%n2]) <=0) 
        { 
            indb = (n2+indb-1)%n2; 
            done = 0; 
        } 
    } 

    int uppera = inda, upperb = indb; 
    inda = ia, indb=ib; 
    done = 0; 
    int g = 0; 
    while (!done)
    { 
        done = 1; 
        while (orientation(a[inda], b[indb], b[(indb+1)%n2])>=0) 
            indb=(indb+1)%n2; 

        while (orientation(b[indb], a[inda], a[(n1+inda-1)%n1])<=0) 
        { 
            inda=(n1+inda-1)%n1; 
            done=0; 
        } 
    } 

    int lowera = inda, lowerb = indb; 
    vector<Point> ret; 

    int ind = uppera; 
    ret.push_back(a[uppera]); 
    while (ind != lowera) 
    { 
        ind = (ind+1)%n1; 
        ret.push_back(a[ind]); 
    } 

    ind = lowerb; 
    ret.push_back(b[lowerb]); 
    while (ind != upperb) 
    { 
        ind = (ind+1)%n2; 
        ret.push_back(b[ind]); 
    } 
    return ret; 
} 

bool checkAbove(Point p, Point i, Point q) { 
    int val = (q.x - p.x) * (i.y - p.y) - (i.x - p.x) * (q.y - p.y); 
    return (val > 0);
} 
vector<Point> bruteHull(vector<Point> a) { 
    vector<Point> hull; 
    int l = 0, n = a.size(); 
    for (int i = 1; i < n; i++) {
        if (a[i].x < a[l].x) 
            l = i; 
    }
    int p = l, q; 
    do { 
        hull.push_back(a[p]); 
        q = (p + 1) % n; 
        for (int i = 0; i < n; i++) { 
            if (checkAbove(a[p], a[i], a[q])) 
                q = i; 
        }  
        p = q; 
    } while (p != l);

    mid = {0, 0}; 
    n = hull.size();
    for (int i = 0; i < n; i++) { 
        mid.x += hull[i].x; 
        mid.y += hull[i].y; 
        hull[i].x *= n; 
        hull[i].y *= n; 
    } 
    sort(hull.begin(), hull.end(), compare); 
    for (int i = 0; i < n; i++) {
        hull[i].x /= n;
        hull[i].y /= n;
    }
    return hull; 
} 

vector<Point> divide(vector<Point> a) { 
    if (a.size() <= 5) return bruteHull(a); 

    vector<Point> left, right; 

    for (int i = 0; i < a.size() / 2; i++) {
        left.push_back(a[i]);
    } 
    for (int i = a.size() / 2; i < a.size(); i++) {
        right.push_back(a[i]); 
    }

    vector<Point> left_hull = divide(left); 
    vector<Point> right_hull = divide(right); 

    return combine(left_hull, right_hull); 
} 

int main() { 
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    sort(pts.begin(), pts.end()); 
    vector<Point> convex_hull = divide(pts); 

    cout << "Convex Hull:\n";
    for (auto it : convex_hull) {
        cout << "(" << it.x << ", " << it.y << ")\n";
    } 
    return 0; 
} 