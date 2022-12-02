#include <bits/stdc++.h>
#include <iomanip>
#include "matplotlibcpp.h" 
namespace plt = matplotlibcpp;
using namespace std;

int vector_size(vector <double> vctr){

	int length = 0;
	for (double element: vctr) length++;
	return length;

}

double interpolate(vector<double> X, vector<double> Y, int x_point, int n){

	double P, L;
	P = 0; 
	for (int i = 0; i < n; i++){ //loop P
		L = 1;
		for (int j = 0; j < n; j++){ // loop L
			if (i != j) L = L * (x_point - X[j]) / (X[i] - X[j]);
		}
		P += L * Y[i];
	}
	return P;

}

int main(){

	/*Jumlah data yang diketahui*/
	int N;
	cout << "Jumlah input data : ";
	cin >> N;
	
	/*1. input titik dan value sebanyak n kali*/
	vector<double> x0, y0;
	double in;
	cout << "\n1. Masukkan X (titik) dan Y (value) sebanyak " << N << " kali\n";
	for (int input = 0; input < N; input++){
		cout << "X" << " : ";cin >> in;
		x0.push_back(in);
		cout << "Y" << " : ";cin >> in;
		y0.push_back(in);
	}
	cout << "\nSet Data : \n";
	for (int i = 0; i < N; i++){
		cout << "(x" << i << ", y" << i << ") : ";
		cout << "(" << x0.at(i) << ", " << y0.at(i) << ")\n";
	}
	
	/*2. menampilkan list hasil interpolasi dari x[0] hingga x ke x[n]*/
	vector<double> x1, y1;
	double value = 0;
	for (int index = x0.at(0); index <= x0.at(N-1); index++){
		x1.push_back(index);
		value = interpolate(x0, y0, index, N);
		y1.push_back(value);
	}

	cout << "\n2. Hasil interpolasi dari x ke 0 hingga x ke x[n]" << endl;
	cout << "X : ";
	for (int x: x1) cout << x << setw(10);
	cout << "\n\nY : ";
	for (int y: y1) cout << y << setw(10);
	plt::figure();
    plt::plot(x1, y1, "blue");
	
	/*3. xpoint (titik yang ingin dicari valuenya)*/
	int xp;
	cout << "\n\n3. Masukkan titik yang ingin diketahui valuenya \nxp : " ;
	cin >> xp; 
	
	/*interpolasi sampai x ke xp*/
	double result = 0;
	for (int index = x0[vector_size(x0)-1]+1; index <= xp; index++){
		x1.push_back(index);
		result = interpolate(x0, y0, index, N);
		y1.push_back(result);
	}

	cout << "\nHasil interpolasi dari x ke 0 hingga x ke xp" << endl;
	cout << "X : ";
	for (double x: x1) cout << x << setw(6);
	cout << endl << "\nY : ";
	for (double y: y1) cout << y << setw(6);
	
	cout << endl;

	plt::xlabel("Points");
	plt::ylabel("Value");
	plt::plot(x1, y1, "r--");
	plt::title("Grafik interpolasi ->xp");
	plt::show();
}
