//
// Created by Lauren Steel on 11/27/22.
// 20218337
// Assignment 4
// Dec 5 2022
//

#include <iostream>
#include <string>
#include "ShapesGood.h"

using namespace std;

//Shape - parent
Shape::Shape() : length(0), width(0), colour("red") {}
Shape::Shape(int len, int wid, const string& col) : length(len), width(wid), colour(col) {}
Shape::~Shape() {}
int Shape::getLength() const { return length; }
int Shape::getWidth() const { return width; }
string Shape::getColour() const { return colour; }

//Fillable - parent class
Fillable::Fillable(const string& fillCol) : fillColour(fillCol) {}
Fillable::~Fillable() {}
string Fillable::getFillColour() const { return fillColour; }

//TextShape - parent
TextShape::TextShape(const string& txt) : text(txt) {}
TextShape::~TextShape() {}
string TextShape::getText() const { return text; }



//Square - child
Square::Square(int len, int wid, const string& col) :
        Shape(len, wid, col) {}
Square::~Square() {}
void Square::drawOutside() const {
    cout << "\nDrawing a " + getColour() + " square.";
}
void Square::draw() {
    drawOutside();
}

//FilledSquare - child
FilledSquare::FilledSquare(int len, int wid, const string& col, const string& fColour) :
        Square(len, wid, col), Fillable(fColour) {}
FilledSquare::~FilledSquare() {}
void FilledSquare::fill() {
    cout << " With " + getFillColour() + " fill.";
}
void FilledSquare::draw() {
    drawOutside();
    fill();
}

//FilledTextSquare - child
FilledTextSquare::FilledTextSquare(int len, int wid, const string& col, const string& fColour,
                                   const string& text) :
        FilledSquare(len, wid, col, fColour), TextShape(text) {}
FilledTextSquare::~FilledTextSquare() {}
void FilledTextSquare::drawText() {
    cout << " Containing the text: \"" << getText() << "\".";
}
void FilledTextSquare::draw() {
    drawOutside();
    fill();
    drawText();
}



//Circle - child
Circle::Circle(int len, int wid, const string& col) :
        Shape(len, wid, col) {}
Circle::~Circle() {}
void Circle::drawOutside() const {
    cout << "\nDrawing a " + getColour() + " circle.";
}
void Circle::draw() {
    drawOutside();
}

//FilledCircle - child
FilledCircle::FilledCircle(int len, int wid, const string& col, const string& fColour) :
        Circle(len, wid, col), Fillable(fColour) {}
FilledCircle::~FilledCircle() {}
void FilledCircle::fill() {
    cout << " With " + getFillColour() + " fill.";
}
void FilledCircle::draw() {
    drawOutside();
    fill();
}



//Arc - child
Arc::Arc(int len, int wid, const string& col) :
        Shape(len, wid, col) {}
Arc::~Arc() {}
void Arc::draw() {
    cout << "\nDrawing a " + getColour() + " arc.";
}


