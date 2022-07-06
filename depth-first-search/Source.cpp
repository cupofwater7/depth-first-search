#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
    string name;
    vector<Node*> children;

    Node(string name) { this->name = name; }

    vector<string> depthFirstSearch(vector<string>* array) {
        // Write your code here.
        array->push_back(this->name);
        for (int i = 0; i < this->children.size(); i++)
        {
            children[i]->depthFirstSearch(array);
        }
        return *array;
    }

    Node* addChild(string name) {
        Node* child = new Node(name);
        children.push_back(child);
        return this;
    }
};

int main()
{
    Node graph("A");
    graph.addChild("B")->addChild("C")->addChild("D");
    graph.children[0]->addChild("E")->addChild("F");
    graph.children[2]->addChild("G")->addChild("H");
    graph.children[0]->children[1]->addChild("I")->addChild("J");
    graph.children[2]->children[0]->addChild("K");

    vector<string> inputArray{};
    graph.depthFirstSearch(&inputArray);
    for (int i = 0; i < inputArray.size(); i++)
    {
        cout << inputArray[i] << " ";
    } 

    return 0;
}