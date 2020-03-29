#ifndef App_h
#define App_h
#include <vector>

#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"


class App: public GlutApp {
    
    bool fullscreen;
    Rect* button1;
    Rect* button2;
    Rect* rect2;
    Circle* circl;

    bool rotating;
    bool animating;

public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);

    void idle();

    void leftMouseDown(float x, float y);
    
    ~App();
};

#endif
