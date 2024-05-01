#pragma once
#include <string>
#include <ftxui/screen/screen.hpp>
#include <list>

using namespace std;
using namespace std;

class Dibujo
{
private:
    int posicionX = 0;
    int posicionY = 0;
    list<string> contenido;
public:
    Dibujo()
    {
        this -> posicionX = 0;
        this -> posicionY = 0;
    }
    Dibujo(int posicionX, int posicionY)
    {
        this -> posicionX = posicionX;
        this -> posicionY = posicionY;
    }
    Dibujo(list<string> contenido, int posicionX, int posicionY)
    {
        this -> contenido = contenido;
        this -> posicionX = posicionX;
        this -> posicionY = posicionY;
    }
    void Dibujar(ftxui::Screen &pantalla)
    {
        int posicionPalabraY = 0;
        
        for (auto &&linea : contenido)
        {
            int posicionPalabraX = 0;
            for (auto &&letra : linea)
            {
                int posicionFinalX = this->posicionX + posicionPalabraX;
                int posicionFinalY = this->posicionY + posicionPalabraY;
                
                pantalla.PixelAt(posicionFinalX, posicionFinalY).character = letra;
                posicionPalabraX++;
            }
            posicionPalabraY++;
        }
    }

    void DesplazarX (int distancia)
    {
        posicionX += distancia;
    }

    void DesplazarY (int distancia)
    {
        posicionY += distancia;
    }
};
