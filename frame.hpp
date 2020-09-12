#include <vector>
#include<iostream>

using namespace std;

class Frame{         // stores an array of pixels to represent the final image
private:
  int width;
  int height;
  vector<int> pixels;
public:
  Frame(int new_width, int new_height){   // dimensions can't be adjusted later
    width = new_width;
    height = new_height;
    pixels.assign(width*height, 1);
  }
  int get_height() const{
    return height;
  }
  int get_width() const{
    return width;
  }
  int get_pixel(vector<int> location) const{
    return pixels[location[1]*width + location[0]];
  }
  void set_pixel(vector<int> location, int val){
    pixels[location[1]*width + location[0]] = val;
  }
  void to_pgm() const{         // saves image as a pgm file
    cout << "P1" << endl;
    cout << width << " " << height << endl;
    for(int i=0; i<width*height; i++){
      cout << pixels[i];
    }
  }
};
