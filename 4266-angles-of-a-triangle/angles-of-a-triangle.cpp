class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        vector<double> angles;
        if(sides[0] + sides[1] <= sides[2]){
            return {};
        }
        // condition for a triangle to exist
        else if(sides[0] + sides[1] > sides[2]){  
            double a = sides[0];
            double b = sides[1];
            double c = sides[2];
            // Angle opposite a
            double A = acos((b*b + c*c - a*a) / (2*b*c));
            // Angle opposite b
            double B = acos((a*a + c*c - b*b) / (2*a*c));
            // Angle opposite c
            double C = acos((a*a + b*b - c*c) / (2*a*b));
            // Convert radians -> degrees
            A = A * 180.0 / acos(-1);
            B = B * 180.0 / acos(-1);
            C = C * 180.0 / acos(-1);
            angles.push_back(A);
            angles.push_back(B);
            angles.push_back(C);
            sort(angles.begin(), angles.end());
        }
        return angles;
    }
};