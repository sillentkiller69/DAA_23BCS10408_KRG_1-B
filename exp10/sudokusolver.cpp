 #include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;
class SG{
int g[9][9];
public:
SG(){m();}
void m(){
cout<<"\n======================\n"<<" 	Sudoku Solver\n"<<"======================\n\n"<<"Welcome to Sudoku Solver!\n"<<"You can either:\n"<<"1. Enter values manually.\n"<<"2. Read puzzle from file.\n"<<"-> ";
int o;
cin>>o;
if(cin.fail()){
cin.clear();
cin.ignore(10000,'\n');
o=0;
}
if(o==1)rc();
else if(o==2)rf();
else{
cout<<"Invalid option. Try again.\n";
m();
}
}
void rc(){
cout<<"\nEnter 0 for empty cells.\n";
for(int i=0;i<9;i++){
for(int j=0;j<9;j++){
int v;
cout<<"Enter value for cell["<<i+1<<"]["<<j+1<<"] -> ";
cin>>v;
while(v<0||v>9){
cout<<"Invalid value! Enter between 0–9 -> ";
cin>>v;
}
g[i][j]=v;
}
cout<<"-------\n";
}
}
void rf(){
string f;
cout<<"\nEnter filename -> ";
cin>>f;
ifstream in(f);
if(!in){
cout<<"Error opening file!\n";
exit(1);
}
for(int i=0;i<9;i++)
for(int j=0;j<9;j++){
int v;
if(!(in>>v)||v<0||v>9){
cout<<"Invalid data in file.\n";
exit(1);
}
g[i][j]=v;
}
in.close();
}
int gv(int r,int c)const{return g[r][c];}
void sv(int r,int c,int v){g[r][c]=v;}
bool iF()const{
for(int i=0;i<9;i++)
for(int j=0;j<9;j++)
if(g[i][j]==0)
return false;
return true;
}
void d()const{
cout<<"++=====================================++";
for(int i=0;i<9;i++){
cout<<"\n||";
for(int j=0;j<9;j++){
cout<<" ";
if(g[i][j])cout<<g[i][j]<<" ";
else cout<<"  ";
if((j+1)%3==0)cout<<"||";
}
if((i+1)%3==0)
cout<<"\n++=====================================++";
else
cout<<"\n++-----------++-----------++-----------++";
}
cout<<endl;
}
};
class SS{
SG g;
long long rc=0;
bool iV(int r,int c,int v){
for(int i=0;i<9;i++)
if(g.gv(r,i)==v||g.gv(i,c)==v)
return false;
int sr=(r/3)*3,sc=(c/3)*3;
for(int i=sr;i<sr+3;i++)
for(int j=sc;j<sc+3;j++)
if(g.gv(i,j)==v)
return false;
return true;
}
bool sR(){
rc++;
for(int r=0;r<9;r++){
for(int c=0;c<9;c++){
if(g.gv(r,c)==0){
for(int v=1;v<=9;v++){
if(iV(r,c,v)){
g.sv(r,c,v);
if(sR())return true;
g.sv(r,c,0);
}
}
return false;
}
}
}
return true;
}
public:
SS(){
cout<<"\nOriginal Puzzle:\n";
g.d();
cout<<"\nSolving puzzle...\n";
bool s=sR();
cout<<"\nThe solver was called "<<rc<<" times.\n";
if(s){
cout<<"\nSolved Puzzle:\n";
g.d();
cout<<"\nPuzzle solved successfully!\n";
}else{
cout<<"\nNo valid solution exists.\n";
}
}
};
int main(){
SS s;
return 0;
}