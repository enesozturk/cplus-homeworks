#include <iostream>
#include "process.h"
#include "product.h"
#include <fstream>
#include "customer.h"

using namespace std;


Islem::Islem(){

}

void	Islem::urunKoduGetir(){
	Product p1;
	p1.getPCode();
}

void	Islem::tcNoGetir(){
	//Customer c1;
	
}

void	Islem::kaydet(){
	fstream save;
	Customer c1;

	save.open("Processes.txt", fstream::in | fstream::out | fstream::app);

	if (save.is_open() == true){
		save << c1.getTrNo();
	}

	save.close();
}

//string Islem::islemKoduUret(string )