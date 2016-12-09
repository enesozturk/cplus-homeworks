#pragma once
#include <string>

using namespace std;
class Islem
{
public:
	Islem();

	void	urunKoduGetir();

	void	tcNoGetir();

	void	islemKoduGetir();

	void	kaydet();

	string islemKoduUret();

private:
	string  mIslemKodu;
	string	mUrunKodu;
	string  mMusteriTcNo;

};