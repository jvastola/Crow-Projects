#include "Circle.h"
#include "GlutApp.h"
#include <cmath>

Circle::Circle(){

    theta = 0;
    inc = 2*M_PI/60;
    r = 0.2;
    cx = 0;
    cy = 0;
	re = 1;
	g = 0;
	b = 0;
    up = true;
}

Circle::Circle(float theta,float inc,float r,float cx,float cy, float re, float g, float b){
	this->theta = theta;
    this->inc = inc;
    this->r = r;
    this->cx = cx;
    this->cy =cy;
	this->re = re;
	this->g = g;
	this->b = b;
}

void Circle::draw() const {
    glColor3f(re,g,b);
    glBegin(GL_POLYGON);

    for (float i =theta; i <= 2*M_PI; i += inc){
        glVertex2f(r*cos(i) + cx, r*sin(i) + cy);
        glVertex2f(r*cos(i+inc) + cx, r*sin(i+inc) + cy);
    }

	glEnd();
}
void Circle::leftright(){
        if (cx >= 0.9){
            up = false;
        }
        if (cx <= -0.9){
            up = true;
        }

        if (up){
            cx=cx+.01;
        }
        else{
            cx=cx-.01;
        }
}
void Circle::rotateCenter(){

            cx=cx*cos(inc)-cy*sin(inc);
            cy=+cx*sin(inc)+cy*cos(inc);
}

