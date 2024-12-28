//
// Created by Lauren Steel on 11/27/22.
// 20218337
// Assignment 4
// Dec 5 2022
//

#pragma once
#include <string>
using namespace std;

//Shape object
class Shape {
public:
    //base class
    Shape();
    //all shapes have a length, width and outline colour
    Shape(int length, int width, const string& colour);
    //virtual function - can be redefined in derived class
    //destructor
    virtual ~Shape();
    //draw function
    virtual void draw() = 0;
    //accessors
    int getLength() const;
    int getWidth() const;
    string getColour() const;
private:
    //attributes are private
    int length;
    int width;
    string colour;
};//end Shape class

//Fillable class
class Fillable {
public:
    //Fillable parent
    Fillable(const string& fillColour);
    //destructor
    virtual ~Fillable();
    //fill function
    virtual void fill() = 0;
    //constructor
    string getFillColour() const;
private:
    //attributes are private
    string fillColour;
};//end Fillable class

//TextShape class
class TextShape {
public:
    //TextShape parent - (for the shapes that may have text)
    TextShape(const string& text);
    //destructor
    virtual ~TextShape();
    //drawText function
    virtual void drawText() = 0;
    //constructor
    string getText() const;
private:
    //attributes are private
    string text;
};//end TextShape class



//Square - child class of shape
class Square : public Shape {
public:
    Square(int length, int width, const string& colour);
    ~Square();
    //function drawing outline of square
    void drawOutside() const;
    void draw();
};//end Square

//FilledSquare - child class of Shape and Fillable
class FilledSquare : public Square, public Fillable {
public:
    FilledSquare(int length, int width, const string& colour, const string& fillColour);
    ~FilledSquare();
    void fill();
    void draw();
};//end FilledSquare

//FilledTextSquare - child class of FilledSquare and TextShape
class FilledTextSquare : public FilledSquare, public TextShape {
public:
    FilledTextSquare(int length, int width, const string& colour, const string& fillColour,
                     const string& text);
    ~FilledTextSquare();
    void drawText();
    void draw();
};//end FilledTextSquare



//Circle - child class of shape
class Circle : public Shape {
public:
    Circle(int length, int width, const string& colour);
    ~Circle();
    void drawOutside() const;
    void draw();
};

//FilledCircle - child class of Shape and Fillable
class FilledCircle : public Circle, public Fillable {
public:
    FilledCircle(int length, int width, const string& colour, const string& fillColour);
    ~FilledCircle();
    void fill();
    void draw();
};//end FilledCircle



//Arc - child class of Shape
class Arc : public Shape {
public:
    Arc(int length, int width, const string& colour);
    ~Arc();
    void draw();
};//end Arc
