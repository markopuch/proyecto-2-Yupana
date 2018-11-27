#include "Yupana.h"

int operator +(Yupana lhs, Yupana rhs) {
    Yupana resul = lhs.suma(rhs);
    resul.imprimir_yupa();
    return resul.entrega_denum();
}

int operator *(Yupana lhs, int a) {
    Yupana resul = lhs.multiplicacion(a);
    resul.imprimir_yupa();
    return resul.entrega_denum();
}


int main() {
    std::cout<<"YUPANA\n";
    Yupana a1=Yupana(3485);
    a1.imprimir_yupa();
    std::cout<<std::endl;

    Yupana a2=Yupana(2199);
    a2.imprimir_yupa();
    std::cout<<std::endl;

    a1.resta(a2);








    return 0;
}
