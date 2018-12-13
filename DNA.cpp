#include "DNA.h"
#include "Sequence.h"
DNA::DNA()
{

}

DNA::DNA(char * Seq, DNA_Type atype,int length):Sequence(length)
{
    for (int i = 0 ; i<length ; i++)
    {
        seq[i]= Seq[i];
    }
    type = atype;
}
DNA::DNA(DNA& rhs)
{
    seq_length = rhs.seq_length;
    seq = new char [seq_length];
    for (int i = 0 ; i<seq_length ; i++)
    {
        seq[i] = rhs.seq[i];
    }
    type = rhs.type;
}

DNA::~DNA()
{
    delete [] seq;
}

void DNA::Print()
{
    cout<<"Sequence: ";
    for (int i=0 ; i<seq_length ; i++)
    {
        cout<<seq[i]<<" ";
    }

}

RNA DNA::ConvertToRNA()
{
    char* newRna = new  char [seq_length];
    for (int i = 0 ; i < seq_length ; i++)
    {
        if (seq[i]=='T')
        {
            newRna[i]='U';
        }
        else
        {
            newRna[i] = seq[i];
        }
    }
    for (int i = 0 ; i<seq_length ; i++)
    {
        seq[i]= newRna[i];
    }

    RNA convert(newRna,mRNA,seq_length);
    return convert;
}



void DNA::BuildComplementaryStrand()
{
    for (int i = 0 ; i < seq_length ; i++)
    {
        if (seq[i]=='A')
        {
            seq[i]='T';
        }
        else if (seq[i]=='T')
        {
            seq[i] = 'A';
        }

        else if (seq[i]=='C')
        {
            seq[i] = 'G';
        }
        else if (seq[i]=='G')
        {
            seq[i] = 'C';
        }
    }
    char *Reverse = new char[1];
    for (int i=0 ; i<seq_length/2 ; i++)
    {
        Reverse[0] = seq[i];
        seq[i] = seq[seq_length-i-1];
        seq[seq_length-i-1]=Reverse[0];
    }

}

istream& operator>> (istream& in,DNA& dna)
{
    int choosen;
    a:
    cout<<"What type of DNA you want to choose??"<<endl<<"1-DO you want promoter?"<<endl<<"2-Do you want motif"<<endl<<"3-Do you want tail"<<endl<<"4-Do you want noncoding"<<endl;
    cin>>choosen;
    try
    {
        if (choosen>4)
            throw 2;
    }
    catch(...)
    {
        cout<<"you have entered wrong number please enter a number again"<<endl;
        goto a;
    }

    if(choosen == 1)
    {
        dna.type = promoter;
    }
    else if(choosen == 2)
    {
        dna.type = motif;
    }
    else if(choosen==3)
    {
        dna.type = tail;
    }
    else
    {
        dna.type = noncoding;

    }

    cout << "Enter the length of the DNA sequence: ";
    in >> dna.seq_length;
    dna.seq = new char[dna.seq_length];
    cout<<"write your sequence"<<endl;
    b:
    try
    {
        for (int i=0; i<dna.seq_length; i++)
        {
            in >> dna.seq[i];
            if (dna.seq[i]!= 'A' && dna.seq[i]!= 'C' && dna.seq[i]!='G' && dna.seq[i]!='T')
            {
                throw 2;
            }
        }
    }
    catch(...)
    {
        cout<<"invalid Sequence"<<endl<<"DNA sequence must contain A C G T letters only please write your sequence again"<<endl;
        goto b;
    }


    return in;
}

ostream& operator<<(ostream& out, DNA &dna)
{
    string DNA_types[4]= {"Promoter","motif","tail","noncoding"};
    out << "DNA type: " << DNA_types[dna.type] << endl;
    out << "DNA sequence: ";
    for (int i=0; i<dna.seq_length; i++)
        out<< dna.seq[i];
    return out;
}

DNA& DNA::operator=(const DNA& dna)
{
    type = dna.type;
    seq_length = dna.seq_length;
    seq= new char[seq_length];
    for(int i=0; i<seq_length; i++)
        seq[i] = dna.seq[i];
    return *this;
}

bool DNA::operator==(DNA &dna)
{
    int cnt=0;
    if((type != dna.type) || (seq_length != dna.seq_length))
        return false;
    else
    {
        for(int i=0; i<seq_length; i++)
            if(seq[i] == dna.seq[i])
                cnt++;
        if(cnt == seq_length)
            return true;
        else
            return false;

    }
}

bool DNA::operator!= (DNA &dna)
{
    int cnt=0;
    if((type != dna.type) || (seq_length != dna.seq_length))
        return true;
    else
    {
        for(int i=0; i<seq_length; i++)
            if(seq[i] == dna.seq[i])
                cnt++;
        if(cnt == seq_length)
            return false;
        else
            return true;

    }
}


