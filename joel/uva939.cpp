/*
Autor: Joel Will Belmiro 

O problema informa o nome de algumas pessoas e o seu tipo de gene,
e também informa alguns filhos dessas pessoas. Dado essas informações, deseja-se
saber o tipo de gene dos filhos baseados nos tipos de gene dos pais.
O problema impõe regras para descobrir qual o tipo de gene.
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool isGene(string g){
    return g == "dominant" || g == "recessive" || g == "non-existent";
}

bool exist(string p1, string p2, map<string, string> genes) {
    return (genes[p1] != "non-existent" && genes[p2] != "non-existent") ||
           (genes[p1] == "dominant" || genes[p2] == "dominant");
}

bool isDominant(string p1, string p2, map<string, string> genes) {
    return (genes[p1] == "dominant" && genes[p2] == "dominant") ||
           (genes[p1] == "dominant" && genes[p2] == "recessive") ||
           (genes[p2] == "dominant" && genes[p1] == "recessive");
}

void match(string childName, map<string, string> *genes, map<string, pair<string, string>> children){
    string p1, p2;
    pair<string, string> parents;
    parents = children[childName];
    p1 = parents.first;
    p2 = parents.second;

    if (genes->find(p1) == genes->end()) match(p1, genes, children);
    if (genes->find(p2) == genes->end()) match(p2, genes, children);

    if (exist(p1, p2, *genes)) {
        if (isDominant(p1, p2, *genes)) genes->insert(make_pair(childName, string("dominant")));
        else genes->insert(make_pair(childName, string("recessive")));
    } else {
        genes->insert(make_pair(childName, string("non-existent")));
    }
}

int main(){
    int N;

    cin >> N;
    map<string, string> genes;
    map<string, pair<string, string>> children;


    string parent, geneOrChild;
    for (int i = 0; i < N; i++){
        cin >> parent >> geneOrChild;

        if (isGene(geneOrChild)) genes.insert(make_pair(parent, geneOrChild));
        else if (children.find(geneOrChild) == children.end()){
            children.insert(make_pair(geneOrChild, make_pair(parent, "")));
        } else {
            children[geneOrChild].second = parent;
        }
    }

    for (auto const& c : children){
        match(c.first, &genes, children);
    }

    for (auto const& g : genes){
        cout << g.first << " " << g.second << endl;
    }
}