#include "turtle.hpp"
#include "frame.hpp"

using namespace std;

int main(){
  Turtle turtle;                  // object that moves
  Frame frame(1024, 1024);    // plots position of turtle after each time step
  float step_size = 0.1;         // smaller values are more accurate
  int total_steps = 100000;
  vector<int> current_pos;     // position of turtle on 1024x1024 grid
  vector<float> pos;                // actual position of turtle
  current_pos.assign(2, 0);    // initialise as {0, 0}
  pos.assign(2, 0);

  turtle.set_ypos(6378100);      // set turtle to start on south pole of earth
  turtle.set_xvelocity(20000);      // starting velocity of turtle
  turtle.set_pen(true);         // causes turtle to plot path

  for(int i=0; i < total_steps; i++){   // for each time step while turtle is within bounds
    if(turtle.get_xpos() <= 12000000 && turtle.get_ypos() <= 12000000
    && turtle.get_xpos() >= -12000000 && turtle.get_ypos() >= -12000000){
      pos = turtle.step_time(step_size);
      current_pos[0] = 0.00004*pos[0] + 512;    // convert actual position to 1024x1024 grid
      current_pos[1] = 0.00004*pos[1] + 512;
      if(turtle.get_pen_down()){
        frame.set_pixel(current_pos, 0);
      }
    }else{
      break;         // break if turtle is out of bounds
    }
  }
  frame.to_pgm();    // save the plotted trajectory to a .pgm file
}
