#include "vect2.hpp"
#include <iostream>

/*int main(void) {
    
    vect2 v1; // 0, 0
    vect2 v2(1, 2); // 1, 2
    const vect2 v3(v2); // 1, 2
    vect2 v4 = v2; // 1, 2

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;
    std::cout << "v4++: " << v4++ << std::endl; // 2, 3
    std::cout << "++v4: " << ++v4 << std::endl; // 3, 4
    std::cout << "v4--: " << v4-- << std::endl; // 2, 3
    std::cout << "--v4: " << --v4 << std::endl; // 1, 2
    // ver notes.txt
    
    v2 += v3; // 2,4
    std::cout << "v2: " << v2 << std::endl;
    v1 -= v2; // -2, -4
    std::cout << "v1: " << v1 << std::endl;
    v2 = v3 + v3 * 2; // 3, 6
    v2 = 3 * v2; // 9, 18
    v2 += v2 += v3; // 20, 40
    std::cout << "v2: " << v2 << std::endl;
    v1 *= 42; // -84, -168
    std::cout << "v1: " << v1 << std::endl;
    v1 = v1 - v1 + v1;
    std::cout << "v1: " << v1 << std::endl;

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "-v2: " << -v2 << std::endl;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    v1[1] = 12;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "v3[1]: " << v3[1] << std::endl;
    std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl;
    return 0;
}*/

#include <iostream>
#include "vect2.hpp"

int main(void) {
    vect2 a(1, 2);
    vect2 b(3, 4);
    vect2 c;

    std::cout << "== Teste de operadores aritmeticos ==" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;

    std::cout << "\n== Operações com inteiros ==" << std::endl;
    std::cout << "a + 2 = " << a + 2 << std::endl;
    std::cout << "a - 2 = " << a - 2 << std::endl;
    std::cout << "a * 2 = " << a * 2 << std::endl;
    std::cout << "2 * a = " << 2 * a << std::endl;

    std::cout << "\n== Operadores compostos ==" << std::endl;
    c = a;
    c += b;
    std::cout << "c += b -> " << c << std::endl;
    c -= 1;
    std::cout << "c -= 1 -> " << c << std::endl;
    c *= 2;
    std::cout << "c *= 2 -> " << c << std::endl;

    std::cout << "\n== Incremento e decremento ==" << std::endl;
    c = a;
    std::cout << "++c = " << ++c << std::endl;
    std::cout << "c++ = " << c++ << " (valor antes)" << std::endl;
    std::cout << "c depois do c++ = " << c << std::endl;
    std::cout << "--c = " << --c << std::endl;
    std::cout << "c-- = " << c-- << " (valor antes)" << std::endl;
    std::cout << "c depois do c-- = " << c << std::endl;

    std::cout << "\n== Operador unário -" << std::endl;
    vect2 d = -a;
    std::cout << "-a = " << d << std::endl;
    std::cout << "a ainda é = " << a << std::endl; // deve continuar (1, 2)

    std::cout << "\n== Operadores de comparação ==" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "a == b ? " << (a == b) << std::endl;
    std::cout << "a != b ? " << (a != b) << std::endl;
    vect2 e(1, 2);
    std::cout << "a == e ? " << (a == e) << std::endl;

    std::cout << "\n== Acesso por índice ==" << std::endl;
    std::cout << "a[0] = " << a[0] << ", a[1] = " << a[1] << std::endl;
    a[0] = 10;
    a[1] = 20;
    std::cout << "a modificado: " << a << std::endl;

    return 0;
}
