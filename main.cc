#include <iostream>
#include <fstream>
#include <algorithm>
#include "dynmatrix.h"

using namespace std;

// construct a string representation 

void usage() {
  cerr << "Usage: upgma species.txt" << endl;
}

int main( int argc, char *argv[] ) {
  if( argc != 2 ) {
    usage();
    return 0;
  }

  // let's start with empty DynMatrix:
  ClusterNode* head = NULL; 
  ClusterNode* tail = NULL;

  int n = 0; // number of species
  ifstream fin( argv[1] );
  if( fin.is_open() ) {
    // read species:
    string species;
    while ((fin.peek() != '\n') && (fin >> species)) {
      n++;
      cout << species << endl;
      // YOUR CODE HERE: replace print statemnt by a code that insert a new species into DynMatrix
    }
    // read distances:
    for (int i=0; i<n && fin; i++)
      for (int j=0; j<n && fin; j++) {
	double d;
	fin >> d;
	cout << d << endl;
      // YOUR CODE HERE: replace print statemnt by a code that updates distance field of the corresponding DistanceNode
      }
    fin.close();
  }

  // YOUR CODE HERE: implement UPGMA method

  // print the name of the last remaining cluster
  if (head)
    cout << head->name << endl;

  // BONUS (optional): print the tree in a nice way

  return 0;
}
