#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <set>
#define _USE_MATH_DEFINES
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int Cross(int x1, int y1, int x2, int y2)
{
	return (x1 * y2) - (y1 * x2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	cout.tie(nullptr);
	
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	int ux = x2 - x1;
	int uy = y2 - y1;
	int vx = x3 - x2;
	int vy = y3 - y2;
	int Crossuv = Cross(ux, uy, vx, vy);
	if (Crossuv == 0) cout << 0;
	else Crossuv > 0 ? cout << 1 : cout << -1;
	
}