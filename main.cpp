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

int operator -(Yupana lhs, Yupana rhs) {
    Yupana resul = lhs.resta(rhs);
    resul.imprimir_yupa();
    return resul.entrega_denum();
}


int main() {
    std::cout<<"YUPANA\n";
    Yupana a1=Yupana(3485);

    Yupana a2=Yupana(2199);

    std::cout<<a1+a2;
    std::cout<<std::endl;
    std::cout<<a1-a2;
    std::cout<<std::endl;
    std::cout<<a1*2;
    std::cout<<std::endl;
    std::cout<<(a1+a2)-(a1-a2);
    std::cout<<std::endl;


    return 0;
}
