//
// Created by Krushikesh Sunil Shelar on 10/01/25.
//
// This file defines an abstract base class `GenericRubiksCube` for modeling a Rubik's Cube.
// The class provides an interface for cube operations such as rotation, shuffling, and state retrieval.
// Derived classes must implement the pure virtual methods to provide specific representations of the cube.


#ifndef GENERICRUBIKSCUBE_H
#define GENERICRUBIKSCUBE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random> // For random number generation
#include <ctime>  // For time functions
using namespace std;

/**
 * GenericRubiksCube
 *
 * An abstract base class representing a Rubik's Cube. It defines the basic operations
 * and properties of a cube, such as face colors, moves, and shuffling.
 *
 * Key Features:
 * - Enums for FACE, MOVE, and COLOR to encapsulate cube-specific constants.
 * - Pure virtual functions for cube manipulations (to be implemented by derived classes).
 * - Utility functions for printing, shuffling, and working with cube states.
 *
 * Usage:
 * - Derive this class to create a specific cube representation (e.g., 3D array-based, flat array-based).
 */

class GenericRubiksCube
{
public:
    enum class FACE
    {
        UP, LEFT, FRONT, RIGHT, BACK, DOWN
    };

    enum class MOVE
    {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    enum class COLOR
    {
        WHITE, GREEN, BLUE, RED, ORANGE, YELLOW
    };

    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    static char getColorLetter(COLOR color);

    virtual bool isSolved() const = 0;

    static string getMove(MOVE);

    void print() const;

    vector<MOVE> randomShuffleCube(unsigned int times);

    GenericRubiksCube& move(MOVE ind);
    GenericRubiksCube& invert(MOVE ind);

    virtual GenericRubiksCube& f() = 0;
    virtual GenericRubiksCube& fPrime() = 0;
    virtual GenericRubiksCube& f2() = 0;
    virtual GenericRubiksCube& b() = 0;
    virtual GenericRubiksCube& bPrime() = 0;
    virtual GenericRubiksCube& b2() = 0;
    virtual GenericRubiksCube& r() = 0;
    virtual GenericRubiksCube& rPrime() = 0;
    virtual GenericRubiksCube& r2() = 0;
    virtual GenericRubiksCube& d() = 0;
    virtual GenericRubiksCube& dPrime() = 0;
    virtual GenericRubiksCube& d2() = 0;
    virtual GenericRubiksCube& u() =0;
    virtual GenericRubiksCube& uPrime() = 0;
    virtual GenericRubiksCube& u2() = 0;
    virtual GenericRubiksCube& l() = 0;
    virtual GenericRubiksCube& lPrime() = 0;
    virtual GenericRubiksCube& l2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;
};


#endif //GENERICRUBIKSCUBE_H
