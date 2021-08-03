#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void hex(int v);
void oct(int v);

int main(){
    int v;
    cout << "Digite um numero Decimal: ";
    cin >> v;
    hex(v);
    oct(v);
    return 0;
}

void hex(int v){
    int i=0, hex=16, x=-1;
    int resto[10];
    int devi[10];
    //Calculo
    while ( true){
        resto[i] = floor(v%hex);
        devi[i] = floor(v/hex);
        if (devi[i] != 1){
            v = devi[i];
        }
        //cout << devi[i] << "-" << resto[i] << endl; //Para debugar
        if(devi[i] == 1 or (resto[i] >= 10 and resto[i] <= 15 and devi[i] <= 9)){
            break;
            i++;  
        }
        if(devi[i] <16 and resto[i]<16 ) {
            break;
        }
        i++;
        
    }  
    //vars para as letras
    string re[10];
    string di[10];
    cout << "Em Hex: ";
    //Laço mal feito para substituição
    while (x <= i){
        x++;  
        int t = resto[x];
        if (t < 10){
            re[x] = to_string(t);
        }else{
            switch(t){
                case 10:
                    re[x] = "a";
                    break; 
                case 11:
                    re[x] = "b";
                    break;
                case 12:
                    re[x] = "c";
                    break;
                case 13:
                    re[x] = "d";
                    break;
                case 14:
                    re[x] = "e";
                    break;
                case 15:
                    re[x] = "f";
                    break;
            }
        }
        int te = devi[x];
        if (te < 10){
            di[x] = to_string(te);
        }else {
            switch(te){
                case 10:
                    di[x] = "a";
                    break; 
                case 11:
                    di[x] = "b";
                    break;
                case 12:
                    di[x] = "c";
                    break;
                case 13:
                    di[x] = "d";
                    break;
                case 14:
                    di[x] = "e";
                    break;
                case 15:
                    di[x] = "f";
                    break;
            }
        }
        //Bypass para possiveis bugs e imprimi o ultimo quociente
        if( di[x] == "0" or di[x] == "-1"){
            break;
        }else if( di[x] == "-858993606" ){
            cout  << "";
        }else{
            cout << di[x];
        }
    }
    //Imprime os restos
    for (x=i;x>0;x--){
        cout << re[x];
    }
    cout << re[0] << endl;     
}

void oct(int v){
    int resto[10], devi[10], oct=8, x=0;
    //Calculo
    while(true){
        if ( v <= 7){
            cout << v << endl;
            exit(1);
        }
        devi[x] = floor(v/oct);
        resto[x] = fmod(v,oct);
        //cout << devi[x] << "-" << resto[x] << endl; //Para debugar
        if (devi[x] > 7){
            v = devi[x];
        }else{
            break;
        }
        x++;
        
    }
    cout  << "Em Octal: " << devi[x];
    for (int i=x;i>0;i--){
        cout   << resto[i];
    }
    cout << resto[0] << endl;
}