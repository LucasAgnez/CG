#include "../include/CG/background.h"
#include <fstream>
#include <iostream>


Background::Background(int h, int w, std::vector<RGBColor> c){
	this->height=h;
	this->width=w;
	this->corners=c;
	pixels.resize(h*w);
};


void Background::set_pixel(int x, int y, RGBColor color) {
	if (x >= 0 && x < width && y >= 0 && y < height) {
		pixels[y * width + x] = color;
	}
}

void Background::interpolate(){
	enum Corners_e {
		bl=0, //!< Bottom left corner.
		tl,   //!< Top left corner.
		tr,   //!< Top right corner.
		br	//!< Bottom right corner.
	};
	RGBColor interpolatedColor;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double x_ratio = static_cast<double>(x) / (width - 1);
            double y_ratio = static_cast<double>(y) / (height - 1);

			for(int k = 0; k < 3; k++){
				interpolatedColor.color[k] = (1 - x_ratio) * (1 - y_ratio) * corners[tl].color[k] +
											x_ratio * (1 - y_ratio) * corners[tr].color[k] +
											(1 - x_ratio) * y_ratio * corners[bl].color[k] +
											x_ratio * y_ratio * corners[br].color[k];
			}

            set_pixel(x, y, interpolatedColor);
        }
    }
}


void Background::generate(std::string filename){
	 std::ofstream file("./images/"+filename+".ppm", std::ios::out | std::ios::binary);
	 if (!file) {
		  std::cerr << "Error: Unable to open file for writing." << std::endl;
		  return;
	 }

	 file << "P3" << std::endl;
	 file << width << " " << height << std::endl;
	 file << "255" << std::endl;

	 for (const auto& pixel : pixels) {
		  file << pixel.color[0] << " " << pixel.color[1] << " " << pixel.color[2] << std::endl;
	 }

	 file.close();
};

