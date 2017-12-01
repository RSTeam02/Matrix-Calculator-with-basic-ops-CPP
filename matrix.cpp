/**
 * @sakaijun
 * C++ Version
 * +,- or * of 2 Matrices
 *
 */

#include <iostream>
#include "matrix.h"
#include <iomanip>
#include <string.h> 
#include <vector>
#include <stdexcept> 
using namespace std;

Matrix::Matrix(){}
Matrix::Matrix(vector<vector<int>>& mat){
	currentMat = mat;
}


vector<vector<int>> Matrix::getMatrix(){
	return currentMat;
}

void Matrix::printRes(Matrix matRes){	
	for (int i =0; i<matRes.getMatrix().size(); i++){
		cout<<"(";
		for (int j=0; j<matRes.getMatrix()[0].size(); j++){
			cout<<setw(4)<<matRes.getMatrix()[i][j];			
		}
		cout<<setw(4)<<")"<<endl;	
	}
	cout<<endl;	
}

Matrix Matrix::matAddSub(char op, Matrix mat){

	vector<vector<int>>result(currentMat.size(),vector<int>(currentMat[0].size()));
	if(currentMat.size()==mat.getMatrix().size() && currentMat[0].size() == mat.getMatrix()[0].size()){
		for (int i =0; i<currentMat.size(); i++){
			for (int j=0; j< currentMat[0].size(); j++){
				result[i][j] = (op == '+') 
					? currentMat[i][j] + mat.getMatrix()[i][j] 
					: currentMat[i][j] - mat.getMatrix()[i][j];				
			}
		}			
	}else{
		throw invalid_argument("rows and cols of both matrices are not equal");
	}
	Matrix matRes(result);
	return matRes;
	
}


Matrix Matrix::matMult(Matrix mat){
	
	vector<vector<int>>result(currentMat.size(),vector<int>(mat.getMatrix()[0].size()));
	if(currentMat[0].size() == mat.getMatrix().size()){
		for (int r =0 ; r < currentMat.size(); r++){
			for (int c =0 ; c < mat.getMatrix()[0].size(); c++){
				result[r][c] =0;
				for (int k =0 ; k < currentMat[0].size(); k++){
					result[r][c] += currentMat[r][k] * mat.getMatrix()[k][c];						
				}					
			}		
		}
		Matrix matRes(result);	
	}else{
		throw invalid_argument("Number of colA and rowB are not equal");
	}	
	
	return result;	
	
}