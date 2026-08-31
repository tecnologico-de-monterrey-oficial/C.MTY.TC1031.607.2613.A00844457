
//Allison Charlize Arriaza 
//A00844457

// =========================================== Ejercicio 2 =============================================
#include <iostream>
#include <string>

using namespace std; 



int pedirNStr(){
    int n; 
    cout<<"Cuantos strings desea ingresar? ";
    cin >> n;

    return n;
}

char repeatSeq(string repeatedList, int &comparacion){
    int seqComp = 0; 
    
    for (int i = 0; i<repeatedList.size() -1; i+=2){
        seqComp ++;

        if (repeatedList[i] != repeatedList[i + 1]){
            comparacion = seqComp;
            return repeatedList[i];


        }

    }
    comparacion = seqComp;
    return repeatedList[repeatedList.size() - 1];



}

char repeatedBin (string repeatedList, int & comparacion){
    int compBin = 0; 
    int compStart = 0;
    int compEnd = repeatedList.size() - 1;
    int compMiddle ;

    while (compStart<compEnd){
        compMiddle = (compStart + compEnd)/2;
        compBin ++;

        bool binIzq = (compMiddle == 0 || repeatedList[compMiddle] != repeatedList[compMiddle - 1]); 
        bool binDer = (compMiddle == repeatedList.size() - 1 || repeatedList[compMiddle] != repeatedList[compMiddle + 1]);


        if (binIzq && binDer){
             comparacion = compBin; return repeatedList[compMiddle];
        }



        if (compMiddle % 2 == 0){

            if (repeatedList[compMiddle] == repeatedList[compMiddle + 1]){
                compStart = compMiddle + 1;
                
            } else {
                compEnd = compMiddle -1;

            }

        } else {
                if (repeatedList[compMiddle] == repeatedList[compMiddle - 1]){
                    compStart = compMiddle + 1;
                }
                else{
                    compEnd = compMiddle - 1;
                }

        }



            
    } 

    comparacion = compBin;
    return repeatedList[compStart];
      
}


int main(){
    int n = pedirNStr();

   for (int i = 0; i<n; i++){
    string cadena;
    cout<<"Ingrese la cadena de caracteres "<< i + 1<< " : ";
    cin>> cadena; 

    int compSeq =0;
    int compBin = 0;

    char resultSeq = repeatSeq(cadena, compSeq);
    char resultBin = repeatedBin(cadena, compBin);

    cout << resultSeq << " " << compSeq << " "
        << resultBin << " " << compBin << endl;


   }

    return 0;
}