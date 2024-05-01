#pragma once
#include <fstream>
#include <ftxui/dom/elements.hpp>
#include <list>

using namespace std;
using namespace ftxui;

class Archivo
{
private:
    fstream archivo;
    list<string> contenido;
public: 
    Archivo(string path)
    {
        archivo.open(path);
        Elements lineas;
        while (!archivo.eof())
        {
            string linea;
            getline(archivo, linea);
            contenido.push_back(linea);
        }
        archivo.close();
    }
    Dibujo CrearDibujo()
    {
        Dibujo temp(contenido, 0,0);
        return temp;
    }
~Archivo(){}
};