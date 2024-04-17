#include <iostream>
#include <string>
#include <thread>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

using namespace std;
using namespace ftxui;


int main(int argc, char const *argv[])
{
    Element lienzo = hbox({
        spinner(21,4) | bold
    });

    Screen pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fit(lienzo)
        );

    Render(pantalla,lienzo);
    pantalla.Print();
    pantalla.ResetPosition();
    this_thread::sleep_for(0.1s);

    return 0;
}
