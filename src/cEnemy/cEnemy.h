
#ifndef cEnemy_h
#define cEnemy_h


class cEnemy
{
private:
  int yCordinate;
public:
  cEnemy() = default;
  ~cEnemy() = default;
  virtual void draw() =0;
  virtual void sound() =0;
};

#endif // cEnemy
