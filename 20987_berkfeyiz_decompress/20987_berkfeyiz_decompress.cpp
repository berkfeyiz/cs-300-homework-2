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

void decompress()
{
    
    string dictionary[256];
    string str = " ";
    for ( int i = 0; i <255; i++)
    {
        unsigned char ch;
        ch = i ;
        str.at(0) = ch;
        dictionary[i] = str;
        cout << dictionary[i];
    }
    
}

int main()
{
    decompress();
    return 0;
}
