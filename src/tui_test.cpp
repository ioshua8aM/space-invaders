#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
using namespace ftxui;

int main() {
  Element doc = text("Hello, World!") | bold | color(Color::Red) | bgcolor(Color::Blue);
  auto screen = Screen::Create(Dimension::Fit(doc));
  Render(screen, doc);
  screen.Print();
  return 0;
}
