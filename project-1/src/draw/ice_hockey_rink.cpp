/*
 * Copyright <2/2/19> <Filipe Falcao>
 *
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the 
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, sublicense, and/or sell copies of the Software, and to 
 * permit persons to whom the Software is furnished to do so, subject to 
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "../bresenham/bresenham_line.h"
#include "../bresenham/bresenham_circle.h"


void drawHinkBresenham() {

    // Render the ice hockey rink
    plotLineBresenham(160, 75, 160, 575);
    plotLineBresenham(490, 75, 490, 575);
    plotLineBresenham(165, 60, 485, 60);
    plotLineBresenham(162, 585, 488, 585);

    plotLineBresenham(160, 325, 490, 325);
    plotLineBresenham(160, 250, 490, 250);
    plotLineBresenham(160, 400, 490, 400);

    plotCircleBresenham(325, 325, 45, "default");
    plotCircleBresenham(325, 325, 3, "default");

    plotCircleBresenham(245, 120, 45, "default");
    plotCircleBresenham(245, 120, 2, "default");
    plotCircleBresenham(405, 120, 45, "default");
    plotCircleBresenham(405, 120, 2, "default");

    plotCircleBresenham(245, 525, 45, "default");
    plotCircleBresenham(245, 525, 2, "default");
    plotCircleBresenham(405, 525, 45, "default");
    plotCircleBresenham(405, 525, 2, "default");

    plotCircleBresenham(245, 260, 2, "default");
    plotCircleBresenham(405, 260, 2, "default");
    plotCircleBresenham(245, 410, 2, "default");
    plotCircleBresenham(405, 410, 2, "default");

    plotCircleBresenham(325, 60, 30, "upper");
    plotCircleBresenham(325, 585, 30, "lower");

    plotCircleBresenham(215, 575, 55, "upper-left");
    plotLineBresenham(215, 630, 435, 630);
    plotCircleBresenham(435, 575, 55, "upper-right");

    plotCircleBresenham(220, 80, 60, "lower-left");
    plotLineBresenham(215, 20, 435, 20);
    plotCircleBresenham(430, 80, 60, "lower-right");

}

void drawEquation() {



}