#include <iostream>
#include <string>
#include <thread>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <fstream>
#include <ftxui/screen/terminal.hpp>
#include <Dibujo.hpp>
#include <chrono>

using namespace std::chrono_literals;
using namespace std;
using namespace ftxui;


int main(int argc, char const *argv[])
{
   
    Dibujo dTanque ("./assets/images/canon.txt");
    Dibujo dAlien ("./assets/images/alien.txt");
    Dibujo dBloque ("./assets/images/canon.txt");

   
    int fotograma = 0;

    
    while (true)
    {
    fotograma++;
    
    Element personaje = spinner(21,fotograma) | bold | color(Color::Yellow1) | bgcolor(Color::Green1);
    Element tanque = dTanque.GetElement() | bold | color(Color::Green) | bgcolor(Color::Blue);
    Element lienzo = hbox({ personaje, tanque, dAlien.GetElement() });

    Screen pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fit(lienzo)
        );

    Render(pantalla,lienzo);
    pantalla.Print();
    cout << pantalla.ResetPosition();

    this_thread::sleep_for(100ms);
    }
    return 0;
}
