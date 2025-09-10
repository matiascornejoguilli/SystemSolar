#include <iostream>
#include <string>
#include <vector>



template <typename T>
struct Vector 
{
    T x = 0;
    T y = 0;

    Vector<T> operator+(const Vector<T>& other) const 
    {
        return {x + other.x, y + other.y};
    }

    Vector<T> operator-(const Vector<T>& other) const 
    {
        return {x - other.x, y - other.y};
    }

    Vector<T> operator*(T other) const 
    {
        return {x * other, y * other};
    }

     Vector<T> operator/(T other) const 
    {
        return {x / other, y / other};
    }

};

using Vec = Vector<double>;
    
struct Body 
{
    std::string name;
    double mass;       
    Vec position;  
    Vec velocity;  
};

// Constante gravitacional
const double G = 6.67430e-11;

Vec gravityForce(const Body& a, const Body& b)
{
    //vector diference a to b
    Vec diff= b.position - a.position;

    //distance
    double dist = std::sqrt(diff.x * diff.x + diff.y * diff.y);

    // TODO: calcular distancia y normalizar vector
    Vec unit = diff * (1.0 / dist);
    // TODO: aplicar fórmula de Newton: F = G * m1 * m2 / r^2
    double forceMag= G*((a.mass * b.mass)) / (dist * dist);
    // TODO: devolver fuerza como vector
    return unit * forceMag;
}

int main() 
{
    Body sun{"Sol", 1.99e30, {0, 0}, {0, 0}};
    Body earth{"Tierra", 5.97e24, {1.5e11, 0}, {0, 29780}}; // 29.78 km/s

    Vec force = gravityForce(sun, earth);

    std::cout << "Fuerza sobre la Tierra debido al Sol: (" << force.x << ", " << force.y << ") N\n";

    return 0;
}