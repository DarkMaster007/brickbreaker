#ifndef CPOWERUP_H
#define CPOWERUP_H

#include "defines.h"

class cBricks;

class cPowerup {
    eActivePowerups type;
    int ID;
    float x, y;
    bool enabled;
    int spawnChance;
  public:
    static int powerupCount;
    static Texture2D texPowerup;

    cPowerup();
    eActivePowerups getType() const{
        return type;
    }
    void setType(eActivePowerups newType) {
        type = newType;
    }
    Vector2 getPosition() {
        return {x,y};
    }
    void setPosition(float newX, float newY) {
        x = newX;
        y = newY;
    }
    void setPosition(Vector2 newPosition) {
        x = newPosition.x;
        y = newPosition.y;
    }
    bool getEnabled() const{
        return enabled;
    }
    void setEnabled(bool newEnabled) {
        enabled = newEnabled;
    }
    bool spawnPowerup(cBricks *brick);
    void Logic();
    static void Draw(cPowerup *powerup);
    static void Input();
};

#endif // CPOWERUP_H
