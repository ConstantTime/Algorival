#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int , pair < int , int > > mp;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
#define per(i , j , n) for(long long i = j ; i >= n ; i--)
 
const ll N = 153456;
const ll mod = 1e18 + 7;
const ld eps = 1e-6;
const ld pi = 3.1415926535;

class base {
protected :
  int i;
  int j;
public :
  base () {
    i = 30;
    j = 35;
    cout << "Base has been called" << endl;
  }
};

class base1 {
private :
  int i;
  int j;
protected:  
  base1 () {
    i = 0;
    j = 0;
    cout << "Base 1 has been called" << endl;
  }
};

class derived : private base1 , public base {
private:
  int i;
  int j;
public:
  derived() {
    i = 0;
    j = 0;
    cout << "Derived has been called" << endl;
  } 
  get() {
    cout << base::i << " " << base::j << endl;
  }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << setprecision(12);
    
    derived di;
    di.get();

    return 0;
}
