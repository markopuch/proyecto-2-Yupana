//
// Created by Marko  Puchuri on 11/24/18.
//

#include "funciones.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iomanip>
using namespace std;
string horarios(char curso){
    string a;
        if(curso=='E'){
            a="horarios disponibles sugeridos:\n"
              "E.discretas 1 1 seccion 1 lu 9-11, ju 7-9 and vi 11-13 \n"
              "E.discretas 1 seccion 2 lu 13-15, mi 15-17 and vi 15-17 \n"
              "cual desea(seccion 1=1, seccion 2 =2, borrar curso=-1 or niguno= 0 )\n";
            return a;
        }
        if(curso=='M'){
            a="horarios disponibles sugeridos:\n"
              "Matematica 1 seccion 1 lu 11-13, mi 9-11 and vi 13-15 \n"
              "Matematica 1 seccion 2 lu 13-15, mi 15-17 and vi 15-17 \n"
              "cual desea(seccion 1=1, seccion 2 =2, borrar curso=-1 or niguno= 0 )\n";
            return a;
        }
        if(curso=='F'){
            a="horarios disponibles sugeridos:\n "
              "FISICA 1 seccion 1 lu 7-9 and mi 7-9 \n "
              "FISICA 1 seccion 2 ma 17-19 and mi 17-19 \n "
              "cual desea(seccion 1=1, seccion 2 =2, borrar curso=-1 or niguno= 0 )\n";
            return a;
        }
        if(curso=='I'){
            a="horarios disponibles sugeridos:\n"
              "ICC seccion 1 ma 7-9 and mi 15-17 \n"
              "ICC seccion 2 mi 9-11 and vi 9-11\n"
              "ICC seccion 3 ma 17-19 and ju 17-19 \n"
              "ICC seccion 4 lu 13-15 and vi 13-15 \n"
              "ICC seccion 5 lu 11-13 and vi 19-21 \n"
              "ICC seccion 6 ma 15-17 and vi 15-17 \n"
              "cual desea(seccion 1=1, seccion 2 =2, seccion 3=3, seccion 4=4, seccion 5=5, seccion 6=6, borrar curso=-1 or niguno= 0 )\n";
            return a;
        }
        if(curso=='D'){
            a="horarios disponibles sugeridos:\n"
              "DESAFIOS G. seccion 1 ma 17-19 \n"
              "DESAFIOS G. seccion 2 lu 15-17 \n"
              "DESAFIOS G. seccion 3 mi 13-15 \n"
              "DESAFIOS G. seccion 4 vi 09-11 \n"
              "cual desea(seccion 1=1, seccion 2 =2, seccion 3=3, seccion 4=4, borrar curso=-1 or niguno= 0 )\n";
            return a;
        }
        if(curso=='L'){
            a="horarios disponibles sugeridos:\n"
              "Lab com 1 seccion 1 mar 7-9 and ju 11-13 \n"
              "Lab com 1 seccion 2 mar 7-9 and ju 7-9 \n"
              "Lab com 1 seccion 3 mi 17-19 and vi 13-15 \n"
              "Lab com 1 seccion 4 lu 15-16 and vi 9-11 \n"
              "Lab com 1 seccion 5 ma 11-13 and mi 15-17 \n"
              "cual desea(seccion 1=1, seccion 2 =2, seccion 3=3, seccion 4=4, seccion 5=5, borrar curso=-1 or niguno= 0 )\n";
            return a;
        }
        if(curso=='Q'){
            a="horarios disponibles sugeridos:\n"
              "Quimica General seccion 1 ma 17-19 \n"
              "Quimica General seccion 2 lu 15-17 \n"
              "Quimica General seccion 3 mi 15-17\n"
              "Quimica General seccion 4 mi 13-15 \n"
              "cual desea(seccion 1=1, seccion 2 =2, seccion 3=3, seccion 4=4, borrar curso=-1 or niguno= 0 )\n";
            return a;
        }

}
void horario(){
        string horario[8][5]={{"        LUNES         ","        MARTES        ","       MIERCOLES      ","       JUEVES         ","        VIERNES       "},//dias
                              {"Fisica-1              ","                      ","Fisica-1              ","E.Discretas-1         ","                      "},//7-9
                              {"E.discretas-1         ","                      ","Matematica-1          ","                      ","                      "},//9-11
                              {"Matematica-1          ","LabCom-1              ","                      ","                      ","E.Discretas-1         "},//11-13
                              {"                      ","                      ","Desafios-Globales     ","                      ","Matematica-1          "},//13-15
                              {"Quimica               ","Icc                   ","LabCom-1              ","                      ","Icc                   "},//15-17
                              {"                      ","                      ","                      ","                      ","                      "},//17-19
                              {"                      ","                      ","                      ","                      ","                      "}};//19-21
        imprimir(horario);
        int resp;//para entrar al loop
        do {
            cout << "quieres cambiar el horario propuesto?(1=si or 0=no)\n";//pregunta si deseas cambiar
            resp=inden();
            if (resp == 0)break;//si tu respuesta es no se sale del loop
            if (resp != 1) { cout << "valor incorrecto.. ingrese otra vez\n"; }
            else {
                cout << "que curso deseas cambiar?(escriba el curso con el nombre que se ve en el horario): \n";
                string curso;
                cin >> curso;//se ingresa el curso a cambiar
                //E. discretas 1
                if (toupper(curso[0])=='E'){
                    int cambio;
                    //comunicando los cursos disponibles
                    do{
                        cout<<horarios(toupper(curso[0]));
                        cambio=inden();// opcion
                        if(cambio==0)break;
                        if(cambio==-1){eliminacion(curso,horario);imprimir(horario);}
                        if(cambio==1){
                            char muestra = horario[2][0][0];
                            char muestra2 = horario[1][3][0];
                            char muestra3 = horario[3][4][0];

                            int valor = int(muestra);
                            int valor2 = int(muestra2);
                            int valor3 = int(muestra3);
                            if (valor < 90 && valor > 64 && muestra != toupper(curso[0]))
                                cout << "conflicto" << endl;
                            else {
                                if (valor2 < 90 && valor2 > 64 && muestra2 != toupper(curso[0]))
                                    cout << "conflicto" << endl;
                                else {
                                    if (valor3 < 90 && valor3 > 64 && muestra3 != toupper(curso[0]))
                                        cout << "conflicto" << endl;
                                    else {
                                        eliminacion(curso, horario);
                                        horario[2][0] = "E.Discrestas-1       ";
                                        horario[1][3] = "E.Discrestas-1       ";
                                        horario[3][4] = "E.Discrestas-1       ";
                                        cout << "Se cambio exitosamente tu horario\n";
                                        imprimir(horario);

                                    }
                                }
                            }
                        }
                        if(cambio==2){
                            char muestra = horario[4][0][0];
                            char muestra2 = horario[5][2][0];
                            char muestra3 = horario[5][4][0];

                            int valor = int(muestra);
                            int valor2 = int(muestra2);
                            int valor3 = int(muestra3);
                            if (valor < 90 && valor > 64 && muestra != toupper(curso[0]))
                                cout << "conflicto" << endl;
                            else {
                                if (valor2 < 90 && valor2 > 64 && muestra2 != toupper(curso[0]))
                                    cout << "conflicto" << endl;
                                else {
                                    if (valor3 < 90 && valor3 > 64 && muestra3 != toupper(curso[0]))
                                        cout << "conflicto" << endl;
                                    else {
                                        eliminacion(curso, horario);
                                        horario[4][0] = "E.Discrestas-2       ";
                                        horario[5][2] = "E.Discrestas-2       ";
                                        horario[5][4] = "E.Discrestas-2       ";
                                        cout << "Se cambio exitosamente tu horario\n";
                                        imprimir(horario);

                                    }
                                }
                            }
                        }
                    }while(cambio!=0);
                }
                //fisica 1
                if (toupper(curso[0])=='F'){
                    int cambio;
                    //comunicando los cursos disponibles
                    do{
                        cout<<horarios(toupper(curso[0]));
                        cambio=inden();// opcion
                        if(cambio==0)break;
                        if(cambio==-1){eliminacion(curso,horario);imprimir(horario);}
                        if(cambio==1){
                            char muestra = horario[1][0][0];
                            char muestra2=horario[1][2][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[1][0]="Fisica-1              ";
                                    horario[1][2]="Fisica-1              ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }
                        }
                        if(cambio==2){
                            char muestra = horario[6][1][0];
                            char muestra2=horario[6][2][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[6][1]="Fisica-1              ";
                                    horario[6][2]="Fisica-1              ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }
                        }
                    }while(cambio!=0);

                }
                //Mate 1
                if (toupper(curso[0])=='M'){
                    int cambio;
                    //comunicando los cursos disponibles
                    do{
                        cout<<horarios(toupper(curso[0]));
                        cambio=inden();// opcion
                        if(cambio==0)break;
                        if(cambio==-1){eliminacion(curso,horario);imprimir(horario);}
                        if(cambio==1){
                            char muestra = horario[3][0][0];
                            char muestra2= horario[2][2][0];
                            char muestra3= horario[4][4][0];

                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            int valor3=int(muestra3);

                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    if(valor3<90 && valor3>64 && muestra3!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                    else{
                                        eliminacion(curso,horario);//se elimina en toda la matriz el curso elegido
                                        horario[3][0]="Matematica-1          ";
                                        horario[2][2]="Matematica-1          ";
                                        horario[4][4]="Matematica-1          ";
                                        cout<<"Se cambio exitosamente tu horario\n";
                                        imprimir(horario);
                                    }
                                }
                            }
                        }
                        if(cambio==2){
                            char muestra = horario[4][0][0];
                            char muestra2= horario[5][2][0];
                            char muestra3= horario[5][4][0];

                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            int valor3=int(muestra3);

                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    if(valor3<90 && valor3>64 && muestra3!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                    else{
                                        eliminacion(curso,horario);//se elimina en toda la matriz el curso elegido
                                        horario[4][0]="Matematica-1          ";
                                        horario[5][2]="Matematica-1          ";
                                        horario[5][4]="Matematica-1          ";
                                        cout<<"Se cambio exitosamente tu horario\n";
                                        imprimir(horario);
                                    }
                                }
                            }
                        }

                    }while(cambio!=0);

                }
                //quimica general
                if (toupper(curso[0])=='Q'){
                    int cambio;
                    //comunicando los cursos disponibles
                    do{
                        cout<<horarios(toupper(curso[0]));
                        cambio=inden();// opcion
                        if(cambio==0)break;
                        if(cambio==-1){eliminacion(curso,horario);imprimir(horario);}
                        if(cambio==1){
                            char muestra = horario[6][1][0];
                            int valor = int(muestra);

                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else {
                                eliminacion(curso, horario);//se elimina en toda la matriz el curso elegido
                                horario[6][1] = "Quimica               ";
                                cout << "Se cambio exitosamente tu horario\n";
                                imprimir(horario);
                            }
                        }
                        if(cambio==2){
                            char muestra = horario[5][0][0];
                            int valor = int(muestra);

                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                eliminacion(curso,horario);//se elimina en toda la matriz el curso elegido
                                horario[5][0]="Quimica               ";
                                cout<<"Se cambio exitosamente tu horario\n";
                                imprimir(horario);
                            }
                        }
                        if(cambio==3){
                            char muestra = horario[5][2][0];
                            int valor = int(muestra);

                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                eliminacion(curso,horario);//se elimina en toda la matriz el curso elegido
                                horario[5][2]="Quimica               ";
                                cout<<"Se cambio exitosamente tu horario\n";
                                imprimir(horario);
                            }
                        }
                        if(cambio==4){
                            char muestra = horario[4][2][0];
                            int valor = int(muestra);

                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                eliminacion(curso,horario);//se elimina en toda la matriz el curso elegido
                                horario[4][2]="Quimica               ";
                                cout<<"Se cambio exitosamente tu horario\n";
                                imprimir(horario);
                            }
                        }

                    }while(cambio!=0);

                }
                //desafios globales
                if (toupper(curso[0])=='D'){
                    int cambio;
                    //comunicando los cursos disponibles
                    do{
                        cout<<horarios(toupper(curso[0]));
                        cambio=inden();// opcion
                        if(cambio==0)break;
                        if(cambio==-1){eliminacion(curso,horario);imprimir(horario);}
                        if(cambio==1){
                            char muestra = horario[6][1][0];
                            int valor = int(muestra);

                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else {
                                eliminacion(curso, horario);//se elimina en toda la matriz el curso elegido
                                horario[6][1] = "Desafios-Globales     ";
                                cout << "Se cambio exitosamente tu horario\n";
                                imprimir(horario);
                            }
                        }
                        if(cambio==2){
                            char muestra = horario[5][0][0];

                            int valor = int(muestra);

                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                eliminacion(curso,horario);//se elimina en toda la matriz el curso elegido
                                horario[5][0]="Desafios-Globales     ";
                                cout<<"Se cambio exitosamente tu horario\n";
                                imprimir(horario);
                            }
                        }
                        if(cambio==3){
                            char muestra = horario[4][2][0];
                            int valor = int(muestra);

                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                eliminacion(curso,horario);//se elimina en toda la matriz el curso elegido
                                horario[4][2]="Desafios-Globales     ";
                                cout<<"Se cambio exitosamente tu horario\n";
                                imprimir(horario);
                            }
                        }
                        if(cambio==4){
                            char muestra = horario[2][4][0];
                            int valor = int(muestra);

                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                eliminacion(curso,horario);//se elimina en toda la matriz el curso elegido
                                horario[2][4]="Desafios-Globales     ";
                                cout<<"Se cambio exitosamente tu horario\n";
                                imprimir(horario);
                            }
                        }


                    }while(cambio!=0);

                }
                //ICC
                if (toupper(curso[0])=='I'){
                    int cambio;
                    //comunicando los cursos disponibles
                    do{
                        cout<<horarios(toupper(curso[0]));
                        cambio=inden();// opcion
                        if(cambio==0)break;
                        if(cambio==-1){eliminacion(curso,horario);imprimir(horario);}
                        if(cambio==1){
                            char muestra = horario[1][1][0];
                            char muestra2=horario[5][2][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[1][1]="Icc                   ";
                                    horario[5][2]="Icc                   ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }


                        }
                        if(cambio==2){

                            char muestra = horario[2][2][0];
                            char muestra2=horario[2][4][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[2][2]="Icc                   ";
                                    horario[2][4]="Icc                   ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }


                        }
                        if(cambio==3){
                            char muestra = horario[6][1][0];
                            char muestra2=horario[6][3][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[6][1]="Icc                   ";
                                    horario[6][3]="Icc                   ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }
                        }
                        if(cambio==4){
                            char muestra = horario[4][0][0];
                            char muestra2=horario[4][4][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[4][0]="Icc                   ";
                                    horario[4][4]="Icc                   ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }
                        }
                        if(cambio==5){
                            char muestra = horario[3][0][0];
                            char muestra2=horario[7][4][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[3][0]="Icc                   ";
                                    horario[7][4]="Icc                   ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }
                        }
                        if(cambio==6){
                            char muestra = horario[5][1][0];
                            char muestra2=horario[5][4][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[5][1]="Icc                   ";
                                    horario[5][4]="Icc                   ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }}

                    }while(cambio!=0);

                }
                //Lab com1
                if (toupper(curso[0])=='L'){
                    int cambio;
                    //comunicando los cursos disponibles
                    do{
                        cout<<horarios(toupper(curso[0]));
                        cambio=inden();// opcion
                        if(cambio==0)break;
                        if(cambio==-1){eliminacion(curso,horario);imprimir(horario);}
                        if(cambio==1){
                            char muestra = horario[1][1][0];
                            char muestra2=horario[3][3][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[1][1]="LabCom-2              ";
                                    horario[3][3]="LabCom-2              ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }
                        }
                        if(cambio==2){
                            char muestra = horario[1][1][0];
                            char muestra2=horario[1][3][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[1][1]="LabCom-2              ";
                                    horario[1][3]="LabCom-2              ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }
                        }
                        if(cambio==3){
                            char muestra = horario[6][2][0];
                            char muestra2=horario[4][4][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[6][2]="LabCom-2              ";
                                    horario[4][4]="LabCom-2              ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }
                        }
                        if(cambio==4){
                            char muestra = horario[5][0][0];
                            char muestra2=horario[2][4][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[5][0]="LabCom-2              ";
                                    horario[2][4]="LabCom-2              ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }
                        }
                        if(cambio==5){
                            char muestra = horario[3][1][0];
                            char muestra2=horario[5][2][0];
                            int valor = int(muestra);
                            int valor2=int(muestra2);
                            if(valor<90 && valor>64 && muestra!=toupper(curso[0]))cout<<"conflicto"<<endl;
                            else{
                                if(valor2<90 && valor2>64 && muestra2!=toupper(curso[0]))cout<<"conflicto"<<endl;
                                else{
                                    eliminacion(curso,horario);
                                    horario[2][2]="LabCom-2              ";
                                    horario[2][4]="LabCom-2              ";
                                    cout<<"Se cambio exitosamente tu horario\n";
                                    imprimir(horario);
                                }
                            }
                        }

                    }while(cambio!=0);

                }

            }
        }while(resp!=0);

        imprimir(horario);
        leerarch(horario);


}
int verif(string a,char answer){
    if(a.length()<2){
        if (toupper(a[0])<65 || toupper(a[0])>68 ) {
            return -1;
        } else {
            if (toupper(a[0])== answer) {
                return 1;
            }
            return 0;
        }
    }
    else {
        return -1;
    }

}
void imprimir(string horario[8][5]){
    for(int i=0;i<8;i++){
        if(i==0){cout<<"Dias: ";}
        if(i==1){cout<<"07-09 ";}
        if(i==2){cout<<"09-11 ";}
        if(i==3){cout<<"11-13 ";}
        if(i==4){cout<<"13-15 ";}
        if(i==5){cout<<"15-17 ";}
        if(i==6){cout<<"17-19 ";}
        if(i==7){cout<<"19-21 ";}
        for(int j=0;j<5;j++){

            cout<<setw(5)<<"|"<<horario[i][j]<<"|";
        }

        cout<<endl;
    }
}
void leerarch(string a[8][5]){
    ofstream archivo;
    archivo.open("/Users/markopuchuri/Desktop/horario.txt",ios::out);
    archivo<<"Tu horario es este:\n";
    for (int i=0;i<8;i++) {
        if(i==0){archivo<<"Dias: ";}
        if(i==1){archivo<<"07-09 ";}
        if(i==2){archivo<<"09-11 ";}
        if(i==3){archivo<<"11-13 ";}
        if(i==4){archivo<<"13-15 ";}
        if(i==5){archivo<<"15-17 ";}
        if(i==6){archivo<<"17-19 ";}
        if(i==7){archivo<<"19-21 ";}
        for (int j = 0; j < 5; j++) {
            archivo <<setw(5)<<"|"<< a[i][j] << "|"; // behaves like cout - cout is also a stream
        }
        archivo << "\n";
    }
    archivo.close();
}
int inden(){
        string num;

    while(true){
        cin>>num;
        if(num=="-1"){return -1;}
        if(num.length()>1){return -2;}
        for(int i=0; i<num.length();i++){
            if(toupper(num[i])>'A' && toupper(num[i])<'Z'){
                return -2;
            }
        }
        break;
    }
    int numv= int(num[0]-48);
    return numv;
}
void eliminacion(string curso, string matriz[8][5]){
    for (int y=1;y<8;y++){
        for(int x=0;x<5;x++){
            if (matriz[y][x][0]==toupper(curso[0])){
                matriz[y][x]= "                      ";
            }
        }
    }
}

