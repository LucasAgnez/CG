#include "../include/CG/background.h"

using namespace std;

int main(int argc, char** argv){
    std::vector<RGBColor> p = {{255,0,0},{0,255,0},{0,0,255},{0,255,255}};
    Background G(100, 100, p);
    G.interpolate();
    G.generate("teste");
    return 1;
}