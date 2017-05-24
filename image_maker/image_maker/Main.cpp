#include <iostream>
#include "easybmp.h"
#include <memory>
#include <functional>

const float PI = 3.14159265359;
const float DTOR = PI / 180;

std::unique_ptr<BMP> Make_Image(std::function<RGBApixel(int,int)> Func, int width, int hight);

int main(int argc, char* argv[]) {
	auto func = [](int x, int y) -> RGBApixel {
		++y;
		++x;

		int color = tan((x * y) * DTOR) * 255;
		int other = tan((x * y) * DTOR) * 255;
		int fith = tan((y * x) * DTOR) * 255;

		RGBApixel pixel;
		pixel.Red = color;
		pixel.Blue = other;
		pixel.Green = fith;
		return pixel;
	};

	std::unique_ptr<BMP> image = Make_Image(func, 1920, 1080);
  
	image->WriteToFile("C:/My Documents/visual studio 2015/Projects/image_Maker/image_maker/Debug/test.bmp");

	return 0;
}

std::unique_ptr<BMP> Make_Image(std::function<RGBApixel(int, int)> Func, int width, int hight) {
	std::unique_ptr<BMP> image = std::make_unique<BMP>();
	image->SetSize(width, hight);

	for(int x = 0; x < width; x++) {
		for(int y = 0; y < hight; y++) {
			image->SetPixel(x, y, Func(x,y));
		}
	}
	return image;
}
