#include <iostream>
#include <fstream>
#include <iomanip>  // per poter scegliere le cifre decimali e il formato dell'output.

using namespace std;




int main() {
	
	// definisco le variabili che mi serviranno
	
	auto f = [](double x) {return 3.0/4.0 * x - 7.0/4.0;};
	double x;
	double mean;
	string lineafile;
	
	// apro il file data.txt
	
	ifstream filein("data.txt");
	
	
	if (filein.fail()) {
		cout<<"errore all'apertura del file"<<endl;
		return 1;
	}
	
	// creo il file output su cui scriverò le medie dei primi i termini
	
	ofstream fileout("result.txt");
	
	// se il file su cui voglio scrivere l'output si è creato correttamente,
	// leggo il file data.txt e riga per riga eseguo le seguenti operazioni:
	// coverto la riga dal formato String al formato Double (con il comando stod),
	// applico la trasformnazione lineare che manda [1,5] in [-1,2] al numero in questione,
	// salvo in mean la media di tutti i numeri fino a quello che sto leggendo,
	// scrivo mean sul file di output.
	
	if (fileout.is_open()){
		cout<<"file creato"<<endl;
	
		fileout<<"# N Mean"<<endl;
		int j = 0;
		double sum = 0;
		
		while (getline(filein, lineafile)) {
			
			j += 1;
			x = stod(lineafile);
			x = f(x);
			sum += x;
			mean = sum/j;
			fileout << j << scientific << setprecision(16) << " " << mean <<endl;
		}
		
	cout<<"file scritto"<<endl;	
	} else { cout<<"errore nella creazione del file"<<endl; }
	return 0;
}
