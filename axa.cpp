#include <iostream>
#include <vector>
#include <iterator>
using namespace std;



bool suma_backtrack(int n, vector<int> * vec, vector<int> *&aux) {
    if (n==0) {
        vector<int>::iterator it1 = aux->begin();
        for (;it1<aux->end();it1++) {
            cout << *it1<<" ";
        }
        cout << endl;
        return true;
    }
    vector<int>::iterator it = vec->begin();
    for (;it<vec->end();it++) {
        aux->push_back(*it);
        if(n-*it<0) {
            aux->pop_back();
            continue;
        }
        if (suma_backtrack(n-*it, vec, aux)) {
            aux->pop_back();
        }
    }
    aux->pop_back();
    return false;
}

int main(){
    int x = 15;
    vector<int> vec = {10,8,7,6,5,2};
    vector<int> *aux = new vector<int>; 
    suma_backtrack(x, &vec, aux);
}
