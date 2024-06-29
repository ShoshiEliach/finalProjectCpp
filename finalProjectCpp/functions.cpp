#include "functions.h"
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
#include "nodesManager.h"
// g++ -shared -o main.so -fPIC main.cpp

using namespace std;
nodesManager nM;
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

                int edge = std::get<1>(nn); // Second element in the list
                source.AddNextNode(newNode, edge);
                cout << source.getIdNode() << "----- " << edge << " --- " << newNode->getIdNode() << endl;
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


void functions::parsePythonList(const std::vector<std::tuple<int, int, int>>& edges)
{
    std::vector<node> nodes;
    std::vector<int> sourceStrings;
    // Assuming edges is the original variable
    std::vector<std::tuple<int, int, int>> edgesCopy(edges.begin(), edges.end());
    std::map<int, std::vector<std::tuple<int, int, int>>> AllStForNodes = decomposeVector(edgesCopy);



    for (const auto& edge : edges) {
        int source = std::get<0>(edge);
        sourceStrings.push_back(source);
        int destination = std::get<1>(edge);
        int weight = std::get<2>(edge);

        std::cout << "Source: " << source << ", Destination: " << destination << ", Weight: " << weight << std::endl;

        sourceStrings = removeDuplicates(sourceStrings);

        nodes = createNodesFromStrings(sourceStrings);
    }
    intliaizeNextNode(AllStForNodes, nodes);
    nM.setAllNodes(nodes);

}

//  פונקציה מקבלת רשימה של צמתים ומשקלים ומפרקת אותם למקור,יעד ומשקל 
extern "C"
{
    void parseAndPrint(int* data, int length) {
        std::vector<std::tuple<int, int, int>> edges;
        for (int i = 0; i < length; i += 3) {
            edges.push_back(std::make_tuple(data[i], data[i + 1], data[i + 2]));
        }
        functions f;
        f.parsePythonList(edges);
    }
}

void axis() {
    //לחלק את הצמתים לצירים לפי פייתון ולהגדיר לכל נתיב בכל צומת איזה ציר הוא שייך
}








//מקבלת את החלוקה לצירים מפייתון
extern "C"
{

    void process_graph_data(std::pair<char, std::tuple<int, int, int>>* data, int size)
    {

        for (int i = 0; i < size; ++i) {
            char key = data[i].first;
            std::tuple<int, int, int> value = data[i].second;
            nM.setAxisInRoad(std::string(1, key), { value });
        }
    }
}

