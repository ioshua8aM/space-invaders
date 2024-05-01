#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>
#include <Dibujo.hpp>
#include <Archivo.hpp>
#include <list>
#include <experimental/random>
#include <chrono>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Archivo alien("./assets/images/alien.txt");
    list<Dibujo> dibujos;

    for (size_t i = 0; i < 20; i++)
    {
        Dibujo d = alien.CrearDibujo();
        d.EstablecerPosicion(experimental::randint(0,20), experimental::randint(0,20));
        dibujos.push_back(d);

    for (int i = 0; i < 20; i++)
    {
        list<string> c;
        c.push_back("Personaje" + to_string(i));
        c.push_back("  O");
        c.push_back("--|--");
        c.push_back(" /  ");

        Dibujo contenido (c, experimental::randint(0,20), experimental::randint(0,20)); //(contenido + no iteracion, posx, posy )
        dibujos.push_back(contenido);

    }
    
    auto pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

    while (true)
    {

        pantalla.Clear();
        this_thread::sleep_for(100ms);
    
        //actualizar
        for (auto && i : dibujos)
        {
            i.DesplazarX(experimental::randint(-1,1));
            i.DesplazarY(experimental::randint(-1,1)); 
        }

        //dibujar
        for (auto && i : dibujos)
        {
            i.Dibujar(pantalla);
        }

        pantalla.Print();
        cout << pantalla.ResetPosition();

    }

    return 0;
}
