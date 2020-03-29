#include <iostream>
#include <cmath>
#include "App.h"

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    
    fullscreen = false;

    button1 = new Rect(0.1, -0.8, 0.3, 0.1, 1,1,1);
    button2 = new Rect(0.5, -0.8, 0.3, 0.1, 1,1,1);
    rect2 = new Rect(-0.8, 0.8, 0.4, 0.1, 0, 0,1);
    circl = new Circle();
    
    
    animating = false;
    rotating = false;
}

void App::draw() const {
    button1->draw();
    button2->draw();
    rect2->draw();
    circl->draw();

}


void App::leftMouseDown(float x, float y){
    std::cout << "Mouse down at " << x << ", " << y << std::endl;
    if (x >= 0.1 && x <= 0.4 && y <= -0.8 && y >= -0.9){
        std::cout << "Clicked button1" << std::endl;
        animating = !animating;
    }
    if (x >= 0.6 && x <= 0.9 && y <= -0.8 && y >= -0.9){
        std::cout << "Clicked button2" << std::endl;
        rotating= !rotating;
    }
}


void App::idle(){

    if (animating){
        circl->leftright();
    }
    if (rotating){
        circl->rotateCenter();
    }

    redraw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 'e'){
        exit(0);
    }
    if (key == ' '){
        animating = !animating;
    }
    else if (key == 'f'){
        toggleFullScreen();
    }
    redraw();
}

App::~App(){    
    delete button1;
    delete button2;
    delete rect2;
    delete circl;
    std::cout << "Exiting..." << std::endl;
}
