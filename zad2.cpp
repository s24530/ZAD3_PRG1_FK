#include <iostream>
#include <cmath>
struct Punkt 
{
private:
    int x, y;

public:
    void show() const {
        std::cout << "point coordinates (" << x << ", " << y << ")\n";
    }
    void show_pkt() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }


    void setXY(const int& new_x, const int& new_y) {
        x = new_x;
        y = new_y;
    }

    void setXY(const Punkt& p) {
        x = p.x;
        y = p.y;
    }


    Punkt getXY() {
        return Punkt(x, y);
    }

    Punkt(const int& new_x, const int& new_y) {
        x = new_x;
        y = new_y;

        std::cout << "Point (" << x << ", " << y << ") was destroyed\n";
    }

    Punkt(const Punkt& pkt) {
        x = pkt.getX();
        y = pkt.getY();
        std::cout << "New point was created using a old one";
        pkt.show_pkt();
    }

    ~Punkt() {
        std::cout << "Point ";
        show_pkt();
        std::cout << "was destroyed\n";
    }
};

struct Prostokat 
{
private:
    Punkt lt, rb;

public:
    Prostokat(const int& x1, const int& x2, const int& y1, const int& y2) : lt(x1, y1), rb(x2, y2) {}

    Prostokat(const Punkt& p1, const Punkt& p2) : lt(p1), rb(p2) {}

    ~Prostokat() {
        std::cout << "Rectangle ";
        std::cout << "(" << lt.getX() << ", " << lt.getY() << ")";
        std::cout << " x ";
        std::cout << "(" << rb.getX() << ", " << rb.getY() << ")";
        std::cout << " fell apart\n";
    }

    void show() const { //Rectangle info
        

        std::cout << "Top left "; lt.show();
        std::cout << "Bottom right "; rb.show();

        std::cout << "Rectangle length =  ";
        std::cout << abs(lt.getX() - rb.getX()) << "\n";
        std::cout << "Rectangle height = ";
        std::cout << abs(lt.getY() - rb.getY()) << "\n";
    }

    int area() const {
        int w = abs(lt.getX() - rb.getX());
        int h = abs(lt.getY() - rb.getY());
        return w * h;
    }

    bool is_inside(const Punkt& p) const {
        int x_min, x_max, y_min, y_max;
        int p_x = p.getX();
        int p_y = p.getY();

        if (lt.getX() <= rb.getX()) {
            x_min = lt.getX();
            x_max = rb.getX();
        }
        else {
            x_min = rb.getX();
            x_max = lt.getX();
        }

        if (lt.getY() <= rb.getY()) {
            y_min = lt.getY();
            y_max = rb.getY();
        }
        else {
            y_min = rb.getY();
            y_max = lt.getY();
        }

        if (p_x < x_min || p_x > x_max || p_y < y_min || p_y > y_max)
            return false;
        return true;
    }
};

int main()
{

    auto p1 = Prostokat(5, 8, 4, 2);
    auto p2 = Prostokat(Punkt(5, 9), Punkt(4, 3));

    p1.show();
    p2.show();

    std::cout << "P1 area =  " << p1.area() << "\n";
    std::cout << "P2 area =  " << p2.area() << "\n";

    auto p3 = Punkt(6, 3);
    std::cout << "Is point (6,3) inside the rectangle? " << (p1.is_inside(p3) ? "Yes" : "No") << "\n";
    std::cout << "Is point (6,3) inside the rectangle? " << (p2.is_inside(p3) ? "Yes" : "No") << "\n";

    return 0;
}