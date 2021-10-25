#ifndef LUX_BOT_LOGIC_SETUP_HPP_
#define LUX_BOT_LOGIC_SETUP_HPP_

#include <vector>
#include <string>

void setup(kit::Agent *gameState, std::vector<std::string> *actions,
				std::vector<lux::Cell *> *woodTiles,
				std::vector<lux::Cell *> *coalTiles,
				std::vector<lux::Cell *> *uraniumTiles,
				std::vector<lux::Cell *> *availableResourceTiles){
	
	lux::GameMap &gameMap = gameState->map;

	for (int x = 0; x < gameMap.width; x++) {
		for (int y = 0; y < gameMap.height; y++) {
			lux::Cell *cell = gameMap.getCell(x,y);
			if (cell->hasResource()) {
				if (cell->resource.type == lux::ResourceType::wood) {
					woodTiles->push_back(cell);
					actions->push_back(lux::Annotate::text(x, y, std::to_string(cell->resource.amount) + " wood"));
				}
				if (cell->resource.type == lux::ResourceType::coal) {
					coalTiles->push_back(cell);
					actions->push_back(lux::Annotate::text(x, y, std::to_string(cell->resource.amount) + " coal"));
				}
				if (cell->resource.type == lux::ResourceType::uranium) {
					uraniumTiles->push_back(cell);
					actions->push_back(lux::Annotate::text(x, y, std::to_string(cell->resource.amount) + " uranium"));
				}
			}
		}

		availableResourceTiles = woodTiles;
		//availableResourceTiles->insert(availableResourceTiles->end(), coalTiles->begin(), coalTiles->end());
	}
}
#endif // #ifndef LUX_BOT_LOGIC_STARTUP_HPP_