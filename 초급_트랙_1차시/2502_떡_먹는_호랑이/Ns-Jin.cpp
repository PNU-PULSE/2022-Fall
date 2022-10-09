#include<iostream>

using namespace std;

int fibo(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }
    else {
        return fibo(n-1) + fibo(n-2);
    }
}

int main() {
    int d,k;
    cin >> d >> k;

    int fibo_x = fibo(d-2);
    int fibo_y = fibo(d-1);
    
    int a,b;
    for(int i=1;i<k;i++) {
        if((k - i*fibo_x)%fibo_y == 0) {
            a = i;
            b = (k-i*fibo_x)/fibo_y;
            break;
        }
    }
    cout << a << endl;
    cout << b << endl;

}
