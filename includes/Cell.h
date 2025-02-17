#ifndef CELL_H
#define CELL_H

#include "Genome.h"

using namespace std;

class Cell : public Genome
{
protected:
    vector<Genome> chromosomes;
    // A list of Genome objects representing chromosomes.

public:
    Cell(const vector<pair<string, string>> &chromosomeDNA);
    // Constructor to initialize the chromosomes (no RNA for chromosomes)

    void printChromosomeContents() const;
    /* Loops through the chromosomes vector, retrieving and printing the DNA strands of each chromosome
    using the 'getDNA' method from the Genome class.
    This gives a clear view of the genetic makeup of each chromosome. */

    vector<Genome> getChromosomes() const;
    // Returns all chromosomes stored in the cell allowing other parts of the program to examine or manipulate the chromosomes.

    int count() const;
    // Simply returns the size of the chromosomes vector.

    bool checkForCellDeath();
    /* This method iterates through each chromosome and checks for mismatches in base pairing and counts A-T and C-G pairs.
    If more than 5 mismatches are found or if the ratio of A-T pairs to C-G pairs exceeds 3:1,
    the method returns true, indicating the cell is unhealthy and should die. */

    void largeMutation(const string &S1, int n, const string &S2, int m);
    /* This method calls the 'largeMutation' method on the n-th chromosome to replace the first occurrence of S1 with S2,
    and then performs a similar operation on the m-th chromosome, ensuring that genetic alterations are mirrored. */

    void smallMutation(char from, char to, int n, int m);
    // This method executes the 'smallMutation' method on the m-th chromosome, replacing occurrences of 'from' with 'to'.

    void reverseMutation(const string &S1, int n);
    /* This method calls the reverseMutation method on the n-th chromosome,
    modifying the genetic content by reversing the first occurrence of S1. */

    void findComplementaryPalindromes(int m);
    /* This method checks substrings of the DNA strands for palindromic properties,
    using nested loops to evaluate every possible substring length.
    If a substring matches its complementary reverse, it is printed as a complementary palindrome. */
};

#endif