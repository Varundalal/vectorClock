//============================================================================
// Name        : vClock.cpp
// Author      : Varun
// Version     :
// Copyright   : Your copyright notice
// Description : vClock in C++, Ansi-style
//============================================================================

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include <vector>
#include<string.h>
#define mP 50
#define mE 50
using namespace std;


int main(){
	char C;
	int SizeE[mP],n,m=0,i,j,m1[mP][4]={0},total,i1,p1,i2,j2;
	vector<int> processVector[mP][mE];
	cout<<"\nTime Stamp Of Events Using Vector Clock Rules";
	cout<<"\n=============================================="<<endl<<endl;

	//Input the number of processes and events and insert in vector using pushback function.

	cout<<"\nEnter Number Of Process: ";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"\nEnter number of events for process P"<<i<<"   ";
		cin>>SizeE[i];
	}
    for(i=0;i<n;i++){
        for(j=1;j<=SizeE[i];j++){
			for(int k=0;k<n;k++)
                if(k==i)
                    processVector[i][j].push_back(j);
                else
                     processVector[i][j].push_back(0);

		}
    }

    // do-while loop for continuous program flow by user input

    do{
		cout<<"\nEvents Transit Details";
		cout<<"\nFROM ->\nEnter Process Number P";
		cin>>m1[m][0];
		cout<<"\nEnter Event Number e";
		cin>>m1[m][1];
		cout<<"\nTO ->\nEnter Process Number P";
		cin>>m1[m][2];
		cout<<"\nEnter Event Number e";
		cin>>m1[m][3];
		cout<<"\n\nPress 'y' to continue:";
		cin>>C;
		cout<<C<<endl;
		m++;
		total=m;

	}while(C=='y'||C=='Y');
	m=0;

	//Calculating time stamps using Vectors and Lamports Clock Algo

	for (i=0;i<total;i++){
		  i1=m1[i][0];
		  i2=m1[i][1];
		  p1=m1[i][2];
		  j2=m1[i][3];
		  if(i>0&&processVector[p1][j2][i-1] < (processVector[i1][i2][i-1])){
                processVector[p1][j2][i-1] = (processVector[i1][i2][i-1]);
				for (j=j2+1;j<=SizeE[p1];j++){
					 processVector[p1][j][i-1]=processVector[p1][j-1][i-1];
					}
			 }
		  if(processVector[p1][j2][i] < (processVector[i1][i2][i])){
                processVector[p1][j2][i] = (processVector[i1][i2][i]);
				for (j=j2+1;j<=SizeE[p1];j++){
					 processVector[p1][j][i]=processVector[p1][j-1][i];
					}
			 }
			 if(processVector[p1][j2][i+1]<processVector[i1][i2][i+1]){
                processVector[p1][j2][i+1]=processVector[i1][i2][i+1];
                for (j=j2+1;j<=SizeE[p1];j++){
                     processVector[p1][j][i+1]=processVector[p1][j-1][i+1];
					}
			 }
		}

    //Displaying Process , events and their dependencies

	cout<<endl<<endl;
	cout<<"OUTPUT : ";
	for (i=0;i<n;i++){
        for (j=1;j<=SizeE[i];j++){
            cout<<i<<"-"<<j<<": ( ";
                for(int k=0;k<n;k++)
                    cout<<processVector[i][j][k]<<" ";
            cout<<" ) ";
        }
        cout<<endl;
    }
	cout<<endl;
	cout<<"Developed and implemented by : "<<endl;
	cout<<"Varun Dalal"<<endl;
	cout<<"A04743047";
	return 0;
}
