// Eric Chun - jc2ppp - 10/10/20 - hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <math.h>
using namespace std;

class hashTable {
 public: 
  hashTable(int size);
  ~hashTable();

  void insert(string key);
  bool contains(string key);
  bool checkPrime(unsigned int x);
  int nextPrime(unsigned int x);
  
 private:
  vector<list<string>>* buckets;
  unsigned int getHash(string key);
  int tableSize;
};

#endif
