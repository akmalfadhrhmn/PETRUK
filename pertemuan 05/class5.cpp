#include <iostream>

using namespace std;

class Mahasiswa{
    private:
		string nama;
	
	public:
	    void setNama(string nama){
	        this->nama = nama;
	    }
	    string getNama(){
	        return nama;
	    }
	    
};

int main()
{
    Mahasiswa Mhs;
    Mhs.setNama("Anta");
    cout<<"NAma: "<<Mhs.getNama()<<endl;
   
    return 0;
}

