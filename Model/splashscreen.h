#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "model.h"

enum struct SplashScreenType { GO, GAME_OVER, COMPLETED }; //splash screen types

class SplashScreen: public Model
{
public:
    //constructor
    SplashScreen(int, int, QString);

    //setters and getters
    inline bool getIsSplashScreen() { return this->isSplashScreen; }
    inline void setIsSplashScreen(bool splash) { this->isSplashScreen = splash; }
    inline void setType(SplashScreenType type) { this->type = type; }
    inline SplashScreenType getType() { return this->type; }

private:
    //private attributes
    bool isSplashScreen = true; //update screen or not
    SplashScreenType type = SplashScreenType::GO; //init type = go
};

#endif // SPLASHSCREEN_H
