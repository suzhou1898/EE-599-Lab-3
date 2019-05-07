#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int m=0;

class pancake {

public:
    int size;
    bool burnt;
    void flip_pancake(){
        burnt=!burnt;
    }
};

int findmax(pancake *p,int z,int q){
    int temp=p->size;
    int i,t;
    t=q;
    for (i=1;i<z;i++){
        if((p+i)->size>temp){
            temp=(p+i)->size;
            t=i+q;
        }
    }
    return t;
}

int findmin(pancake *p,int z,int q){
    int temp=p->size;
    int i,t;
    t=q;
    for (i=1;i<z;i++){
        if((p+i)->size<temp){
            temp=(p+i)->size;
            t=i+q;
        }

    }

    return t;
}

void flip(pancake *p, int r,int n){
    int k=n-r+1;
    int i,temp;
    int t=k/2;
    for(i=0;i<t;i++){
        temp=(p+r+i)->size;
        (p+r+i)->size=(p+n-i)->size;
        (p+n-i)->size=temp;
    }
}

void flip_burnt(pancake *p,int r, int n){
    int k=n-r+1;
    int i, temp1;
    bool temp2,temp3;
    int t=k/2;
    int q=k%2;
    if (q == 0) {
        for (i = 0; i < t; i++) {
            temp1 = (p + r + i)->size;
            (p + r + i)->size = (p + n - i)->size;
            (p + n - i)->size = temp1;
            temp2 = !((p + r + i)->burnt);
            (p + r + i)->burnt = !((p + n - i)->burnt);
            ((p + n - i)->burnt) = temp2;
        }
    }
    else {
        for (i = 0; i < t; i++) {
            temp1 = (p + r + i)->size;
            (p + r + i)->size = (p + n - i)->size;
            (p + n - i)->size = temp1;
            temp2 = !((p + r + i)->burnt);
            (p + r + i)->burnt = !((p + n - i)->burnt);
            (p + n - i)->burnt = temp2;
        }
        temp3 = !((p + (r + n) / 2)->burnt);
        (p + (r + n) / 2)->burnt=temp3;
    }
}

class pancakepile {
public:
    int z;
    pancake *pile;

    void setpancakepile(int h) {
        z = h;
        pile = new pancake[z];
    }

    void pancake_sort_ascending() {
        int i, t;
        for (i = 0; i < z - 1; i++) {
            t = findmax(pile + i, z - i, i);
            if (t == z - 1) {
                flip(pile, i, z - 1);
            } else if (t > i && t < z - 1) {
                flip(pile, t, z - 1);
                flip(pile, i, z - 1);

            }

        }
    }

    void pancake_sort_descending() {
        int i, t;
        for (i = 0; i < z - 1; i++) {
            t = findmin(pile + i, z - i, i);
            if (t == z - 1) {
                flip(pile, i, z - 1);
            } else if (t > i && t < z - 1) {
                flip(pile, t, z - 1);
                flip(pile, i, z - 1);

            }

        }
    }

    void pancake_sort_ascending_burnt_down() {
        int i, t;
        for (i = 0; i < z - 1; i++) {
            t = findmin(pile + i, z - i, i);
            if (t == z - 1) {
                if (((pile + t)->burnt) != 1) {
                    pile[t].flip_pancake();
                }
                flip_burnt(pile, i, z - 1);
            } else if (t > i && t < z - 1) {
                flip_burnt(pile, t, z - 1);
                if (((pile + z - 1)->burnt) != 1) {
                    pile[z - 1].flip_pancake();
                }
                flip_burnt(pile, i, z - 1);
            } else {
                if (((pile + t)->burnt) != 0) {
                    flip_burnt(pile, t, z - 1);
                    pile[z - 1].flip_pancake();
                    flip_burnt(pile, t, z - 1);
                }
            }
        }
        if (((pile + z - 1)->burnt) != 0) {
            pile[z - 1].flip_pancake();
        }

    }

    void pancake_sort_descending_burnt_up() {
        int i, t;
        for (i = 0; i < z - 1; i++) {
            t = findmax(pile + i, z - i, i);
            if (t == z - 1) {
                if (((pile + t)->burnt) != 0) {
                    pile[t].flip_pancake();
                }
                flip_burnt(pile, i, z - 1);
            } else if (t > i && t < z - 1) {
                flip_burnt(pile, t, z - 1);
                if (((pile + z - 1)->burnt) != 0) {
                    pile[z - 1].flip_pancake();
                }
                flip_burnt(pile, i, z - 1);
            } else {
                if (((pile + t)->burnt) != 1) {
                    flip_burnt(pile, t, z - 1);
                    pile[z - 1].flip_pancake();
                    flip_burnt(pile, t, z - 1);
                }
            }
        }
        if (((pile + z - 1)->burnt) != 1) {
            pile[z - 1].flip_pancake();
        }
    }
    };

    class mpancakepiles {
    public:
        pancakepile **mpiles;

        void setmpancakepiles(int x_size, int y_size, int z_size) {
            x = x_size;
            y = y_size;
            z = z_size;
            mpiles = new pancakepile *[y];
            for (i = 0; i < y; i++) {
                *(mpiles + i) = new pancakepile[x];
            }
            for (i = 0; i < y; i++) {
                for (j = 0; j < x; j++) {
                    mpiles[i][j].setpancakepile(z);
                }
            }
        }

        void sort_interior() {
            if (x > 2 && y > 2) {
                for (i = 1; i < y - 1; i++) {
                    for (j = 1; j < x - 1; j++) {
                        mpiles[i][j].pancake_sort_ascending_burnt_down();
                    }
                }
            }
        }

        void sort_exterior() {
            for (i = 0; i < y; i++) {
                for (j = 0; j < x; j++) {
                    if (i == 0 || i == y - 1 || j == 0 || j == x - 1) {
                        mpiles[i][j].pancake_sort_descending_burnt_up();
                    }
                }
            }
        }

    private:
        int x, y, z;
        int i, j;
    };

    void strtonum(string s, bool *f, int *dem, int *num) {
        int data = 0;
        if (*f) {
            for (int i = 0; i < s.length(); i++) {
                while (s[i] >= '0' && s[i] <= '9') {
                    data *= 10;
                    data += (s[i] - '0');
                    i++;
                }
                *(dem + m) = data;
                data = 0;
                m++;
                *f = false;
            }
        } else {
            for (int i = 0; i < s.length(); i++) {
                while (s[i] >= '0' && s[i] <= '9') {
                    data *= 10;
                    data += (s[i] - '0');
                    i++;
                }
                *(num + m) = data;
                data = 0;
                m++;
            }
        }
    }

    int main() {
        int *a, *b;
        int *num;
        int dem[3];
        int i, j, k, size;
        bool *f, q;
        mpancakepiles piles;
        f = &q;
        *f = true;
        string s;
        ifstream infile;
        infile.open("input.txt");
        getline(infile, s);
        strtonum(s, f, dem, num);
        *f = false;
        size = dem[0] * dem[1] * dem[2] * 2;
        num = new int[size];
        m -= 3;
        while (getline(infile, s)) {
            strtonum(s, f, dem, num);
        }
        infile.close();
        size = size / 2;
        a = new int[size];
        b = new int[size];
        for (i = 0; i < size; i++) {
            a[i] = num[2 * i];
            b[i] = bool(num[2 * i + 1]);
        }
        piles.setmpancakepiles(dem[0], dem[1], dem[2]);
        for (i = 0; i < dem[1]; i++) {
            for (j = 0; j < dem[0]; j++) {
                for (k = 0; k < dem[2]; k++) {
                    piles.mpiles[i][j].pile[k].size = a[i * dem[2] + j * dem[1] * dem[2] + k];
                    piles.mpiles[i][j].pile[k].burnt = b[i * dem[2] + j * dem[1] * dem[2] + k];
                }
            }
        }

        piles.sort_exterior();
        piles.sort_interior();

        ofstream outfile("output.txt", ios::out);
        outfile << dem[0] << ' ';
        outfile << dem[1] << ' ';
        outfile << dem[2];
        outfile << endl;
        for (i = 0; i < dem[0]; i++) {
            for (j = 0; j < dem[1]; j++) {
                for (k = 0; k < dem[2]; k++) {
                    outfile << piles.mpiles[j][i].pile[k].size << ',';
                    outfile << piles.mpiles[j][i].pile[k].burnt << ' ';
                }
                outfile << endl;
            }
        }

    }














