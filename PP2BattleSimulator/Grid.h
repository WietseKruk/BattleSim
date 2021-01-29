#pragma once
class Grid
{
    private:
    vector<Tank> tanks;
    vec2 gridSize;
    vector<Tile*> tiles;
    int tileIndex = 0;
    int indexX, indexY;
    int index;

    public:
    Grid(vector<Tank> tanks);
    void createGrid();
    vec2 getGridSize() { return gridSize; };
    vector<Tile*> getAdjacentTiles(int index);
    vector<Tile*> getAllTiles() { return tiles; };
    Tile* getCurrTile(int index);
    void updateTanks();
};



