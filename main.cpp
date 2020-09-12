#include "turtle.hpp"
#include "frame.hpp"

using namespace std;

int main(){
  Turtle turtle;
  Frame frame(1024, 1024);
  float step_size = 0.1;
  int total_steps = 100000;
  vector<int> current_pos;
  vector<float> pos;
  current_pos.assign(2, 0);
  pos.assign(2, 0);

  turtle.set_ypos(6378100);
  turtle.set_xvelocity(8000);
  turtle.set_pen(true);

  for(int i=0; i < total_steps; i++){
    if((turtle.get_xpos() <= 25500000 && turtle.get_ypos() <= 25500000)){
      pos = turtle.step_time(step_size);
      current_pos[0] = 0.00004*pos[0] + 512;
      current_pos[1] = 0.00004*pos[1] + 512;
      if(turtle.get_pen_down()){
        frame.set_pixel(current_pos, 0);
      }
    }else{
      break;
    }
  }

  frame.to_pgm();
}
