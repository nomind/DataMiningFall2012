
#include "lib.cpp"
#include <cassert>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    assert(argc > 1);
    //cout<<"file is "<<argv[1]<<endl;
    char *filename = argv[1];
    
    vector<Edge> edge_list;
    
    ifstream fin;
    fin.open(filename, ios::in);
    
    int a, b;
    while(true) {
        fin>>a>>b;
        if(fin.eof()) {
            break;
        }

        int id1 = get_id(a);
        int id2 = get_id(b);
        edge_list.push_back(Edge(id1, id2));
    }

    DistanceMatrix dist(count_node);
    EdgeMatrix mat(count_node);
    mat.update(edge_list);
    EdgeMatrix temp(count_node);
    int d = 1, updated = 1;
    temp = mat;
    
    while(updated) {
        temp = temp * mat;
        updated = dist.update(temp, d++);
    }
    cout<<d<<endl;
        
    return 0;
}

