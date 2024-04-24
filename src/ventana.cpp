#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    string prueba = ("DVD");
    int posicionX = 0;
    int posicionY = 0;
    while(true)
    {
        this_thread::sleep_for(0.1s);
        auto pantalla = Screen::Create(Dimension::Full(), Dimension::Fixed(10));
        Render(pantalla, border(text("hola")));
        pantalla.PixelAt(5, 5).character = 's';
        pantalla.Print();

        

        for (auto &&letra : prueba)
        {
            pantalla.PixelAt(posicionX, posicionY).character = letra;
            posicionX++;
        }
        pantalla.Print();
        cout << pantalla.ResetPosition();
    }
    return 0;
}
