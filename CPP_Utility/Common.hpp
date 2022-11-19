#ifndef Common_HPP
#define Common_HPP

#include <algorithm>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define mod107(m) m % 1000000007
#define mod998(m) m % 998244353
#define m107      1000000007
#define m998      998244353
typedef long long int                  ll;
typedef vector<ll>                     vll;
typedef vector<vector<ll>>             vvll;
typedef vector<vector<vector<ll>>>     vvvll;
typedef vector<int>                    vi;
typedef vector<vector<int>>            vvi;
typedef vector<vector<vector<int>>>    vvvi;
typedef vector<float>                  vf;
typedef vector<vector<float>>          vvf;
typedef vector<vector<vector<float>>>  vvvf;
typedef vector<double>                 vd;
typedef vector<vector<double>>         vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<string>                 vs;
typedef vector<vector<string>>         vvs;
typedef pair<ll, ll>                   pll;
typedef pair<ll, string>               pls;
typedef pair<string, ll>               psl;
typedef pair<int, int>                 pii;
typedef pair<int, string>              pis;
typedef pair<string, int>              psi;

// ------------------- ここも設定してください！！！！！ -------------------
typedef float input_data_type;  // 入力データの型 整数型32bit
typedef float output_data_type; // 出力データの型 浮動小数型32bit

typedef vector<input_data_type>                  vidt;
typedef vector<vector<input_data_type>>          vvidt;
typedef vector<vector<vector<input_data_type>>>  vvvidt;
typedef vector<output_data_type>                 vodt;
typedef vector<vect<output_data_type>>           vvodt;
typedef vector<vector<vector<output_data_type>>> vvvodt;

// -------------------------- プロトタイプ宣言 --------------------------

#endif