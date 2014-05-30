/*
Starstructor, the Starbound Toolset
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#include "gui/steditorglwidget.hpp"

EditorGLWidget::EditorGLWidget(QWidget* parent)
{
}

void EditorGLWidget::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}

void EditorGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -7.5f);

    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0f, +1.0f, +0.0f);
    glVertex3f(-1.0f, -1.0f, +0.0f);
    glVertex3f(+0.0f, +0.0f, +1.0f);
    glEnd();
}

void EditorGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif

    glMatrixMode(GL_MODELVIEW);
}