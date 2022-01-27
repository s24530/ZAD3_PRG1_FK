#include <iostream>

struct Punkt 
{
private:
	int x, y;

public:
	void show() const {
		std::cout << "Wspolrzedne punktu (" << x << ", " << y << ")\n";
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


	void setXY(const int& new_x,const int& new_y) {
		x = new_x;
		y = new_y;
	}

	void setXY(const Punkt &p) {
		x = p.x;
		y = p.y;
	}


	Punkt getXY() { 
		return Punkt(x, y); 
	}

	Punkt(const int &new_x,const int &new_y)  {
		x = new_x;
		y = new_y;

		std::cout << "Punkt (" << x << ", " << y << ") zostal utworzony\n";
	}

	Punkt(const Punkt& pkt) {
		x = pkt.getX();
		y = pkt.getY();
		std::cout << "Nowy punkt zostal stworzony przy uzywcu punktu";
		pkt.show_pkt();
	}

	~Punkt() {
		std::cout << "Punkt ";
		show_pkt();
		std::cout << " zostal zniszczony\n";
	}
};


int main() {
	auto p1 = Punkt(1, 2);
	auto p2 = Punkt(5, 3);
	
	//std::cout << "Wspolrzedne punktu 1 to (" << p1.x << "," << p1.y << ")\n";
	//std::cout << "Wspolrzedne punktu 2 to (" << p2.x << "," << p2.y << ")\n";

	p1.show();
	p2.show();

	std::cout << "Wspolrzedna x pkt 1 = " << p1.getX() << "\n";
	std::cout << "Wspolrzedna y pkt 1 = " << p1.getY() << "\n";

	std::cout << "Wspolrzedna x pkt 2 = " << p2.getX() << "\n";
	std::cout << "Wspolrzedna y pkt 2 = " << p2.getY() << "\n";


	p1.setXY(2, 7);
	p1.show_pkt();
	std::cout << "\n";


	p2.setXY(Punkt(8, 5));
	p2.show_pkt();
	std::cout << "\n";


	p1.getXY().show_pkt();
	std::cout << "\n";


	auto p3 = Punkt(p2);
	p3.show_pkt();
	std::cout << "\n";

	return 0;
}