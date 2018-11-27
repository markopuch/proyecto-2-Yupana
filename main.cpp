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
    Yupana a1=Yupana(5969);
    Yupana a2=Yupana(3208);
    std::cout<<a1+a2<<std::endl;








    return 0;
}
