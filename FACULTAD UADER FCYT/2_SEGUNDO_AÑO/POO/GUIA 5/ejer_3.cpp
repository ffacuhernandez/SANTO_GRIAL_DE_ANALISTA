#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Catalogo{
public:
	virtual void mostrar() = 0;
	virtual ~Catalogo(){};
};

class Texto : public Catalogo{
private:
	char contenido[100];
public:
	Texto(const char* text){
		strncpy(contenido, text, sizeof(contenido) - 1);
		contenido[sizeof(contenido) - 1] = '\0';
	}
	void mostrar() override{
		cout << "Texto: " << contenido << endl;
	}
};

class Imagenes : public Catalogo{
private:
	char imagen[100];
public:
	Imagenes(const char* img){
		strncpy(imagen, img, sizeof(imagen) - 1);
		imagen[sizeof(imagen) - 1] = '\0';
	}
	
	void mostrar() override {
		cout << "Imagen: " << imagen << endl;
	}
};

class Multivideo : public Catalogo{
private:
	char video[100];
public:
	Multivideo(const char* vid){
		strncpy(video, vid, sizeof(video) - 1);
		video[sizeof(video) - 1] = '\0';
	}
	
	void mostrar() override {
		cout << "Video: " << video << endl;
	}
};

class CatalogoCompleto {
private:
	vector<Catalogo*> articulos;
public:
	void agregarArticulo(Catalogo* articulo) {
		articulos.push_back(articulo);
	}
	
	void mostrarCatalogo() {
		for (const auto& bucle : articulos) {
			bucle->mostrar();  // Llamada polimórfica
		}
	}
};

int main(int argc, char *argv[]) {
	// Crear objetos
	Texto* texto = new Texto("Este es un artículo de texto.");
	Imagenes* imagen = new Imagenes("Imagen de ejemplo.jpg");
	Multivideo* video = new Multivideo("video_increible.mp4");
	
	// Crear el catálogo y agregar artículos
	CatalogoCompleto catalogo;
	catalogo.agregarArticulo(texto);
	catalogo.agregarArticulo(imagen);
	catalogo.agregarArticulo(video);
	
	// Mostrar todo el catálogo
	catalogo.mostrarCatalogo();
	
	// Liberar memoria
	delete texto;
	delete imagen;
	delete video;
	
	return 0;
}

