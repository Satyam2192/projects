#include <iostream>
#include <string>

#include "Magick++.h"

using namespace std;
using namespace Magick;

int main() {
    // Set the input text
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    // Set the font and text rendering options
    InitializeMagick("");
    Image image(Geometry(640, 480), Color("white"));
    image.font("[PATH_TO_FONT_FILE]");
    image.fontPointsize(48);
    image.fillColor("black");
    image.draw(DrawableText(10, 50, text));

    // Set the painting style options
    image.edge("10");
    image.charcoal("5x5");

    // Save the image
    image.write("image.png");

    return 0;
}
