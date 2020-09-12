#include<vector>
#include<cmath>

using namespace std;

class Turtle{
private:
	vector<float> pos;  // vector holds position of turtle
	vector<float> velocity;  // vector holds velocity of turtle
	bool pen_down;  // determines whether or not to draw path of turtle
public:
	Turtle(){
		pos.assign(2, 0);
		velocity.assign(2, 0);
		pen_down = false;
	}

	float get_xpos() const{
		return pos[0];
	}
	float get_ypos() const{
		return pos[1];
	}
	float get_xvelocity() const{
		return velocity[0];
	}
	float get_yvelocity() const{
		return velocity[1];
	}
	bool get_pen_down() const{
		return pen_down;
	}

	void set_xpos(float new_xpos){
		pos[0] = new_xpos;
	}
	void set_ypos(float new_ypos){
		pos[1] = new_ypos;
	}
	void set_xvelocity(float new_xvelocity){
		velocity[0] = new_xvelocity;
	}
	void set_yvelocity(float new_yvelocity){
		velocity[1] = new_yvelocity;
	}
	void set_pen(bool pen){
		pen_down = pen;
	}
	vector<float> step_time(float step_size){
		double CONST_G_MASS = 3.986*pow(10, 14);
	  double square_distance = pow(pos[0], 2) + pow(pos[1], 2);
	  double magnitude = CONST_G_MASS / pow(square_distance, 1.5);
		velocity[0] += pos[0]*magnitude;
	  velocity[1] += pos[1]*magnitude;
		pos[0] -= velocity[0]*step_size;
		pos[1] -= velocity[1]*step_size;
		return pos;
	}
};
