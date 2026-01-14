#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Event {
        long long y;
        int type;
        int x1, x2;
    };

    vector<long long> xs;
    vector<int> cnt;
    vector<long double> seg;

    void pushUp(int idx, int l, int r) {
        if (cnt[idx] > 0) {
            seg[idx] = xs[r] - xs[l];
        } else if (l + 1 == r) {
            seg[idx] = 0;
        } else {
            seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
        }
    }

    void update(int idx, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            cnt[idx] += val;
            pushUp(idx, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(idx * 2, l, mid, ql, qr, val);
        update(idx * 2 + 1, mid, r, ql, qr, val);
        pushUp(idx, l, r);
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        xs.clear();

        for (auto &s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            xs.push_back(x);
            xs.push_back(x + l);
            events.push_back({y, +1, 0, 0});
            events.push_back({y + l, -1, 0, 0});
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        int m = xs.size();
        cnt.assign(4 * m, 0);
        seg.assign(4 * m, 0);

        int ei = 0;
        for (auto &s : squares) {
            long long x = s[0], l = s[2];
            int x1 = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
            int x2 = lower_bound(xs.begin(), xs.end(), x + l) - xs.begin();
            events[ei++].x1 = x1, events[ei++].x1 = x1;
            events[ei - 2].x2 = x2;
            events[ei - 1].x2 = x2;
        }

        sort(events.begin(), events.end(),
             [](auto &a, auto &b) { return a.y < b.y; });

        long double total = 0;
        long long prevY = events[0].y;

        for (auto &e : events) {
            total += seg[1] * (e.y - prevY);
            update(1, 0, m - 1, e.x1, e.x2, e.type);
            prevY = e.y;
        }

        long double half = total / 2;
        cnt.assign(4 * m, 0);
        seg.assign(4 * m, 0);

        long double cur = 0;
        prevY = events[0].y;

        for (auto &e : events) {
            long double area = seg[1] * (e.y - prevY);
            if (cur + area >= half) {
                return (double)(prevY + (half - cur) / seg[1]);
            }
            cur += area;
            update(1, 0, m - 1, e.x1, e.x2, e.type);
            prevY = e.y;
        }

        return (double)prevY;
    }
};
