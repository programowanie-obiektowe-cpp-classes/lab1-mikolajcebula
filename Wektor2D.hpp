class Wektor2D
{
   private:
    double x;
    double y;
    static int num_wek;

public:
    Wektor2D() : x(0.0), y(0.0) {
        ++num_wek;
    }

    Wektor2D(double val1, double val2, bool polar = false) {
        ++num_wek;
        if (polar) {
            x = val1 * cos(val2);
            y = val1 * sin(val2);
        } else {
            x = val1;
            y = val2;
        }
    }

    ~Wektor2D() {
        --num_wek;
    }

    static int populacja() {
        return num_wek;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double norm() const {
        return sqrt(x * x + y * y);
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }

    Wektor2D operator+(const Wektor2D& other) const {
        return Wektor2D(x + other.x, y + other.y);
    }

    Wektor2D operator*(double scalar) const {
        return Wektor2D(x * scalar, y * scalar);
    }

    friend std::ostream& operator<<(std::ostream& os, const Wektor2D& wektor) {
        os << "(" << wektor.x << ", " << wektor.y << ")";
        return os;
    }

    void setX(double val) {
        x = val;
    }

    void setY(double val) {
        y = val;
    }
};
