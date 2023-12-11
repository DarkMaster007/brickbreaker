#pragma once
#ifndef CBALL_H
#define CBALL_H
#endif // CBALL_H
#include "defines.h"

class cBall {
  private:
    float x, y;
    float originalX, originalY;
    int current_size;
    int originalSize;
    float speed;
    float originalSpeed;
    float acceleration;
    eDir direction;
    float randomMovementOffset[2] {};
    std::mt19937 marsenneTwister{static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count())};
    std::uniform_int_distribution<> randomNrDistribution{1, 4};
    std::uniform_int_distribution<> randomNrDirection{1, 4};
  public:
    static int ballCount;
    static Texture2D texBall;

    cBall(int posX, int posY, int ball_size, float ballSpeed);
    ~cBall();
    inline void setDirection(eDir d);
    inline void randomDirection();
    inline float getX();
    inline float getY();
    inline void setX(float newX);
    inline void setY(float newY);
    inline eDir getDirection();
    inline void setDimensions(int ball_size);
    inline int getDimensions();
    inline int getAcceleration();
    inline void setAcceleration(float newAccel);
    void randomizeMovement();
    void Move();
    void Reset();
    void Logic(double &startTimer, bool isPaused);
    static void Draw(cBall *ball);
    void Input();
};

void cBall::setDirection(eDir d) {
    direction = d;
}
void cBall::randomDirection() {
    direction = (eDir)(randomNrDirection(marsenneTwister));
}
float cBall::getX() {
    return x;
}
float cBall::getY() {
    return y;
}
void cBall::setX(float newX) {
    x = newX;
}
void cBall::setY(float newY) {
    y = newY;
}
eDir cBall::getDirection() {
    return direction;
}
void cBall::setDimensions(int ball_size) {
    current_size = ball_size;
}
int cBall::getDimensions() {
    return current_size;
}
int cBall::getAcceleration(){
    return acceleration;
}
void cBall::setAcceleration(float newAccel = 0.017){
    acceleration = newAccel;
}
