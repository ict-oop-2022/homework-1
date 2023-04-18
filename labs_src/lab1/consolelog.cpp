#include <iostream>
#include <vector>

#include <cmath>

#define PI  3.14159265358979323846

class point {
public:
    float x, y;

    point() {}
    point(float a, float b) :x(a), y(b) {}

    point& operator=(const point& object) {
        x = object.x;
        y = object.y;
        return *this;
    }

    static float distance(const point& a, const point& b) {
        return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
    }

    friend std::ostream& operator << (std::ostream& stream, const point& obj) {
        stream << '(' << obj.x << ',' << obj.y << ')';
        return stream;
    }
};

class polyline {
protected:
    std::vector<point> coords;

public:
    polyline() {}

    void push_back(float xp, float yp) {
        coords.push_back(point(xp, yp));
    }

    void push_back(const point& p) {
        coords.push_back(p);
    }

    int get_len() const {
        return coords.size();
    }

    const std::vector<point>& get_coords() const {
        return coords;
    }

    point& operator[](int i) {
        return coords[i];
    }

    polyline& operator=(const polyline& object) {
        coords = object.coords;
        return *this;
    }

    friend std::ostream& operator << (std::ostream& stream, const polyline& obj) {
        for (auto a : obj.coords)
            stream << a << std::endl;
        return stream;
    }

    virtual float get_perimeter() const {
        int len = get_len();
        if (len == 0 || len == 1)
            return 0;

        float summ = 0;

        for (int i = 1; i < len; i++) {
            summ += point::distance(coords[i], coords[i - 1]);
        }
        return summ;
    }

    void clear_coords() {
        coords.clear();
    }

    virtual ~polyline() {}
};

class closed_polyline : public polyline {
public:
    closed_polyline() {}

    float get_perimeter() const override {
        float s = (polyline::get_perimeter() + point::distance((*this)[0], (*this)[get_len() - 1]));
        return s > 0 ? s : -s;
    }

    ~closed_polyline() {}
};

class polygon : public closed_polyline {
public:
    polygon() {}

    float get_area() const {
        std::vector<point> coords = get_coords();
        int n = get_len();
        float s = 0;

        for (int i = 0; i < n - 1; i++) {
            s += (coords[i].x + coords[(i + 1) % n].x) * (coords[(i + 1) % n].y - coords[i].y);
        }
        
        return abs(s) / 2;
    }

bool polygon::is_trapezoid() {
    if (this->getlen() != 4) return false;
    if (is_parallel((*this)[0], (*this)[1], (*this)[2], (*this)[3]) ||
        is_parallel((*this)[1], (*this)[2], (*this)[3], (*this)[0])) {
        return true;
    }
    return false;
}

void triangle::push_back(point a) {
    if (this->getlen() < 3) {
        this->polygon::push_back(a);
    } else {
        cout << "triangle is three points figure only\n";
    }
}

trapezoid::trapezoid() {
    float x, y;
    for (int i = 0; i < 4; i++) {
        cout << "trapezoid's coords x,y:\n";
        cin >> x >> y;
        this->push_back(x, y);
    }
    if (!this->is_trapezoid()) {
        this->clear_coords();
        cout << "not trapezoid, points cleared";
    }
}

trapezoid::trapezoid(vector<point> v) {
    for (auto i : v) {
        this->push_back(i);
    }
    if (!this->is_trapezoid()) {
        this->clear_coords();
        cout << "not trapezoid, points cleared";
    }
}

regular_polygon::regular_polygon() {
    int n;
    float r, x, y;
    cout << "center coords:\nx,y\n";
    cin >> x >> y;
    cout << "n,r\n";
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        push_back(x + r * cos(2 * PI * i / n), y + r * sin(2 * PI * i / n));
    }
}

regular_polygon::regular_polygon(int n, float r, float x, float y) {
    for (int i = 0; i < n; i++) {
        push_back(x + r * cos(2 * PI * i / n), y + r * sin(2 * PI * i / n));
    }
}
