#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void read(const int N, const string filename, double* const p){
  ifstream in(filename.c_str());
  for(int i=0;i<N;i++){
   in >> p[i];
   //cout << p[i] << endl;
  }
  in.close();
}

void filter(const int N,double* const p){
  double const m=3;
  double p_null;
  double p_Nmin1;
  p_null = (p[N-1] + p[0] + p[1]) /m;
  p_Nmin1 = (p[N-2] + p[N-1] + p[0]) /m; 
  for (int i=1; i<N-1 ; i++){
    p[i] = (p[i-1] + p[i] + p[i+1]) /m;
  }
  p[0]=p_null;
  p[N-1]=p_Nmin1;
}
void write(double* const p,const int N){
  ofstream out("filtered.txt");
  for(int i=0; i<N; i++){
    out << p[i] << endl;
  }
  out.close();
}

int main(void){
  const int N = 237;
  int n;
  const string filename = "noisy.txt";
  double* const p = new double [N];
  read(N,filename,p);
  //cout << "Anzahl an Filterumläufen festlegen: n="; 
  //cin >> n ;
  //for(int i=0;i<n;i++){
  filter(N,p);
  //}
  write(p,N);
  delete[] p;
  return 0;
}