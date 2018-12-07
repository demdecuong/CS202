#ifndef cPosition_h
#define cPosition_h

class cPosition {
protected:
    int X, Y;
public:
    int getX();
	int getY();
    cPosition();
    cPosition(int x, int y);
    ~cPosition();
};

#endif // cPosition
