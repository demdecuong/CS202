#ifndef cRow_h
#define cRow_h

#include <vector>
#include "../cOneRow/cOneRow.h"

using namespace std;

class cRows
{
private:
  vector <cOneRow*> subRows;
public:
  cRows();
  ~cRows();
};

#endif // cRows
