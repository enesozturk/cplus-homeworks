#include <iostream>
#include "customer.h"
#include "product.h"
#include "control.h"
#include "process.h"

using namespace std;

int main(){
	//idem onal
	//atek tv youtube

	Customer c1;
	Customer c2;
	Product p1;
	
	string list;
	string newName, newSurname, newTel, newTr;
	int secim;
	Kontrol control;
	control.anaMenuCiz(20);
	cout << "Choose...";
	cin >> secim;
	switch (secim)
	{
	case 1:
		control.musteriMenuCiz();
		break;
	case 2:
		control.yoneticiMenuCiz();
		break;
	case 3:
		break;
	default:
		break;
	}

	/*



	while (true){
		system("cls");
		control.anaMenuCiz(20);
		if (secim == 1){
			control.musteriMenuCiz();
			while (true){
				int musterimenusecim;
				cout << "secim::";
				cin >> musterimenusecim;
				if (musterimenusecim == 4){
					return 0;
				}
			}
		}
		if (secim == 3){
			return 0;
		}
	}
	*/

	/*if (secim == 1){
		control.musteriMenuCiz();
	}
	if (secim == 2){
		control.yoneticiMenuCiz();
	}
	if (secim == 3){
		return 0;
	}
	*/

	/*do
	if (secim == 1){
		int musteriSecim;
		control.musteriMenuCiz();
		cout << "secim..";
		cin >> musteriSecim;
		if (musteriSecim == 4){
			system("cls");
			control.anaMenuCiz(20);
		}
		else{


		}
	}
	else{
		return 0;
	}
	*/

	/*

	} while (secim >= 3)
	switch (secim){
	case 1: //Customer Panel
		//system("cls");
		int tc,product;
		c1.listCustomers();
		cout << "tcNO: ";
		cin >> tc;
		c1.listCustomerMenu(tc);
		int secim;
		cin >> secim;
		if (secim == 1){
			p1.listProducts();
		}if (secim == 2){
			cout << "islemleri listele";
		}if (secim == 3){
			cout << "Islem sil";
		}
		if(secim==4){
			cout << "geri";
		}
		break;

	case 2: //Admin Panel
		system("cls");
		int adminpanelchoosen;
		control.tavanCiz(20);
		control.araCiz(20, " Admin Panel");
		control.ayracCiz(20);
		control.araCiz(20, " 1.Add Customer");
		control.araCiz(20, " 2.List Customers");
		control.araCiz(20, " 3.Delete Customer");
		control.araCiz(20, " 4.Add Product");
		control.araCiz(20, " 5.List Products");
		control.araCiz(20, " 6.Delete Products");
		control.araCiz(20, " 7.Back");
		control.zeminCiz(20);
		cout << "Choose..."; cin >> adminpanelchoosen;

		switch (adminpanelchoosen){
			case 1:
				c1.addCustomer();
				c1.save();
				break;
			case 2:
				c1.listCustomers();
				c1.save();
				break;
			case 3:
				int tc;
				c1.listCustomers();
				cout << "tc no gir:";
				cin >> tc;
				c1.deleteCustomer(tc);
				break;
			case 4:
				p1.addProduct();
				break;
			case 5:
				p1.listProducts();
				break;
			case 6:
				int deleteProductCode;
				p1.deleteProduct(deleteProductCode);
				break;
			default:
				break;
		}

	default:
		break;

	}
	Islem i1;*/
	
	system("pause");
	return 0;
}