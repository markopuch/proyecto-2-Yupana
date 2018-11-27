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
    Yupana a1=Yupana(2858);
    Yupana a2=Yupana(5716);
    std::cout<<a1*2<<std::endl;







    return 0;
}
