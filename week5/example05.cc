#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename T>
void print_vec_index( const vector<T> & v ) {
  cout << '<';
  for (int sz = v.size(), i = 0; i < sz; ++i)
    cout << ' ' << v[i];
  cout << " >";
}

template <typename T>
void print_vec_iterator1( const vector<T> & v ) { // Old C++
  cout << '<';
    // UNCOMMENT the different for loops to see the errors you get.
  // WRONG: Need typename before template type since vector<T> doesn't exist!!!
  // for (vector<T>::const_iterator i = begin(v); i != end(v); ++i)
  // WRONG: Need a constant iterator, as v is a const reference
  // for (typename vector<T>::iterator i = begin(v); i != end(v); ++i)
  for (typename vector<T>::const_iterator i = begin(v); i != end(v); ++i)
    cout << ' ' << *i;
  cout << " >";
}

template <typename T>
void print_vec_iterator2( const vector<T> & v ) { // New C++ (C++11)
  cout << '<';
  for (auto i = begin(v); i != end(v); ++i)
    cout << ' ' << *i;
  cout << " >";
}

// Exercise 1
// Function to print out the elements of a list instead of a vector.
template <typename T>
void print_list_iterator(const list<T> &l) {
  cout << '<';
  for (auto i = begin(l); i != end(l); ++i) {
    cout << ' ' << *i;
  }
  cout << " >";
}

// Exercise 2
// Function to double each element.
void double_elements(list<int> &l) {
  for (auto i = begin(l); i != end(l); ++i) {
    *i *= 2;
  }
}

// Exercise 3
// Generalize previous function so that it works for every list of numbers (float, double, etc..)
template <typename T>
void double_any_elements(list<T> &n) {
  for (auto i = begin(n); i != end(n); ++i) {
    *i *= 2;
  }
}

int main() {
  vector<int> vi;
  vi.push_back(1);
  vi.push_back(2);
  vi.push_back(3);
  print_vec_index(vi); cout << endl;
  print_vec_iterator1(vi); cout << endl;
  print_vec_iterator2(vi); cout << endl;

  // Ex 1 test
  list<int> li;
  li.push_back(1);
  li.push_back(2);
  li.push_back(3);
  print_list_iterator(li);
  cout << endl;

  // Ex 2 test
  double_elements(li);
  print_list_iterator(li);
  cout << endl;

  // Ex 3 test
  list<double> ld;
  ld.push_back(5);
  ld.push_back(3);
  ld.push_back(8);
  double_any_elements(ld);
  print_list_iterator(ld);
  cout << endl;

  // Exercise 4
  // Initialise vector as copy of a list
  vector<int> v;
  for (auto i = li.begin(); i != li.end(); ++i) {
    v.push_back(*i);
  }
  print_vec_iterator2(v);
  cout << endl;

  return 0;
}
