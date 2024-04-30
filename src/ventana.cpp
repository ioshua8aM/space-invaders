#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/dom/elements.hpp>
#include <thread>
#include <Dibujo.hpp>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Dibujo palabra1("Hola", 0, 0), palabra2("Adios", 5, 5);

    auto pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

    while (true)
    {
        this_thread::sleep_for(0.1s);
    
        palabra1.Dibujar(pantalla);
        palabra2.Dibujar(pantalla);

        pantalla.Print();
        pantalla.Clear();
        cout << pantalla.ResetPosition();

    }

    return 0;
}
