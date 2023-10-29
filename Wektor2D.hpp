class Wektor2D {
private:
    double x;
    double y;

public:
    Wektor2D()
    {
        x=0;
        y=0;
        // ++num_wek;

    }
    Wektor2D(double a, double b) : x(a), y(b) 
    {
        cout << "Współrzędne wektora = "<< x << ", "<< y << "\n";
    }
    ~Wektor2D() {
        cout << "Dekonstruktor, współrzędne wektora = "<< x << ", "<< y <<"\n";
    }

    // static int populacja() {
    //     return num_wek;
    // }
    void setX(double val) {
        x = val;
    }

    void setY(double val) {
        y = val;
    }
    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

    double norm() {
        return sqrt(x * x + y * y);
    }

    void print() {
        cout << "Współrzędne wektora = " << x << ", " << y << ")\n";
    }
    Wektor2D operator+(Wektor2D &w1)
    {   
        Wektor2D wynik;
        wynik.x = x + w1.x;
        wynik.y = y + w1.y;
        return wynik;
    }
    double operator*(Wektor2D &w1)
    {
        Wektor2D wynik;
        wynik.x = x * w1.x;
        wynik.y = y * w1.y;
        double wyn =  wynik.getX() + wynik.getX();
        return wyn;
    }
};
