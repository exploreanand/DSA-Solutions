#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LFUCache {
public:
    
    struct Node{
        int key;
        int val;
        int freq;
        list<Node*>::iterator pos;

        Node(int k, int v){
            key = k;
            val = v;
            freq = 1;
        };
    };

    unordered_map<int, Node*> keynode;
    unordered_map<int, list<Node*>> freqlist;

    int capacity;
    int minfreq;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minfreq = 0;
    }
    
    int get(int key) {
        // First check into the keynode
        auto it = keynode.find(key);

        if(it == keynode.end()){
            return -1;
        }

        Node* node = it->second;

        increase_freq(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0){
            return;
        }

        auto it = keynode.find(key);

        if(it != keynode.end()){
            Node* node = it->second;
            node->val = value;
            increase_freq(node);
            return;
        }

        if(keynode.size() == capacity){
            Node* node_to_delete = freqlist[minfreq].front();
            freqlist[minfreq].pop_front();

            keynode.erase(node_to_delete->key);
            delete node_to_delete;
        }

        Node* new_node = new Node(key, value);
        minfreq = 1;
        freqlist[minfreq].push_back(new_node);
        new_node->pos = prev(freqlist[1].end());

        keynode[key] = new_node;
    }

    private:

    void increase_freq(Node* node){
        int old_freq = node->freq;

        freqlist[old_freq].erase(node->pos);

        if(freqlist[old_freq].empty() && minfreq == old_freq){
            minfreq++;
        }

        node->freq++;

        int new_freq = node->freq;

        freqlist[new_freq].push_back(node);

        node->pos = prev(freqlist[new_freq].end());
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{

    return 0;
}