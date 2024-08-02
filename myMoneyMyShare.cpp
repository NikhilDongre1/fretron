// Ram , sham and rahim went for shopping apple. They bought apple worth
// 100 rupees. Ram paid 50 rupees, sham paid 30 rupees and rahim paid 20
// rupees. Each apple is tagged with its weight on it. Write a program to
// distribute apples such that the quantity of apple they get is in best
// proportionate to the amount they paid.
// Note : you cannot cut a apple into pieces have to allocate the whole apple to
// one of them.
// For example :
// If there is 8 apple of 400g , 100g , 400g , 300g , 200g , 300g ,100g , 200g
// then we can distribute them as
// Ram : 400g , 400g , 200g (total 1kg , 50%)
// Sham : 300g , 300g (tatal 600g , 30%)
// rahim , 200g , 100g , 100g (tatal 400g , 20%)

 


// Expected program output :
// run distribute_apple
// Enter apple weight in gram (-1 to stop ) : 400
// Enter apple weight in gram (-1 to stop ) : 100
// Enter apple weight in gram (-1 to stop ) : 400
// Enter apple weight in gram (-1 to stop ) : 300
// Enter apple weight in gram (-1 to stop ) : 200
// Enter apple weight in gram (-1 to stop ) : 300
// Enter apple weight in gram (-1 to stop ) : 100
// Enter apple weight in gram (-1 to stop ) : 200
// Enter apple weight in gram (-1 to stop ) : -1
// Distribution Result :
// Ram : 400 400 100
// Sham : 300 , 300
// Rahim : 200 , 100 , 100


#include<iostream>
#include<vector>
#include<stack>

#include<algorithm>
using namespace std;

int main(){
    vector<int> apple_weight;
    stack<int> stk;
    int  i = 0;
    int weight;
    cout << "Enter apple weight in gram (-1 to stop ) : ";
    int total_weight = 0;
    while(cin >> weight){
        if(weight == -1)
            break;
        apple_weight.push_back(weight);
        total_weight += weight;
    }
    

    sort(apple_weight.begin(),apple_weight.end());
  for(int i = 0; i < apple_weight.size();i++){
    stk.push(apple_weight[i]);
  }
 
    int ram_proportion =  (50 * total_weight)/100;
    int sham_proportion = (30 * total_weight)/100;
    int rahim_proportion = (20 * total_weight)/100;

    int distribution[3] = {0};

    vector<int> dist;
    int sum = 0;
    // for(int j = 0; j < apple_weight.size(); j++){
    //     sum+=stk.top();
    //     if(sum<=ram_proportion){
    //         stk.pop();
    //     }
    //     else if(sum)
    // }
    for(int k = 0; k < apple_weight.size(); k++){
        if(ram_proportion > 0){
            distribution[0] += apple_weight[k];
            ram_proportion -=  apple_weight[k] / total_weight;
        }
        if(sham_proportion > 0){
            distribution[1] += apple_weight[k];
            sham_proportion -=  apple_weight[k] / total_weight;
        }
        if(rahim_proportion > 0){
            distribution[2] += apple_weight[k];
            rahim_proportion -=  apple_weight[k] / total_weight;
        }
    }


    cout << "Distribution Result : " << endl;
    cout << "Ram : " << distribution[0]  << endl;
    cout << "Sham : " << distribution[1]  << endl;
    cout << "Rahim : " << distribution[2]  << endl;
    return 0;
}