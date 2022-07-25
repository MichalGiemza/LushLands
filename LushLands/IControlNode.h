#pragma once

class IControlNode {
    /* Pozwala na surowy input do ruchu
     *  - Ruch postaci
     *  - Przewijanie mapy
     */
public:
    virtual void goNorth(int _);
    virtual void goSouth(int _);
    virtual void goEast(int _);
    virtual void goWest(int _);
    virtual void stopGoingNorth(int _);
    virtual void stopGoingSouth(int _);
    virtual void stopGoingEast(int _);
    virtual void stopGoingWest(int _);
};