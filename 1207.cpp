#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class rel_point {
	public:
    double angle;
    int index;
};

bool rel_point_compar(rel_point a, rel_point b){
    return a.angle < b.angle;
}

int main(){
    int n;
    cin>>n;

    int left_dot[3] = {99999999, 99999999, 0};
    vector <vector <int> > dots(n, vector <int>(2));
    for (int i = 0; i < n; ++i) {
        cin>>dots[i][0]>>dots[i][1];

        if (left_dot[0] > dots[i][0]) {
            left_dot[0] = dots[i][0]; left_dot[1] = dots[i][1]; left_dot[2] = i;
        }
    }
    
    vector <rel_point> angles(n-1);
    int k = 0;

    for (int i=0; i<n; i++) {
    	if (i != left_dot[2]) {
		
        double x = dots[i][0] - left_dot[0];
        double y = dots[i][1] - left_dot[1];

        angles[k].angle = atan(y/x);
		angles[k].index = i;
        k++;
    }
    }

    sort(angles.begin(), angles.end(), rel_point_compar);

    cout << left_dot[2]+1 << " " << angles[(n-1)/2].index+1 << endl;
}
