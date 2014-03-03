/*
Starstructor, the Starbound Toolset
Copyright (C) 2013-2014 Chris Stamford
Licensed under terms of The MIT License (MIT)

Source file contributers:
    Chris Stamford      contact: cstamford@gmail.com
*/

#ifndef STEDITORGLWIDGET_HPP
#define STEDITORGLWIDGET_HPP

#include <QGLWidget>

class EditorGLWidget : public QGLWidget
{
    Q_OBJECT;

public:
    EditorGLWidget(QWidget* parent = nullptr);

private:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
};

#endif // STEDITORGLWIDGET_HPP