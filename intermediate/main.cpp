#include "lux/kit.hpp"
#include "lux/define.cpp"
#include <string.h>
#include <vector>
#include <set>
#include <stdio.h>

#include <iostream>

#include "logic/setup.hpp"

int main()
{
  kit::Agent gameState = kit::Agent();
  // initialize
  gameState.initialize();

  while (true)
  {
    /** Do not edit! **/
    // wait for updates
    gameState.update();

    std::vector<std::string> actions = std::vector<std::string>();

		/** AI Code Goes Below! **/
		lux::Player &player = gameState.players[gameState.id];
    lux::Player &opponent = gameState.players[(gameState.id + 1) % 2];

    lux::GameMap &gameMap = gameState.map;

		// Generate seperate lists of wood, coal and uranium tiles
		
		std::vector<lux::Cell *> woodTiles = std::vector<lux::Cell *>();
		std::vector<lux::Cell *> coalTiles = std::vector<lux::Cell *>();
		std::vector<lux::Cell *> uraniumTiles = std::vector<lux::Cell *>();
		std::vector<lux::Cell *> availableResourceTiles = std::vector<lux::Cell *>();

		setup(&gameState, &actions, &woodTiles, &coalTiles, &uraniumTiles, &availableResourceTiles);

		for(auto x : availableResourceTiles){
			
		}

		actions.push_back(lux::Annotate::x(uraniumTiles[0]->pos.x, uraniumTiles[0]->pos.y));



    
    

/*
    Player &player = gameState.players[gameState.id];
    Player &opponent = gameState.players[(gameState.id + 1) % 2];

    GameMap &gameMap = gameState.map;

		// Generates a list of resource tiles
    vector<Cell *> resourceTiles = vector<Cell *>();
    for (int y = 0; y < gameMap.height; y++)
    {
      for (int x = 0; x < gameMap.width; x++)
      {
        Cell *cell = gameMap.getCell(x, y);
        if (cell->hasResource())
        {
          resourceTiles.push_back(cell);
        }
      }
    }

    // We iterate over all our units and do something with them
    for (int i = 0; i < player.units.size(); i++)
    {
      Unit unit = player.units[i];
      if (unit.isWorker() && unit.canAct())
      {
        if (unit.getCargoSpaceLeft() > 0)
        {
          // if the unit is a worker and has space in cargo, finds the nearest resource tile and tries to mine it
          Cell *closestResourceTile;
          float closestDist = 9999999;
          for (auto it = resourceTiles.begin(); it != resourceTiles.end(); it++)
          {
            auto cell = *it;
            if (cell->resource.type == ResourceType::coal && !player.researchedCoal()) continue;
            if (cell->resource.type == ResourceType::uranium && !player.researchedUranium()) continue;
            float dist = cell->pos.distanceTo(unit.pos);
            if (dist < closestDist)
            {
              closestDist = dist;
              closestResourceTile = cell;
            }
          }
          if (closestResourceTile != nullptr)
          { 
            auto dir = unit.pos.directionTo(closestResourceTile->pos);
            actions.push_back(unit.move(dir));
          }
        }
        else
        {
          // if unit is a worker and there is no cargo space left, and we have cities, lets return to them
          if (player.cities.size() > 0)
          {
            auto city_iter = player.cities.begin();
            auto &city = city_iter->second;

            float closestDist = 999999;
            CityTile *closestCityTile;
            for (auto &citytile : city.citytiles)
            {
              float dist = citytile.pos.distanceTo(unit.pos);
              if (dist < closestDist)
              {
                closestCityTile = &citytile;
                closestDist = dist;
              }
            }
            if (closestCityTile != nullptr)
            {
              auto dir = unit.pos.directionTo(closestCityTile->pos);
              actions.push_back(unit.move(dir));
            }
          }
        }
      }
    }

    // you can add debug annotations using the methods of the Annotate class.
    // actions.push_back(Annotate::circle(0, 0));*/

    /** AI Code Goes Above! **/

    /** Do not edit! **/
    for (int i = 0; i < actions.size(); i++)
    {
      if (i != 0)
        std::cout << ",";
      std::cout << actions[i];
    }
    std::cout << std::endl;
    // end turn
    gameState.end_turn();
  }

  return 0;
}
