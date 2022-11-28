#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n;
int BessieCards[100000];

int main(){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    
    cin >> n;
    int ElsieCards[n];
    for(int i=0; i<n; i++){
        cin  >> ElsieCards[i];
    }
    sort(ElsieCards, ElsieCards+n);
    bool allCards[2*n];
    for(int i=0; i<2*n; i++){
        allCards[i]=false;
    }
    for(int i=0; i<n;i++){
        allCards[ElsieCards[i]-1]=true;
    }
    
    int counter=0;
    int val=0;
    
    for(int i=0; i<2*n; i++){
        if(allCards[i]==false){
            BessieCards[val]=i+1;
            val++;
        }
    }
    
    
    //sort(BessieCards, BessieCards+n);
    int ans=0;
   
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ElsieCards[i]>BessieCards[j]){
                continue;
            }
            else{
                ans++;
                BessieCards[j]=0;
                break;
            }
            
        }
        if(BessieCards[n-1]==0)
            break;
    
    }
    
    cout << ans << endl;
    
    return 0;
}

