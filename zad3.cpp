#include <iostream>

struct Wymierne 
{
private:
    int numerator, denominator;

    int nwd(int a, int b) const {
        while (a != b) {
            if (a > b) 
                a -= b;
            else 
                b -= a;
        }
        return a;
    }

    int nww(int a, int b) const {
        int new_nwd = nwd(a, b);
        return (a * b) / new_nwd;
    }

public:
    Wymierne(int const& n,int const& d) : numerator(n), denominator(d) {
        simplify();
    }

    Wymierne(int const& v) : numerator(v), denominator(1) {}

    ~Wymierne() {
        std::cout << "Number " << numerator << "/" << denominator << " was removed\n\n";
    }

    void simplify() {
        int div = nwd(numerator, denominator);
        numerator /= div;
        denominator /= div;
    }

    int getX() const { 
        return numerator; 
    }
    int getY() const { 
        return denominator;
    }

    void show() const {
        std::cout << "Number = " << numerator;
        std::cout << "/" << denominator << "\n";
    }

    Wymierne* sum(Wymierne const& w) const {
      
        int n1 = numerator;
        int d1 = denominator;
        int n2 = w.getX();
        int d2 = w.getY();

        int new_nww = nww(d1, d2);
        int d1_mltp = new_nww / d1;
        int d2_mltp = new_nww / d2;

        
        n1 = n1 * d1_mltp;
        n2 = n2 * d2_mltp;
        int new_n = n1 + n2;

        return new Wymierne (new_n, new_nww);
    }

    Wymierne* sum(int const& v) const { 

        int n1 = numerator;
        int d1 = denominator;
        int n2 = v;
        int d2 = 1;

        int new_nww = nww(d1, d2);
        int d1_mltp = new_nww / d1;
        int d2_mltp = new_nww / d2;

        n1 = n1 * d1_mltp;
        n2 = n2 * d2_mltp;
        int new_n = n1 + n2;

        return new Wymierne(new_n, new_nww);
    }

    void sum2(Wymierne const& w) {
        
        int n1 = numerator;
        int d1 = denominator;
        int n2 = w.getX();
        int d2 = w.getY();

        
        int new_nww = nww(d1, d2);
        int d1_mltp = new_nww / d1;
        int d2_mltp = new_nww / d2;

        
        n1 = n1 * d1_mltp;
        n2 = n2 * d2_mltp;
        int new_num = n1 + n2;

        numerator = new_num;
        denominator = new_nww;
        simplify();
    }
};

int main() {
	auto w1 = Wymierne(24, 14);
	auto w2 = Wymierne(4, 8);
	auto w3 = Wymierne(3, 7);
	auto w4 = Wymierne(6, 5);

	w1.show();
	w2.show();
    w3.show();
    w4.show();

	Wymierne* sum1 = w1.sum(w2); 

	std::cout << "\n";

	auto sum2 = w2.sum(Wymierne(3, 8)); 

    std::cout << "\n";

	w3.sum2(w1); 
	w3.show();

	auto sum3 = w4.sum(2);

	std::cout << "\n";

	return 0;
}