#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps;
public:
  void output() const {
    cout << swaps.size() << "\n";
    for (int i = 0; i < swaps.size(); ++i) {
      cout << swaps[i].first << " " << swaps[i].second << "\n";
    }
  }
public:
  void input() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int leftValue(int i){
    return 2*i + 1;
  }

  int rightValue(int i){
    return 2*i + 2;
  }

  int parent(int i){
return floor((i-1)/2);
  }

  void build(int i){
    int min = i;int l = leftValue(i);
    if(l <= data_.size()-1 && data_[l] < data_[min])
      min = l;
    int r = rightValue(i);
    if(r <= data_.size()-1 && data_[r] < data_[min])
      min = r;
    if(i != min){
      swap(data_[i], data_[min]);
      swaps.push_back(make_pair(i, min));
      build(min);
    }
  }

  void min_heap() {
    swaps.clear();

      int n = data_.size();
      //cout << " size : " << n << endl;
      for(int i = (n-1)/2; i+1 != 0; i--){
        build(i);
      }
  }

 
};

int main() {
  HeapBuilder heap_builder;
  
   heap_builder.input();
    heap_builder.min_heap();
    heap_builder.output();
  return 0;
}
