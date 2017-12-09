/**
 * @sakaijun
 * C++ Version
 * 
 * init 2 dim matrix as vector
 * calculate n Matrices +,-,*
 *  
 */

#include <iostream>
#include <vector> 
#include "matrix.h"
using namespace std;
Matrix result;
short countMat = 1;

//input validation number of row, columns
short *validRowCol(){
	short *rowCol = new short[2];
	cout<<"Enter row (A"<<countMat<<"): "; 
	do{
		cin >> rowCol[0]; 
		if (!cin){
			cout<<"not an integer, repeat input\n";
			cin.clear();
			cin.ignore();
		}else{
			break;
		}
	}while(1);
	cout<<"Enter col (A"<<countMat<<"): ";
	do{
		cin >> rowCol[1];
		if (!cin){
			cout<<"not an integer, repeat input\n";
			cin.clear();
			cin.ignore();
		}else{
			break;
		}	
	}while(1);
	return rowCol;
}

//input validation of matrix(ces), append operand for continue calculation t/f
vector<Matrix> validMat(int numOfMat){
	vector<Matrix> a;	
	a.reserve(numOfMat);	
	vector<vector<vector<int>>> m;
	for(int n = 0; n < numOfMat; n++){
		short *rowCol = validRowCol();
		m.resize(numOfMat);
		for (int i =0 ; i < rowCol[0]; i++){
			m[n].resize(rowCol[0]);
			for (int j =0 ; j < rowCol[1]; j++){
				m[n][i].resize(rowCol[1]);
				do{			
					int tmp = 0;
					cout <<"A"<<countMat<<": "<< "a"<<(i+1)<<(j+1)<<"=";
					cin >> tmp;
					m[n][i][j]=tmp;	
					if (!cin){
						cout<<"not an integer, repeat input\n";
						cin.clear();
						cin.ignore();		                                
					}else{
						break;
					}
				}while(1);					
			}	
		}

		a.emplace_back(m[n]);
		a[n].printRes(a[n]);
		countMat++;
	}
	return a;
}

//input validation of calc operation
char validOp(){
	char op;
	cout << "Choose operation: +, - or *: ";
	cin >> op;
	while(op != '+' && op != '*' && op != '-'){		
		cout<<"not an operation, repeat input\n";
		cin.clear();
		cin.ignore();	
		cin >> op;
	}	
	return op;
}

//return result of operation
void resultMat(bool appendLast, char op, vector<Matrix> m){	
	switch (op){
		case '+':
		case '-': 
			result = (appendLast) ? result.matAddSub(op, m[0]) : m[0].matAddSub(op, m[1]);		
			break;
		case '*':
			result = (appendLast) ? result.matMult(m[0]) : m[0].matMult(m[1]);	
			break;				
	}
	result.printRes(result);
}

void testOutput(vector<Matrix> m){
	for(auto x : m){
		x.printRes(x);
	}
}

//start main
int main(){	
	bool firstCalc = true;
	do{
		char op;
		char selection;
		cout<<"n: new calculation\nc: continue calculation with last result\nany key, except n, c: end program\n";  
		cin>>selection;
		//first calc with 2 matrices: result = m_a operation m_b
		if(selection == 'n'){
			countMat =1;
			vector<Matrix> m_ab = validMat(2);	
			op = validOp();
			cout<<"Result:\n";	
			resultMat(false, op, m_ab);
			//testOutput(m_ab);
			firstCalc = false;
		//chain every other mat with last result: result = result operation m_x
		}else if(selection == 'c'){
			if(!firstCalc){
				vector<Matrix> m_x = validMat(1);	
				op = validOp();
				cout<<"Result:\n";	
				resultMat(true, op, m_x);
			}else{
				cout<<"2 operands required, choose n.\n\n";
				continue;				
			}
		//end program
		}else{
			exit(0);			
		}
	}while(1);
	
}
