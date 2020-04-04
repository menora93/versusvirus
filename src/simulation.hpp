#include <iostream>
#include <math.h>void PerformTimeStep(Population& population, Parameters& parameters);
#include "entities.hpp"
#include "parameters.hpp"

#pragma once

namespace ABM
{
    void PerformTimeStep(Population& population, Parameters& parameters);
    double lambda(const index_t agentIdx, const Population& population, const Parameters& parameters);
}