//
//  main.cpp
//  20987_berkfeyiz_compress
//
//  Created by Feyiz on 20/11/18.
//  Copyright � 2018 Feyiz. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "BST.h"

void compress(){
	string out_name;
	char in;			// the name of the file that will be created
	out_name = "compout.txt";		
	ofstream compressed;	// the stream file of the created file
	compressed.open(out_name);
	ifstream readfile;
	readfile.open("compin.txt");
    string input = "";
   
    BST<string> *dictionary = new BST<string>();
    
	while(!readfile.eof())
	{
		readfile.get(in);
        input += in;
	}
    
    
    string p, pc;
    char c;
    bool end = false;
    
    
    int i = 256;
    while(input != "\r\n\n")
    {
        int ccount = 1;
        p = input[0];
        c = input[ccount];
        pc = p + c;
       
        while(dictionary->contains(pc) == true)
        {
            ccount++;
            p += c;
            c = input[ccount];
            pc = p + c;
            if(c== '\r')
            {pc = p; end = true; break;}
        }
        if(i != 4096)
        {dictionary->add(pc, i);}
        
        if(p.length() == 1 && end == false)
        {
            cout << int(p.at(0)) << " ";
            compressed << int(p.at(0)) << " ";
        }
        else if(p.length() > 1 && end == false)
        {
            cout << dictionary->fetch(p)->key << " ";
            compressed << dictionary->fetch(p)->key << " ";
        }
        else if (end == true)
        {
            if (dictionary->contains(pc) == true)
            {
                cout <<dictionary->fetch(pc)->key << " " << endl;
                compressed << dictionary->fetch(pc)->key << " " << endl;
            }
            
        }
        i++;
        input.erase(0, ccount);
        
    }
    compressed.close();
}

int main() {
   
	compress();
	
    return 0;
}
