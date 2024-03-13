#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <vector>
#include <fstream>
#include "RGBColor.h"

class Background{
    private:
        int height, width;
        std::vector<RGBColor> pixels, corners;

    public:
        void generate_ppm(std::string filename);
        void set_pixel(int x, int y, RGBColor color);
        RGBColor get_pixel(int x, int y);
        void interpolate();
        Background(int h, int w, std::vector<RGBColor> c);

};

#endif