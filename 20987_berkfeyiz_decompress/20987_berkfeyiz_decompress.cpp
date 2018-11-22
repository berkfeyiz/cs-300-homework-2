//
//  20987_berkfeyiz_decompress.cpp
//  20987_berkfeyiz_decompress
//
//  Created by Feyiz on 21/11/18.
//  Copyright © 2018 Feyiz. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "BST.h"

using namespace std;

string dictionary[256];



string text(int a)
{
    return dictionary[a];
}

string fc(int b)
{
    return dictionary[b].substr(0,1);
}

bool inlist(int c)
{
    if(dictionary[c] != "")
    {return true;}
    else{return false;}
}


void decompress()
{
    string out_name;		// the name of the file that will be created
    out_name = "compin.txt";
    ofstream decompressed;	// the stream file of the created file
    decompressed.open(out_name);
    ifstream readfile;
    readfile.open("compout.txt");
    
    
    string str = " ";
    for ( int i = 0; i <255; i++)
    {
        unsigned char ch;
        ch = i ;
        str.at(0) = ch;
        dictionary[i] = str;
    }
    
    string g;
    int x;
    int q = -1;
    int insertcounter = 256;
    int testcounter = 0;
    
    while(getline(readfile,g))
    {
        istringstream gg(g);
        string ggg;

        while(gg>>ggg)
        {
         x = stoi(ggg);
        if(x < 255 && q == -1)
        {
            decompressed<< char(x);
        }
        else if(x<255 && q != -1)
        {
            decompressed << char(x);
            dictionary[insertcounter] = text(q)+fc(x);
            insertcounter++;
        }
        else if(x> 255 && inlist(x))
        {
            decompressed<< text(x);
            dictionary[insertcounter] = text(q)+fc(x);
            insertcounter++;
        }
        else if(x>255 && !inlist(x))
        {
            decompressed << text(q)+fc(q);
            dictionary[insertcounter] = text(q)+fc(q);
            insertcounter++;
        }
        q = x;
        testcounter++;
        }
    }
    
}

int main()
{
    decompress();
    
    return 0;
}
