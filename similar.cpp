#include <iostream>
using std::pair;
using std::string;
template <typename T>
using ppair = pair<pair<T, T>, pair<T, T>>;

bool similar(ppair<float> in) {
	float k1 = in.first.first / in.first.second;
	float k2 = in.second.first / in.second.second;
	return k1 == k2;
}
ppair<float> isto(pair<float,float> xy, pair<float,float> ab) {
	bool swap = false;
	if ( ab.first == 0 ){
		swap = true;
		std::swap(xy.first, xy.second);
		std::swap(ab.first, ab.second);
	}
	float k = xy.second / xy.first;
	ab.second = ab.first * k;
	if ( swap ) {
		std::swap(xy.first, xy.second);
		std::swap(ab.first, ab.second);
	}

	ppair<float> fin(xy, ab);
	return fin;
}
void printit(ppair<float> in) {
	std::cout << "(" << in.first.first << ":" << in.first.second << ") = (" << in.second.first << ":" << in.second.second << ")\n";
}
int main() {
	std::cout << "Similarity Calculator" << std::endl << "X and Y are known, A or B are not. type 0 for the unknown." << std::endl << "(c) Samiyel D Frazier, 2024\n\n\n";
	while ( 1 ) {
		float x, y, a, b;
		std::cout << "\nX: ";
		std::cin >> x;
		std::cout << "is to Y: ";
		std::cin >> y;
		std::cout << "as A: ";
		std::cin >> a;
		std::cout << "is to B: ";
		std::cin >> b;

		std::cout << "do you know if they're similar? (y/n): ";
		bool sim = false;
		string ans;
		std::cin >> ans;
		if ( ans == "y"  || ans == "Y" ) {
			sim = true;
		}
		pair<float, float> XY(x, y);
		pair<float, float> AB(a, b);
		if ( sim ) {
			auto out = isto(XY,AB);
			printit(out);
		}
		else {
			sim = similar(ppair<float>(XY, AB));
			if ( sim ) {
				std::cout << "they are similar\n";
			}
			else {
				std::cout << "they are not similar\n";
			}
		}
	}
	return 0;
}