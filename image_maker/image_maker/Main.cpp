#include <iostream>
#include "easybmp.h"
#include <memory>
#include <functional>

std::unique_ptr<BMP> Make_Image(std::function<RGBApixel(int,int)> Func, int width, int hight);


int main(int argc, char* argv[]) {
  auto func = [](int x, int y) -> RGBApixel {
	RGBApixel color;
    color.Red = (x % 255);
    color.Blue = (y % 255);
    color.Green = ((x+y)%255);
    return color;
  };

  std::unique_ptr<BMP> image = Make_Image(func, 150, 150);
  
  image->WriteToFile(argv[1]);

  return 0;
}

template <typename Func>
std::unique_ptr<BMP> Make_Image(std::function<RGBApixel(int, int)> Func, int width, int hight) {
  std::unique_prt<BMP> image = std::make_unique<bmp>();
  image->SetSize(width, hight);

  for(int x = 0; x < width; x++) {
    for(int y = 0; y < hight; y++) {
      image.SetPixel(x, y, Func(x,y));
    }
  }

  return image;
}
