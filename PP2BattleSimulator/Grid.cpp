#include "precomp.h"

Grid::Grid(vector<Tank> tanks)
{
    this->tanks = tanks;
    gridSize.x = ROWS;
    gridSize.y = COLS;
    createGrid();
}


void Grid::createGrid() {
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            vec2 pos;
            pos.x = i;
            pos.y = j;
            Tile* tile = new Tile(pos, tileIndex);
            tiles.push_back(tile);
            tileIndex++;
        }
    }
}

vector<Tile*> Grid::getAdjacentTiles(int index) {

    vector<Tile*> adjTiles;
    adjTiles.reserve(9);

    Tile* currTile = getCurrTile(index);  
    
    int currPosX = floor(currTile->getPos().x);
    int currPosY = floor(currTile->getPos().y);

    int posX;
    int posY;

    int diffX;
    int diffY;

    for (Tile* tile : tiles)
    {
        posX = tile->getPos().x;
        posY = tile->getPos().y;
      
        diffX = currPosX - posX;
        diffY = currPosY - posY;

        if ((diffX == 1 || diffX == -1 || diffX == 0) && (diffY == 1 || diffY == -1 || diffY == 0))
        {
            adjTiles.push_back(tile);
        }
    }

    return adjTiles;
}

Tile* Grid::getCurrTile(int index) {

    for (Tile* tile : tiles)
    {
        int indexDif = index - tile->getIndex();

        if (indexDif == 0)
        {
            return tile;
        }
    }
    
}

void Grid::updateTanks() {

    float tileX = SCRWIDTH / gridSize.x;
    float tileY = SCRHEIGHT / gridSize.y;

    for (int i = 0; i < tiles.size(); i++)
    {
        for (Tank* tank : tiles[i]->getTanks()) {
            indexX = (tank->get_position().x / tileX);
            indexY = (tank->get_position().y / tileY);

            if (tank->get_position().x > SCRWIDTH) {
                indexX = (ROWS - 1);
            }

            if (tank->get_position().y > SCRHEIGHT) {
                indexY = (COLS - 1);
            }

            if (tiles[i]->getPos().x != indexX || tiles[i]->getPos().y != indexY) {
                index = ((ROWS * indexY) + indexX);

                tank->setCurrTileIn(index);

                tiles[index]->addTank(tank);
                tiles[i]->removeTank(tank);
            }
        }
    }
}



