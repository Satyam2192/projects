#include <iostream>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "Magick++.h"

using namespace std;
using namespace Magick;

int main() {
    // Initialize FreeType
    FT_Library library;
    if (FT_Init_FreeType(&library)) {
        cerr << "Error initializing FreeType library" << endl;
        return 1;
    }

    // Load the font
    FT_Face face;
    if (FT_New_Face(library, "[PATH_TO_FONT_FILE]", 0, &face)) {
        cerr << "Error loading font file" << endl;
        return 1;
    }

    // Set the font size
    FT_Set_Pixel_Sizes(face, 0, 48);

    // Set the text and rendering options
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    int width = 0;
    int height = 0;
    for (char c : text) {
        FT_Load_Char(face, c, FT_LOAD_RENDER);
        width += face->glyph->advance.x >> 6;
        height = max(height, face->glyph->bitmap.rows);
    }

    // Create the image
    Image image(Geometry(width, height), Color("white"));
    image.strokeColor("black");
    image.font(face->family_name);
    image.fontPointsize(48);
    image.draw(DrawableText(0, height - face->glyph->bitmap_top, text));

    // Save the image
    image.write("image.png");

    // Clean up
    FT_Done_Face(face);
    FT_Done_FreeType(library);

    return 0;
}
