#include <iostream>

using namespace std;

class Mahasiswa{
    public:
		string nama;
		
	Mahasiswa(string nama, string x){
	    this->nama = nama;
	    this->npm = x;
	}
	    
};

int main()
{
    Mahasiswa Mhs("Anta","2217051000");
    cout <<"Nama" << Mhs.nama<< endl;
    cout <<"Npm" << Mhs.npm<< endl;
    return 0;
}

