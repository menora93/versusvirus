#include <cinttypes>
#include <vector>
#include <string>
#include <random>

#include "util.hpp"

#pragma once

typedef size_t index_t;

namespace ABM
{

    enum AgeCat { Minor, Adult, Old};
    enum HealthCat { Susceptible, Exposed, Infected, Recovered};

    struct Agent
    {
        index_t Household;
        index_t Workplace;
        AgeCat Age;
        HealthCat Health;

        double Get_c(const double symptomaticCases) const;
        double Get_I() const;


    };

    struct Household
    {
        index_t Municipality;
    };

    struct Workplace
    {
        index_t Municipality;
    };

    struct Municipality
    {
        index_t BfsId;
        std::string Name;
        std::pair<double,double> Coordinates;
        index_t Plz;
     
    };

    struct HelpPopulation
    {
        index_t BfsId;
        index_t NPeople;
        double  pYoung;
        double  pMiddle;
        double  pOld;
        index_t NHouseholds;
        index_t NWorker;
        index_t NWorkplaces;
    };

    struct Commuter
    {
        index_t BfsId;
        index_t WorkId;
        index_t CantonId;
        index_t NCommuters;
    };


    class Population
    {
        private:

        SparseMatrix DistanceWeights;

        public:
        std::vector<Agent> Agents;
        std::vector<Household> Households;
        std::vector<Workplace> Workplaces;



        // Initilize class and fill Agents, Households and Workplaces see Figure 2 in "Additional file"
        Population(/* data */)
        {}

        void assignAgentsToHouseholds( /* data */);

        void assignAgentsToWorkplaces( /* data */);


        std::vector<index_t> GetAgentsOfHousehold(index_t hhIdx) const;
        std::vector<index_t> GetAgentsOfWorkplace(index_t wpIdx) const;

        Household GetHouseholdOfAgent(index_t agentIdx) const;
        Workplace GetWorkplaceOfAgent(index_t agentIdx) const;
    };
}