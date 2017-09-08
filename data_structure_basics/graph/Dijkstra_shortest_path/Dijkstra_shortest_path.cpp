#include <iostream>

using namespace std;

#define M_MAX_VER_NUM    7
#define M_MAX_ADJVER_NUM 6


struct Adj_Node {
    int nodeIndex;
    int distance;
};

struct Node {
    int value;
    int distance;
    int adjVerNum;
    struct Adj_Node adjVer[M_MAX_ADJVER_NUM];
};

int g_cur_node_num = 7;
struct Node g_verList[M_MAX_VER_NUM] = {
    {0, INT_MAX, 2, { {1,2}, {3,1} } },
    {1, INT_MAX, 2, { {3,3}, {4,10} } },
    {2, INT_MAX, 2, { {0,4}, {5,5} } },
    {3, INT_MAX, 4, { {2,2}, {4,2}, {5,8}, {6,4}} },
    {4, INT_MAX, 1, { {6,6} } },
    {5, INT_MAX, 0, { {0,0} } },
    {6, INT_MAX, 1, { {5,1} } },
};



void print_graph() {
    cout << "\nGraph: \n";
    for (int i = 0; i < g_cur_node_num; ++i) {
        cout << g_verList[i].value << ": ";
        for (int j = 0; j < g_verList[i].adjVerNum; ++j)
            cout << g_verList[i].adjVer[j].nodeIndex << "(" << g_verList[i].adjVer[j].distance << ")" << " ";
        cout << endl;
    }
}

void get_input() {
    int value;
    cout << "Enter graph: \n";
    while (g_cur_node_num < M_MAX_VER_NUM && cin >> value) {
        g_verList[g_cur_node_num].value = value;
        cout << "Enter adjVerNum: "; 
        cin >> g_verList[g_cur_node_num].adjVerNum;
        cout << "Enter each adj ver: ";
        for (int i = 0; i < g_verList[g_cur_node_num].adjVerNum && i < M_MAX_ADJVER_NUM; ++i) {
            cin >> g_verList[g_cur_node_num].adjVer[i].nodeIndex >> g_verList[g_cur_node_num].adjVer[i].distance;
        }
    }
    cout << "\nGet input done!\n";
}

void init_ver() {
    for (int i = 0; i < M_MAX_VER_NUM; ++i) {
        g_verList[i].value = -1;
        g_verList[i].adjVerNum = 0;
        for (int j = 0; j < M_MAX_ADJVER_NUM; ++j) {
            g_verList[i].adjVer[j].nodeIndex = -1;
            g_verList[i].adjVer[j].distance = INT_MAX;
        }
    }
}

void print_prev(int start, int end, int* prevlist) {
    if (start == end) {
        cout << end << " ";
        return;
    }
    print_prev(start, prevlist[end], prevlist);
    cout << end << " ";
}

void Dijkstra(int start, int end)
{
    int min = INT_MAX;
    int minIndex = 0;
    int nodeIndex = 0;
    int known[M_MAX_VER_NUM] = {false};
    int prevlist[M_MAX_VER_NUM];

    g_verList[start].distance = 0;
    prevlist[start] = -1;

    for (int i = 1; i < M_MAX_VER_NUM; ++i) {
        min = INT_MAX;
        // find smallest distance;
        for (int j = 0; j < M_MAX_VER_NUM; ++j) {
            if (!known[j] && g_verList[j].distance < min) {
                min = g_verList[j].distance;
                minIndex = j;
            }
        }
        known[minIndex] = true;
        // update adj ver
        for (int j = 0; j < g_verList[minIndex].adjVerNum; ++j) {
            nodeIndex = g_verList[minIndex].adjVer[j].nodeIndex;
            if (!known[nodeIndex] && g_verList[nodeIndex].distance > g_verList[minIndex].distance + g_verList[minIndex].adjVer[j].distance) {
                g_verList[nodeIndex].distance = min + g_verList[minIndex].adjVer[j].distance;
                prevlist[nodeIndex] = minIndex;
            }
        }
        
    }

    //print
    cout << "Dijkstra Shortest Path:\n";
    print_prev(start, end, prevlist);
}



void init()
{
    init_ver();
    g_cur_node_num = 0;
}


int main(int argc, char**argv)
{
    //init();
    //get_input();
    print_graph();
    Dijkstra(2, 6);
}