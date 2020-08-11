ll n; double x;
struct Point {
    ll x, y; int segIdx;
};
struct Segment{
    Point p, q; int idx;
};
// Test for intersection
int sign(ll x) { if (x==0) return 0; else return x<0 ? -1 : +1; }
// Point operators
bool operator< (Point p1, Point p2) { return p1.x==p2.x ? p1.y<p2.y : p1.x<p2.x; }
int operator* (Point p1, Point p2) { return sign(p1.x * p2.y - p1.y * p2.x); }
Point operator- (Point p1, Point p2) { Point p = {p1.x-p2.x, p1.y-p2.y}; return p; }
bool intersect(Segment &s1, Segment &s2){
  Point &p1 = s1.p, &q1 = s1.q, &p2 = s2.p, &q2 = s2.q;
  return ((q2-p1)*(q1-p1)) * ((q1-p1)*(p2-p1)) >= 0 && ((q1-p2)*(q2-p2)) * ((q2-p2)*(p1-p2)) >= 0;
}
// y value at certain x value of segment
double eval(Segment s) {
  if (s.p.x == s.q.x) return s.p.y;
  return s.p.y + (s.q.y-s.p.y) * (x-s.p.x) / (s.q.x-s.p.x);
}
// Segment operators
bool operator< (Segment s1, Segment s2) { return s1.idx != s2.idx && eval(s1)<eval(s2); }
bool operator== (Segment s1, Segment s2) { return s1.idx == s2.idx; }

int main(){
    vector<Point> p; vector<Segment> s;
    //take input + sort vector of points
    set<Segment> active;
    FOR(i, 0, 2*n){
        int curr = p[i].segIdx; x = p[i].x;
        auto it = active.find(s[curr]);
        if(it != active.end()){
            // right point of segment
            // check intersection with pair of segments that become
            // adjacent once this one is deleted
            auto after = it, before = it; after++;
            if(before != active.begin() && after != active.end()){
                before--;
                if(intersect(s[before->idx], s[after->idx])){
                    // found two intersecting segments -> do stuff
                }
            }
            active.erase(it);
        }
        else{
            // add a new segment into active set
            // check for intersections with adjacent segments
            auto it = active.lower_bound(s[curr]);
            if(it != active.end() && intersect(s[it->idx], s[curr])){ /* curr+above intersect */ break; }
            if(it != active.begin()){ it--; if(intersect(s[it->idx], s[curr])){ /* curr+below intersect */ break;}}
            active.insert(s[one]);
        }
    }
}
