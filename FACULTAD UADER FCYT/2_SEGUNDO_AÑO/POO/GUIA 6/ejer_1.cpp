#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Tags{
public:
	virtual void mostrar() = 0;
	virtual ~Tags(){};
};
class Tagp : public Tags{
private:
	char texto[100];
public:
	Tagp(const char* text){
		strcpy(texto, text);
	}
	void mostrar()override {
		cout << "<p> " << texto << " </p>" << endl;
	}
};

class Tagimg : public Tags{
private:
	char link[100];
public:
	Tagimg(const char* url){
		strcpy(link, url);
	}
	void mostrar() override{
		cout << "<img href = ''" << link << "'' />" << endl;
	}
};

class Taga : public Tags{
private:
	char texto[100];
	char link[100];
public:
	Taga(const char* text, const char* lin){
		strcpy(texto, text);
		strcpy(link, lin);
	}
	void mostrar() override{
		cout << "<a href = ''" << link << ">" << texto << "</a>" << endl;
	}
};

class Gestor{
private:
	vector<Tags*> tags;
public:
	void agregartag(Tags* tag){
		tags.push_back(tag);
	}
	void mostrar(){
		cout << "<body>" << endl;
		for (const auto& bucle : tags){
			bucle->mostrar();
		}
		cout << "</body>" << endl;
	}
	~Gestor(){
		for(const auto& bucle : tags){
			delete bucle;
		}
	}
};

int main(int argc, char *argv[]) {
	Gestor gestor;
	
	// Crear y agregar tags
	gestor.agregartag(new Tagp("Este es el examen de POO"));
	gestor.agregartag(new Tagimg("nombreDeUnaImg.jpg"));
	gestor.agregartag(new Tagp("Espero que hayas estudiado"));
	gestor.agregartag(new Taga("texto del link", "http://unlink.html"));
	
	// Mostrar el HTML generado
	gestor.mostrar();
	return 0;
}

