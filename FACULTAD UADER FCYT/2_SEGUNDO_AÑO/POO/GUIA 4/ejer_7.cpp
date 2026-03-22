#include <iostream>
#include <vector>
using namespace std;

class fiestas{
private:
	vector<const char*> cumpleanios;
public:
	void cargar_cumpleanios(const char* cumple){
		cumpleanios.push_back(cumple);
	}
	void mostrar_cumple(){
		for (const auto & bucle:cumpleanios){
			cout << bucle << endl;
		}
	}
};
int main(int argc, char *argv[]) {
	fiestas cumpleanito;
	cumpleanito.cargar_cumpleanios("20102004");
	cumpleanito.cargar_cumpleanios("30102777");
	cumpleanito.mostrar_cumple();
	return 0;
}

