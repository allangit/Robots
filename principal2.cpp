
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <filesystem>
#include <fstream>
#include <typeinfo>
using namespace std;
using namespace cv;
namespace fs = std::filesystem;


class imagenes {

	private:

		Mat foto, img,imgx,diferencia,img_kernel,kernel,img2,gray,th,closing,bordes;

	public:

		void setlectura(Mat foto);
		Mat ImagenGray();
		Mat getlectura();
		Mat formatImagen();
		Mat Color();
		Mat thC();
		Mat Morpho();
		Mat Kern();
		Mat Cann();
		Mat dCopy();
		vector<vector<Point>> findContorno();
		Mat Draw();
		string *directorio();
		void mostrar();

};

string *imagenes::directorio() {

	string path = "ruta donde se encuentra sus imagenes";
	string name = " ";
	string imgs[200] = {};
	int i = 0;
	fs::is_directory(path) ? cout << "encontro el directorio" : cout << "No es directorio";
	
	for (auto& input : fs::directory_iterator(path)) {

		if (input.path().extension() == ".png") {

			name= path + "/" + input.path().filename().string()+"\n";
			imgs[i] = name;
			i += 1;
		}
	}

	return imgs;
	
}

void imagenes::mostrar() {

	string* dir;
	dir = directorio();
	for (int i = 0; i < directorio()->size(); i++) {

		cout << *(dir+i) << endl;
	}
}

void imagenes::setlectura(Mat foto) {

	this->foto = foto;
}

Mat imagenes::getlectura() {

	Size tam(400, 400);
	resize(this->foto,this-> img2, tam);
	return this->img2;
}

Mat imagenes::ImagenGray() {

	cvtColor(getlectura(), this->gray, COLOR_BGR2GRAY);
	return this->gray;

}

Mat imagenes::Color() {

	Size tam(400, 400);
	resize(getlectura(), this->img, tam);
	cvtColor(this->img, this->gray, COLOR_BGR2GRAY);

	return this->gray;
}
Mat imagenes::thC() {

	threshold(Color(), this->th, 122, 255, THRESH_BINARY);
	return this->th;

}
Mat imagenes::Kern() {

	this->kernel = (Mat_<float>(3, 3) << 10, 10, 10,
		5, 5, 5,
		1, 1, 1) / 4.0;

	return this->kernel;

}

Mat imagenes::Morpho() {

	morphologyEx(thC(), this->closing, MORPH_CLOSE, Kern());
	return this->closing;

}

Mat imagenes::Cann() {

	Canny(Morpho(), this->bordes, 115, 255);
	return this->bordes;

}

vector<vector<Point>> imagenes::findContorno() {
	vector<vector<Point>> contornos;

	findContours(Cann(), contornos, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	
	return contornos;

}

Mat imagenes::dCopy() {


	this->img2.copyTo(getlectura());


		return this->img2;
}

Mat imagenes::Draw() {

	Size tamg(12, 255);	
	drawContours(findContorno(), this->img, -1, Scalar(0, 150, 200), 4);
	return this->img;

}
	


int main() {

	Mat foto = imread("ruta de las imagenes");
	Mat data;
	imagenes m = imagenes();
	m.setlectura(foto);
	//m.findContorno();
	//data = m.Cann();
	imshow("imagen",m.getlectura());
	//m.directorio();
	//m.mostrar();
	//imshow("imagen", m.umbralizacion());
	//m.setlectura(foto);
	//imshow("imagen", m.Draw());
	
	waitKey(0);



	return 0;


}