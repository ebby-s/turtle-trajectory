#include "turtle.hpp"
#include "frame.hpp"

using namespace std;

int main(){
  Turtle turtle;
  Frame frame(1024, 1024);
  float step_size = 0.1;
  total_steps = 100000;

  turtle.set_ypos(6378100);
  turtle.set_xvelocity(8000);
  turtle.set_pen(true);

  for(int i=0; i < total_steps; i++){
    if((turtle.get_xpos() <= 25500000 && turtle.get_ypos() <= 25500000)){
      pos = turtle.step_time(step_size);
      pos[0] *= 0.00004;
      pos[1] *= 0.00004;
      if(turtle.get_pen_down()){
        frame.set_pixel(pos, 1);
      }
    }else{
      break;
    }
  }

// print frame cout

}
