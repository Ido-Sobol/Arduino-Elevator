#include <Arduino.h>

class LED
{
public:
    LED(int red, int green, int blue);
    void init();
    enum Color
    {
        RED,
        GREEN,
        BLUE,
        WHITE,
        NOTHING
    };

    void setColor(Color color);

private:
    int red;
    int green;
    int blue;
    Color color;
};

LED::LED(int red, int green, int blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void LED::init()
{
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
}

void LED::setColor(Color color)
{
    this->color = color;
    switch (color)
    {
    case RED:
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        digitalWrite(blue, LOW);
        break;
    case GREEN:
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        digitalWrite(blue, LOW);
        break;
    case BLUE:
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(blue, HIGH);
        break;
    case WHITE:
        digitalWrite(red, HIGH);
        digitalWrite(green, HIGH);
        digitalWrite(blue, HIGH);
        break;
    case NOTHING:
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(blue, LOW);
        break;
    default:
        break;
    }
}