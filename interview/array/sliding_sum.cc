#include<bits/stdc++.h>

/*
 A = [5, 3 , 7, 2, 3]
 W = 3

moyenne glissante

Results[0] = (5 + 3 + 7) / 3 = 5
Results[1] = (3 + 7 + 2) / 3 = 4
Results[2] = (7 + 2 + 3) / 3 = 4
Results[3] = (2 + 3) / 2 = 2.5
Results[4] = (3) / 1 = 3

*/

using namespace std;
// O(N*W)
vector<float> find_means(vector<float>& input, int w) {

  vector<float> res;

  for (int i = 0; i < input.size(); i++) {
    if (i + w > input.size())
    {
      w--;
    }
    float sum = 0;

    for (int j = 0; j < w; j++) {
      sum += input[j + i];
    }
    sum /= w;
    res.push_back(sum);
  }
  return res;
}

int my_min(int a, int b)
{
  return a < b ? a : b;
}

// O(N+W)
vector<float> find_means_2(vector<float>& input, int w) {

  vector<float> res;


  float sum = 0;
  for (int i = 0; i < w; i++) {
      sum += input[i];
  }

  int len = 0;
  for (int i = 0; i < input.size(); i++) {


    len = my_min(w, input.size() - i);
    res.push_back(sum/len);

    sum = sum - input[i];

    if (i + w < input.size())
    {
      sum = sum + input[i + w];
    }


  }
  return res;
}

int main() {

  vector<float> a = {5, 3, 7, 2, 3};
  int w = 3;
  auto res = find_means(a, w);
  for (auto _val : res) {
    cout << _val << endl;
  }
  res = find_means_2(a, w);
  for (auto _val : res) {
    cout << _val << endl;
  }

  return 0;
}
