#ifndef HEX_PUREMONTECARLO_H
#define HEX_PUREMONTECARLO_H

#include <utility>
#include <random>
#include <chrono>
#include "boardL.h"
#include "AI.h"

class PureMonteCarlo : public AIStrategy
{
private:
    std::default_random_engine rng_;
    double simulatePlay_(Board &board, const int niter, TileColour ai_colour, bool is_first) const;

public:
    PureMonteCarlo()
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        rng_.seed(seed);
    }
    std::pair<int, int> nextMove(Board &board, TileColour ai_colour, bool is_first) const override;
};

#endif 
