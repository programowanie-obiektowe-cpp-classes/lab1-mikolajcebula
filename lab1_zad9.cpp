#include <iostream>
#include <cmath>

class Wektor2D {
private:
    double x;
    double y;
    static int num_wek;

    // Prywatny konstruktor
    Wektor2D(double x_val, double y_val) : x(x_val), y(y_val) {
        std::cout << "Wektor2D(" << x << ", " << y << ") - Konstruktor (kartezjańskie)\n";
        ++num_wek; // Zwiększ liczbę istniejących wektorów
    }

public:
    // Statyczna metoda do tworzenia wektora na podstawie współrzędnych kartezjańskich
    static Wektor2D kart(double x_val, double y_val) {
        return Wektor2D(x_val, y_val);
    }

    // Statyczna metoda do tworzenia wektora na podstawie współrzędnych biegunowych
    static Wektor2D bieg(double r, double theta) {
        double x_val = r * std::cos(theta);
        double y_val = r * std::sin(theta);
        return Wektor2D(x_val, y_val);
    }

    // Przeciążenie operatora dodawania
    Wektor2D operator+(const Wektor2D& other) const {
        return Wektor2D(x + other.x, y + other.y);
    }

    // Przeciążenie operatora mnożenia przez skalar
    Wektor2D operator*(double scalar) const {
        return Wektor2D(x * scalar, y * scalar);
    }

    // Przeciążenie operatora <<
    friend std::ostream& operator<<(std::ostream& os, const Wektor2D& wektor) {
        os << "Wektor2D(" << wektor.x << ", " << wektor.y << ")";
        return os;
    }

    // Metoda do obliczania normy wektora
    double norm() const {
        return std::sqrt(x * x + y * y);
    }

    // Destruktor
    ~Wektor2D() {
        std::cout << "Wektor2D(" << x << ", " << y << ") - Destruktor\n";
        --num_wek; // Zmniejsz liczbę istniejących wektorów
    }

    // Statyczna metoda zwracająca liczbę istniejących wektorów
    static int populacja() {
        return num_wek;
    }
};

// Inicjalizacja statycznego pola num_wek
int Wektor2D::num_wek = 0;

int main() {
    {
        // Tworzenie wektorów za pomocą metod statycznych
        Wektor2D wektor1 = Wektor2D::kart(1.0, 2.0);
        Wektor2D wektor2 = Wektor2D::bieg(2.0, M_PI / 3.0); // 2.0 i M_PI/3.0 to r i theta w układzie biegunowym

        // Przeciążenie operatora dodawania
        Wektor2D suma = wektor1 + wektor2;

        // Wyświetlanie wyników
        std::cout << "Wektor1: " << wektor1 << "\n";
        std::cout << "Wektor2: " << wektor2 << "\n";
        std::cout << "Suma: " << suma << "\n";

        // Wyświetlanie liczby istniejących wektorów
        std::cout << "Liczba istniejących wektorów w zagnieżdżonym scope: " << Wektor2D::populacja() << "\n";
    }

    // Wyświetlanie liczby istniejących wektorów po opuszczeniu zagnieżdżonego scope
    std::cout << "Liczba istniejących wektorów po opuszczeniu zagnieżdżonego scope: " << Wektor2D::populacja() << "\n";

    return 0;
}
