// Eric Chun - jc2ppp - 10/10/20 - hashTable.cpp

#include "hashTable.h"
using namespace std;

hashTable::hashTable(int size) {
  if (checkPrime(size)) tableSize = 2 * size;
  else tableSize = nextPrime(2 * size);
  
  buckets = new vector<list<string>>;
  buckets->resize(tableSize);
  for (int i = 0; i < tableSize; i++) {
    list<string> temp;
    buckets->push_back(temp);
  }
}

hashTable::~hashTable(){
  delete buckets;
}

bool hashTable::checkPrime(unsigned int x) {
  if (x <= 1) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (int i = 3; i*i <= x; i += 2){
    if (x % i == 0) return false;
  }
  return true;
}

int hashTable::nextPrime(unsigned int x) {
  while (!checkPrime(++x));
  return x;
}

unsigned int hashTable::getHash(string key) {
  /**unsigned int h = 5381;
  char c;
  for (int i = 0; i < key.size(); i++) {
    c = key[i];
    h = ((h << 5) + h) + c;
  }
  return h % tableSize;**/

  unsigned int p = 37;
  long p_pow = 1;
  unsigned int h = 0;
  char c;
  for (int i = 0; i < key.size(); i++) {
    c = key[i];
    h = (h + (c - 'a' + 1) * p_pow);
    p_pow = (p_pow * p);
  }
  return h % tableSize;
}

void hashTable::insert(string key) {
  if (!(this->contains(key))) {
    list<string>& myList = buckets->at(getHash(key));
    myList.push_back(key);
  }
}

bool hashTable::contains(string key) {
  list<string>& myList = buckets->at(getHash(key));
  for (list<string>::iterator i = myList.begin(); i != myList.end(); ++i) {
    if (key == *i) return true;
  }
  return false;
}
