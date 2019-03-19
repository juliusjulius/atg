#pragma once

class Hrana
{
	int v1;
	int v2;
	int stav;
	bool hranaPP;
 
public:
	Hrana(int v1, int v2) : v1(v1), v2(v2), stav{ 0 }, hranaPP{ false } {};
	~Hrana();

	int getHranaV1() { return v1; };
	int getHranaV2() { return v2; };
	int getStav() { return stav; };
	int getHranaPP() { return hranaPP; };
	void setStav() { stav++; };
	void setHranaPP() { hranaPP = true; };

};

