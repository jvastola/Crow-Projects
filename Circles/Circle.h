#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
	

    float theta;
    float inc;
    float r;
    float cx;
    float cy;
	float re = 1;
	float g = 0;
	float b = 0;
    bool up;

public:
	Circle();
	Circle(float, float, float, float, float,float re=1, float g=0, float b=0);

	void draw() const;
    void leftright();
    void rotateCenter();
};

#endif
