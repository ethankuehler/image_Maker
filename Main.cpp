#include <iostream>
#include "easybmp.h"
#include <memory>

template <typename Func>
BMP Make_Image(Func fun, int width, int hight);


int main(int argc, char* argv[]) {
  auto func = [](int x, int y) -> RGBApixle {
    RGBApixle color;
    color.red(x % 255);
    color.blue(y % 255);
    color.green((x+Y)%255);
    return color;
  };


  std::unique_ptr<bmp> image = Make_Image(func, 150, 150);
  
  image->WriteToFile(argv[1]);

  return 0;
}

template <typename Func>
std::unique_ptr<bmp> Make_Image(Func, int width, int hight) {
  std::unique_prt<BMP> image = std::make_unique<bmp>();
  image->SetSize(width, hight);

  for(int x = 0; x < width; x++) {
    for(int y = 0; y < hight; y++) {
      image.SetPixel(x, y, Func(x,y));
    }
  }

  return image;
}
