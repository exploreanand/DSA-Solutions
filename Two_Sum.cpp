#include <iostream>
#include <string>
using namespace std;

void solution(int nums[],int size, int target){



}

int main() {
    
    int nums[100];
    string arr;
    cout<<"nums = ";
    getline(cin,arr);
    int size = arr.size();

    for (int i = 0; i < size; i++)                  // 'i' is for arr[]
    {
        while (arr[i]!='[' && arr[i]!=',' && arr[i] != ']')
        {
            for (int j = 0; j < ((size/2)-1); j++)              // 'j' is nums[]
            {
                nums[j] = (arr[i]);
            }
            
        }
    }
        
    return 0;
}
