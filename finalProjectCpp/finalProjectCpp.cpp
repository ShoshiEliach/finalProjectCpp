// try.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "string.h"
#include <thread>
#include "functions.h"
#include "nodesManager.h"
#include "node.h"
using namespace std;
template<typename T>
functions f;
node<int> nTry;
vector<node<int>> vecTry;
void Always_rand(nodesManager& f);
void listenFromPython();
void getValuesFromMicro(std::string id, int numCars);
int main()
{
    nodesManager nm;

    for (int i = 0; i < 3; i++)
    {
        nTry = node<int>(i);
        vecTry.push_back(nTry);
    }

    nm.setAllNodes(vecTry);


    std::thread StartCars([&nm]() {
        Always_rand(nm);
        });

    std::vector<std::thread> threads_trraficLogic;
    std::vector<std::thread> threads_overWaiting;
    std::vector<std::thread> threads_updatePriority;

    //תהליכונים של ניהול רמזור בצומת
    for (auto& n : nm.getAllNodes()) {
        threads_trraficLogic.emplace_back([&n]() {
            n.trraficLogicInNode();
            });
    }
    //תהליכונים של המתנה מעבר לזמן החורג
    for (auto& n : nm.getAllNodes()) {
        threads_overWaiting.emplace_back([&n]() {
            n.overWaiting();
            });
    }
    //תהליכונים שמשנים טת העדיפות בצומת
    for (auto& n : nm.getAllNodes()) {
        threads_updatePriority.emplace_back([&n]() {
            n.updatePriority();
            });
    }
    //join

    for (auto& t : threads_trraficLogic)
    {
        t.join();
    }
    for (auto& w : threads_overWaiting)
    {
        w.join();
    }
    for (auto& p : threads_overWaiting)
    {
        p.join();
    }
    StartCars.join();
}
void Always_rand(nodesManager& f)
{
    //����� �� �������� ����
    cout << f.getAllNodes()[0].getIdNode() << endl;

    //����� �� ��� ��� ������
   /* random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis3(1, 60);
    int When = dis3(gen);
    cout << When << endl;
    std::this_thread::sleep_for(std::chrono::seconds(When));
    cout << "i woke uppppppppppppp!!!" << endl;*/
    //��� ����� �� ������



}

void getValuesFromMicro(string id, int numCars) {
    nodesManager nM;
    for (size_t i = 0; i < numCars; i++)
    {
        nM.getNodeById(5).getNodeSt()[id].addCar(std::chrono::system_clock::now(), 0);

    }
}
//���� ���� �� ���� ������ ��� ����
void listenFromPython()
{
    std::string stIn;
    int num_cars;

    // Wait for input from Python
    std::cin >> stIn >> num_cars;

}