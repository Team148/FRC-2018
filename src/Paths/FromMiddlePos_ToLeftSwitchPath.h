#ifndef FromMiddlePos_ToLeftSwitchPath_H
#define FromMiddlePos_ToLeftSwitchPath_H

#include "TrajectoryPath.h"

class FromMiddlePos_ToLeftSwitchPath : TrajectoryPath {

public:
	static TrajectoryPath* GetInstance();
	static FromMiddlePos_ToLeftSwitchPath *m_instance;
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
	FromMiddlePos_ToLeftSwitchPath();
	int num_index = 241;
	double left_wheel[241][8] ={ 
	{0.000, 0.058, 5.843, 584.298, 0.000, 0.010, 0.000, 12.450},
	{0.001, 0.117, 5.843, -0.017, 0.000, 0.010, 0.001, 12.450},
	{0.004, 0.263, 14.606, 876.358, 0.000, 0.010, 0.004, 12.450},
	{0.009, 0.467, 20.447, 584.017, 0.000, 0.010, 0.009, 12.450},
	{0.016, 0.730, 26.283, 583.651, 0.000, 0.010, 0.016, 12.450},
	{0.027, 1.051, 32.114, 583.053, 0.000, 0.010, 0.027, 12.450},
	{0.041, 1.431, 37.935, 582.164, 0.000, 0.010, 0.041, 12.450},
	{0.060, 1.868, 43.745, 580.928, 0.000, 0.010, 0.060, 12.450},
	{0.083, 2.364, 49.537, 579.289, 0.000, 0.010, 0.083, 12.450},
	{0.112, 2.917, 55.309, 577.190, 0.000, 0.010, 0.112, 12.450},
	{0.148, 3.527, 61.055, 574.579, 0.000, 0.010, 0.148, 12.450},
	{0.190, 4.195, 66.769, 571.403, 0.000, 0.010, 0.190, 12.450},
	{0.239, 4.919, 72.445, 567.611, 0.000, 0.010, 0.239, 12.450},
	{0.296, 5.700, 78.077, 563.157, 0.000, 0.010, 0.296, 12.450},
	{0.361, 6.537, 83.657, 557.994, 0.000, 0.010, 0.361, 12.450},
	{0.435, 7.428, 89.178, 552.080, 0.000, 0.010, 0.435, 12.450},
	{0.519, 8.375, 94.631, 545.377, 0.000, 0.010, 0.519, 12.450},
	{0.613, 9.346, 97.119, 248.732, 0.000, 0.010, 0.613, 12.450},
	{0.716, 10.312, 96.656, -46.229, 0.000, 0.010, 0.716, 12.450},
	{0.829, 11.274, 96.149, -50.746, 0.000, 0.010, 0.829, 12.450},
	{0.951, 12.230, 95.597, -55.167, 0.001, 0.010, 0.951, 12.450},
	{1.083, 13.180, 95.002, -59.489, 0.001, 0.010, 1.083, 12.450},
	{1.224, 14.124, 94.365, -63.708, 0.001, 0.010, 1.224, 12.450},
	{1.374, 15.060, 93.687, -67.822, 0.001, 0.010, 1.374, 12.451},
	{1.534, 15.990, 92.969, -71.829, 0.002, 0.010, 1.534, 12.451},
	{1.703, 16.912, 92.211, -75.731, 0.002, 0.010, 1.703, 12.451},
	{1.882, 17.826, 91.416, -79.527, 0.002, 0.010, 1.882, 12.452},
	{2.069, 18.732, 90.584, -83.219, 0.003, 0.010, 2.069, 12.452},
	{2.265, 19.629, 89.716, -86.810, 0.004, 0.010, 2.265, 12.453},
	{2.471, 20.518, 88.813, -90.305, 0.004, 0.010, 2.471, 12.453},
	{2.684, 21.396, 87.876, -93.707, 0.005, 0.010, 2.684, 12.454},
	{2.907, 22.265, 86.906, -97.022, 0.006, 0.010, 2.907, 12.456},
	{3.138, 23.124, 85.903, -100.256, 0.007, 0.010, 3.138, 12.457},
	{3.378, 23.973, 84.869, -103.416, 0.008, 0.010, 3.378, 12.459},
	{3.626, 24.811, 83.804, -106.505, 0.009, 0.010, 3.626, 12.461},
	{3.883, 25.638, 82.708, -109.534, 0.010, 0.010, 3.883, 12.463},
	{4.147, 26.454, 81.583, -112.508, 0.012, 0.010, 4.147, 12.466},
	{4.420, 27.258, 80.429, -115.429, 0.014, 0.010, 4.420, 12.470},
	{4.700, 28.051, 79.246, -118.308, 0.015, 0.010, 4.700, 12.474},
	{4.989, 28.831, 78.035, -121.144, 0.017, 0.010, 4.988, 12.479},
	{5.285, 29.599, 76.795, -123.943, 0.020, 0.010, 5.284, 12.484},
	{5.588, 30.354, 75.528, -126.707, 0.022, 0.010, 5.588, 12.490},
	{5.899, 31.097, 74.234, -129.432, 0.024, 0.010, 5.899, 12.498},
	{6.217, 31.826, 72.913, -132.117, 0.027, 0.010, 6.217, 12.506},
	{6.543, 32.542, 71.565, -134.757, 0.030, 0.010, 6.542, 12.515},
	{6.875, 33.243, 70.192, -137.340, 0.033, 0.010, 6.874, 12.526},
	{7.214, 33.931, 68.793, -139.853, 0.037, 0.010, 7.214, 12.538},
	{7.561, 34.605, 67.370, -142.280, 0.041, 0.010, 7.559, 12.551},
	{7.913, 35.264, 65.924, -144.597, 0.045, 0.010, 7.912, 12.566},
	{8.272, 35.909, 64.457, -146.774, 0.049, 0.010, 8.270, 12.583},
	{8.638, 36.539, 62.969, -148.774, 0.053, 0.010, 8.635, 12.601},
	{9.009, 37.153, 61.463, -150.561, 0.058, 0.010, 9.006, 12.622},
	{9.387, 37.753, 59.942, -152.073, 0.063, 0.010, 9.383, 12.645},
	{9.770, 38.337, 58.410, -153.256, 0.069, 0.010, 9.766, 12.670},
	{10.159, 38.905, 56.869, -154.041, 0.075, 0.010, 10.154, 12.698},
	{10.554, 39.459, 55.326, -154.341, 0.081, 0.010, 10.547, 12.729},
	{10.954, 39.997, 53.785, -154.067, 0.088, 0.010, 10.946, 12.763},
	{11.359, 40.519, 52.254, -153.112, 0.095, 0.010, 11.349, 12.800},
	{11.769, 41.026, 50.741, -151.356, 0.102, 0.010, 11.757, 12.840},
	{12.184, 41.519, 49.254, -148.671, 0.110, 0.010, 12.170, 12.884},
	{12.604, 41.997, 47.805, -144.909, 0.118, 0.010, 12.587, 12.931},
	{13.029, 42.461, 46.406, -139.913, 0.126, 0.010, 13.009, 12.983},
	{13.458, 42.912, 45.071, -133.514, 0.135, 0.010, 13.434, 13.039},
	{13.892, 43.350, 43.815, -125.524, 0.145, 0.010, 13.864, 13.099},
	{14.329, 43.777, 42.658, -115.768, 0.155, 0.010, 14.297, 13.165},
	{14.771, 44.193, 41.617, -104.034, 0.165, 0.010, 14.733, 13.235},
	{15.217, 44.600, 40.716, -90.144, 0.176, 0.010, 15.172, 13.311},
	{15.667, 45.000, 39.977, -73.891, 0.187, 0.010, 15.615, 13.392},
	{16.121, 45.394, 39.426, -55.112, 0.199, 0.010, 16.060, 13.479},
	{16.579, 45.785, 39.090, -33.635, 0.211, 0.010, 16.509, 13.572},
	{17.041, 46.175, 38.996, -9.340, 0.224, 0.010, 16.960, 13.672},
	{17.506, 46.567, 39.175, 17.868, 0.237, 0.010, 17.413, 13.779},
	{17.976, 46.963, 39.655, 48.025, 0.251, 0.010, 17.869, 13.892},
	{18.450, 47.368, 40.466, 81.098, 0.265, 0.010, 18.327, 14.013},
	{18.928, 47.784, 41.636, 116.991, 0.280, 0.010, 18.787, 14.142},
	{19.410, 48.216, 43.191, 155.502, 0.295, 0.010, 19.249, 14.279},
	{19.896, 48.668, 45.154, 196.342, 0.311, 0.010, 19.714, 14.424},
	{20.388, 49.143, 47.546, 239.115, 0.327, 0.010, 20.180, 14.578},
	{20.884, 49.647, 50.379, 283.311, 0.343, 0.010, 20.649, 14.741},
	{21.386, 50.183, 53.662, 328.316, 0.360, 0.010, 21.120, 14.914},
	{21.894, 50.757, 57.396, 373.416, 0.377, 0.010, 21.594, 15.096},
	{22.407, 51.373, 61.574, 417.813, 0.394, 0.010, 22.070, 15.290},
	{22.928, 52.035, 66.181, 460.644, 0.412, 0.010, 22.549, 15.494},
	{23.455, 52.747, 71.191, 501.011, 0.430, 0.010, 23.030, 15.709},
	{23.990, 53.513, 76.571, 538.016, 0.448, 0.010, 23.514, 15.937},
	{24.534, 54.335, 82.279, 570.796, 0.466, 0.010, 24.002, 16.176},
	{25.086, 55.218, 88.264, 598.564, 0.484, 0.010, 24.493, 16.429},
	{25.648, 56.163, 94.471, 620.650, 0.503, 0.010, 24.988, 16.695},
	{26.219, 57.171, 100.836, 636.531, 0.521, 0.010, 25.486, 16.975},
	{26.802, 58.244, 107.295, 645.864, 0.539, 0.010, 25.989, 17.269},
	{27.396, 59.382, 113.780, 648.504, 0.557, 0.010, 26.495, 17.579},
	{28.001, 60.584, 120.225, 644.511, 0.575, 0.010, 27.007, 17.904},
	{28.620, 61.850, 126.567, 634.150, 0.593, 0.010, 27.523, 18.245},
	{29.252, 63.177, 132.745, 617.879, 0.610, 0.010, 28.043, 18.603},
	{29.897, 64.564, 138.709, 596.319, 0.628, 0.010, 28.569, 18.977},
	{30.557, 66.008, 144.411, 570.228, 0.644, 0.010, 29.100, 19.369},
	{31.232, 67.506, 149.815, 540.464, 0.661, 0.010, 29.637, 19.779},
	{31.923, 69.055, 154.895, 507.945, 0.677, 0.010, 30.178, 20.207},
	{32.629, 70.652, 159.631, 473.607, 0.692, 0.010, 30.726, 20.654},
	{33.352, 72.292, 164.015, 438.376, 0.707, 0.010, 31.279, 21.120},
	{34.092, 73.972, 168.046, 403.130, 0.721, 0.010, 31.838, 21.604},
	{34.849, 75.690, 171.733, 368.679, 0.735, 0.010, 32.402, 22.108},
	{35.623, 77.441, 175.090, 335.736, 0.748, 0.010, 32.973, 22.632},
	{36.416, 79.222, 178.140, 304.932, 0.761, 0.010, 33.550, 23.174},
	{37.226, 81.006, 178.423, 28.311, 0.773, 0.010, 34.134, 23.737},
	{38.053, 82.764, 175.820, -260.264, 0.784, 0.010, 34.723, 24.318},
	{38.898, 84.492, 172.760, -306.042, 0.795, 0.010, 35.318, 24.918},
	{39.760, 86.185, 169.279, -348.098, 0.804, 0.010, 35.918, 25.536},
	{40.639, 87.839, 165.417, -386.128, 0.813, 0.010, 36.525, 26.171},
	{41.533, 89.451, 161.217, -419.992, 0.822, 0.010, 37.136, 26.824},
	{42.443, 91.018, 156.721, -449.679, 0.829, 0.010, 37.754, 27.493},
	{43.369, 92.538, 151.968, -475.300, 0.836, 0.010, 38.376, 28.177},
	{44.309, 94.008, 146.997, -497.056, 0.842, 0.010, 39.004, 28.877},
	{45.263, 95.426, 141.845, -515.223, 0.847, 0.010, 39.638, 29.591},
	{46.231, 96.792, 136.543, -530.133, 0.852, 0.010, 40.277, 30.317},
	{47.212, 98.103, 131.122, -542.162, 0.855, 0.010, 40.922, 31.057},
	{48.205, 99.359, 125.605, -551.712, 0.858, 0.010, 41.573, 31.807},
	{49.211, 100.559, 120.013, -559.209, 0.860, 0.010, 42.230, 32.569},
	{50.228, 101.703, 114.362, -565.090, 0.861, 0.010, 42.893, 33.340},
	{51.256, 102.789, 108.578, -578.402, 0.862, 0.010, 43.562, 34.120},
	{52.294, 103.787, 99.800, -877.749, 0.861, 0.010, 44.238, 34.907},
	{53.341, 104.696, 90.956, -884.383, 0.860, 0.010, 44.921, 35.701},
	{54.396, 105.546, 84.966, -599.030, 0.858, 0.010, 45.610, 36.500},
	{55.460, 106.335, 78.928, -603.770, 0.855, 0.010, 46.307, 37.304},
	{56.530, 107.063, 72.832, -609.690, 0.851, 0.010, 47.011, 38.111},
	{57.608, 107.730, 66.659, -617.238, 0.847, 0.010, 47.722, 38.919},
	{58.691, 108.334, 60.391, -626.853, 0.842, 0.010, 48.442, 39.729},
	{59.780, 108.874, 54.001, -638.956, 0.836, 0.010, 49.169, 40.539},
	{60.873, 109.349, 47.462, -653.950, 0.829, 0.010, 49.905, 41.348},
	{61.971, 109.756, 40.739, -672.212, 0.822, 0.010, 50.650, 42.155},
	{63.072, 110.094, 33.799, -694.070, 0.813, 0.010, 51.403, 42.958},
	{64.175, 110.360, 26.601, -719.795, 0.804, 0.010, 52.165, 43.756},
	{65.281, 110.551, 19.105, -749.595, 0.794, 0.010, 52.936, 44.548},
	{66.387, 110.664, 11.269, -783.565, 0.784, 0.010, 53.715, 45.334},
	{67.494, 110.694, 3.052, -821.702, 0.773, 0.010, 54.503, 46.111},
	{68.601, 110.638, -5.586, -863.855, 0.761, 0.010, 55.300, 46.879},
	{69.706, 110.493, -14.583, -899.653, 0.748, 0.010, 56.105, 47.635},
	{70.808, 110.286, -20.619, -603.580, 0.735, 0.010, 56.919, 48.380},
	{71.909, 110.050, -23.677, -305.779, 0.721, 0.010, 57.740, 49.113},
	{73.007, 109.779, -27.043, -336.644, 0.707, 0.010, 58.570, 49.831},
	{74.101, 109.472, -30.739, -369.623, 0.692, 0.010, 59.408, 50.536},
	{75.193, 109.124, -34.780, -404.098, 0.676, 0.010, 60.253, 51.226},
	{76.280, 108.732, -39.174, -439.342, 0.660, 0.010, 61.107, 51.899},
	{77.363, 108.293, -43.919, -474.544, 0.644, 0.010, 61.968, 52.557},
	{78.441, 107.803, -49.007, -508.830, 0.627, 0.010, 62.835, 53.196},
	{79.514, 107.259, -54.420, -541.271, 0.610, 0.010, 63.709, 53.818},
	{80.580, 106.658, -60.129, -570.929, 0.592, 0.010, 64.589, 54.422},
	{81.640, 105.997, -66.098, -596.893, 0.575, 0.010, 65.473, 55.006},
	{82.693, 105.274, -72.281, -618.302, 0.557, 0.010, 66.362, 55.570},
	{83.738, 104.487, -78.625, -634.405, 0.539, 0.010, 67.254, 56.114},
	{84.774, 103.637, -85.071, -644.583, 0.520, 0.010, 68.148, 56.638},
	{85.801, 102.721, -91.555, -648.385, 0.502, 0.010, 69.044, 57.140},
	{86.819, 101.741, -98.011, -645.554, 0.484, 0.010, 69.940, 57.622},
	{87.826, 100.697, -104.371, -636.032, 0.465, 0.010, 70.836, 58.082},
	{88.822, 99.592, -110.571, -619.972, 0.447, 0.010, 71.730, 58.521},
	{89.806, 98.426, -116.548, -597.722, 0.429, 0.010, 72.621, 58.938},
	{90.778, 97.204, -122.246, -569.809, 0.411, 0.010, 73.509, 59.335},
	{91.737, 95.928, -127.615, -536.907, 0.394, 0.010, 74.391, 59.711},
	{92.683, 94.601, -132.613, -499.805, 0.376, 0.010, 75.268, 60.066},
	{93.616, 93.229, -137.207, -459.367, 0.359, 0.010, 76.138, 60.401},
	{94.534, 91.816, -141.372, -416.492, 0.343, 0.010, 77.000, 60.717},
	{95.437, 90.365, -145.092, -372.076, 0.326, 0.010, 77.854, 61.014},
	{96.326, 88.881, -148.362, -326.979, 0.310, 0.010, 78.698, 61.292},
	{97.200, 87.369, -151.182, -282.001, 0.295, 0.010, 79.532, 61.552},
	{98.058, 85.834, -153.561, -237.849, 0.280, 0.010, 80.355, 61.795},
	{98.901, 84.279, -155.512, -195.135, 0.265, 0.010, 81.167, 62.022},
	{99.728, 82.708, -157.056, -154.366, 0.251, 0.010, 81.967, 62.233},
	{100.539, 81.126, -158.215, -115.932, 0.237, 0.010, 82.754, 62.429},
	{101.335, 79.536, -159.016, -80.126, 0.224, 0.010, 83.528, 62.610},
	{102.114, 77.941, -159.488, -47.141, 0.211, 0.010, 84.289, 62.778},
	{102.877, 76.344, -159.658, -17.073, 0.199, 0.010, 85.037, 62.934},
	{103.625, 74.749, -159.558, 10.045, 0.187, 0.010, 85.771, 63.077},
	{104.357, 73.157, -159.215, 34.259, 0.176, 0.010, 86.490, 63.209},
	{105.072, 71.570, -158.659, 55.649, 0.165, 0.010, 87.195, 63.330},
	{105.772, 69.991, -157.915, 74.358, 0.154, 0.010, 87.886, 63.441},
	{106.456, 68.421, -157.010, 90.539, 0.145, 0.010, 88.563, 63.543},
	{107.125, 66.861, -155.966, 104.365, 0.135, 0.010, 89.225, 63.636},
	{107.778, 65.313, -154.806, 116.037, 0.126, 0.010, 89.873, 63.721},
	{108.416, 63.777, -153.548, 125.744, 0.117, 0.010, 90.506, 63.799},
	{109.038, 62.255, -152.212, 133.684, 0.109, 0.010, 91.124, 63.869},
	{109.646, 60.747, -150.811, 140.045, 0.102, 0.010, 91.728, 63.933},
	{110.238, 59.254, -149.361, 145.003, 0.094, 0.010, 92.318, 63.991},
	{110.816, 57.775, -147.874, 148.731, 0.087, 0.010, 92.893, 64.043},
	{111.379, 56.311, -146.360, 151.393, 0.081, 0.010, 93.455, 64.091},
	{111.928, 54.863, -144.829, 153.124, 0.075, 0.010, 94.002, 64.133},
	{112.462, 53.430, -143.288, 154.058, 0.069, 0.010, 94.535, 64.171},
	{112.982, 52.013, -141.745, 154.319, 0.063, 0.010, 95.054, 64.206},
	{113.488, 50.611, -140.205, 154.001, 0.058, 0.010, 95.559, 64.236},
	{113.981, 49.224, -138.673, 153.212, 0.053, 0.010, 96.050, 64.264},
	{114.459, 47.852, -137.153, 152.014, 0.049, 0.010, 96.528, 64.288},
	{114.924, 46.496, -135.648, 150.497, 0.044, 0.010, 96.993, 64.310},
	{115.376, 45.154, -134.161, 148.706, 0.040, 0.010, 97.444, 64.329},
	{115.814, 43.827, -132.694, 146.700, 0.037, 0.010, 97.882, 64.346},
	{116.239, 42.515, -131.248, 144.518, 0.033, 0.010, 98.306, 64.361},
	{116.651, 41.217, -129.826, 142.202, 0.030, 0.010, 98.718, 64.374},
	{117.051, 39.932, -128.429, 139.772, 0.027, 0.010, 99.118, 64.385},
	{117.437, 38.662, -127.056, 137.257, 0.024, 0.010, 99.504, 64.395},
	{117.811, 37.405, -125.709, 134.672, 0.022, 0.010, 99.878, 64.404},
	{118.173, 36.161, -124.389, 132.034, 0.019, 0.010, 100.240, 64.411},
	{118.522, 34.930, -123.096, 129.348, 0.017, 0.010, 100.589, 64.418},
	{118.859, 33.712, -121.829, 126.619, 0.015, 0.010, 100.926, 64.423},
	{119.184, 32.506, -120.591, 123.859, 0.014, 0.010, 101.251, 64.428},
	{119.498, 31.312, -119.380, 121.057, 0.012, 0.010, 101.564, 64.432},
	{119.799, 30.130, -118.198, 118.220, 0.010, 0.010, 101.865, 64.435},
	{120.088, 28.959, -117.045, 115.342, 0.009, 0.010, 102.155, 64.438},
	{120.366, 27.800, -115.920, 112.417, 0.008, 0.010, 102.433, 64.440},
	{120.633, 26.652, -114.826, 109.445, 0.007, 0.010, 102.699, 64.442},
	{120.888, 25.514, -113.762, 106.414, 0.006, 0.010, 102.955, 64.444},
	{121.132, 24.387, -112.729, 103.322, 0.005, 0.010, 103.198, 64.445},
	{121.365, 23.270, -111.727, 100.161, 0.004, 0.010, 103.431, 64.446},
	{121.586, 22.162, -110.758, 96.924, 0.004, 0.010, 103.653, 64.447},
	{121.797, 21.064, -109.822, 93.608, 0.003, 0.010, 103.863, 64.448},
	{121.997, 19.975, -108.920, 90.202, 0.002, 0.010, 104.063, 64.448},
	{122.186, 18.894, -108.053, 86.705, 0.002, 0.010, 104.252, 64.449},
	{122.364, 17.822, -107.221, 83.111, 0.002, 0.010, 104.430, 64.449},
	{122.531, 16.758, -106.427, 79.416, 0.001, 0.010, 104.598, 64.449},
	{122.688, 15.701, -105.671, 75.617, 0.001, 0.010, 104.755, 64.450},
	{122.835, 14.652, -104.954, 71.713, 0.001, 0.010, 104.901, 64.450},
	{122.971, 13.609, -104.277, 67.702, 0.001, 0.010, 105.037, 64.450},
	{123.097, 12.572, -103.641, 63.585, 0.000, 0.010, 105.163, 64.450},
	{123.212, 11.542, -103.048, 59.362, 0.000, 0.010, 105.279, 64.450},
	{123.317, 10.517, -102.497, 55.038, 0.000, 0.010, 105.384, 64.450},
	{123.412, 9.497, -101.991, 50.614, 0.000, 0.010, 105.479, 64.450},
	{123.497, 8.483, -101.443, 54.756, 0.000, 0.010, 105.564, 64.450},
	{123.572, 7.503, -98.003, 344.038, 0.000, 0.010, 105.639, 64.450},
	{123.638, 6.585, -91.773, 623.015, 0.000, 0.010, 105.704, 64.450},
	{123.695, 5.729, -85.610, 616.336, 0.000, 0.010, 105.762, 64.450},
	{123.745, 4.934, -79.505, 610.444, 0.000, 0.010, 105.811, 64.450},
	{123.787, 4.199, -73.452, 605.303, 0.000, 0.010, 105.853, 64.450},
	{123.822, 3.525, -67.443, 600.868, 0.000, 0.010, 105.888, 64.450},
	{123.851, 2.910, -61.472, 597.095, 0.000, 0.010, 105.917, 64.450},
	{123.874, 2.355, -55.533, 593.936, 0.000, 0.010, 105.941, 64.450},
	{123.893, 1.858, -49.620, 591.340, 0.000, 0.010, 105.960, 64.450},
	{123.907, 1.421, -43.727, 589.256, 0.000, 0.010, 105.974, 64.450},
	{123.918, 1.043, -37.851, 587.628, 0.000, 0.010, 105.984, 64.450},
	{123.925, 0.723, -31.987, 586.403, 0.000, 0.010, 105.991, 64.450},
	{123.930, 0.461, -26.132, 585.523, 0.000, 0.010, 105.996, 64.450},
	{123.932, 0.259, -20.282, 584.932, 0.000, 0.010, 105.999, 64.450},
	{123.933, 0.114, -14.437, 584.573, 0.000, 0.010, 106.000, 64.450},
	{123.934, 0.028, -8.593, 584.386, 0.000, 0.010, 106.000, 64.450},
	{123.934, 0.000, -2.836, 575.716, 0.000, 0.010, 106.000, 64.450}};
	double right_wheel[241][8] ={ 
	{0.000, 0.058, 5.843, 584.298, 0.000, 0.010, 0.000, -12.450},
	{0.001, 0.117, 5.843, 0.017, 0.000, 0.010, 0.001, -12.450},
	{0.004, 0.263, 14.609, 876.537, 0.000, 0.010, 0.004, -12.450},
	{0.009, 0.467, 20.454, 584.579, 0.000, 0.010, 0.009, -12.450},
	{0.016, 0.731, 26.304, 584.945, 0.000, 0.010, 0.016, -12.450},
	{0.027, 1.052, 32.159, 585.543, 0.000, 0.010, 0.027, -12.450},
	{0.041, 1.432, 38.024, 586.432, 0.000, 0.010, 0.041, -12.450},
	{0.060, 1.871, 43.900, 587.668, 0.000, 0.010, 0.060, -12.450},
	{0.083, 2.369, 49.793, 589.308, 0.000, 0.010, 0.083, -12.450},
	{0.113, 2.926, 55.707, 591.406, 0.000, 0.010, 0.113, -12.450},
	{0.148, 3.543, 61.648, 594.017, 0.000, 0.010, 0.148, -12.450},
	{0.190, 4.219, 67.619, 597.193, 0.000, 0.010, 0.190, -12.450},
	{0.240, 4.955, 73.629, 600.985, 0.000, 0.010, 0.240, -12.450},
	{0.297, 5.752, 79.684, 605.440, 0.000, 0.010, 0.297, -12.450},
	{0.363, 6.610, 85.790, 610.602, 0.000, 0.010, 0.363, -12.450},
	{0.439, 7.530, 91.955, 616.516, 0.000, 0.010, 0.439, -12.450},
	{0.524, 8.511, 98.187, 623.219, 0.000, 0.010, 0.524, -12.450},
	{0.619, 9.527, 101.543, 335.566, 0.000, 0.010, 0.619, -12.450},
	{0.725, 10.547, 102.005, 46.229, 0.000, 0.010, 0.725, -12.450},
	{0.840, 11.572, 102.512, 50.746, 0.000, 0.010, 0.840, -12.450},
	{0.966, 12.603, 103.064, 55.167, 0.001, 0.010, 0.966, -12.450},
	{1.103, 13.639, 103.659, 59.489, 0.001, 0.010, 1.103, -12.450},
	{1.249, 14.682, 104.296, 63.708, 0.001, 0.010, 1.249, -12.450},
	{1.407, 15.732, 104.974, 67.822, 0.001, 0.010, 1.407, -12.449},
	{1.575, 16.789, 105.693, 71.830, 0.002, 0.010, 1.575, -12.449},
	{1.753, 17.853, 106.450, 75.731, 0.002, 0.010, 1.753, -12.449},
	{1.942, 18.926, 107.245, 79.526, 0.002, 0.010, 1.942, -12.448},
	{2.143, 20.007, 108.077, 83.218, 0.003, 0.010, 2.143, -12.448},
	{2.354, 21.096, 108.945, 86.810, 0.004, 0.010, 2.354, -12.447},
	{2.575, 22.195, 109.849, 90.304, 0.004, 0.010, 2.575, -12.446},
	{2.808, 23.302, 110.786, 93.706, 0.005, 0.010, 2.808, -12.445},
	{3.053, 24.420, 111.756, 97.022, 0.006, 0.010, 3.053, -12.444},
	{3.308, 25.548, 112.758, 100.256, 0.007, 0.010, 3.308, -12.442},
	{3.575, 26.686, 113.792, 103.414, 0.008, 0.010, 3.575, -12.440},
	{3.853, 27.834, 114.858, 106.505, 0.009, 0.010, 3.853, -12.438},
	{4.143, 28.994, 115.953, 109.533, 0.010, 0.010, 4.143, -12.435},
	{4.445, 30.164, 117.078, 112.504, 0.012, 0.010, 4.445, -12.432},
	{4.758, 31.347, 118.232, 115.428, 0.014, 0.010, 4.758, -12.428},
	{5.084, 32.541, 119.415, 118.304, 0.015, 0.010, 5.084, -12.423},
	{5.421, 33.747, 120.627, 121.141, 0.017, 0.010, 5.421, -12.418},
	{5.771, 34.966, 121.866, 123.940, 0.020, 0.010, 5.771, -12.411},
	{6.133, 36.197, 123.133, 126.701, 0.022, 0.010, 6.133, -12.404},
	{6.507, 37.441, 124.427, 129.426, 0.024, 0.010, 6.507, -12.395},
	{6.894, 38.699, 125.748, 132.112, 0.027, 0.010, 6.894, -12.385},
	{7.294, 39.970, 127.096, 134.750, 0.030, 0.010, 7.293, -12.373},
	{7.707, 41.255, 128.469, 137.332, 0.033, 0.010, 7.706, -12.360},
	{8.132, 42.553, 129.868, 139.845, 0.037, 0.010, 8.131, -12.345},
	{8.571, 43.866, 131.290, 142.271, 0.041, 0.010, 8.569, -12.328},
	{9.023, 45.193, 132.736, 144.585, 0.045, 0.010, 9.021, -12.309},
	{9.488, 46.536, 134.204, 146.762, 0.049, 0.010, 9.486, -12.288},
	{9.967, 47.892, 135.692, 148.764, 0.053, 0.010, 9.964, -12.263},
	{10.460, 49.264, 137.197, 150.543, 0.058, 0.010, 10.456, -12.236},
	{10.966, 50.652, 138.718, 152.057, 0.063, 0.010, 10.961, -12.205},
	{11.487, 52.054, 140.250, 153.241, 0.069, 0.010, 11.481, -12.170},
	{12.021, 53.472, 141.790, 154.019, 0.075, 0.010, 12.014, -12.132},
	{12.570, 54.905, 143.333, 154.320, 0.081, 0.010, 12.562, -12.089},
	{13.134, 56.354, 144.874, 154.043, 0.088, 0.010, 13.123, -12.042},
	{13.712, 57.818, 146.405, 153.085, 0.095, 0.010, 13.699, -11.989},
	{14.305, 59.297, 147.918, 151.329, 0.102, 0.010, 14.289, -11.931},
	{14.913, 60.791, 149.404, 148.641, 0.110, 0.010, 14.893, -11.867},
	{15.536, 62.300, 150.853, 144.877, 0.118, 0.010, 15.512, -11.796},
	{16.174, 63.822, 152.252, 139.878, 0.126, 0.010, 16.146, -11.719},
	{16.828, 65.358, 153.587, 133.474, 0.135, 0.010, 16.794, -11.633},
	{17.497, 66.907, 154.842, 125.491, 0.145, 0.010, 17.456, -11.540},
	{18.182, 68.467, 155.999, 115.722, 0.155, 0.010, 18.133, -11.438},
	{18.882, 70.037, 157.039, 103.997, 0.165, 0.010, 18.825, -11.326},
	{19.598, 71.616, 157.940, 90.094, 0.176, 0.010, 19.531, -11.205},
	{20.330, 73.203, 158.678, 73.851, 0.187, 0.010, 20.251, -11.073},
	{21.078, 74.796, 159.229, 55.063, 0.199, 0.010, 20.985, -10.929},
	{21.842, 76.391, 159.565, 33.592, 0.211, 0.010, 21.733, -10.773},
	{22.622, 77.988, 159.658, 9.293, 0.224, 0.010, 22.494, -10.605},
	{23.418, 79.583, 159.479, -17.912, 0.237, 0.010, 23.269, -10.423},
	{24.229, 81.172, 158.998, -48.062, 0.251, 0.010, 24.056, -10.227},
	{25.057, 82.754, 158.187, -81.138, 0.265, 0.010, 24.857, -10.015},
	{25.900, 84.325, 157.016, -117.020, 0.280, 0.010, 25.669, -9.788},
	{26.759, 85.879, 155.461, -155.526, 0.295, 0.010, 26.492, -9.545},
	{27.633, 87.414, 153.497, -196.361, 0.311, 0.010, 27.327, -9.284},
	{28.522, 88.925, 151.106, -239.123, 0.327, 0.010, 28.171, -9.005},
	{29.427, 90.408, 148.273, -283.310, 0.343, 0.010, 29.025, -8.708},
	{30.345, 91.858, 144.990, -328.303, 0.360, 0.010, 29.887, -8.392},
	{31.278, 93.270, 141.256, -373.392, 0.377, 0.010, 30.757, -8.056},
	{32.224, 94.641, 137.078, -417.774, 0.394, 0.010, 31.634, -7.700},
	{33.184, 95.966, 132.473, -460.592, 0.412, 0.010, 32.517, -7.324},
	{34.156, 97.241, 127.463, -500.945, 0.430, 0.010, 33.405, -6.927},
	{35.141, 98.461, 122.084, -537.937, 0.448, 0.010, 34.296, -6.508},
	{36.137, 99.625, 116.377, -570.703, 0.466, 0.010, 35.190, -6.069},
	{37.144, 100.729, 110.392, -598.461, 0.484, 0.010, 36.086, -5.608},
	{38.162, 101.771, 104.187, -620.536, 0.503, 0.010, 36.982, -5.126},
	{39.190, 102.749, 97.823, -636.409, 0.521, 0.010, 37.878, -4.623},
	{40.226, 103.663, 91.365, -645.736, 0.539, 0.010, 38.772, -4.099},
	{41.271, 104.512, 84.882, -648.371, 0.557, 0.010, 39.664, -3.554},
	{42.324, 105.296, 78.438, -644.377, 0.575, 0.010, 40.553, -2.989},
	{43.385, 106.017, 72.098, -634.019, 0.593, 0.010, 41.437, -2.404},
	{44.451, 106.676, 65.920, -617.750, 0.610, 0.010, 42.317, -1.800},
	{45.524, 107.276, 59.958, -596.195, 0.628, 0.010, 43.190, -1.178},
	{46.602, 107.818, 54.257, -570.113, 0.644, 0.010, 44.058, -0.538},
	{47.685, 108.307, 48.853, -540.359, 0.661, 0.010, 44.918, 0.120},
	{48.773, 108.745, 43.775, -507.849, 0.677, 0.010, 45.771, 0.794},
	{49.864, 109.135, 39.040, -473.525, 0.692, 0.010, 46.617, 1.484},
	{50.959, 109.482, 34.657, -438.308, 0.707, 0.010, 47.454, 2.189},
	{52.057, 109.788, 30.626, -403.075, 0.721, 0.010, 48.284, 2.909},
	{53.157, 110.057, 26.940, -368.633, 0.735, 0.010, 49.105, 3.641},
	{54.260, 110.293, 23.582, -335.710, 0.748, 0.010, 49.918, 4.387},
	{55.365, 110.498, 20.533, -304.912, 0.761, 0.010, 50.723, 5.144},
	{56.472, 110.642, 14.407, -612.594, 0.773, 0.010, 51.520, 5.912},
	{57.579, 110.696, 5.324, -908.325, 0.784, 0.010, 52.308, 6.689},
	{58.685, 110.663, -3.302, -862.562, 0.795, 0.010, 53.087, 7.475},
	{59.791, 110.548, -11.507, -820.524, 0.804, 0.010, 53.858, 8.267},
	{60.894, 110.354, -19.332, -782.507, 0.813, 0.010, 54.619, 9.066},
	{61.995, 110.086, -26.818, -748.658, 0.822, 0.010, 55.372, 9.869},
	{63.093, 109.746, -34.008, -718.981, 0.829, 0.010, 56.116, 10.676},
	{64.186, 109.337, -40.942, -693.371, 0.836, 0.010, 56.852, 11.484},
	{65.275, 108.860, -47.658, -671.623, 0.842, 0.010, 57.579, 12.294},
	{66.358, 108.318, -54.193, -653.463, 0.847, 0.010, 58.299, 13.104},
	{67.435, 107.712, -60.578, -638.558, 0.852, 0.010, 59.010, 13.913},
	{68.505, 107.044, -66.844, -626.534, 0.855, 0.010, 59.714, 14.720},
	{69.568, 106.314, -73.014, -616.988, 0.858, 0.010, 60.410, 15.523},
	{70.624, 105.523, -79.109, -609.493, 0.860, 0.010, 61.099, 16.322},
	{71.670, 104.671, -85.145, -603.614, 0.861, 0.010, 61.782, 17.116},
	{72.708, 103.759, -91.220, -607.501, 0.862, 0.010, 62.457, 17.903},
	{73.736, 102.758, -100.144, -892.451, 0.861, 0.010, 63.127, 18.683},
	{74.752, 101.669, -108.830, -868.622, 0.860, 0.010, 63.790, 19.454},
	{75.757, 100.524, -114.527, -569.675, 0.858, 0.010, 64.446, 20.215},
	{76.751, 99.322, -120.176, -564.935, 0.855, 0.010, 65.097, 20.965},
	{77.731, 98.065, -125.767, -559.012, 0.851, 0.010, 65.742, 21.704},
	{78.699, 96.752, -131.281, -551.461, 0.847, 0.010, 66.381, 22.431},
	{79.653, 95.385, -136.700, -541.844, 0.842, 0.010, 67.014, 23.144},
	{80.592, 93.965, -141.997, -529.736, 0.836, 0.010, 67.642, 23.843},
	{81.517, 92.493, -147.144, -514.734, 0.829, 0.010, 68.265, 24.527},
	{82.427, 90.972, -152.109, -496.467, 0.822, 0.010, 68.882, 25.195},
	{83.321, 89.404, -156.855, -474.602, 0.813, 0.010, 69.493, 25.848},
	{84.199, 87.790, -161.344, -448.862, 0.804, 0.010, 70.099, 26.483},
	{85.060, 86.135, -165.534, -419.056, 0.794, 0.010, 70.700, 27.100},
	{85.905, 84.441, -169.385, -385.069, 0.784, 0.010, 71.295, 27.700},
	{86.732, 82.713, -172.854, -346.920, 0.773, 0.010, 71.884, 28.280},
	{87.541, 80.953, -175.902, -304.751, 0.761, 0.010, 72.467, 28.842},
	{88.333, 79.169, -178.419, -251.734, 0.748, 0.010, 73.044, 29.384},
	{89.107, 77.389, -178.054, 36.489, 0.735, 0.010, 73.614, 29.907},
	{89.863, 75.639, -174.996, 305.797, 0.721, 0.010, 74.179, 30.410},
	{90.603, 73.923, -171.629, 336.674, 0.707, 0.010, 74.738, 30.894},
	{91.325, 72.243, -167.933, 369.668, 0.692, 0.010, 75.290, 31.359},
	{92.031, 70.604, -163.891, 404.153, 0.676, 0.010, 75.838, 31.805},
	{92.721, 69.009, -159.497, 439.410, 0.660, 0.010, 76.379, 32.233},
	{93.396, 67.462, -154.751, 474.629, 0.644, 0.010, 76.915, 32.642},
	{94.055, 65.965, -149.662, 508.925, 0.627, 0.010, 77.446, 33.034},
	{94.701, 64.523, -144.248, 541.377, 0.610, 0.010, 77.972, 33.408},
	{95.332, 63.137, -138.537, 571.046, 0.592, 0.010, 78.493, 33.765},
	{95.950, 61.812, -132.567, 597.015, 0.575, 0.010, 79.008, 34.106},
	{96.556, 60.548, -126.383, 618.431, 0.557, 0.010, 79.519, 34.430},
	{97.149, 59.347, -120.037, 634.537, 0.539, 0.010, 80.026, 34.739},
	{97.731, 58.212, -113.590, 644.716, 0.520, 0.010, 80.529, 35.034},
	{98.303, 57.140, -107.105, 648.518, 0.502, 0.010, 81.027, 35.313},
	{98.864, 56.134, -100.648, 645.682, 0.484, 0.010, 81.521, 35.579},
	{99.416, 55.191, -94.287, 636.154, 0.465, 0.010, 82.012, 35.831},
	{99.959, 54.310, -88.086, 620.086, 0.447, 0.010, 82.500, 36.070},
	{100.494, 53.489, -82.108, 597.826, 0.429, 0.010, 82.984, 36.297},
	{101.021, 52.725, -76.409, 569.900, 0.411, 0.010, 83.466, 36.512},
	{101.541, 52.015, -71.039, 536.986, 0.394, 0.010, 83.944, 36.716},
	{102.055, 51.354, -66.040, 499.870, 0.376, 0.010, 84.420, 36.909},
	{102.562, 50.740, -61.446, 459.418, 0.359, 0.010, 84.893, 37.092},
	{103.064, 50.167, -57.281, 416.529, 0.343, 0.010, 85.365, 37.264},
	{103.560, 49.631, -53.560, 372.100, 0.326, 0.010, 85.833, 37.427},
	{104.051, 49.129, -50.290, 326.993, 0.310, 0.010, 86.300, 37.581},
	{104.538, 48.654, -47.470, 282.001, 0.295, 0.010, 86.764, 37.726},
	{105.020, 48.203, -45.091, 237.839, 0.280, 0.010, 87.227, 37.862},
	{105.498, 47.772, -43.140, 195.118, 0.265, 0.010, 87.687, 37.991},
	{105.971, 47.356, -41.597, 154.339, 0.251, 0.010, 88.145, 38.111},
	{106.441, 46.951, -40.438, 115.901, 0.237, 0.010, 88.600, 38.225},
	{106.906, 46.555, -39.637, 80.091, 0.224, 0.010, 89.054, 38.331},
	{107.368, 46.163, -39.166, 47.100, 0.211, 0.010, 89.504, 38.430},
	{107.826, 45.773, -38.995, 17.031, 0.199, 0.010, 89.953, 38.524},
	{108.280, 45.382, -39.096, -10.091, 0.187, 0.010, 90.398, 38.611},
	{108.729, 44.988, -39.439, -34.302, 0.176, 0.010, 90.841, 38.692},
	{109.175, 44.588, -39.996, -55.698, 0.165, 0.010, 91.280, 38.767},
	{109.617, 44.181, -40.740, -74.403, 0.154, 0.010, 91.716, 38.837},
	{110.055, 43.764, -41.646, -90.579, 0.145, 0.010, 92.149, 38.902},
	{110.488, 43.337, -42.690, -104.409, 0.135, 0.010, 92.578, 38.963},
	{110.917, 42.899, -43.851, -116.078, 0.126, 0.010, 93.003, 39.019},
	{111.342, 42.448, -45.109, -125.784, 0.117, 0.010, 93.425, 39.070},
	{111.761, 41.983, -46.446, -133.721, 0.109, 0.010, 93.842, 39.118},
	{112.176, 41.505, -47.847, -140.077, 0.102, 0.010, 94.255, 39.161},
	{112.587, 41.012, -49.297, -145.035, 0.094, 0.010, 94.663, 39.202},
	{112.992, 40.504, -50.785, -148.765, 0.087, 0.010, 95.066, 39.238},
	{113.391, 39.981, -52.299, -151.419, 0.081, 0.010, 95.465, 39.272},
	{113.786, 39.443, -53.831, -153.149, 0.075, 0.010, 95.858, 39.302},
	{114.175, 38.889, -55.371, -154.084, 0.069, 0.010, 96.246, 39.330},
	{114.558, 38.320, -56.915, -154.338, 0.063, 0.010, 96.628, 39.356},
	{114.935, 37.735, -58.455, -154.025, 0.058, 0.010, 97.005, 39.378},
	{115.307, 37.135, -59.987, -153.225, 0.053, 0.010, 97.375, 39.399},
	{115.672, 36.520, -61.508, -152.034, 0.049, 0.010, 97.740, 39.418},
	{116.031, 35.890, -63.013, -150.509, 0.044, 0.010, 98.099, 39.434},
	{116.383, 35.245, -64.500, -148.720, 0.040, 0.010, 98.451, 39.449},
	{116.729, 34.585, -65.967, -146.711, 0.037, 0.010, 98.796, 39.463},
	{117.068, 33.911, -67.412, -144.531, 0.033, 0.010, 99.135, 39.475},
	{117.400, 33.223, -68.834, -142.209, 0.030, 0.010, 99.467, 39.485},
	{117.726, 32.521, -70.232, -139.780, 0.027, 0.010, 99.792, 39.494},
	{118.044, 31.805, -71.605, -137.264, 0.024, 0.010, 100.110, 39.503},
	{118.354, 31.075, -72.952, -134.680, 0.022, 0.010, 100.421, 39.510},
	{118.658, 30.332, -74.272, -132.038, 0.019, 0.010, 100.724, 39.516},
	{118.953, 29.577, -75.566, -129.351, 0.017, 0.010, 101.020, 39.521},
	{119.242, 28.808, -76.832, -126.627, 0.015, 0.010, 101.308, 39.526},
	{119.522, 28.028, -78.070, -123.860, 0.014, 0.010, 101.588, 39.530},
	{119.794, 27.235, -79.281, -121.062, 0.012, 0.010, 101.861, 39.534},
	{120.058, 26.430, -80.463, -118.223, 0.010, 0.010, 102.125, 39.537},
	{120.315, 25.614, -81.617, -115.343, 0.009, 0.010, 102.381, 39.539},
	{120.562, 24.787, -82.741, -112.421, 0.008, 0.010, 102.629, 39.541},
	{120.802, 23.948, -83.835, -109.445, 0.007, 0.010, 102.868, 39.543},
	{121.033, 23.099, -84.900, -106.416, 0.006, 0.010, 103.099, 39.544},
	{121.255, 22.240, -85.933, -103.323, 0.005, 0.010, 103.322, 39.546},
	{121.469, 21.371, -86.934, -100.162, 0.004, 0.010, 103.536, 39.547},
	{121.674, 20.492, -87.904, -96.926, 0.004, 0.010, 103.740, 39.547},
	{121.870, 19.603, -88.840, -93.607, 0.003, 0.010, 103.936, 39.548},
	{122.057, 18.706, -89.742, -90.203, 0.002, 0.010, 104.124, 39.548},
	{122.235, 17.800, -90.609, -86.705, 0.002, 0.010, 104.302, 39.549},
	{122.404, 16.885, -91.440, -83.111, 0.002, 0.010, 104.470, 39.549},
	{122.564, 15.963, -92.234, -79.416, 0.001, 0.010, 104.630, 39.549},
	{122.714, 15.033, -92.990, -75.617, 0.001, 0.010, 104.780, 39.550},
	{122.855, 14.096, -93.707, -71.713, 0.001, 0.010, 104.921, 39.550},
	{122.986, 13.152, -94.384, -67.702, 0.001, 0.010, 105.053, 39.550},
	{123.108, 12.202, -95.020, -63.585, 0.000, 0.010, 105.175, 39.550},
	{123.221, 11.246, -95.614, -59.363, 0.000, 0.010, 105.287, 39.550},
	{123.324, 10.284, -96.164, -55.038, 0.000, 0.010, 105.390, 39.550},
	{123.417, 9.317, -96.670, -50.614, 0.000, 0.010, 105.483, 39.550},
	{123.500, 8.347, -97.046, -37.560, 0.000, 0.010, 105.567, 39.550},
	{123.574, 7.402, -94.471, 257.456, 0.000, 0.010, 105.641, 39.550},
	{123.639, 6.512, -89.016, 545.581, 0.000, 0.010, 105.706, 39.550},
	{123.696, 5.677, -83.493, 552.261, 0.000, 0.010, 105.763, 39.550},
	{123.745, 4.898, -77.911, 558.152, 0.000, 0.010, 105.812, 39.550},
	{123.787, 4.175, -72.279, 563.294, 0.000, 0.010, 105.853, 39.550},
	{123.822, 3.509, -66.601, 567.728, 0.000, 0.010, 105.888, 39.550},
	{123.851, 2.900, -60.886, 571.501, 0.000, 0.010, 105.917, 39.550},
	{123.875, 2.349, -55.140, 574.660, 0.000, 0.010, 105.941, 39.550},
	{123.893, 1.855, -49.367, 577.256, 0.000, 0.010, 105.960, 39.550},
	{123.907, 1.420, -43.574, 579.341, 0.000, 0.010, 105.974, 39.550},
	{123.918, 1.042, -37.764, 580.968, 0.000, 0.010, 105.984, 39.550},
	{123.925, 0.722, -31.942, 582.193, 0.000, 0.010, 105.991, 39.550},
	{123.930, 0.461, -26.111, 583.073, 0.000, 0.010, 105.996, 39.550},
	{123.932, 0.259, -20.275, 583.664, 0.000, 0.010, 105.999, 39.550},
	{123.933, 0.114, -14.434, 584.024, 0.000, 0.010, 106.000, 39.550},
	{123.934, 0.028, -8.592, 584.211, 0.000, 0.010, 106.000, 39.550},
	{123.934, 0.000, -2.836, 575.685, 0.000, 0.010, 106.000, 39.550}};
};

#endif