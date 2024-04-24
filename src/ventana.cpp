#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    auto pantalla = Screen::Create(Dimension::Full(),Dimension::Fixed(10));
    Render(pantalla,border(text ("hola")));
    pantalla.PixelAt(5,5).character = 's';
    pantalla.Print();

    string prueba = ("Hola mundo");
    int posicionX = 0;
    int posicionY = 0;

    for(auto &&letra : prueba)
    {
        pantalla.PixelAt(posicionX, posicionY).character = letra;
        posicionX++;
    }
    pantalla.Print();
    return 0;
}
