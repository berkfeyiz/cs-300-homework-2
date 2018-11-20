//
//  binarysearchtree.h
//  20987_berkfeyiz_compress
//
//  Created by Feyiz on 20/11/18.
//  Copyright © 2018 Feyiz. All rights reserved.
//

#ifndef binarysearchtree_h
#define binarysearchtree_h

#include <iostream>

using namespace std;

template <typename Comparable>
 class BinarySearchTree
 {
     public:
     BinarySearchTree( );
     BinarySearchTree( const BinarySearchTree & rhs );
     BinarySearchTree( BinarySearchTree && rhs );
     ~BinarySearchTree( );
    
     const Comparable & findMin( ) const;
     const Comparable & findMax( ) const;
     bool contains( const Comparable & x ) const;
     bool isEmpty( ) const;
     void printTree( ostream & out = cout ) const;
    
     void makeEmpty( );
     void insert( const Comparable & x );
     void insert( Comparable && x );
     void remove( const Comparable & x );
    
     BinarySearchTree & operator=( const BinarySearchTree & rhs );
     BinarySearchTree & operator=( BinarySearchTree && rhs );
    
     private:
     struct BinaryNode
     {
         Comparable element;
         BinaryNode *left;
         BinaryNode *right;
    
         BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
         : element{ theElement }, left{ lt }, right{ rt } { }
        
         BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
         : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
         };
    
     BinaryNode *root;
    
     void insert( const Comparable & x, BinaryNode * & t );
     void insert( Comparable && x, BinaryNode * & t );
     void remove( const Comparable & x, BinaryNode * & t );
     BinaryNode * findMin( BinaryNode *t ) const;
     BinaryNode * findMax( BinaryNode *t ) const;
     bool contains( const Comparable & x, BinaryNode *t ) const;
     void makeEmpty( BinaryNode * & t );
     void printTree( BinaryNode *t, ostream & out ) const;
     BinaryNode * clone( BinaryNode *t ) const;
};

bool contains( const Comparable & x ) const
{
     return contains( x, root );
}

void insert( const Comparable & x )
{
     insert( x, root );
}
void remove( const Comparable & x )
{
     remove( x, root );
}
#endif /* binarysearchtree_h */
