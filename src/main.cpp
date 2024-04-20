#include <iostream>
#include <string>
#include <thread>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

using namespace std;
using namespace ftxui;


int main(int argc, char const *argv[])
{
   
   
    int fotograma = 0;

    while(true)
    {
        fotograma++;
    Element personaje = spinner(21,fotograma) | bold | color(Color::Yellow1) | bgcolor(Color::Green1);
    Element lienzo = hbox({
        spinner(21,fotograma) | bold
    });

    Screen pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fit(lienzo)
        );

    Render(pantalla,lienzo);
    pantalla.Print();
    cout << pantalla.ResetPosition();
    this_thread::sleep_for(0.1s);
    }
    return 0;
}
