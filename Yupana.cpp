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
Yupana Yupana::suma(Yupana px) {
    Yupana resul=Yupana();
    for(int i=0;i<para;i++){
        for(int j=0;j<para;j++) {
            resul.matriz[i][j]=matriz[i][j]+px.matriz[i][j];
        }
    }



    return resul;

}

int Yupana::getValor() const {
    return valor;
}

void Yupana::setValor(int valor) {
    Yupana::valor = valor;
}
