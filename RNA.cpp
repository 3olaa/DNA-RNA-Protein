#include "RNA.h"
#include "Sequence.h"

RNA::RNA()
{
    type = mRNA;
}
RNA::RNA(char * Seq, RNA_Type atype,int length):Sequence(length)
{
    for (int i = 0 ; i<length ; i++)
    {
        seq[i]= Seq[i];
    }
    type = atype;
}

RNA::RNA(RNA& rhs)
{
    seq_length = rhs.seq_length;
    seq = new char [seq_length];
    for (int i = 0 ; i<rhs.seq_length ; i++)
    {
        seq[i] = rhs.seq[i];
    }
    type = rhs.type;
}
RNA::~RNA()
{
    delete [] seq;
}

void RNA::Print()
{
    for (int i=0 ; i<seq_length ; i++)
    {
        cout<<seq[i]<<" ";
    }
}

Protein RNA::ConvertToProtein()
{
    char *ch = new char [4];
    char *pSeq = new char [seq_length/3];
    CodonsTable c;
    if (seq_length % 3 == 0)
    {
        for (int i = 0 ; i<=seq_length; i+=3)
        {
            ch[i] = seq[i];
            ch[i+1] = seq[i+1];
            ch[i+2] = seq[i+2];
            ch[i+3]= '\0';
        }
        for (int i = 0 ; i<seq_length/3 ; i++)
        {
            pSeq[i] = c.getAminoAcid(ch).AminoAcid;
        }
        cout << pSeq;

        Protein convert(pSeq);
        return convert;
    }
    else
    {
        cout<<"can't convert to protein";
    }
}

DNA RNA::ConvertToDNA()
{
    char* newDna = new char [seq_length];
    for (int i = 0 ; i < seq_length ; i++)
    {
        if (seq[i]=='U')
        {
            newDna[i]='T';
        }
        else
        {
            newDna [i] = seq[i];
        }
    }
    for (int i = 0 ; i<seq_length ; i++)
    {
        seq[i]= newDna[i];
    }
    DNA convert(seq,promoter,seq_length);
    return convert;
}

istream&operator>>(istream& in, RNA &rna )
{
    int choosen;
a:
    cout<<"What type of RNA you want to choose??"<<endl<<"1-DO you want mRNA?"<<endl<<"2-Do you want pre_mRNA"<<endl<<"3-Do you want mRNA_exon"<<endl<<"4-Do you want mRNA_intron"<<endl;
    try
    {
        cin>>choosen;
        if (choosen>4)
            throw 2;
    }
    catch(...)
    {
        cout<<"you have entered wrong number please choose again"<<endl;
        goto a;
    }

    if(choosen == 1)
    {
        rna.type = mRNA;
    }
    else if(choosen == 2)
    {
        rna.type = pre_mRNA;
    }
    else if(choosen == 3)
    {
        rna.type = mRNA_exon;
    }
    else
    {
        rna.type = mRNA_intron;
    }

    cout << "Enter the length of the RNA sequence: ";
    in >> rna.seq_length;
    rna.seq = new char[rna.seq_length];
    cout<<"write your sequence"<<endl;
    b:
    try
    {
        for (int i=0; i<rna.seq_length; i++)
        {
            in >> rna.seq[i];
            if (rna.seq[i]!= 'A' && rna.seq[i]!= 'C' && rna.seq[i]!='G' && rna.seq[i]!='U')
            {
                throw 2;
            }
        }
    }
    catch(...)
    {
        cout<<"invalid Sequence"<<endl<<"RNA sequence must contain A C G U letters only please write your sequence again"<<endl;
        goto b;
    }

    return in;
}

ostream& operator<<(ostream& out, RNA &rna)
{
    string RNA_types[4]= {"mRNA","pre_mRNA","mRNA_exon","mRNA_intron"};
    out << "RNA type: " << RNA_types[rna.type] << endl;
    out << "RNA sequence: ";
    for (int i=0; i<rna.seq_length; i++)
        out<< rna.seq[i];
    return out;
}

RNA& RNA::operator=(const RNA& rna)
{
    type = rna.type;
    seq_length = rna.seq_length;
    seq= new char[seq_length];
    for(int i=0; i<seq_length; i++)
        seq[i] = rna.seq[i];
    return *this;
}

bool RNA::operator== (RNA &rna)
{
    int cnt=0;
    if((type != rna.type) || (seq_length != rna.seq_length))
        return false;
    else
    {
        for(int i=0; i<seq_length; i++)
            if(seq[i] == rna.seq[i])
                cnt++;
        if(cnt == seq_length)
            return true;
        else
            return false;

    }
}

bool RNA::operator!= (RNA &rna)
{
    int cnt=0;
    if((type != rna.type) || (seq_length != rna.seq_length))
        return true;
    else
    {
        for(int i=0; i<seq_length; i++)
            if(seq[i] == rna.seq[i])
                cnt++;
        if(cnt == seq_length)
            return false;
        else
            return true;

    }
}

RNA RNA::operator+(RNA s)
{
    int sumSize = (seq_length + s.seq_length );
    char* Seq = new char[sumSize];
    for (int i = 0; i < seq_length; i++)
    {
        Seq[i] = seq[i];
    }
    for (int i = seq_length ; i< s.seq_length ; i++)
    {
        Seq[i] = s.seq[i];
    }
    RNA Sum(Seq,type,sumSize);
    return Sum;
}

