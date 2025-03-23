#include "functions2.h"

#include "node.h"
//#include "node.cpp"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <tuple>
#include <list>

// g++ -shared -o main.so -fPIC main.cpp

using namespace std;

//פונקציה שיוצרת צמתים הבאות לפי כל צומת
void intliaizeNextNode(std::map<int, std::vector<std::tuple<int, int, int>>> AllStForNodes, std::vector<node> nodes)
{
    auto it = AllStForNodes.begin();
    for (auto& source : nodes)
    {
        if (it == AllStForNodes.end()) {
            break;
        }

        const std::vector<std::tuple<int, int, int>>& nodeList = it->second;
        if (!nodeList.empty()) {
            for (auto& nn : nodeList)
            {
                int nodeId = std::get<2>(nn);
                node* newNode = new node(nodeId);
                int edge = std::get<1>(nn); 
                source.AddNextNode(newNode, edge);
            }
        }

        ++it;
    }


}
//פונקציה שמחלקת לוקטורים לפי כל צומת
std::map<int, std::vector<std::tuple<int, int, int>>> decomposeVector(const std::vector<std::tuple<int, int, int>>& originalVector) {
    std::map<int, std::vector<std::tuple<int, int, int>>> decomposedVectors;

    // Creating the second vector with replaced values
    std::vector<std::tuple<int, int, int>> replacementVector;
    for (const auto& tuple : originalVector) {
        int firstValue = std::get<0>(tuple);
        int SecondValue = std::get<1>(tuple);
        replacementVector.push_back(std::make_tuple(SecondValue, firstValue, std::get<2>(tuple)));
    }

    std::vector<std::tuple<int, int, int>> mergedVector;
    for (const auto& tuple : originalVector) {
        mergedVector.push_back(tuple);
    }
    for (const auto& tuple : replacementVector) {
        mergedVector.push_back(tuple);
    }
    for (const auto& tuple : mergedVector) {
        int firstValue = std::get<0>(tuple);
        decomposedVectors[firstValue].push_back(tuple);
    }
    return decomposedVectors;
}

std::vector<node> createNodesFromStrings(const std::vector<int>& ids) {
    std::vector<node> nodes;

    for (const auto& id : ids) {
        node newNode(id);
        nodes.push_back(newNode);
    }

    return nodes;
}

//מורידה כפולים מרשימת הsource
std::vector<int> removeDuplicates(std::vector<int>& vec)
{
    std::vector<int> originalVec = vec;
    std::unordered_set<int> seen;
    vec.erase
    (std::remove_if(vec.begin(), vec.end(), [&seen](int id)
        {
            if (seen.find(id) != seen.end()) {
                return true;
            }
            else {
                seen.insert(id);
                return false;
            }

        }), vec.end());

    return vec;


}

//  פונקציה מקבלת רשימה של צמתים ומשקלים ומפרקת אותם למקור,יעד ומשקל 
extern "C"
{
    void parseAndPrint(int* data, int length) {
        std::vector<std::tuple<int, int, int>> edges;
        for (int i = 0; i < length; i += 3) {
            edges.push_back(std::make_tuple(data[i], data[i + 1], data[i + 2]));
        }

    }
}

void axis() {
    //לחלק את הצמתים לצירים לפי פייתון ולהגדיר לכל נתיב בכל צומת איזה ציר הוא שייך
}

//מקבלת את החלוקה לצירים מפייתון

void functions2::parsePythonList(const std::vector<std::tuple<int, int, int>>& edges, nodesManager& nm)
{
    std::vector<node> nodes;
    std::vector<int> sourceStrings;
    std::vector<int> node_data_txt;
    // Assuming edges is the original variable
    std::vector<std::tuple<int, int, int>> edgesCopy(edges.begin(), edges.end());
    std::map<int, std::vector<std::tuple<int, int, int>>> AllStForNodes = decomposeVector(edgesCopy);



    for (const auto& edge : edges) {
        int source = std::get<0>(edge);
        sourceStrings.push_back(source);
        int destination = std::get<1>(edge);
        int weight = std::get<2>(edge);

        //std::cout << "Source: " << source << ", Destination: " << destination << ", Weight: " << weight << std::endl;
    }
    //sourceStrings = removeDuplicates(sourceStrings);
    std::ifstream infile("C:\\Users\\User\\Documents\\finalProject\\Macro\\nodes.txt");
    if (infile.is_open()) {
        int n;
        while (infile >> n) {
            node_data_txt.push_back(n);
        }
        infile.close();

    }
    else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }

    nodes = createNodesFromStrings(node_data_txt);

    intliaizeNextNode(AllStForNodes, nodes);
    nm.setAllNodes(nodes);

}

void functions2::read_graph(nodesManager& nm)
{
    std::vector<std::pair<char, std::tuple<int, int, int>>> data;

    std::ifstream infile("C:\\Users\\User\\Documents\\finalProject\\Macro\\data.txt");

    if (infile.is_open()) {
        char key;
        int val1, val2, val3;
        while (infile >> key >> val1 >> val2 >> val3) {
            data.push_back(std::make_pair(key, std::make_tuple(val1, val2, val3)));
        }
        size_t dataLength = data.size();
        process_graph_data(&data[0], dataLength, nm);
        infile.close();

        
    }
    else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }







}

void functions2::process_graph_data(std::pair<char, std::tuple<int, int, int>>* data, int size_d, nodesManager& nm)
{
    for (int i = 0; i < size_d; ++i)
    {
        char key = data[i].first;
        std::tuple<int, int, int> value = data[i].second;
        nm.setAxisInRoad(std::string(1, key), { value });
    }
    std::vector<std::tuple<int, int, int>> edges;

    for (int i = 0; i < size_d; ++i) {
        edges.push_back(data[i].second); // Add the tuple part of each pair to the edges vector
    }

    this->parsePythonList(edges, nm);
}
