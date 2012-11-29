#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

static int count_node = 0;
map<int, int> id_list;
static int default_dist = -1;

struct Edge {
private:
    int start;
    int end;
    
public:
    Edge(int i, int j) {
        start = i;
        end = j;
    }
    
    int getStart() {
        return start;
    }
    
    int getEnd() {
        return end;
    }
};

class EdgeMatrix {
private:
    int sz;
    bool **mat;
    
public:
    EdgeMatrix(int sz) {
        this->sz = sz;
        mat = new bool*[sz+1];
        for(int i=1; i<=sz; i++) {
            mat[i] = new bool[sz+1];
        }
        
        for(int i=1; i<=sz; i++) {
            for(int j=1; j<=sz; j++) {
                mat[i][j] = false;
            }
        }
    }
    
    ~EdgeMatrix() {
        for(int i=1; i<=sz; i++) {
            //delete[] mat[i];
        }
        //delete[] mat;
    }
    
    int getSize() {
        return sz;
    }
    
    void set(int i, int j) {
        mat[i][j] = true;
    }
    
    bool get(int i, int j) {
        return mat[i][j];
    }
    
    void print() {
        for(int i=1; i<=sz; i++) {
            for(int j=1; j<=sz; j++) {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    EdgeMatrix operator =(EdgeMatrix e) {
        for(int i=1; i<=sz; i++) {
            for(int j=1; j<=sz; j++) {
                mat[i][j] = e.get(i, j);
            }
        }
        return *this;
    }
    
    void update(vector<Edge> eList) {
        int a, b;
        for(int i=0; i<eList.size(); i++) {
            a = eList[i].getStart();
            b = eList[i].getEnd();
            mat[a][b] = true;
            mat[b][a] = true;
        }
    }
    
    EdgeMatrix operator *(EdgeMatrix e) {
        EdgeMatrix em(this->sz);
        
        for(int i=1; i<=sz; i++) {
            for(int j=1; j<=sz; j++) {
                for(int k=1; k<=sz; k++) {
                    em.mat[i][j] += mat[i][k]*e.mat[k][j];
                }
            }
        }
        return em;
    }
};

class DistanceMatrix {
private:
    int sz;
    int **mat;
    
public:
    DistanceMatrix(int sz) {
        this->sz = sz;
        mat = new int*[sz+1];
        for(int i=1; i<=sz; i++) {
            mat[i] = new int[sz+1];
        }
        
        for(int i=1; i<=sz; i++) {
            for(int j=1; j<=sz; j++) {
                if(i==j) {
                    mat[i][j] = 0;
                } else {
                    mat[i][j] = default_dist;
                }
            }
        }
    }
    
    int getSize() {
        return sz;
    }
    
    int update(EdgeMatrix& e, int d) {
        int count=0;
        if(e.getSize() != this->sz) {
            return false;
        }
        
        for(int i=1; i<=sz; i++) {
            for(int j=1; j<=sz; j++) {
                if(e.get(i, j) && mat[i][j] == default_dist) {
                    count++;
                    mat[i][j] = d;
                }
            }
        }
        return count;
    }
    
    bool done() {
        for(int i=1; i<=sz; i++) {
            for(int j=1; j<=sz; j++) {
                if(mat[i][j] == -1) {
                    return false;
                } 
            }
        }
        
        return true;
    }
    
    void print() {
        for(int i=1; i<=sz; i++) {
            for(int j=1; j<=sz; j++) {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int get(int i, int j) {
        return mat[i][j];
    }
};

int get_id(int id) {
    if(id_list[id] == 0) {
        id_list[id] = ++count_node;
    }
    return id_list[id];
}


