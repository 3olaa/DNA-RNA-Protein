#include "Sequence.h"

Sequence::Sequence()
{

}

Sequence::Sequence(int length)
{

    seq = new char [length];
    seq_length = length;

}

Sequence::Sequence(Sequence& rhs)
{
    seq_length = rhs.seq_length;
    seq = new char [seq_length];
    for (int i = 0 ; i<seq_length ; i++)
    {
        seq[i] = rhs.seq[i];
    }
}

Sequence::~Sequence()
{
    delete [] seq;
}

char* Align(Sequence * s1, Sequence * s2)
{
}

