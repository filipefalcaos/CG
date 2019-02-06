#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "includes.h"
#include <QTimer>
#include <algorithm>

using namespace std;


extern GLfloat color[3];
extern GLint point_size;
extern GLint render_type;
extern GLint x_max, x_min;
extern GLint y_max, y_min;
extern bool clear;

class GLWidget : public QGLWidget {

    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);

private:
    QTimer timer;
    vector<pair<int,int>> points_1;
    vector<pair<int,int>> points_2;
    bool first_click = true;

};

#endif // GLWIDGET_H
