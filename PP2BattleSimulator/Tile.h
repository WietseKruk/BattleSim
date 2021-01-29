#pragma once
class Tile
{
    private:  
    vec2 pos;
    vector<Tank*> tanks;
    int index;
    
    public:
    Tile(vec2 pos, int index);
    vector<Tank*> getTanks() { return tanks; };
    vec2 getPos() { return pos; };
    int getIndex() { return index; };
    void addTank(Tank* tank);
    void removeTank(Tank* tank);
};
