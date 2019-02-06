#ifndef INCLUDES_H
#define INCLUDES_H

// MacOS includes
#ifdef __APPLE__
    #include "TargetConditionals.h"
    #ifdef TARGET_OS_MAC
        #include <OpenGL/gl.h>
        #include <OpenGl/glu.h>
        #include <GLUT/glut.h>
    #endif

// Linux includes
#elif __linux__
    #include <GL/freeglut.h>
    #include <GL/gl.h>
#endif

#endif // INCLUDES_H
