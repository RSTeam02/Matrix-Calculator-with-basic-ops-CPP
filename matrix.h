#ifndef PrintArr_H
#define PrintArr_H
#include <vector>
using namespace std;

class Matrix{

public:
	Matrix();	
	Matrix(vector<vector<int>>& mat);			
	Matrix matAddSub(char op, Matrix mat);	
	Matrix matMult(Matrix mat);
	vector<vector<int>> getMatrix();
	void printRes(Matrix matRes);	
private:
	vector<vector<int>> currentMat;
};
#endif