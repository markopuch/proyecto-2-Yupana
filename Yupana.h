//
// Created by Marko  Puchuri on 11/27/18.
//

#ifndef PROYECTO2REAL_YUPANA_H
#define PROYECTO2REAL_YUPANA_H

#include <iostream>
#include <cmath>
#include <iomanip>

const int para=4;

class Yupana {
private:
    int valor;
public:
    int matriz[para][para];
    int getValor() const;
    void setValor(int valor);

    Yupana();
    Yupana(int pvalor);
    void reparticion_de_valores();
    void imprimir_yupa();
    Yupana suma(Yupana px);
    int entrega_denum();
    Yupana resta(Yupana px);
    Yupana multiplicacion(int a);
    void distribuicion_columna();


};




#endif //PROYECTO2REAL_YUPANA_H
