#include <iostream>
using namespace std;

// #define MAIN_ARGS

#ifndef MAIN_ARGS
/* main without input arguments */
int main() {
  cout << "Hello Duc" << endl;

  return 0;
  // throw new domain_error("error!");
}

#else 
/* main with input arguments */
int main(int argc, char *argv[]) {
  cout << "Input arguments: " << argc << endl;
  for (int i = 0; i < argc; i++) {
    cout << "argv[" << i << "] = " << argv[i] << endl;
  }
  cout << endl;

  return 0;
}
#endif 