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
	//compressed.open(out_name);
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
    while(input != "\r\n\n" )
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
            {pc = p; end = true;}
        }
        dictionary->add(pc, i);
        if(p.length() == 1 && end == false)
        {
            cout << int(p.at(0)) << " ";
        }
        else if(p.length() > 1 && end == false)
        {
            cout << dictionary->fetch(p)->key << " ";
        }
        i++;
        input.erase(0, ccount);
        
    }
    
    
   /* p = input[0];
    c = input[1];
    pc = p + c;
    
    cout << "p: "<< p << " c: " << c << " pc :" << pc << endl;
    
    p += c;
    c = input[2];
    pc = p + c;
    
    cout << "p: "<< p << " c: " << c << " pc :" << pc << endl;
    
    p += c;
    c = input[3];
    pc = p + c;
    
    cout << "p: "<< p << " c: " << c << " pc :" << pc << endl;

    p += c;
    c = input[4];
    pc = p + c;
    
    cout << "p: "<< p << " c: " << c << " pc :" << pc << endl;
    */
}

int main() {
   
	compress();
	
	
	/* BST<int> *bst = new BST<int>();
    bst->add(11);  bst->add(1);  bst->add(6); bst->add(-1); bst->add(-10); bst->add(100);
    bst->print();
    cout<<endl;
    cout<<"Nodes count: "<<bst->nodesCount();
    cout<<endl;
    cout<<"Height: "<<bst->height();
    cout<<endl;
    cout<<"Max path: ";
    bst->printMaxPath();
    cout<<endl;
    bst->deleteValue(11);
    cout<<"11 removed: ";
    bst->print();
    cout<<endl;
    cout<<"1 removed: ";
    bst->deleteValue(1);
    bst->print();
    cout<<endl;
    cout<<"-1 removed: ";
    bst->deleteValue(-1);
    bst->print();
    cout<<endl;
    cout<<"6 removed: ";
    bst->deleteValue(6);
    bst->print();
    cout<<endl;
    cout<<"-10 removed: ";
    bst->deleteValue(-10);
    bst->print();
    cout<<endl;
    cout<<"100 removed: ";
    bst->deleteValue(100);
    bst->print();
    cout<<endl;*/
    return 0;
}
