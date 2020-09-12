#include <vector>

class Frame{
private:
  int width;
  int height;
  vector<float> pixels;
public:
  Image(int new_width, int new_height){
    width = new_width;
    height = new_height;
    pixels.assign(width*height, 0);
  }
  int get_height() const{
    return height;
  }
  int get_width() const{
    return width;
  }
  vector<int> get_pixel(vector<int> location) const{
    return pixels[location[1]*width + location[0]];
  }
  void set_pixel(vector<int> location, float val){
    pixels[location[1]*width + location[0]] = val;
  }
  void to_pgm() const{
    cout << "P1" << endl;
    cout << width << " " << height << endl;
    for(int i=0; i<width*height; i++){
      cout << pixels[i];
    }
  }
}
