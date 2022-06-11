#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> Mi;
    queue<int> Mj;
    queue<int> Oi;
    queue<int> Oj;
    queue<int> z;

    int t, n, m, res;
    cin >> t;
    
    for (int g = 0; g < t; g++)
    {
        cin >> n >> m;
        char **karta = new char *[n];
        int **kartM = new int *[n];
        int **kartO = new int *[n];

        for (int i = 0; i < n; i++) {
            karta[i] = new char[m];
            kartM[i] = new int[m];
            kartO[i] = new int[m];
            for (int j = 0; j < m; j++) {
                cin >> karta[i][j];
                if (karta[i][j] == 'M') {
                    kartM[i][j] = 0;
                    Mi.push(i);
                    Mj.push(j);
                }
                else{
                    kartM[i][j] = -1;
                }
                if (karta[i][j] == 'O') {
                    kartO[i][j] = 0;
                    Oi.push(i);
                    Oj.push(j);
                }
                else{
                    kartO[i][j] = -1;
                }
            }
        }
        
        while (!Mi.empty()) {
            if ((Mj.front() > 0) && karta[Mi.front()][Mj.front() - 1] == '.' &&
                kartM[Mi.front()][Mj.front() - 1] == -1) {
                Mi.push(Mi.front());
                Mj.push(Mj.front() - 1);
                kartM[Mi.front()][Mj.front() - 1] = kartM[Mi.front()][Mj.front()] + 1;
            }
            if ((Mi.front() < n - 1) && karta[Mi.front() + 1][Mj.front()] == '.' &&
                kartM[Mi.front() + 1][Mj.front()] == -1) {
                Mi.push(Mi.front() + 1);
                Mj.push(Mj.front());
                kartM[Mi.front() + 1][Mj.front()] = kartM[Mi.front()][Mj.front()] + 1;
            }
            if ((Mj.front() < m - 1) && karta[Mi.front()][Mj.front() + 1] == '.' &&
                kartM[Mi.front()][Mj.front() + 1] == -1) {
                Mi.push(Mi.front());
                Mj.push(Mj.front() + 1);
                kartM[Mi.front()][Mj.front() + 1] = kartM[Mi.front()][Mj.front()] + 1;
            }
            if ((Mi.front() > 0) && karta[Mi.front() - 1][Mj.front()] == '.' &&
                kartM[Mi.front() - 1][Mj.front()] == -1) {
                Mi.push(Mi.front() - 1);
                Mj.push(Mj.front());
                kartM[Mi.front() - 1][Mj.front()] = kartM[Mi.front()][Mj.front()] + 1;
            }
            Mi.pop();
            Mj.pop();
        }

        while (!Oi.empty()){
            if ((Oj.front() > 0) && karta[Oi.front()][Oj.front() - 1] == '.' &&
                kartO[Oi.front()][Oj.front() - 1] == -1) {
                Oi.push(Oi.front());
                Oj.push(Oj.front() - 1);
                kartO[Oi.front()][Oj.front() - 1] = kartO[Oi.front()][Oj.front()] + 1;
            }
            if ((Oi.front() < n - 1) && karta[Oi.front() + 1][Oj.front()] == '.' &&
                kartO[Oi.front() + 1][Oj.front()] == -1) {
                Oi.push(Oi.front() + 1);
                Oj.push(Oj.front());
                kartO[Oi.front() + 1][Oj.front()] = kartO[Oi.front()][Oj.front()] + 1;
            }
            if ((Oj.front() < m - 1) && karta[Oi.front()][Oj.front() + 1] == '.' &&
                kartO[Oi.front()][Oj.front() + 1] == -1) {
                Oi.push(Oi.front());
                Oj.push(Oj.front() + 1);
                kartO[Oi.front()][Oj.front() + 1] = kartO[Oi.front()][Oj.front()] + 1;
            }
            if ((Oi.front() > 0) && karta[Oi.front() - 1][Oj.front()] == '.' &&
                kartO[Oi.front() - 1][Oj.front()] == -1) {
                Oi.push(Oi.front() - 1);
                Oj.push(Oj.front());
                kartO[Oi.front() - 1][Oj.front()] = kartO[Oi.front()][Oj.front()] + 1;
            }
            Oi.pop();
            Oj.pop();
        }

        for (int i = 0; i < m; i++) {
            if (kartM[0][i] != -1 && (kartM[0][i] < kartO[0][i] || kartO[0][i] == -1)){
                z.push(kartM[0][i] + 1);
            }
            if (kartM[n - 1][i] != -1 && (kartM[n - 1][i] < kartO[n - 1][i] || kartO[n - 1][i] == -1)){
                z.push(kartM[n - 1][i] + 1);
            }
        }
        for (int i = 1; i < n - 1; i++) {
            if (kartM[i][0] != -1 && (kartM[i][0] < kartO[i][0] || kartO[i][0] == -1)){
                z.push(kartM[i][0] + 1);
            }
            if (kartM[i][m - 1] != -1 && (kartM[i][m - 1] < kartO[i][m - 1] || kartO[i][m - 1] == -1)){
                z.push(kartM[i][m - 1] + 1);
            }
        }
        
        if (z.empty()) {
            cout << "NIE" << "\n";
        } else {
            res = z.front();
            z.pop();
            while (!z.empty()) {
                if (z.front() < res) {
                    res = z.front();
                }
                z.pop();
            }
            cout << res << "\n";
        }
        
        for (int i = 0; i < n; i++)
        {
            delete[] karta[i];
            delete[] kartM[i];
            delete[] kartO[i];
        }
        delete[] karta;
        delete[] kartM;
        delete[] kartO;
    }
    return 0;
}