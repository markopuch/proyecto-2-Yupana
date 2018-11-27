//
// Created by Marko  Puchuri on 11/27/18.
//

#include "Yupana.h"
Yupana::Yupana() {
    for(int i=0;i<para;i++){
        for(int j=0;j<para;j++) {
            matriz[i][j] = 0;
        }
    }
}

Yupana::Yupana(int pvalor) {
    valor=pvalor;

    for(int i=0;i<para;i++){
        for(int j=0;j<para;j++) {
            matriz[i][j] = 0;
        }
    }
    reparticion_de_valores();
}

void Yupana::reparticion_de_valores() {

    int M,R=valor;
    for(int i=para-1;i>=0;i--){
        int k=pow(10,i);
        M= R/k;
        R= R%k;
        if(M==1){
            matriz[3-i][0]++;
        }
        if(M==2){
            matriz[3-i][1]++;
        }
        if(M==3 or M==4){
            int rest= M-3;
            matriz[3-i][2]++;
            (rest==1)?matriz[3-i][0]++:0;
        }
        if(4<M and M<10){
            int rest=M-5;
            matriz[3-i][3]++;

            if(rest==1){
                matriz[3-i][0]++;
            }
            if(rest==2){
                matriz[3-i][1]++;
            }
            if(rest==3 or rest==4){
                int rest2= rest-3;
                matriz[3-i][2]++;
                (rest2==1)?matriz[3-i][0]++:0;
            }
        }

    }


}

void Yupana::imprimir_yupa() {

    for(int i=0;i<para;i++){
        for(int j=0;j<para;j++) {
            std::cout<<std::setw(2)<<matriz[i][j];
        }
        std::cout<<std::endl;
    }

}

int Yupana::getValor() const {
    return valor;
}

void Yupana::setValor(int valor) {
    Yupana::valor = valor;
}

int Yupana::entrega_denum() {
    int num=0;
    for(int i=3;i>=0;i--) {
        int k=pow(10,3-i);
        num=num+(matriz[i][0] + matriz[i][1] * 2 + matriz[i][2] * 3 + matriz[i][3] * 5)*k;
    }
    return num;

}

void Yupana::distribuicion_columna() {
    for(int i=3;i>=0;i--){
        int v=matriz[i][0],R=v%5,C=v/5;
        matriz[i][0] = 0;

        if(R==1){
            matriz[i][0]++;
        }
        if(R==2){
            matriz[i][1]++;
        }
        if(R==3 or R==4){
            matriz[i][2]++;
            int rest= R-3;
            (rest==1)?matriz[i][0]++:0;
        }

        matriz[i][3]=C;

        while(1<C){
            matriz[i-1][0]++;
            C=C-2;
            matriz[i][3]=C;
        }

    }

}

Yupana Yupana::suma(Yupana px) {

    Yupana resul;
    for(int i=0;i<para;i++){
        for(int j=0;j<para;j++) {
            resul.matriz[i][j]=matriz[i][j]+px.matriz[i][j];
        }
    }


    for(int i=0;i<para;i++) {
        resul.matriz[i][0] =resul.matriz[i][0] + resul.matriz[i][1] * 2 + resul.matriz[i][2] * 3 + resul.matriz[i][3] * 5;
        for(int j=1;j<para;j++){
            resul.matriz[i][j]=0;
        }
    }

    resul.distribuicion_columna();
    resul.imprimir_yupa();


    return resul;

}

Yupana Yupana::resta(Yupana px) {
    //el que esta en el parametro siempre es menor
    Yupana resul;
    for(int i=0;i<para;i++){
        for(int j=0;j<para;j++) {
            resul.matriz[i][j]=matriz[i][j]-px.matriz[i][j];
        }
    }

    for(int i=0;i<para;i++) {
        resul.matriz[i][0] =resul.matriz[i][0] + resul.matriz[i][1] * 2 + resul.matriz[i][2] * 3 + resul.matriz[i][3] * 5;
        for(int j=1;j<para;j++){
            resul.matriz[i][j]=0;
        }
    }

    for(int i=3;i>=0;i--){
        (resul.matriz[i][0]<0)?resul.matriz[i][0]=resul.matriz[i][0]+10,resul.matriz[i-1][0]=resul.matriz[i-1][0]-1 :0;

    }

    resul.distribuicion_columna();
    resul.imprimir_yupa();

    return resul;
}


Yupana Yupana::multiplicacion(int a) {
    Yupana acu= Yupana(valor);
    Yupana result;
    for(int i=0;i<a;i++){
        result= result.suma(acu);
    }
    return result;
}