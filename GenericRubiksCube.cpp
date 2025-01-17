//
// Created by Krushikesh Sunil Shelar  on 10/01/25.
//
//

#include "GenericRubiksCube.h"

// Returns the first letter of a color.
char GenericRubiksCube::getColorLetter(COLOR color)
{
    switch (color)
    {
    case COLOR::RED: return 'R';
    case COLOR::GREEN: return 'G';
    case COLOR::BLUE: return 'B';
    case COLOR::WHITE: return 'W';
    case COLOR::ORANGE: return 'O';
    case COLOR::YELLOW: return 'Y';
    }
}

// Converts a MOVE enum to a string.
string GenericRubiksCube::getMove(MOVE move)
{
    switch (move)
    {
    case MOVE::L: return "L";
    case MOVE::LPRIME: return "L'";
    case MOVE::L2: return "L2";
    case MOVE::R: return "R";
    case MOVE::RPRIME: return "R'";
    case MOVE::R2: return "R2";
    case MOVE::U: return "U";
    case MOVE::UPRIME: return "U'";
    case MOVE::U2: return "U2";
    case MOVE::D: return "D";
    case MOVE::DPRIME: return "D'";
    case MOVE::D2: return "D2";
    case MOVE::F: return "F";
    case MOVE::FPRIME: return "F'";
    case MOVE::F2: return "F2";
    case MOVE::B: return "B";
    case MOVE::BPRIME: return "B'";
    case MOVE::B2: return "B2";
    default: return "?";
    }
}


vector<GenericRubiksCube::MOVE> GenericRubiksCube::randomShuffleCube(unsigned int times)
{
    vector<MOVE> moves = {
        MOVE::L, MOVE::LPRIME, MOVE::L2, MOVE::R, MOVE::RPRIME, MOVE::R2,
        MOVE::U, MOVE::UPRIME, MOVE::U2, MOVE::D, MOVE::DPRIME, MOVE::D2,
        MOVE::F, MOVE::FPRIME, MOVE::F2, MOVE::B, MOVE::BPRIME, MOVE::B2
    };
    vector<MOVE> shuffle;

    // Seed for randomness
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < times; i++)
    {
        MOVE randomMove = moves[rand() % moves.size()];
        shuffle.push_back(randomMove);
        // Apply the move to the cube
        this->move(randomMove);
    }
    return shuffle;
}


GenericRubiksCube& GenericRubiksCube::move(MOVE ind)
{
    switch (ind)
    {
    case MOVE::L: return this->l();
    case MOVE::LPRIME: return this->lPrime();
    case MOVE::L2: return this->l2();
    case MOVE::R: return this->r();
    case MOVE::RPRIME: return this->rPrime();
    case MOVE::R2: return this->r2();
    case MOVE::U: return this->u();
    case MOVE::UPRIME: return this->uPrime();
    case MOVE::U2: return this->u2();
    case MOVE::D: return this->d();
    case MOVE::DPRIME: return this->dPrime();
    case MOVE::D2: return this->d2();
    case MOVE::F: return this->f();
    case MOVE::FPRIME: return this->fPrime();
    case MOVE::F2: return this->f2();
    case MOVE::B: return this->b();
    case MOVE::BPRIME: return this->bPrime();
    case MOVE::B2: return this->b2();
    default: return *this;
    }
}

GenericRubiksCube& GenericRubiksCube::invert(MOVE ind)
{
    switch (ind)
    {
    case MOVE::L: return this->lPrime();
    case MOVE::LPRIME: return this->l();
    case MOVE::L2: return this->l2();
    case MOVE::R: return this->rPrime();
    case MOVE::RPRIME: return this->r();
    case MOVE::R2: return this->r2();
    case MOVE::U: return this->uPrime();
    case MOVE::UPRIME: return this->u();
    case MOVE::U2: return this->u2();
    case MOVE::D: return this->dPrime();
    case MOVE::DPRIME: return this->d();
    case MOVE::D2: return this->d2();
    case MOVE::F: return this->fPrime();
    case MOVE::FPRIME: return this->f();
    case MOVE::F2: return this->f2();
    case MOVE::B: return this->bPrime();
    case MOVE::BPRIME: return this->b();
    case MOVE::B2: return this->b2();
    default: return *this;
    }
}
