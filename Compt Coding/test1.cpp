#include <cmath>
#include <cassert>
#include <ctime>
#include <memory.h>
#include <set>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
typedef long double dbl;

const dbl eps = 1e-10;

dbl sqr(dbl x) {
    return x * x;
}

// y -- OK
bool equal(dbl x, dbl y) {
	return fabs(x - y) / max((dbl)1.0, fabs(y)) < eps;
}

struct pt {
    dbl x, y;

    pt() {}
    pt(dbl x, dbl y) : x(x), y(y) {}

    pt operator+ (const pt &p) const {
        return pt(x + p.x, y + p.y);
    }

    pt operator- (const pt &p) const {
        return pt(x - p.x, y - p.y);
    }

    dbl operator* (const pt &p) const {
        return x * p.y - y * p.x;
    }

    dbl operator% (const pt &p) const {
        return x * p.x + y * p.y;
    }

    pt operator* (dbl d) const {
        return pt(x * d, y * d);
    }

    pt operator/ (dbl d) const {
        return pt(x / d, y / d);
    }

    dbl d() const {
        return sqrt(x * x + y * y);
    }

    pt rotate90() const {
        return pt(-y, x);
    }

    pt norm() const {
        return pt(x / d(), y / d());
    }

    pt inv() const {
        return pt(x, y) / (sqr(x) + sqr(y));
    }

    void print() const {
        printf("%.10f %.10f\n", (double)x, (double)y);
    }
};

pt ooo;
dbl f(pt a, dbl r) {
    /*dbl x0 = a.x, y0 = a.y;
    dbl t1 = -r / a.d() + 1;
    dbl t2 = +r / a.d() + 1;
    pt p1 = pt(x0 * t1, y0 * t1).inv();
    pt p2 = pt(x0 * t2, y0 * t2).inv();
	ooo = (p1 + p2) / 2;
	dbl res = (p1 - p2).d() / 2.0;*/
	double s = 1 / (a.x * a.x + a.y * a.y - r * r);
	ooo = a * s;
	double res = fabs(s) * r;
    return res;
}

vector<pt> intersect(pt a1, dbl r1, pt a2, dbl r2) {
    assert((a1 - a2).d() > eps);

    dbl A1 = a1.y - a2.y;
    dbl B1 = a2.x - a1.x;
    dbl C1 = -(A1 * a1.x + B1 * a1.y);

    dbl A2 = 2 * (a1.x - a2.x);
    dbl B2 = 2 * (a1.y - a2.y);
    dbl C2 = -sqr(r2) + sqr(r1) + sqr(a2.x) + sqr(a2.y) - sqr(a1.x) - sqr(a1.y);

    dbl det = A1 * B2 - A2 * B1;
    dbl detx = C1 * B2 - C2 * B1;
    dbl dety = A1 * C2 - A2 * C1;
    pt b(-detx / det, -dety / det);

    if ((b - a1).d() - r1 > eps) return vector<pt>();
	if (equal((b - a1).d(), r1)) return vector<pt>(1, b);

    pt v = (a2 - a1).norm().rotate90();
    dbl len = sqrt(sqr(r1) - sqr((b - a1).d()));
    vector<pt> res;
    res.push_back(b + v * len);
    res.push_back(b - v * len);
    return res;
}

int main() {
#ifndef ONLINE_JUDGE

    //freopen("output.txt", "w", stdout);
#endif
    freopen("C:\\Users\\DARPAN\\Desktop\\b.txt","r",stdin);
    int T, n, p, m, b;
    cin >> T >> n >> p >> m >> b;
    double _r1, _r2, _r3, _r4;
    cin >> _r1 >> _r2 >> _r3 >> _r4;
	dbl r1 = _r1, r2 = _r2, r3 = _r3, r4 = _r4;

    pt a1(0, r1);
    pt a2(0, r2);

    // (p1, p2), (p3, p4) -- lines
    pt p1 = pt(-r1, r1).inv();
    pt p2 = pt(r1, r1).inv();
    pt p3 = pt(-r2, r2).inv();
    pt p4 = pt(r2, r2).inv();

    dbl rad = fabs(p1.y - p3.y) / 2;
    pt a3 = intersect(a1, r1 - r3, a2, r2 + r3)[0];
    f(a3, r3);
    dbl S = ooo.x;

	double rr3 = f(pt(S, (p1.y + p3.y) / 2), rad);
    assert(equal(r3, rr3));

    dbl rL = f(pt(S - 2 * rad, (p1.y + p3.y) / 2), rad); pt aL = ooo;
    dbl rR = f(pt(S + 2 * rad, (p1.y + p3.y) / 2), rad); pt aR = ooo;

	pt a4;
    int dir;
    if (equal(rL, r4)) dir = -1, a4 = aL;
    else if (equal(rR, r4)) dir = 1, a4 = aR;
    else assert(0);

	assert(equal((a1 - a2).d(), r1 - r2));
	assert(equal((a1 - a3).d(), r1 - r3));
	assert(equal((a1 - a4).d(), r1 - r4));
	assert(equal((a2 - a3).d(), r2 + r3));
	assert(equal((a2 - a4).d(), r2 + r4));
	assert(equal((a3 - a4).d(), r3 + r4));

    dbl ans = 0;
    while (T--) {
        n = 1LL * p * n % m + b;

        if (n <= 2) {
            if (n == 1) ans += r1;
            else if (n == 2) ans += r2;
			else assert(0);
            continue;
        }
        n -= 3;
        double rn = f(pt(S + dir * 2 * rad * n, (p1.y + p3.y) / 2), rad);
		ans += rn;
    }

    printf("%.6f\n", (double)ans);

    return 0;
}
