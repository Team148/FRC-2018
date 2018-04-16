#ifndef FromMiddlePos_ToRightSwitchPath_H
#define FromMiddlePos_ToRightSwitchPath_H

#include "TrajectoryPath.h"

class FromMiddlePos_ToRightSwitchPath : TrajectoryPath {

public:
	static TrajectoryPath* GetInstance();
	static FromMiddlePos_ToRightSwitchPath *m_instance;
	int GetIndexLength();
	double GetStartHeading();
	double GetEndHeading();
	double GetTimeLength();
	double GetDT();
	double* GetLeftTrajectoryArray(int index);
	double* GetRightTrajectoryArray(int index);
	double GetLeftPosition(int index);
	double GetLeftVelocity(int index);
	double GetLeftAcceleration(int index);
	double GetRightPosition(int index);
	double GetRightVelocity(int index);
	double GetRightAcceleration(int index);
	double GetHeading(int index);
	double GetX(int index);
	double GetY(int index);

private:
	FromMiddlePos_ToRightSwitchPath();
	int num_index = 225;
	double left_wheel[225][8] ={ 
	{0.000, 0.058, 5.839, 583.855, 6.283, 0.010, 0.000, 12.450},
	{0.001, 0.117, 5.839, 0.006, 6.283, 0.010, 0.001, 12.450},
	{0.004, 0.263, 14.597, 875.814, 6.283, 0.010, 0.004, 12.450},
	{0.009, 0.467, 20.436, 583.955, 6.283, 0.010, 0.009, 12.450},
	{0.016, 0.730, 26.277, 584.086, 6.283, 0.010, 0.016, 12.450},
	{0.027, 1.051, 32.120, 584.299, 6.283, 0.010, 0.027, 12.450},
	{0.041, 1.431, 37.966, 584.617, 6.283, 0.010, 0.041, 12.450},
	{0.060, 1.869, 43.817, 585.058, 6.283, 0.010, 0.060, 12.450},
	{0.083, 2.366, 49.673, 585.642, 6.283, 0.010, 0.083, 12.450},
	{0.112, 2.921, 55.537, 586.390, 6.283, 0.010, 0.112, 12.450},
	{0.148, 3.535, 61.410, 587.320, 6.283, 0.010, 0.148, 12.450},
	{0.190, 4.208, 67.295, 588.450, 6.283, 0.010, 0.190, 12.450},
	{0.239, 4.940, 73.193, 589.797, 6.283, 0.010, 0.239, 12.450},
	{0.297, 5.731, 79.107, 591.378, 6.283, 0.010, 0.297, 12.450},
	{0.362, 6.581, 85.039, 593.206, 6.283, 0.010, 0.362, 12.450},
	{0.437, 7.491, 90.992, 595.295, 6.283, 0.010, 0.437, 12.450},
	{0.522, 8.461, 96.968, 597.656, 6.283, 0.010, 0.522, 12.450},
	{0.617, 9.461, 100.041, 307.293, 6.283, 0.010, 0.617, 12.450},
	{0.721, 10.464, 100.204, 16.318, 6.283, 0.010, 0.721, 12.450},
	{0.836, 11.467, 100.383, 17.863, 6.283, 0.010, 0.836, 12.450},
	{0.961, 12.473, 100.577, 19.358, 6.283, 0.010, 0.961, 12.450},
	{1.095, 13.481, 100.785, 20.798, 6.283, 0.010, 1.095, 12.450},
	{1.240, 14.491, 101.006, 22.177, 6.283, 0.010, 1.240, 12.450},
	{1.395, 15.503, 101.241, 23.493, 6.283, 0.010, 1.395, 12.450},
	{1.561, 16.518, 101.489, 24.741, 6.283, 0.010, 1.561, 12.450},
	{1.736, 17.536, 101.748, 25.916, 6.282, 0.010, 1.736, 12.450},
	{1.921, 18.556, 102.018, 27.015, 6.282, 0.010, 1.921, 12.449},
	{2.117, 19.579, 102.298, 28.035, 6.282, 0.010, 2.117, 12.449},
	{2.323, 20.605, 102.588, 28.970, 6.282, 0.010, 2.323, 12.449},
	{2.540, 21.634, 102.886, 29.818, 6.282, 0.010, 2.540, 12.449},
	{2.766, 22.666, 103.192, 30.576, 6.281, 0.010, 2.766, 12.448},
	{3.003, 23.701, 103.504, 31.239, 6.281, 0.010, 3.003, 12.448},
	{3.251, 24.739, 103.822, 31.805, 6.281, 0.010, 3.251, 12.447},
	{3.508, 25.780, 104.145, 32.270, 6.280, 0.010, 3.508, 12.447},
	{3.777, 26.825, 104.471, 32.632, 6.280, 0.010, 3.777, 12.446},
	{4.055, 27.873, 104.800, 32.888, 6.280, 0.010, 4.055, 12.445},
	{4.345, 28.924, 105.131, 33.034, 6.279, 0.010, 4.345, 12.444},
	{4.644, 29.979, 105.461, 33.069, 6.278, 0.010, 4.644, 12.442},
	{4.955, 31.037, 105.791, 32.989, 6.278, 0.010, 4.955, 12.441},
	{5.276, 32.098, 106.119, 32.793, 6.277, 0.010, 5.276, 12.439},
	{5.607, 33.163, 106.444, 32.477, 6.276, 0.010, 5.607, 12.437},
	{5.950, 34.230, 106.764, 32.040, 6.276, 0.010, 5.950, 12.435},
	{6.303, 35.301, 107.079, 31.480, 6.275, 0.010, 6.303, 12.432},
	{6.666, 36.375, 107.387, 30.795, 6.274, 0.010, 6.666, 12.429},
	{7.041, 37.452, 107.687, 29.982, 6.273, 0.010, 7.041, 12.425},
	{7.426, 38.531, 107.977, 29.040, 6.272, 0.010, 7.426, 12.421},
	{7.822, 39.614, 108.257, 27.968, 6.271, 0.010, 7.822, 12.416},
	{8.229, 40.699, 108.525, 26.763, 6.270, 0.010, 8.229, 12.411},
	{8.647, 41.787, 108.779, 25.425, 6.268, 0.010, 8.647, 12.405},
	{9.076, 42.877, 109.018, 23.952, 6.267, 0.010, 9.076, 12.398},
	{9.516, 43.970, 109.242, 22.343, 6.265, 0.010, 9.515, 12.391},
	{9.966, 45.064, 109.448, 20.598, 6.264, 0.010, 9.966, 12.382},
	{10.428, 46.160, 109.635, 18.715, 6.262, 0.010, 10.428, 12.373},
	{10.901, 47.259, 109.802, 16.695, 6.261, 0.010, 10.900, 12.363},
	{11.384, 48.358, 109.947, 14.537, 6.259, 0.010, 11.383, 12.351},
	{11.879, 49.459, 110.070, 12.241, 6.257, 0.010, 11.878, 12.339},
	{12.384, 50.560, 110.168, 9.808, 6.255, 0.010, 12.383, 12.325},
	{12.901, 51.663, 110.240, 7.239, 6.253, 0.010, 12.900, 12.310},
	{13.429, 52.766, 110.285, 4.534, 6.251, 0.010, 13.427, 12.294},
	{13.967, 53.869, 110.302, 1.696, 6.249, 0.010, 13.966, 12.276},
	{14.517, 54.972, 110.290, -1.273, 6.246, 0.010, 14.515, 12.256},
	{15.078, 56.074, 110.246, -4.371, 6.244, 0.010, 15.075, 12.235},
	{15.650, 57.176, 110.170, -7.594, 6.242, 0.010, 15.647, 12.212},
	{16.232, 58.276, 110.061, -10.938, 6.239, 0.010, 16.229, 12.187},
	{16.826, 59.375, 109.917, -14.399, 6.236, 0.010, 16.822, 12.160},
	{17.431, 60.473, 109.737, -17.972, 6.234, 0.010, 17.426, 12.131},
	{18.047, 61.568, 109.520, -21.651, 6.231, 0.010, 18.041, 12.099},
	{18.673, 62.661, 109.266, -25.428, 6.228, 0.010, 18.666, 12.066},
	{19.311, 63.750, 108.973, -29.297, 6.225, 0.010, 19.303, 12.030},
	{19.959, 64.837, 108.641, -33.250, 6.222, 0.010, 19.950, 11.991},
	{20.618, 65.920, 108.268, -37.276, 6.219, 0.010, 20.608, 11.949},
	{21.288, 66.998, 107.854, -41.366, 6.216, 0.010, 21.277, 11.905},
	{21.969, 68.072, 107.399, -45.509, 6.212, 0.010, 21.956, 11.858},
	{22.660, 69.141, 106.902, -49.695, 6.209, 0.010, 22.645, 11.808},
	{23.362, 70.205, 106.363, -53.909, 6.206, 0.010, 23.345, 11.755},
	{24.075, 71.263, 105.782, -58.140, 6.202, 0.010, 24.056, 11.698},
	{24.798, 72.314, 105.158, -62.373, 6.199, 0.010, 24.776, 11.639},
	{25.532, 73.359, 104.492, -66.595, 6.195, 0.010, 25.507, 11.576},
	{26.276, 74.397, 103.784, -70.789, 6.192, 0.010, 26.248, 11.509},
	{27.030, 75.427, 103.035, -74.942, 6.188, 0.010, 26.999, 11.439},
	{27.794, 76.450, 102.244, -79.037, 6.184, 0.010, 27.760, 11.365},
	{28.569, 77.464, 101.414, -83.057, 6.181, 0.010, 28.531, 11.287},
	{29.354, 78.469, 100.544, -86.988, 6.177, 0.010, 29.311, 11.205},
	{30.148, 79.466, 99.636, -90.813, 6.174, 0.010, 30.101, 11.120},
	{30.953, 80.452, 98.691, -94.515, 6.170, 0.010, 30.901, 11.030},
	{31.767, 81.430, 97.710, -98.079, 6.166, 0.010, 31.710, 10.937},
	{32.591, 82.397, 96.695, -101.489, 6.163, 0.010, 32.528, 10.839},
	{33.425, 83.353, 95.648, -104.729, 6.159, 0.010, 33.355, 10.738},
	{34.268, 84.299, 94.570, -107.786, 6.156, 0.010, 34.192, 10.632},
	{35.120, 85.233, 93.463, -110.645, 6.152, 0.010, 35.037, 10.522},
	{35.982, 86.157, 92.330, -113.291, 6.149, 0.010, 35.891, 10.408},
	{36.852, 87.068, 91.173, -115.714, 6.145, 0.010, 36.753, 10.290},
	{37.732, 87.968, 89.994, -117.899, 6.142, 0.010, 37.625, 10.168},
	{38.621, 88.856, 88.796, -119.835, 6.139, 0.010, 38.504, 10.041},
	{39.518, 89.732, 87.581, -121.512, 6.136, 0.010, 39.392, 9.911},
	{40.424, 90.596, 86.352, -122.919, 6.133, 0.010, 40.288, 9.776},
	{41.338, 91.416, 82.075, -427.641, 6.130, 0.010, 41.191, 9.638},
	{42.260, 92.164, 74.787, -728.811, 6.127, 0.010, 42.102, 9.496},
	{43.188, 92.840, 67.549, -723.767, 6.124, 0.010, 43.019, 9.350},
	{44.122, 93.443, 60.370, -717.935, 6.122, 0.010, 43.941, 9.202},
	{45.062, 93.976, 53.257, -711.351, 6.120, 0.010, 44.869, 9.050},
	{46.007, 94.438, 46.216, -704.060, 6.117, 0.010, 45.800, 8.895},
	{46.955, 94.831, 39.255, -696.108, 6.115, 0.010, 46.736, 8.737},
	{47.906, 95.155, 32.379, -687.545, 6.114, 0.010, 47.674, 8.578},
	{48.861, 95.410, 25.595, -678.424, 6.112, 0.010, 48.614, 8.416},
	{49.817, 95.600, 18.907, -668.799, 6.111, 0.010, 49.556, 8.253},
	{50.774, 95.723, 12.320, -658.726, 6.110, 0.010, 50.499, 8.088},
	{51.732, 95.781, 5.837, -648.261, 6.109, 0.010, 51.442, 7.922},
	{52.689, 95.776, -0.537, -637.462, 6.108, 0.010, 52.385, 7.755},
	{53.646, 95.708, -6.801, -626.385, 6.107, 0.010, 53.328, 7.588},
	{54.602, 95.578, -12.952, -615.088, 6.107, 0.010, 54.269, 7.420},
	{55.556, 95.387, -19.129, -617.700, 6.107, 0.010, 55.208, 7.253},
	{56.507, 95.106, -28.099, -897.024, 6.107, 0.010, 56.144, 7.086},
	{57.455, 94.738, -36.778, -867.856, 6.107, 0.010, 57.077, 6.920},
	{58.398, 94.314, -42.413, -563.535, 6.108, 0.010, 58.005, 6.755},
	{59.336, 93.835, -47.934, -552.082, 6.109, 0.010, 58.929, 6.592},
	{60.269, 93.301, -53.342, -540.794, 6.110, 0.010, 59.848, 6.430},
	{61.196, 92.715, -58.639, -529.729, 6.111, 0.010, 60.762, 6.270},
	{62.117, 92.077, -63.829, -518.944, 6.112, 0.010, 61.669, 6.113},
	{63.031, 91.387, -68.914, -508.496, 6.114, 0.010, 62.569, 5.958},
	{63.937, 90.648, -73.898, -498.443, 6.116, 0.010, 63.463, 5.806},
	{64.836, 89.861, -78.786, -488.840, 6.118, 0.010, 64.349, 5.657},
	{65.726, 89.025, -83.584, -479.744, 6.120, 0.010, 65.227, 5.511},
	{66.608, 88.142, -88.296, -471.208, 6.122, 0.010, 66.097, 5.369},
	{67.480, 87.213, -92.929, -463.286, 6.125, 0.010, 66.958, 5.230},
	{68.342, 86.238, -97.489, -456.027, 6.127, 0.010, 67.810, 5.095},
	{69.194, 85.218, -101.984, -449.478, 6.130, 0.010, 68.652, 4.964},
	{70.036, 84.154, -106.421, -443.682, 6.133, 0.010, 69.484, 4.836},
	{70.866, 83.047, -110.673, -425.227, 6.136, 0.010, 70.305, 4.713},
	{71.686, 81.926, -112.100, -142.718, 6.139, 0.010, 71.116, 4.594},
	{72.494, 80.817, -110.871, 122.861, 6.142, 0.010, 71.916, 4.479},
	{73.291, 79.721, -109.657, 121.441, 6.146, 0.010, 72.705, 4.369},
	{74.077, 78.636, -108.460, 119.752, 6.149, 0.010, 73.484, 4.262},
	{74.853, 77.563, -107.281, 117.803, 6.152, 0.010, 74.253, 4.160},
	{75.618, 76.502, -106.125, 115.606, 6.156, 0.010, 75.012, 4.061},
	{76.372, 75.452, -104.994, 113.173, 6.159, 0.010, 75.760, 3.967},
	{77.117, 74.413, -103.889, 110.516, 6.163, 0.010, 76.499, 3.876},
	{77.850, 73.385, -102.812, 107.648, 6.167, 0.010, 77.228, 3.789},
	{78.574, 72.367, -101.766, 104.581, 6.170, 0.010, 77.947, 3.706},
	{79.288, 71.360, -100.753, 101.332, 6.174, 0.010, 78.656, 3.627},
	{79.991, 70.362, -99.774, 97.914, 6.177, 0.010, 79.355, 3.551},
	{80.685, 69.374, -98.830, 94.343, 6.181, 0.010, 80.045, 3.479},
	{81.369, 68.394, -97.924, 90.634, 6.185, 0.010, 80.726, 3.411},
	{82.043, 67.424, -97.056, 86.804, 6.188, 0.010, 81.397, 3.346},
	{82.708, 66.462, -96.227, 82.868, 6.192, 0.010, 82.059, 3.284},
	{83.363, 65.507, -95.439, 78.843, 6.195, 0.010, 82.711, 3.225},
	{84.009, 64.560, -94.691, 74.745, 6.199, 0.010, 83.354, 3.170},
	{84.645, 63.620, -93.986, 70.590, 6.202, 0.010, 83.988, 3.118},
	{85.272, 62.687, -93.322, 66.393, 6.206, 0.010, 84.613, 3.068},
	{85.889, 61.760, -92.700, 62.171, 6.209, 0.010, 85.229, 3.021},
	{86.498, 60.839, -92.120, 57.937, 6.212, 0.010, 85.836, 2.977},
	{87.097, 59.923, -91.583, 53.707, 6.216, 0.010, 86.434, 2.936},
	{87.687, 59.012, -91.088, 49.493, 6.219, 0.010, 87.023, 2.897},
	{88.268, 58.106, -90.635, 45.309, 6.222, 0.010, 87.602, 2.861},
	{88.840, 57.204, -90.224, 41.168, 6.225, 0.010, 88.173, 2.827},
	{89.403, 56.305, -89.853, 37.080, 6.228, 0.010, 88.736, 2.795},
	{89.957, 55.410, -89.522, 33.057, 6.231, 0.010, 89.289, 2.765},
	{90.502, 54.518, -89.231, 29.109, 6.234, 0.010, 89.833, 2.737},
	{91.039, 53.628, -88.979, 25.244, 6.236, 0.010, 90.369, 2.712},
	{91.566, 52.740, -88.764, 21.471, 6.239, 0.010, 90.896, 2.688},
	{92.085, 51.854, -88.586, 17.797, 6.242, 0.010, 91.414, 2.666},
	{92.594, 50.970, -88.444, 14.230, 6.244, 0.010, 91.923, 2.645},
	{93.095, 50.087, -88.336, 10.774, 6.247, 0.010, 92.424, 2.626},
	{93.587, 49.204, -88.262, 7.435, 6.249, 0.010, 92.915, 2.609},
	{94.070, 48.322, -88.220, 4.218, 6.251, 0.010, 93.398, 2.593},
	{94.545, 47.440, -88.208, 1.126, 6.253, 0.010, 93.873, 2.578},
	{95.010, 46.557, -88.227, -1.837, 6.255, 0.010, 94.338, 2.564},
	{95.467, 45.675, -88.273, -4.668, 6.257, 0.010, 94.795, 2.552},
	{95.915, 44.791, -88.347, -7.366, 6.259, 0.010, 95.242, 2.541},
	{96.354, 43.907, -88.446, -9.929, 6.261, 0.010, 95.681, 2.530},
	{96.784, 43.021, -88.570, -12.355, 6.262, 0.010, 96.111, 2.521},
	{97.206, 42.134, -88.716, -14.644, 6.264, 0.010, 96.533, 2.513},
	{97.618, 41.245, -88.884, -16.796, 6.266, 0.010, 96.945, 2.505},
	{98.022, 40.354, -89.072, -18.810, 6.267, 0.010, 97.349, 2.498},
	{98.416, 39.462, -89.279, -20.686, 6.268, 0.010, 97.743, 2.492},
	{98.802, 38.567, -89.503, -22.424, 6.270, 0.010, 98.129, 2.487},
	{99.179, 37.669, -89.744, -24.026, 6.271, 0.010, 98.505, 2.482},
	{99.546, 36.769, -89.999, -25.493, 6.272, 0.010, 98.873, 2.478},
	{99.905, 35.866, -90.267, -26.824, 6.273, 0.010, 99.232, 2.474},
	{100.255, 34.961, -90.547, -28.022, 6.274, 0.010, 99.581, 2.470},
	{100.595, 34.053, -90.838, -29.088, 6.275, 0.010, 99.922, 2.467},
	{100.927, 33.141, -91.138, -30.024, 6.276, 0.010, 100.253, 2.465},
	{101.249, 32.227, -91.447, -30.831, 6.276, 0.010, 100.575, 2.462},
	{101.562, 31.309, -91.762, -31.510, 6.277, 0.010, 100.889, 2.460},
	{101.866, 30.388, -92.082, -32.064, 6.278, 0.010, 101.192, 2.459},
	{102.160, 29.464, -92.407, -32.495, 6.278, 0.010, 101.487, 2.457},
	{102.446, 28.537, -92.735, -32.805, 6.279, 0.010, 101.772, 2.456},
	{102.722, 27.606, -93.065, -32.995, 6.280, 0.010, 102.048, 2.455},
	{102.989, 26.672, -93.396, -33.069, 6.280, 0.010, 102.315, 2.454},
	{103.246, 25.735, -93.726, -33.029, 6.280, 0.010, 102.573, 2.453},
	{103.494, 24.794, -94.055, -32.878, 6.281, 0.010, 102.820, 2.453},
	{103.732, 23.851, -94.381, -32.617, 6.281, 0.010, 103.059, 2.452},
	{103.961, 22.904, -94.704, -32.250, 6.281, 0.010, 103.288, 2.452},
	{104.181, 21.953, -95.021, -31.780, 6.282, 0.010, 103.508, 2.451},
	{104.391, 21.000, -95.334, -31.209, 6.282, 0.010, 103.718, 2.451},
	{104.591, 20.044, -95.639, -30.541, 6.282, 0.010, 103.918, 2.451},
	{104.782, 19.084, -95.937, -29.779, 6.282, 0.010, 104.109, 2.451},
	{104.963, 18.122, -96.226, -28.927, 6.282, 0.010, 104.290, 2.450},
	{105.135, 17.157, -96.506, -27.987, 6.283, 0.010, 104.462, 2.450},
	{105.297, 16.189, -96.776, -26.964, 6.283, 0.010, 104.624, 2.450},
	{105.449, 15.219, -97.034, -25.861, 6.283, 0.010, 104.776, 2.450},
	{105.592, 14.246, -97.281, -24.682, 6.283, 0.010, 104.918, 2.450},
	{105.724, 13.271, -97.515, -23.431, 6.283, 0.010, 105.051, 2.450},
	{105.847, 12.294, -97.736, -22.112, 6.283, 0.010, 105.174, 2.450},
	{105.960, 11.314, -97.944, -20.729, 6.283, 0.010, 105.287, 2.450},
	{106.064, 10.333, -98.137, -19.287, 6.283, 0.010, 105.390, 2.450},
	{106.157, 9.350, -98.314, -17.790, 6.283, 0.010, 105.484, 2.450},
	{106.241, 8.366, -98.336, -2.206, 6.283, 0.010, 105.567, 2.450},
	{106.315, 7.412, -95.429, 290.707, 6.283, 0.010, 105.642, 2.450},
	{106.380, 6.515, -89.728, 570.171, 6.283, 0.010, 105.707, 2.450},
	{106.437, 5.675, -84.003, 572.519, 6.283, 0.010, 105.763, 2.450},
	{106.486, 4.892, -78.257, 574.596, 6.283, 0.010, 105.812, 2.450},
	{106.527, 4.167, -72.492, 576.412, 6.283, 0.010, 105.854, 2.450},
	{106.562, 3.500, -66.713, 577.981, 6.283, 0.010, 105.889, 2.450},
	{106.591, 2.891, -60.919, 579.317, 6.283, 0.010, 105.918, 2.450},
	{106.615, 2.340, -55.115, 580.437, 6.283, 0.010, 105.941, 2.450},
	{106.633, 1.847, -49.302, 581.358, 6.283, 0.010, 105.960, 2.450},
	{106.647, 1.412, -43.481, 582.098, 6.283, 0.010, 105.974, 2.450},
	{106.658, 1.035, -37.654, 582.675, 6.283, 0.010, 105.984, 2.450},
	{106.665, 0.717, -31.823, 583.110, 6.283, 0.010, 105.991, 2.450},
	{106.669, 0.457, -25.988, 583.422, 6.283, 0.010, 105.996, 2.450},
	{106.672, 0.256, -20.152, 583.631, 6.283, 0.010, 105.999, 2.450},
	{106.673, 0.113, -14.315, 583.759, 6.283, 0.010, 106.000, 2.450},
	{106.673, 0.028, -8.476, 583.824, 6.283, 0.010, 106.000, 2.450},
	{106.673, 0.000, -2.779, 569.777, 6.283, 0.010, 106.000, 2.450}};
	double right_wheel[225][8] ={ 
	{0.000, 0.058, 5.839, 583.855, 6.283, 0.010, 0.000, -12.450},
	{0.001, 0.117, 5.838, -0.006, 6.283, 0.010, 0.001, -12.450},
	{0.004, 0.263, 14.596, 875.750, 6.283, 0.010, 0.004, -12.450},
	{0.009, 0.467, 20.434, 583.755, 6.283, 0.010, 0.009, -12.450},
	{0.016, 0.730, 26.270, 583.624, 6.283, 0.010, 0.016, -12.450},
	{0.027, 1.051, 32.104, 583.410, 6.283, 0.010, 0.027, -12.450},
	{0.041, 1.430, 37.935, 583.093, 6.283, 0.010, 0.041, -12.450},
	{0.060, 1.868, 43.761, 582.652, 6.283, 0.010, 0.060, -12.450},
	{0.083, 2.364, 49.582, 582.068, 6.283, 0.010, 0.083, -12.450},
	{0.112, 2.918, 55.395, 581.320, 6.283, 0.010, 0.112, -12.450},
	{0.148, 3.530, 61.199, 580.390, 6.283, 0.010, 0.148, -12.450},
	{0.190, 4.199, 66.992, 579.260, 6.283, 0.010, 0.190, -12.450},
	{0.239, 4.927, 72.771, 577.913, 6.283, 0.010, 0.239, -12.450},
	{0.296, 5.712, 78.534, 576.332, 6.283, 0.010, 0.296, -12.450},
	{0.362, 6.555, 84.279, 574.504, 6.283, 0.010, 0.362, -12.450},
	{0.436, 7.455, 90.003, 572.415, 6.283, 0.010, 0.436, -12.450},
	{0.520, 8.412, 95.704, 570.054, 6.283, 0.010, 0.520, -12.450},
	{0.614, 9.397, 98.470, 276.562, 6.283, 0.010, 0.614, -12.450},
	{0.718, 10.380, 98.306, -16.318, 6.283, 0.010, 0.718, -12.450},
	{0.832, 11.361, 98.128, -17.863, 6.283, 0.010, 0.832, -12.450},
	{0.955, 12.341, 97.934, -19.358, 6.283, 0.010, 0.955, -12.450},
	{1.088, 13.318, 97.726, -20.798, 6.283, 0.010, 1.088, -12.450},
	{1.231, 14.293, 97.504, -22.177, 6.283, 0.010, 1.231, -12.450},
	{1.384, 15.266, 97.269, -23.493, 6.283, 0.010, 1.384, -12.450},
	{1.546, 16.236, 97.022, -24.741, 6.283, 0.010, 1.546, -12.450},
	{1.718, 17.204, 96.763, -25.916, 6.282, 0.010, 1.718, -12.450},
	{1.900, 18.169, 96.493, -27.015, 6.282, 0.010, 1.900, -12.451},
	{2.091, 19.131, 96.212, -28.035, 6.282, 0.010, 2.091, -12.451},
	{2.292, 20.090, 95.923, -28.970, 6.282, 0.010, 2.292, -12.451},
	{2.503, 21.046, 95.624, -29.818, 6.282, 0.010, 2.503, -12.451},
	{2.723, 21.999, 95.319, -30.576, 6.281, 0.010, 2.723, -12.452},
	{2.952, 22.949, 95.006, -31.239, 6.281, 0.010, 2.952, -12.452},
	{3.191, 23.896, 94.688, -31.805, 6.281, 0.010, 3.191, -12.453},
	{3.439, 24.840, 94.366, -32.270, 6.280, 0.010, 3.439, -12.453},
	{3.697, 25.780, 94.039, -32.632, 6.280, 0.010, 3.697, -12.454},
	{3.964, 26.717, 93.710, -32.888, 6.280, 0.010, 3.964, -12.455},
	{4.241, 27.651, 93.380, -33.034, 6.279, 0.010, 4.241, -12.456},
	{4.527, 28.582, 93.049, -33.069, 6.278, 0.010, 4.527, -12.457},
	{4.822, 29.509, 92.719, -32.989, 6.278, 0.010, 4.822, -12.459},
	{5.126, 30.433, 92.392, -32.793, 6.277, 0.010, 5.126, -12.460},
	{5.440, 31.353, 92.067, -32.478, 6.276, 0.010, 5.440, -12.462},
	{5.762, 32.271, 91.746, -32.041, 6.276, 0.010, 5.762, -12.465},
	{6.094, 33.185, 91.432, -31.481, 6.275, 0.010, 6.094, -12.467},
	{6.435, 34.096, 91.124, -30.795, 6.274, 0.010, 6.435, -12.470},
	{6.785, 35.005, 90.824, -29.983, 6.273, 0.010, 6.785, -12.474},
	{7.144, 35.910, 90.533, -29.041, 6.272, 0.010, 7.144, -12.478},
	{7.512, 36.813, 90.254, -27.968, 6.271, 0.010, 7.512, -12.482},
	{7.890, 37.712, 89.986, -26.764, 6.270, 0.010, 7.889, -12.487},
	{8.276, 38.610, 89.732, -25.426, 6.268, 0.010, 8.276, -12.493},
	{8.671, 39.505, 89.492, -23.953, 6.267, 0.010, 8.671, -12.499},
	{9.075, 40.397, 89.269, -22.344, 6.265, 0.010, 9.074, -12.506},
	{9.488, 41.288, 89.063, -20.599, 6.264, 0.010, 9.487, -12.513},
	{9.909, 42.177, 88.876, -18.716, 6.262, 0.010, 9.909, -12.522},
	{10.340, 43.064, 88.709, -16.696, 6.261, 0.010, 10.339, -12.531},
	{10.780, 43.949, 88.563, -14.538, 6.259, 0.010, 10.779, -12.541},
	{11.228, 44.834, 88.441, -12.242, 6.257, 0.010, 11.227, -12.553},
	{11.685, 45.717, 88.343, -9.809, 6.255, 0.010, 11.684, -12.565},
	{12.151, 46.600, 88.270, -7.240, 6.253, 0.010, 12.150, -12.578},
	{12.626, 47.482, 88.225, -4.536, 6.251, 0.010, 12.624, -12.593},
	{13.109, 48.364, 88.208, -1.697, 6.249, 0.010, 13.108, -12.609},
	{13.602, 49.247, 88.221, 1.272, 6.246, 0.010, 13.600, -12.627},
	{14.103, 50.129, 88.264, 4.369, 6.244, 0.010, 14.101, -12.646},
	{14.613, 51.013, 88.340, 7.592, 6.242, 0.010, 14.611, -12.667},
	{15.132, 51.897, 88.450, 10.937, 6.239, 0.010, 15.129, -12.689},
	{15.660, 52.783, 88.594, 14.398, 6.236, 0.010, 15.656, -12.713},
	{16.197, 53.671, 88.773, 17.971, 6.234, 0.010, 16.192, -12.739},
	{16.742, 54.561, 88.990, 21.650, 6.231, 0.010, 16.737, -12.766},
	{17.297, 55.453, 89.244, 25.428, 6.228, 0.010, 17.291, -12.796},
	{17.860, 56.348, 89.537, 29.297, 6.225, 0.010, 17.854, -12.828},
	{18.433, 57.247, 89.870, 33.249, 6.222, 0.010, 18.425, -12.862},
	{19.014, 58.150, 90.242, 37.275, 6.219, 0.010, 19.005, -12.899},
	{19.605, 59.056, 90.656, 41.366, 6.216, 0.010, 19.595, -12.938},
	{20.205, 59.967, 91.111, 45.509, 6.212, 0.010, 20.193, -12.979},
	{20.814, 60.883, 91.608, 49.695, 6.209, 0.010, 20.800, -13.023},
	{21.432, 61.805, 92.147, 53.910, 6.206, 0.010, 21.416, -13.070},
	{22.059, 62.732, 92.729, 58.141, 6.202, 0.010, 22.042, -13.120},
	{22.696, 63.666, 93.352, 62.374, 6.199, 0.010, 22.676, -13.173},
	{23.342, 64.606, 94.018, 66.596, 6.195, 0.010, 23.320, -13.228},
	{23.997, 65.553, 94.726, 70.791, 6.192, 0.010, 23.973, -13.287},
	{24.662, 66.508, 95.476, 74.944, 6.188, 0.010, 24.635, -13.349},
	{25.337, 67.471, 96.266, 79.039, 6.184, 0.010, 25.307, -13.414},
	{26.021, 68.441, 97.097, 83.060, 6.181, 0.010, 25.988, -13.483},
	{26.716, 69.421, 97.967, 86.991, 6.177, 0.010, 26.678, -13.555},
	{27.420, 70.410, 98.875, 90.816, 6.174, 0.010, 27.378, -13.631},
	{28.134, 71.408, 99.820, 94.518, 6.170, 0.010, 28.088, -13.710},
	{28.858, 72.416, 100.801, 98.083, 6.166, 0.010, 28.807, -13.793},
	{29.592, 73.434, 101.816, 101.493, 6.163, 0.010, 29.536, -13.880},
	{30.337, 74.463, 102.863, 104.734, 6.159, 0.010, 30.275, -13.971},
	{31.092, 75.502, 103.941, 107.790, 6.156, 0.010, 31.024, -14.066},
	{31.857, 76.553, 105.047, 110.649, 6.152, 0.010, 31.783, -14.164},
	{32.634, 77.615, 106.180, 113.296, 6.149, 0.010, 32.553, -14.267},
	{33.420, 78.688, 107.338, 115.718, 6.145, 0.010, 33.332, -14.374},
	{34.218, 79.773, 108.517, 117.903, 6.142, 0.010, 34.122, -14.485},
	{35.027, 80.870, 109.715, 119.840, 6.139, 0.010, 34.923, -14.600},
	{35.847, 81.980, 110.930, 121.516, 6.136, 0.010, 35.734, -14.719},
	{36.678, 83.101, 112.159, 122.923, 6.133, 0.010, 36.556, -14.842},
	{37.520, 84.207, 110.597, -156.209, 6.130, 0.010, 37.388, -14.970},
	{38.372, 85.269, 106.208, -438.895, 6.127, 0.010, 38.231, -15.101},
	{39.235, 86.287, 101.769, -443.939, 6.124, 0.010, 39.083, -15.237},
	{40.108, 87.260, 97.271, -449.773, 6.122, 0.010, 39.944, -15.376},
	{40.990, 88.187, 92.708, -456.357, 6.120, 0.010, 40.815, -15.518},
	{41.880, 89.067, 88.071, -463.649, 6.117, 0.010, 41.693, -15.664},
	{42.779, 89.901, 83.355, -471.603, 6.115, 0.010, 42.580, -15.813},
	{43.686, 90.686, 78.553, -480.167, 6.114, 0.010, 43.474, -15.965},
	{44.601, 91.423, 73.661, -489.289, 6.112, 0.010, 44.375, -16.120},
	{45.522, 92.110, 68.671, -498.915, 6.111, 0.010, 45.282, -16.278},
	{46.449, 92.746, 63.582, -508.989, 6.110, 0.010, 46.196, -16.438},
	{47.382, 93.329, 58.387, -519.454, 6.109, 0.010, 47.115, -16.599},
	{48.321, 93.860, 53.084, -530.254, 6.108, 0.010, 48.039, -16.763},
	{49.264, 94.337, 47.671, -541.332, 6.107, 0.010, 48.968, -16.928},
	{50.212, 94.759, 42.145, -552.629, 6.107, 0.010, 49.901, -17.094},
	{51.163, 95.122, 36.363, -578.163, 6.107, 0.010, 50.838, -17.261},
	{52.117, 95.397, 27.536, -882.694, 6.107, 0.010, 51.777, -17.428},
	{53.073, 95.584, 18.699, -883.717, 6.107, 0.010, 52.718, -17.596},
	{54.030, 95.711, 12.657, -604.183, 6.108, 0.010, 53.660, -17.763},
	{54.988, 95.776, 6.501, -615.636, 6.109, 0.010, 54.603, -17.930},
	{55.946, 95.778, 0.232, -626.923, 6.110, 0.010, 55.547, -18.096},
	{56.903, 95.717, -6.148, -637.987, 6.111, 0.010, 56.489, -18.261},
	{57.859, 95.591, -12.636, -648.772, 6.112, 0.010, 57.431, -18.424},
	{58.813, 95.398, -19.228, -659.219, 6.114, 0.010, 58.371, -18.585},
	{59.764, 95.139, -25.921, -669.271, 6.116, 0.010, 59.309, -18.745},
	{60.712, 94.812, -32.710, -678.873, 6.118, 0.010, 60.244, -18.902},
	{61.656, 94.416, -39.589, -687.968, 6.120, 0.010, 61.176, -19.057},
	{62.596, 93.951, -46.554, -696.502, 6.122, 0.010, 62.103, -19.209},
	{63.530, 93.415, -53.598, -704.423, 6.125, 0.010, 63.025, -19.357},
	{64.458, 92.807, -60.715, -711.681, 6.127, 0.010, 63.942, -19.503},
	{65.379, 92.128, -67.898, -718.229, 6.130, 0.010, 64.852, -19.645},
	{66.293, 91.377, -75.138, -724.024, 6.133, 0.010, 65.755, -19.783},
	{67.199, 90.554, -82.281, -714.333, 6.136, 0.010, 66.651, -19.917},
	{68.096, 89.690, -86.411, -412.987, 6.139, 0.010, 67.538, -20.047},
	{68.984, 88.814, -87.640, -122.857, 6.142, 0.010, 68.417, -20.174},
	{69.863, 87.925, -88.854, -121.437, 6.146, 0.010, 69.288, -20.296},
	{70.733, 87.025, -90.051, -119.747, 6.149, 0.010, 70.150, -20.414},
	{71.594, 86.112, -91.229, -117.799, 6.152, 0.010, 71.004, -20.528},
	{72.446, 85.189, -92.385, -115.602, 6.156, 0.010, 71.849, -20.637},
	{73.289, 84.253, -93.517, -113.169, 6.159, 0.010, 72.685, -20.743},
	{74.122, 83.307, -94.622, -110.512, 6.163, 0.010, 73.511, -20.844},
	{74.945, 82.350, -95.699, -107.643, 6.167, 0.010, 74.329, -20.942},
	{75.759, 81.383, -96.744, -104.577, 6.170, 0.010, 75.138, -21.035},
	{76.563, 80.405, -97.758, -101.328, 6.174, 0.010, 75.937, -21.124},
	{77.357, 79.418, -98.737, -97.911, 6.177, 0.010, 76.726, -21.209},
	{78.142, 78.421, -99.680, -94.340, 6.181, 0.010, 77.506, -21.291},
	{78.916, 77.415, -100.587, -90.631, 6.185, 0.010, 78.277, -21.368},
	{79.680, 76.401, -101.455, -86.801, 6.188, 0.010, 79.037, -21.442},
	{80.434, 75.378, -102.283, -82.866, 6.192, 0.010, 79.788, -21.512},
	{81.177, 74.347, -103.072, -78.841, 6.195, 0.010, 80.528, -21.579},
	{81.910, 73.309, -103.819, -74.743, 6.199, 0.010, 81.258, -21.642},
	{82.633, 72.264, -104.525, -70.588, 6.202, 0.010, 81.979, -21.701},
	{83.345, 71.212, -105.189, -66.392, 6.206, 0.010, 82.688, -21.757},
	{84.046, 70.154, -105.811, -62.170, 6.209, 0.010, 83.388, -21.811},
	{84.737, 69.090, -106.390, -57.936, 6.212, 0.010, 84.077, -21.860},
	{85.418, 68.020, -106.927, -53.706, 6.216, 0.010, 84.756, -21.907},
	{86.087, 66.946, -107.422, -49.493, 6.219, 0.010, 85.424, -21.951},
	{86.746, 65.867, -107.875, -45.309, 6.222, 0.010, 86.081, -21.993},
	{87.393, 64.785, -108.287, -41.168, 6.225, 0.010, 86.728, -22.031},
	{88.030, 63.698, -108.657, -37.081, 6.228, 0.010, 87.364, -22.067},
	{88.657, 62.608, -108.988, -33.058, 6.231, 0.010, 87.989, -22.101},
	{89.272, 61.515, -109.279, -29.110, 6.234, 0.010, 88.603, -22.132},
	{89.876, 60.420, -109.532, -25.245, 6.236, 0.010, 89.207, -22.161},
	{90.469, 59.323, -109.746, -21.472, 6.239, 0.010, 89.799, -22.188},
	{91.051, 58.223, -109.924, -17.798, 6.242, 0.010, 90.381, -22.213},
	{91.623, 57.123, -110.067, -14.231, 6.244, 0.010, 90.952, -22.236},
	{92.183, 56.021, -110.174, -10.775, 6.247, 0.010, 91.512, -22.257},
	{92.732, 54.918, -110.249, -7.436, 6.249, 0.010, 92.060, -22.277},
	{93.270, 53.815, -110.291, -4.219, 6.251, 0.010, 92.598, -22.295},
	{93.797, 52.712, -110.302, -1.128, 6.253, 0.010, 93.125, -22.311},
	{94.313, 51.610, -110.284, 1.835, 6.255, 0.010, 93.641, -22.326},
	{94.818, 50.507, -110.237, 4.667, 6.257, 0.010, 94.146, -22.340},
	{95.312, 49.406, -110.164, 7.365, 6.259, 0.010, 94.640, -22.352},
	{95.796, 48.305, -110.064, 9.928, 6.261, 0.010, 95.123, -22.363},
	{96.268, 47.206, -109.941, 12.354, 6.262, 0.010, 95.595, -22.373},
	{96.729, 46.108, -109.794, 14.643, 6.264, 0.010, 96.056, -22.383},
	{97.179, 45.011, -109.626, 16.795, 6.266, 0.010, 96.506, -22.391},
	{97.618, 43.917, -109.438, 18.809, 6.267, 0.010, 96.945, -22.398},
	{98.046, 42.825, -109.231, 20.684, 6.268, 0.010, 97.373, -22.405},
	{98.464, 41.735, -109.007, 22.423, 6.270, 0.010, 97.790, -22.411},
	{98.870, 40.647, -108.767, 24.025, 6.271, 0.010, 98.197, -22.416},
	{99.266, 39.562, -108.512, 25.492, 6.272, 0.010, 98.592, -22.421},
	{99.650, 38.479, -108.244, 26.823, 6.273, 0.010, 98.977, -22.425},
	{100.024, 37.400, -107.964, 28.022, 6.274, 0.010, 99.351, -22.429},
	{100.388, 36.323, -107.673, 29.088, 6.275, 0.010, 99.714, -22.432},
	{100.740, 35.249, -107.372, 30.023, 6.276, 0.010, 100.067, -22.435},
	{101.082, 34.179, -107.064, 30.830, 6.276, 0.010, 100.409, -22.437},
	{101.413, 33.111, -106.749, 31.510, 6.277, 0.010, 100.740, -22.439},
	{101.734, 32.047, -106.428, 32.064, 6.278, 0.010, 101.060, -22.441},
	{102.043, 30.986, -106.103, 32.495, 6.278, 0.010, 101.370, -22.443},
	{102.343, 29.928, -105.775, 32.804, 6.279, 0.010, 101.669, -22.444},
	{102.631, 28.874, -105.445, 32.995, 6.280, 0.010, 101.958, -22.445},
	{102.910, 27.822, -105.115, 33.069, 6.280, 0.010, 102.236, -22.446},
	{103.177, 26.775, -104.784, 33.029, 6.280, 0.010, 102.504, -22.447},
	{103.435, 25.730, -104.456, 32.877, 6.281, 0.010, 102.761, -22.447},
	{103.682, 24.689, -104.130, 32.617, 6.281, 0.010, 103.008, -22.448},
	{103.918, 23.651, -103.807, 32.250, 6.281, 0.010, 103.245, -22.448},
	{104.144, 22.616, -103.489, 31.779, 6.282, 0.010, 103.471, -22.449},
	{104.360, 21.584, -103.177, 31.209, 6.282, 0.010, 103.687, -22.449},
	{104.566, 20.555, -102.872, 30.541, 6.282, 0.010, 103.892, -22.449},
	{104.761, 19.530, -102.574, 29.779, 6.282, 0.010, 104.088, -22.449},
	{104.946, 18.507, -102.285, 28.927, 6.282, 0.010, 104.273, -22.450},
	{105.121, 17.487, -102.005, 27.987, 6.283, 0.010, 104.447, -22.450},
	{105.286, 16.469, -101.735, 26.964, 6.283, 0.010, 104.612, -22.450},
	{105.440, 15.455, -101.477, 25.861, 6.283, 0.010, 104.767, -22.450},
	{105.585, 14.442, -101.230, 24.682, 6.283, 0.010, 104.911, -22.450},
	{105.719, 13.432, -100.995, 23.431, 6.283, 0.010, 105.045, -22.450},
	{105.843, 12.425, -100.774, 22.112, 6.283, 0.010, 105.170, -22.450},
	{105.957, 11.419, -100.567, 20.729, 6.283, 0.010, 105.284, -22.450},
	{106.061, 10.415, -100.374, 19.287, 6.283, 0.010, 105.388, -22.450},
	{106.156, 9.413, -100.196, 17.790, 6.283, 0.010, 105.482, -22.450},
	{106.240, 8.414, -99.893, 30.351, 6.283, 0.010, 105.566, -22.450},
	{106.314, 7.447, -96.680, 321.293, 6.283, 0.010, 105.641, -22.450},
	{106.380, 6.540, -90.704, 597.539, 6.283, 0.010, 105.706, -22.450},
	{106.437, 5.693, -84.753, 595.191, 6.283, 0.010, 105.763, -22.450},
	{106.486, 4.905, -78.821, 593.114, 6.283, 0.010, 105.812, -22.450},
	{106.527, 4.176, -72.908, 591.298, 6.283, 0.010, 105.854, -22.450},
	{106.562, 3.506, -67.011, 589.729, 6.283, 0.010, 105.889, -22.450},
	{106.591, 2.894, -61.127, 588.393, 6.283, 0.010, 105.918, -22.450},
	{106.615, 2.342, -55.254, 587.273, 6.283, 0.010, 105.941, -22.450},
	{106.633, 1.848, -49.391, 586.352, 6.283, 0.010, 105.960, -22.450},
	{106.647, 1.412, -43.535, 585.612, 6.283, 0.010, 105.974, -22.450},
	{106.658, 1.036, -37.684, 585.034, 6.283, 0.010, 105.984, -22.450},
	{106.665, 0.717, -31.838, 584.600, 6.283, 0.010, 105.991, -22.450},
	{106.669, 0.457, -25.996, 584.288, 6.283, 0.010, 105.996, -22.450},
	{106.672, 0.256, -20.155, 584.079, 6.283, 0.010, 105.999, -22.450},
	{106.673, 0.113, -14.315, 583.951, 6.283, 0.010, 106.000, -22.450},
	{106.673, 0.028, -8.476, 583.886, 6.283, 0.010, 106.000, -22.450},
	{106.673, 0.000, -2.779, 569.788, 6.283, 0.010, 106.000, -22.450}};
};

#endif