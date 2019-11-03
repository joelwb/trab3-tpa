#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct car {
    int tempo;
    int ordem;
};

bool acceptCar(queue<car> q, int hour){
    return !q.empty() && q.front().tempo <= hour;
}

int nextHour(queue<car> l, queue<car> r,  int hour, int next) {
    if (next == 1) return max(r.front().tempo, hour);
    else return max(l.front().tempo, hour);
}

int nextCarSide(queue<car> l, queue<car> r, bool isOnLeft, int hour) {

    if (r.empty() && !l.empty()) return -1;
    else if (!r.empty() && l.empty()) return 1;

    else if (isOnLeft && l.front().tempo <= hour) return -1;
    else if (!isOnLeft && r.front().tempo <= hour) return 1;

    else if (l.front().tempo < r.front().tempo) return -1;
    else if (l.front().tempo > r.front().tempo) return 1;

    return 0;
}

int main(){
    int n, t, m, c;

    cin >> c;
    for (int k = 0; k < c; k++){
        cin >> n >> t >> m;
        queue<car> left, right;
        bool isOnLeft = true;
        int hour = 0;



        vector<int> tempos(m);

        int tempo;
        string dir;

        for (int i = 0; i < m; i++){
            cin >> tempo >> dir;

            if (dir == "left") left.push(car{tempo, i});
            else right.push(car{tempo, i});
        }

        while (left.size() > 0 || right.size() > 0) {
            bool viajou = false;
            if (isOnLeft && left.size() > 0) {
                for (int i = 0; i < n; i++) {
                    if (acceptCar(left, hour)) {
                        tempos[left.front().ordem] = hour + t;
                        left.pop();
                        isOnLeft = false;
                        viajou = true;
                    }
                }
            } else if (!isOnLeft && right.size() > 0) {
                for (int i = 0; i < n; i++) {
                    if (acceptCar(right, hour)) {
                        tempos[right.front().ordem] = hour + t;
                        right.pop();
                        isOnLeft = true;
                        viajou = true;
                    }
                }
            }

            hour += viajou ? t : 0;
            int next = nextCarSide(left, right, isOnLeft, hour);
            hour = nextHour(left, right, hour, next);
            if ((next == -1 && !isOnLeft) || (next == 1) && isOnLeft) {
                isOnLeft = !isOnLeft;
                hour += t;
            }
        }

        for (int i = 0; i < tempos.size(); i++) {
            cout << tempos[i] << endl;
        }

        if (k != c - 1) cout << endl;
    }
}