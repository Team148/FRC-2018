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

private:
	FromMiddlePos_ToRightSwitchPath();
	int num_index = 237;
	double left_wheel[237][8] ={ 
	{0.000, 0.058, 5.826, 582.601, 6.283, 0.010, 0.000, 14.500},
	{0.001, 0.117, 5.826, 0.020, 6.283, 0.010, 0.001, 14.500},
	{0.004, 0.262, 14.566, 874.006, 6.283, 0.010, 0.004, 14.500},
	{0.009, 0.466, 20.396, 582.928, 6.283, 0.010, 0.009, 14.500},
	{0.016, 0.728, 26.229, 583.352, 6.283, 0.010, 0.016, 14.500},
	{0.027, 1.049, 32.070, 584.047, 6.283, 0.010, 0.027, 14.500},
	{0.041, 1.428, 37.920, 585.079, 6.283, 0.010, 0.041, 14.500},
	{0.059, 1.866, 43.785, 586.514, 6.283, 0.010, 0.059, 14.500},
	{0.083, 2.363, 49.670, 588.417, 6.283, 0.010, 0.083, 14.500},
	{0.112, 2.919, 55.578, 590.853, 6.283, 0.010, 0.112, 14.500},
	{0.148, 3.534, 61.517, 593.884, 6.283, 0.010, 0.148, 14.500},
	{0.190, 4.209, 67.493, 597.569, 6.283, 0.010, 0.190, 14.500},
	{0.239, 4.944, 73.512, 601.967, 6.283, 0.010, 0.239, 14.500},
	{0.297, 5.740, 79.584, 607.133, 6.283, 0.010, 0.297, 14.500},
	{0.363, 6.597, 85.715, 613.117, 6.283, 0.010, 0.363, 14.500},
	{0.438, 7.516, 91.915, 619.968, 6.283, 0.010, 0.438, 14.500},
	{0.523, 8.498, 98.192, 627.729, 6.283, 0.010, 0.523, 14.500},
	{0.618, 9.514, 101.608, 341.619, 6.283, 0.010, 0.618, 14.500},
	{0.723, 10.535, 102.144, 53.547, 6.283, 0.010, 0.723, 14.500},
	{0.839, 11.563, 102.731, 58.743, 6.283, 0.010, 0.839, 14.500},
	{0.965, 12.596, 103.369, 63.818, 6.283, 0.010, 0.965, 14.500},
	{1.101, 13.637, 104.057, 68.764, 6.282, 0.010, 1.101, 14.500},
	{1.248, 14.685, 104.793, 73.574, 6.282, 0.010, 1.248, 14.500},
	{1.405, 15.741, 105.575, 78.245, 6.282, 0.010, 1.405, 14.499},
	{1.573, 16.805, 106.403, 82.773, 6.282, 0.010, 1.573, 14.499},
	{1.752, 17.877, 107.274, 87.153, 6.281, 0.010, 1.752, 14.499},
	{1.942, 18.959, 108.188, 91.386, 6.281, 0.010, 1.942, 14.498},
	{2.142, 20.051, 109.143, 95.470, 6.280, 0.010, 2.142, 14.498},
	{2.354, 21.152, 110.137, 99.404, 6.280, 0.010, 2.354, 14.497},
	{2.576, 22.264, 111.169, 103.192, 6.279, 0.010, 2.576, 14.496},
	{2.810, 23.386, 112.237, 106.831, 6.278, 0.010, 2.810, 14.495},
	{3.055, 24.520, 113.340, 110.327, 6.277, 0.010, 3.055, 14.494},
	{3.312, 25.664, 114.477, 113.681, 6.276, 0.010, 3.312, 14.492},
	{3.580, 26.821, 115.646, 116.894, 6.275, 0.010, 3.580, 14.490},
	{3.860, 27.989, 116.846, 119.971, 6.274, 0.010, 3.860, 14.488},
	{4.152, 29.170, 118.075, 122.913, 6.273, 0.010, 4.152, 14.485},
	{4.456, 30.363, 119.332, 125.723, 6.271, 0.010, 4.456, 14.482},
	{4.771, 31.570, 120.616, 128.401, 6.270, 0.010, 4.771, 14.478},
	{5.099, 32.789, 121.926, 130.947, 6.268, 0.010, 5.099, 14.473},
	{5.439, 34.021, 123.259, 133.360, 6.266, 0.010, 5.439, 14.468},
	{5.792, 35.268, 124.616, 135.637, 6.264, 0.010, 5.792, 14.461},
	{6.157, 36.527, 125.993, 137.773, 6.262, 0.010, 6.157, 14.454},
	{6.535, 37.801, 127.391, 139.759, 6.259, 0.010, 6.535, 14.445},
	{6.926, 39.089, 128.807, 141.587, 6.256, 0.010, 6.926, 14.435},
	{7.330, 40.392, 130.239, 143.241, 6.253, 0.010, 7.329, 14.424},
	{7.747, 41.709, 131.686, 144.703, 6.250, 0.010, 7.746, 14.411},
	{8.178, 43.040, 133.146, 145.953, 6.247, 0.010, 8.176, 14.396},
	{8.622, 44.386, 134.615, 146.963, 6.243, 0.010, 8.620, 14.379},
	{9.079, 45.747, 136.092, 147.699, 6.239, 0.010, 9.077, 14.360},
	{9.550, 47.123, 137.574, 148.127, 6.235, 0.010, 9.548, 14.338},
	{10.035, 48.514, 139.056, 148.200, 6.231, 0.010, 10.032, 14.314},
	{10.535, 49.919, 140.534, 147.866, 6.226, 0.010, 10.531, 14.286},
	{11.048, 51.339, 142.005, 147.068, 6.221, 0.010, 11.043, 14.256},
	{11.576, 52.774, 143.462, 145.738, 6.216, 0.010, 11.570, 14.222},
	{12.118, 54.223, 144.900, 143.805, 6.210, 0.010, 12.111, 14.183},
	{12.675, 55.686, 146.312, 141.180, 6.204, 0.010, 12.666, 14.141},
	{13.246, 57.163, 147.690, 137.779, 6.198, 0.010, 13.236, 14.094},
	{13.833, 58.653, 149.025, 133.493, 6.191, 0.010, 13.820, 14.042},
	{14.434, 60.156, 150.307, 128.228, 6.184, 0.010, 14.419, 13.985},
	{15.051, 61.671, 151.526, 121.851, 6.177, 0.010, 15.032, 13.922},
	{15.683, 63.198, 152.668, 114.259, 6.169, 0.010, 15.660, 13.852},
	{16.330, 64.735, 153.721, 105.313, 6.161, 0.010, 16.303, 13.776},
	{16.993, 66.282, 154.670, 94.889, 6.153, 0.010, 16.961, 13.692},
	{17.672, 67.837, 155.499, 82.858, 6.144, 0.010, 17.633, 13.601},
	{18.366, 69.399, 156.190, 69.091, 6.134, 0.010, 18.320, 13.501},
	{19.075, 70.966, 156.725, 53.472, 6.125, 0.010, 19.021, 13.393},
	{19.801, 72.537, 157.083, 35.888, 6.115, 0.010, 19.737, 13.275},
	{20.542, 74.109, 157.246, 16.248, 6.104, 0.010, 20.467, 13.147},
	{21.299, 75.681, 157.191, -5.516, 6.093, 0.010, 21.211, 13.008},
	{22.071, 77.250, 156.896, -29.447, 6.082, 0.010, 21.968, 12.858},
	{22.859, 78.813, 156.341, -55.552, 6.070, 0.010, 22.740, 12.696},
	{23.663, 80.368, 155.503, -83.792, 6.058, 0.010, 23.524, 12.521},
	{24.482, 81.912, 154.362, -114.081, 6.046, 0.010, 24.322, 12.334},
	{25.316, 83.441, 152.899, -146.281, 6.033, 0.010, 25.131, 12.133},
	{26.166, 84.952, 151.097, -180.186, 6.020, 0.010, 25.953, 11.917},
	{27.030, 86.441, 148.942, -215.529, 6.006, 0.010, 26.786, 11.686},
	{27.909, 87.906, 146.422, -251.980, 5.993, 0.010, 27.630, 11.440},
	{28.803, 89.341, 143.531, -289.138, 5.978, 0.010, 28.484, 11.178},
	{29.710, 90.744, 140.265, -326.540, 5.964, 0.010, 29.348, 10.900},
	{30.631, 92.110, 136.629, -363.675, 5.949, 0.010, 30.220, 10.604},
	{31.566, 93.436, 132.629, -399.986, 5.934, 0.010, 31.101, 10.292},
	{32.513, 94.719, 128.280, -434.880, 5.919, 0.010, 31.988, 9.961},
	{33.472, 95.955, 123.602, -467.761, 5.904, 0.010, 32.883, 9.613},
	{34.444, 97.141, 118.622, -498.036, 5.889, 0.010, 33.782, 9.246},
	{35.427, 98.275, 113.371, -525.143, 5.873, 0.010, 34.686, 8.861},
	{36.420, 99.354, 107.885, -548.571, 5.857, 0.010, 35.594, 8.458},
	{37.424, 100.376, 102.206, -567.883, 5.842, 0.010, 36.505, 8.037},
	{38.437, 101.340, 96.379, -582.734, 5.826, 0.010, 37.418, 7.597},
	{39.460, 102.244, 90.450, -592.886, 5.811, 0.010, 38.332, 7.138},
	{40.491, 103.089, 84.468, -598.224, 5.795, 0.010, 39.247, 6.662},
	{41.529, 103.874, 78.480, -598.755, 5.780, 0.010, 40.160, 6.168},
	{42.575, 104.599, 72.534, -594.617, 5.765, 0.010, 41.073, 5.657},
	{43.628, 105.266, 66.673, -586.063, 5.750, 0.010, 41.983, 5.129},
	{44.687, 105.875, 60.939, -573.466, 5.735, 0.010, 42.891, 4.584},
	{45.751, 106.429, 55.366, -557.283, 5.721, 0.010, 43.796, 4.023},
	{46.820, 106.929, 49.985, -538.059, 5.707, 0.010, 44.697, 3.447},
	{47.894, 107.377, 44.821, -516.383, 5.694, 0.010, 45.593, 2.856},
	{48.972, 107.776, 39.893, -492.891, 5.680, 0.010, 46.485, 2.251},
	{50.053, 108.128, 35.210, -468.221, 5.668, 0.010, 47.372, 1.632},
	{51.138, 108.436, 30.780, -443.004, 5.655, 0.010, 48.253, 1.000},
	{52.225, 108.702, 26.602, -417.856, 5.644, 0.010, 49.129, 0.356},
	{53.314, 108.928, 22.668, -393.338, 5.632, 0.010, 49.999, -0.299},
	{54.405, 109.084, 15.588, -708.057, 5.622, 0.010, 50.863, -0.964},
	{55.496, 109.139, 5.499, -1008.906, 5.611, 0.010, 51.721, -1.639},
	{56.587, 109.098, -4.141, -963.962, 5.602, 0.010, 52.572, -2.322},
	{57.677, 108.964, -13.350, -920.956, 5.593, 0.010, 53.415, -3.012},
	{58.764, 108.743, -22.154, -880.354, 5.585, 0.010, 54.251, -3.708},
	{59.848, 108.437, -30.579, -842.508, 5.577, 0.010, 55.078, -4.409},
	{60.929, 108.050, -38.655, -807.628, 5.570, 0.010, 55.898, -5.112},
	{62.005, 107.586, -46.413, -775.801, 5.564, 0.010, 56.710, -5.818},
	{63.075, 107.047, -53.884, -747.019, 5.559, 0.010, 57.514, -6.526},
	{64.140, 106.437, -61.095, -721.167, 5.554, 0.010, 58.309, -7.233},
	{65.197, 105.756, -68.076, -698.061, 5.550, 0.010, 59.096, -7.939},
	{66.247, 105.007, -74.850, -677.445, 5.547, 0.010, 59.876, -8.643},
	{67.289, 104.193, -81.440, -659.011, 5.544, 0.010, 60.647, -9.344},
	{68.322, 103.314, -87.864, -642.407, 5.543, 0.010, 61.410, -10.040},
	{69.346, 102.373, -94.137, -627.251, 5.542, 0.010, 62.165, -10.731},
	{70.360, 101.361, -101.171, -703.379, 5.541, 0.010, 62.912, -11.416},
	{71.362, 100.252, -110.907, -973.626, 5.542, 0.010, 63.652, -12.093},
	{72.353, 99.057, -119.462, -855.481, 5.543, 0.010, 64.382, -12.762},
	{73.331, 97.808, -124.941, -547.866, 5.545, 0.010, 65.105, -13.421},
	{74.296, 96.505, -130.275, -533.466, 5.548, 0.010, 65.820, -14.069},
	{75.247, 95.151, -135.454, -517.901, 5.551, 0.010, 66.527, -14.706},
	{76.185, 93.746, -140.462, -500.765, 5.556, 0.010, 67.225, -15.331},
	{77.108, 92.293, -145.279, -481.685, 5.560, 0.010, 67.916, -15.943},
	{78.016, 90.795, -149.882, -460.322, 5.566, 0.010, 68.599, -16.542},
	{78.908, 89.252, -154.246, -436.385, 5.572, 0.010, 69.273, -17.127},
	{79.785, 87.669, -158.342, -409.637, 5.580, 0.010, 69.940, -17.696},
	{80.645, 86.047, -162.141, -379.911, 5.587, 0.010, 70.598, -18.250},
	{81.489, 84.391, -165.613, -347.132, 5.596, 0.010, 71.248, -18.789},
	{82.316, 82.704, -168.726, -311.309, 5.605, 0.010, 71.889, -19.311},
	{83.126, 80.989, -171.451, -272.577, 5.615, 0.010, 72.522, -19.816},
	{83.919, 79.252, -173.763, -231.182, 5.625, 0.010, 73.147, -20.304},
	{84.694, 77.495, -175.638, -187.512, 5.636, 0.010, 73.762, -20.775},
	{85.451, 75.732, -176.322, -68.378, 5.647, 0.010, 74.369, -21.228},
	{86.191, 73.990, -174.231, 209.087, 5.659, 0.010, 74.967, -21.664},
	{86.914, 72.288, -170.223, 400.841, 5.671, 0.010, 75.556, -22.083},
	{87.620, 70.628, -165.967, 425.620, 5.684, 0.010, 76.137, -22.485},
	{88.310, 69.013, -161.458, 450.859, 5.698, 0.010, 76.709, -22.870},
	{88.985, 67.446, -156.698, 475.980, 5.711, 0.010, 77.274, -23.239},
	{89.644, 65.929, -151.695, 500.360, 5.726, 0.010, 77.831, -23.592},
	{90.289, 64.465, -146.461, 523.364, 5.740, 0.010, 78.380, -23.929},
	{90.919, 63.055, -141.018, 544.353, 5.755, 0.010, 78.922, -24.251},
	{91.536, 61.701, -135.390, 562.701, 5.770, 0.010, 79.457, -24.558},
	{92.140, 60.405, -129.612, 577.832, 5.785, 0.010, 79.986, -24.851},
	{92.732, 59.167, -123.720, 589.226, 5.800, 0.010, 80.508, -25.130},
	{93.312, 57.990, -117.755, 596.448, 5.816, 0.010, 81.023, -25.396},
	{93.881, 56.872, -111.764, 599.165, 5.831, 0.010, 81.533, -25.648},
	{94.439, 55.814, -105.792, 597.153, 5.847, 0.010, 82.037, -25.888},
	{94.987, 54.815, -99.889, 590.319, 5.862, 0.010, 82.535, -26.116},
	{95.526, 53.874, -94.102, 578.691, 5.878, 0.010, 83.029, -26.332},
	{96.056, 52.990, -88.478, 562.426, 5.893, 0.010, 83.517, -26.537},
	{96.577, 52.159, -83.060, 541.794, 5.909, 0.010, 84.001, -26.732},
	{97.091, 51.380, -77.888, 517.171, 5.924, 0.010, 84.481, -26.916},
	{97.597, 50.650, -72.998, 489.021, 5.939, 0.010, 84.956, -27.090},
	{98.097, 49.966, -68.419, 457.872, 5.954, 0.010, 85.428, -27.256},
	{98.590, 49.324, -64.176, 424.298, 5.969, 0.010, 85.896, -27.412},
	{99.078, 48.721, -60.287, 388.895, 5.983, 0.010, 86.360, -27.559},
	{99.559, 48.154, -56.765, 352.263, 5.997, 0.010, 86.821, -27.698},
	{100.035, 47.617, -53.615, 314.981, 6.011, 0.010, 87.279, -27.830},
	{100.506, 47.109, -50.839, 277.596, 6.024, 0.010, 87.733, -27.953},
	{100.973, 46.625, -48.433, 240.607, 6.037, 0.010, 88.185, -28.070},
	{101.434, 46.161, -46.388, 204.454, 6.050, 0.010, 88.633, -28.180},
	{101.891, 45.714, -44.693, 169.519, 6.062, 0.010, 89.079, -28.283},
	{102.344, 45.281, -43.332, 136.115, 6.074, 0.010, 89.521, -28.379},
	{102.793, 44.858, -42.287, 104.483, 6.086, 0.010, 89.960, -28.470},
	{103.237, 44.442, -41.539, 74.813, 6.097, 0.010, 90.397, -28.555},
	{103.677, 44.032, -41.067, 47.227, 6.107, 0.010, 90.830, -28.634},
	{104.114, 43.623, -40.849, 21.790, 6.118, 0.010, 91.260, -28.708},
	{104.546, 43.215, -40.864, -1.468, 6.128, 0.010, 91.686, -28.777},
	{104.974, 42.804, -41.089, -22.570, 6.137, 0.010, 92.109, -28.841},
	{105.398, 42.389, -41.505, -41.565, 6.146, 0.010, 92.529, -28.901},
	{105.817, 41.968, -42.090, -58.529, 6.155, 0.010, 92.945, -28.956},
	{106.233, 41.539, -42.826, -73.564, 6.164, 0.010, 93.357, -29.007},
	{106.644, 41.103, -43.694, -86.779, 6.172, 0.010, 93.766, -29.055},
	{107.050, 40.656, -44.677, -98.298, 6.179, 0.010, 94.170, -29.099},
	{107.452, 40.198, -45.759, -108.251, 6.186, 0.010, 94.570, -29.139},
	{107.850, 39.729, -46.927, -116.763, 6.193, 0.010, 94.965, -29.176},
	{108.242, 39.247, -48.166, -123.965, 6.200, 0.010, 95.356, -29.210},
	{108.630, 38.753, -49.466, -129.983, 6.206, 0.010, 95.743, -29.241},
	{109.012, 38.244, -50.816, -134.934, 6.212, 0.010, 96.124, -29.269},
	{109.389, 37.722, -52.205, -138.932, 6.217, 0.010, 96.500, -29.295},
	{109.761, 37.186, -53.626, -142.083, 6.223, 0.010, 96.871, -29.319},
	{110.128, 36.635, -55.071, -144.483, 6.228, 0.010, 97.237, -29.340},
	{110.488, 36.070, -56.533, -146.220, 6.232, 0.010, 97.597, -29.359},
	{110.843, 35.490, -58.007, -147.376, 6.237, 0.010, 97.952, -29.376},
	{111.192, 34.895, -59.487, -148.023, 6.241, 0.010, 98.300, -29.392},
	{111.535, 34.285, -60.969, -148.223, 6.244, 0.010, 98.643, -29.406},
	{111.872, 33.661, -62.449, -148.035, 6.248, 0.010, 98.979, -29.418},
	{112.202, 33.022, -63.924, -147.506, 6.251, 0.010, 99.309, -29.430},
	{112.525, 32.368, -65.391, -146.681, 6.254, 0.010, 99.633, -29.439},
	{112.842, 31.699, -66.847, -145.593, 6.257, 0.010, 99.950, -29.448},
	{113.153, 31.016, -68.290, -144.273, 6.260, 0.010, 100.260, -29.456},
	{113.456, 30.319, -69.717, -142.749, 6.262, 0.010, 100.563, -29.462},
	{113.752, 29.608, -71.128, -141.039, 6.265, 0.010, 100.859, -29.468},
	{114.041, 28.883, -72.519, -139.159, 6.267, 0.010, 101.148, -29.473},
	{114.322, 28.144, -73.891, -137.127, 6.268, 0.010, 101.429, -29.478},
	{114.596, 27.391, -75.240, -134.944, 6.270, 0.010, 101.703, -29.482},
	{114.862, 26.626, -76.566, -132.625, 6.272, 0.010, 101.969, -29.485},
	{115.121, 25.847, -77.868, -130.170, 6.273, 0.010, 102.228, -29.488},
	{115.371, 25.056, -79.144, -127.581, 6.275, 0.010, 102.478, -29.490},
	{115.614, 24.252, -80.392, -124.864, 6.276, 0.010, 102.721, -29.492},
	{115.848, 23.436, -81.613, -122.012, 6.277, 0.010, 102.955, -29.493},
	{116.074, 22.608, -82.803, -119.029, 6.278, 0.010, 103.181, -29.495},
	{116.292, 21.768, -83.962, -115.908, 6.278, 0.010, 103.399, -29.496},
	{116.501, 20.917, -85.088, -112.652, 6.279, 0.010, 103.608, -29.497},
	{116.702, 20.055, -86.181, -109.254, 6.280, 0.010, 103.809, -29.498},
	{116.894, 19.183, -87.238, -105.714, 6.280, 0.010, 104.000, -29.498},
	{117.077, 18.300, -88.258, -102.029, 6.281, 0.010, 104.183, -29.499},
	{117.251, 17.408, -89.240, -98.196, 6.281, 0.010, 104.358, -29.499},
	{117.416, 16.506, -90.183, -94.215, 6.282, 0.010, 104.523, -29.499},
	{117.572, 15.595, -91.083, -90.085, 6.282, 0.010, 104.679, -29.499},
	{117.718, 14.676, -91.941, -85.806, 6.282, 0.010, 104.825, -29.500},
	{117.856, 13.748, -92.755, -81.380, 6.282, 0.010, 104.963, -29.500},
	{117.984, 12.813, -93.523, -76.808, 6.283, 0.010, 105.091, -29.500},
	{118.103, 11.871, -94.244, -72.093, 6.283, 0.010, 105.210, -29.500},
	{118.212, 10.921, -94.917, -67.240, 6.283, 0.010, 105.319, -29.500},
	{118.312, 9.966, -95.539, -62.254, 6.283, 0.010, 105.419, -29.500},
	{118.402, 9.005, -96.111, -57.141, 6.283, 0.010, 105.509, -29.500},
	{118.482, 8.048, -95.733, 37.754, 6.283, 0.010, 105.589, -29.500},
	{118.553, 7.124, -92.404, 332.937, 6.283, 0.010, 105.660, -29.500},
	{118.616, 6.254, -87.004, 539.940, 6.283, 0.010, 105.723, -29.500},
	{118.670, 5.438, -81.530, 547.415, 6.283, 0.010, 105.777, -29.500},
	{118.717, 4.678, -75.990, 553.995, 6.283, 0.010, 105.824, -29.500},
	{118.757, 3.974, -70.393, 559.722, 6.283, 0.010, 105.864, -29.500},
	{118.790, 3.327, -64.747, 564.646, 6.283, 0.010, 105.897, -29.500},
	{118.817, 2.736, -59.058, 568.820, 6.283, 0.010, 105.924, -29.500},
	{118.840, 2.203, -53.335, 572.298, 6.283, 0.010, 105.946, -29.500},
	{118.857, 1.727, -47.584, 575.140, 6.283, 0.010, 105.964, -29.500},
	{118.870, 1.309, -41.810, 577.407, 6.283, 0.010, 105.977, -29.500},
	{118.879, 0.949, -36.018, 579.161, 6.283, 0.010, 105.986, -29.500},
	{118.886, 0.647, -30.214, 580.467, 6.283, 0.010, 105.993, -29.500},
	{118.890, 0.403, -24.400, 581.390, 6.283, 0.010, 105.997, -29.500},
	{118.892, 0.217, -18.580, 581.997, 6.283, 0.010, 105.999, -29.500},
	{118.893, 0.089, -12.756, 582.354, 6.283, 0.010, 106.000, -29.500},
	{118.893, 0.020, -6.931, 582.529, 0.000, 0.010, 106.000, -29.500},
	{118.893, 0.000, -2.009, 492.191, 0.000, 0.010, 106.000, -29.500}};
	double right_wheel[237][8] ={ 
	{0.000, 0.058, 5.826, 582.601, 6.283, 0.010, 0.000, -14.500},
	{0.001, 0.117, 5.826, -0.020, 6.283, 0.010, 0.001, -14.500},
	{0.004, 0.262, 14.564, 873.797, 6.283, 0.010, 0.004, -14.500},
	{0.009, 0.466, 20.387, 582.274, 6.283, 0.010, 0.009, -14.500},
	{0.016, 0.728, 26.205, 581.850, 6.283, 0.010, 0.016, -14.500},
	{0.027, 1.048, 32.017, 581.155, 6.283, 0.010, 0.027, -14.500},
	{0.041, 1.426, 37.818, 580.123, 6.283, 0.010, 0.041, -14.500},
	{0.059, 1.862, 43.605, 578.688, 6.283, 0.010, 0.059, -14.500},
	{0.083, 2.356, 49.373, 576.784, 6.283, 0.010, 0.083, -14.500},
	{0.112, 2.907, 55.116, 574.348, 6.283, 0.010, 0.112, -14.500},
	{0.147, 3.516, 60.829, 571.318, 6.283, 0.010, 0.147, -14.500},
	{0.189, 4.181, 66.506, 567.632, 6.283, 0.010, 0.189, -14.500},
	{0.238, 4.902, 72.138, 563.234, 6.283, 0.010, 0.238, -14.500},
	{0.295, 5.679, 77.719, 558.069, 6.283, 0.010, 0.295, -14.500},
	{0.360, 6.512, 83.239, 552.085, 6.283, 0.010, 0.360, -14.500},
	{0.434, 7.399, 88.692, 545.234, 6.283, 0.010, 0.434, -14.500},
	{0.517, 8.339, 94.066, 537.473, 6.283, 0.010, 0.517, -14.500},
	{0.610, 9.304, 96.476, 240.982, 6.283, 0.010, 0.610, -14.500},
	{0.713, 10.263, 95.941, -53.547, 6.283, 0.010, 0.713, -14.500},
	{0.825, 11.217, 95.353, -58.743, 6.283, 0.010, 0.825, -14.500},
	{0.947, 12.164, 94.715, -63.818, 6.283, 0.010, 0.947, -14.500},
	{1.078, 13.104, 94.028, -68.764, 6.282, 0.010, 1.078, -14.500},
	{1.218, 14.037, 93.292, -73.574, 6.282, 0.010, 1.218, -14.500},
	{1.368, 14.962, 92.509, -78.246, 6.282, 0.010, 1.368, -14.501},
	{1.527, 15.879, 91.682, -82.772, 6.282, 0.010, 1.527, -14.501},
	{1.694, 16.787, 90.810, -87.154, 6.281, 0.010, 1.694, -14.501},
	{1.871, 17.686, 89.896, -91.386, 6.281, 0.010, 1.871, -14.502},
	{2.057, 18.576, 88.942, -95.470, 6.280, 0.010, 2.057, -14.502},
	{2.252, 19.455, 87.947, -99.405, 6.280, 0.010, 2.252, -14.503},
	{2.455, 20.324, 86.916, -103.191, 6.279, 0.010, 2.455, -14.503},
	{2.667, 21.183, 85.847, -106.833, 6.278, 0.010, 2.667, -14.504},
	{2.887, 22.030, 84.744, -110.328, 6.277, 0.010, 2.887, -14.506},
	{3.116, 22.866, 83.607, -113.681, 6.276, 0.010, 3.116, -14.507},
	{3.353, 23.691, 82.438, -116.896, 6.275, 0.010, 3.353, -14.509},
	{3.598, 24.503, 81.238, -119.972, 6.274, 0.010, 3.598, -14.511},
	{3.851, 25.303, 80.009, -122.915, 6.273, 0.010, 3.851, -14.513},
	{4.112, 26.091, 78.752, -125.725, 6.271, 0.010, 4.112, -14.516},
	{4.380, 26.865, 77.468, -128.403, 6.270, 0.010, 4.380, -14.520},
	{4.656, 27.627, 76.159, -130.950, 6.268, 0.010, 4.656, -14.524},
	{4.940, 28.375, 74.825, -133.363, 6.266, 0.010, 4.940, -14.528},
	{5.231, 29.110, 73.469, -135.641, 6.264, 0.010, 5.231, -14.533},
	{5.530, 29.831, 72.091, -137.777, 6.262, 0.010, 5.529, -14.540},
	{5.835, 30.538, 70.693, -139.765, 6.259, 0.010, 5.835, -14.547},
	{6.147, 31.230, 69.277, -141.592, 6.256, 0.010, 6.147, -14.555},
	{6.466, 31.909, 67.845, -143.247, 6.253, 0.010, 6.466, -14.564},
	{6.792, 32.573, 66.398, -144.711, 6.250, 0.010, 6.791, -14.574},
	{7.124, 33.222, 64.938, -145.961, 6.247, 0.010, 7.123, -14.585},
	{7.463, 33.857, 63.468, -146.970, 6.243, 0.010, 7.462, -14.598},
	{7.808, 34.477, 61.991, -147.710, 6.239, 0.010, 7.806, -14.613},
	{8.159, 35.082, 60.510, -148.137, 6.235, 0.010, 8.157, -14.629},
	{8.515, 35.672, 59.028, -148.211, 6.231, 0.010, 8.513, -14.647},
	{8.878, 36.248, 57.549, -147.879, 6.226, 0.010, 8.875, -14.666},
	{9.246, 36.809, 56.078, -147.082, 6.221, 0.010, 9.242, -14.688},
	{9.619, 37.355, 54.621, -145.755, 6.216, 0.010, 9.615, -14.713},
	{9.998, 37.887, 53.182, -143.820, 6.210, 0.010, 9.993, -14.739},
	{10.382, 38.404, 51.770, -141.200, 6.204, 0.010, 10.376, -14.768},
	{10.771, 38.908, 50.392, -137.796, 6.198, 0.010, 10.764, -14.800},
	{11.165, 39.399, 49.057, -133.518, 6.191, 0.010, 11.156, -14.835},
	{11.564, 39.876, 47.775, -128.246, 6.184, 0.010, 11.553, -14.873},
	{11.968, 40.342, 46.556, -121.879, 6.177, 0.010, 11.954, -14.914},
	{12.375, 40.796, 45.413, -114.283, 6.169, 0.010, 12.360, -14.959},
	{12.788, 41.240, 44.360, -105.339, 6.161, 0.010, 12.769, -15.008},
	{13.205, 41.674, 43.411, -94.917, 6.153, 0.010, 13.183, -15.060},
	{13.626, 42.100, 42.582, -82.886, 6.144, 0.010, 13.600, -15.117},
	{14.051, 42.519, 41.891, -69.121, 6.134, 0.010, 14.021, -15.178},
	{14.480, 42.932, 41.356, -53.501, 6.125, 0.010, 14.445, -15.244},
	{14.914, 43.342, 40.996, -35.918, 6.115, 0.010, 14.873, -15.314},
	{15.351, 43.750, 40.834, -16.279, 6.104, 0.010, 15.304, -15.390},
	{15.793, 44.159, 40.888, 5.487, 6.093, 0.010, 15.738, -15.471},
	{16.238, 44.571, 41.183, 29.419, 6.082, 0.010, 16.175, -15.558},
	{16.688, 44.989, 41.738, 55.525, 6.070, 0.010, 16.615, -15.650},
	{17.142, 45.414, 42.576, 83.768, 6.058, 0.010, 17.059, -15.749},
	{17.601, 45.851, 43.716, 114.061, 6.046, 0.010, 17.505, -15.854},
	{18.064, 46.303, 45.179, 146.263, 6.033, 0.010, 17.954, -15.965},
	{18.532, 46.773, 46.980, 180.173, 6.020, 0.010, 18.407, -16.084},
	{19.004, 47.264, 49.136, 215.523, 6.006, 0.010, 18.862, -16.210},
	{19.482, 47.781, 51.656, 251.979, 5.993, 0.010, 19.321, -16.344},
	{19.965, 48.326, 54.547, 289.142, 5.978, 0.010, 19.783, -16.486},
	{20.454, 48.905, 57.812, 326.553, 5.964, 0.010, 20.248, -16.636},
	{20.950, 49.519, 61.449, 363.697, 5.949, 0.010, 20.717, -16.794},
	{21.451, 50.174, 65.450, 400.013, 5.934, 0.010, 21.190, -16.962},
	{21.960, 50.872, 69.799, 434.917, 5.919, 0.010, 21.667, -17.140},
	{22.476, 51.616, 74.477, 467.806, 5.904, 0.010, 22.148, -17.327},
	{23.000, 52.411, 79.458, 498.090, 5.889, 0.010, 22.633, -17.525},
	{23.533, 53.258, 84.710, 525.205, 5.873, 0.010, 23.123, -17.734},
	{24.075, 54.160, 90.196, 548.640, 5.857, 0.010, 23.618, -17.953},
	{24.626, 55.119, 95.876, 567.959, 5.842, 0.010, 24.118, -18.185},
	{25.187, 56.136, 101.704, 582.815, 5.826, 0.010, 24.624, -18.429},
	{25.759, 57.212, 107.634, 592.972, 5.811, 0.010, 25.136, -18.685},
	{26.343, 58.348, 113.617, 598.312, 5.795, 0.010, 25.653, -18.955},
	{26.938, 59.544, 119.605, 598.846, 5.780, 0.010, 26.177, -19.238},
	{27.546, 60.800, 125.552, 594.706, 5.765, 0.010, 26.707, -19.535},
	{28.167, 62.114, 131.414, 586.153, 5.750, 0.010, 27.245, -19.847},
	{28.802, 63.485, 137.149, 573.551, 5.735, 0.010, 27.789, -20.173},
	{29.451, 64.913, 142.723, 557.365, 5.721, 0.010, 28.341, -20.515},
	{30.115, 66.394, 148.104, 538.134, 5.707, 0.010, 28.900, -20.873},
	{30.794, 67.926, 153.269, 516.455, 5.694, 0.010, 29.467, -21.247},
	{31.490, 69.508, 158.198, 492.954, 5.680, 0.010, 30.042, -21.637},
	{32.201, 71.137, 162.881, 468.274, 5.668, 0.010, 30.625, -22.045},
	{32.929, 72.810, 167.312, 443.052, 5.655, 0.010, 31.217, -22.469},
	{33.674, 74.525, 171.491, 417.891, 5.644, 0.010, 31.818, -22.910},
	{34.437, 76.279, 175.424, 393.368, 5.632, 0.010, 32.427, -23.369},
	{35.218, 78.046, 176.679, 125.483, 5.622, 0.010, 33.045, -23.845},
	{36.015, 79.797, 175.116, -156.275, 5.611, 0.010, 33.673, -24.339},
	{36.831, 81.528, 173.104, -201.229, 5.602, 0.010, 34.308, -24.849},
	{37.663, 83.235, 170.661, -244.255, 5.593, 0.010, 34.952, -25.376},
	{38.512, 84.913, 167.813, -284.865, 5.585, 0.010, 35.605, -25.919},
	{39.378, 86.559, 164.586, -322.724, 5.577, 0.010, 36.266, -26.479},
	{40.260, 88.169, 161.009, -357.618, 5.570, 0.010, 36.935, -27.053},
	{41.157, 89.740, 157.115, -389.452, 5.564, 0.010, 37.612, -27.642},
	{42.070, 91.270, 152.932, -418.246, 5.559, 0.010, 38.297, -28.245},
	{42.997, 92.755, 148.491, -444.103, 5.554, 0.010, 38.990, -28.861},
	{43.939, 94.193, 143.819, -467.217, 5.550, 0.010, 39.691, -29.490},
	{44.895, 95.582, 138.941, -487.838, 5.547, 0.010, 40.401, -30.131},
	{45.864, 96.921, 133.878, -506.277, 5.544, 0.010, 41.118, -30.783},
	{46.846, 98.207, 128.649, -522.883, 5.543, 0.010, 41.843, -31.445},
	{47.841, 99.440, 123.269, -538.043, 5.542, 0.010, 42.577, -32.116},
	{48.847, 100.609, 116.842, -642.715, 5.541, 0.010, 43.319, -32.796},
	{49.864, 101.681, 107.291, -955.071, 5.542, 0.010, 44.068, -33.483},
	{50.890, 102.665, 98.367, -892.417, 5.543, 0.010, 44.826, -34.175},
	{51.926, 103.587, 92.192, -617.430, 5.545, 0.010, 45.592, -34.873},
	{52.970, 104.446, 85.874, -631.826, 5.548, 0.010, 46.365, -35.575},
	{54.023, 105.240, 79.400, -647.390, 5.551, 0.010, 47.147, -36.280},
	{55.083, 105.967, 72.755, -664.521, 5.556, 0.010, 47.937, -36.986},
	{56.149, 106.627, 65.919, -683.596, 5.560, 0.010, 48.734, -37.694},
	{57.221, 107.215, 58.870, -704.952, 5.566, 0.010, 49.541, -38.400},
	{58.298, 107.731, 51.581, -728.884, 5.572, 0.010, 50.355, -39.106},
	{59.380, 108.171, 44.025, -755.625, 5.580, 0.010, 51.177, -39.809},
	{60.465, 108.533, 36.171, -785.338, 5.587, 0.010, 52.007, -40.508},
	{61.553, 108.813, 27.990, -818.111, 5.596, 0.010, 52.845, -41.202},
	{62.644, 109.007, 19.451, -853.919, 5.605, 0.010, 53.691, -41.890},
	{63.735, 109.113, 10.524, -892.641, 5.615, 0.010, 54.544, -42.570},
	{64.826, 109.124, 1.184, -934.021, 5.625, 0.010, 55.403, -43.243},
	{65.916, 109.039, -8.593, -977.677, 5.636, 0.010, 56.269, -43.905},
	{67.005, 108.861, -17.753, -916.003, 5.647, 0.010, 57.141, -44.557},
	{68.091, 108.622, -23.861, -610.859, 5.659, 0.010, 58.019, -45.197},
	{69.175, 108.344, -27.869, -400.812, 5.671, 0.010, 58.902, -45.825},
	{70.255, 108.022, -32.125, -425.578, 5.684, 0.010, 59.790, -46.439},
	{71.331, 107.656, -36.633, -450.811, 5.698, 0.010, 60.684, -47.040},
	{72.404, 107.242, -41.392, -475.921, 5.711, 0.010, 61.581, -47.627},
	{73.472, 106.778, -46.395, -500.296, 5.726, 0.010, 62.483, -48.198},
	{74.534, 106.262, -51.628, -523.294, 5.740, 0.010, 63.389, -48.754},
	{75.591, 105.691, -57.071, -544.273, 5.755, 0.010, 64.298, -49.294},
	{76.642, 105.064, -62.697, -562.619, 5.770, 0.010, 65.209, -49.817},
	{77.686, 104.380, -68.475, -577.745, 5.785, 0.010, 66.122, -50.323},
	{78.722, 103.636, -74.366, -589.136, 5.800, 0.010, 67.036, -50.811},
	{79.750, 102.833, -80.330, -596.359, 5.816, 0.010, 67.950, -51.282},
	{80.770, 101.969, -86.320, -599.074, 5.831, 0.010, 68.864, -51.734},
	{81.780, 101.046, -92.291, -597.066, 5.847, 0.010, 69.776, -52.169},
	{82.781, 100.065, -98.193, -590.234, 5.862, 0.010, 70.686, -52.585},
	{83.771, 99.025, -103.979, -578.612, 5.878, 0.010, 71.593, -52.982},
	{84.751, 97.929, -109.603, -562.352, 5.893, 0.010, 72.496, -53.361},
	{85.718, 96.779, -115.020, -541.727, 5.909, 0.010, 73.394, -53.722},
	{86.674, 95.577, -120.191, -517.112, 5.924, 0.010, 74.286, -54.065},
	{87.617, 94.326, -125.081, -488.969, 5.939, 0.010, 75.172, -54.390},
	{88.548, 93.029, -129.659, -457.829, 5.954, 0.010, 76.050, -54.697},
	{89.465, 91.690, -133.902, -424.263, 5.969, 0.010, 76.920, -54.988},
	{90.368, 90.312, -137.791, -388.869, 5.983, 0.010, 77.781, -55.261},
	{91.257, 88.899, -141.313, -352.245, 5.997, 0.010, 78.632, -55.518},
	{92.131, 87.455, -144.463, -314.971, 6.011, 0.010, 79.472, -55.759},
	{92.991, 85.982, -147.239, -277.592, 6.024, 0.010, 80.302, -55.985},
	{93.836, 84.486, -149.645, -240.610, 6.037, 0.010, 81.120, -56.196},
	{94.666, 82.969, -151.689, -204.464, 6.050, 0.010, 81.926, -56.393},
	{95.480, 81.435, -153.385, -169.534, 6.062, 0.010, 82.719, -56.577},
	{96.279, 79.887, -154.746, -136.130, 6.074, 0.010, 83.500, -56.747},
	{97.062, 78.330, -155.791, -104.508, 6.086, 0.010, 84.267, -56.905},
	{97.830, 76.764, -156.540, -74.839, 6.097, 0.010, 85.020, -57.052},
	{98.582, 75.194, -157.012, -47.251, 6.107, 0.010, 85.760, -57.187},
	{99.318, 73.622, -157.230, -21.821, 6.118, 0.010, 86.486, -57.312},
	{100.038, 72.050, -157.216, 1.440, 6.128, 0.010, 87.197, -57.427},
	{100.743, 70.480, -156.991, 22.539, 6.137, 0.010, 87.894, -57.533},
	{101.432, 68.914, -156.575, 41.534, 6.146, 0.010, 88.576, -57.630},
	{102.106, 67.354, -155.990, 58.501, 6.155, 0.010, 89.244, -57.719},
	{102.764, 65.801, -155.255, 73.534, 6.164, 0.010, 89.897, -57.800},
	{103.406, 64.258, -154.387, 86.751, 6.172, 0.010, 90.535, -57.874},
	{104.034, 62.724, -153.405, 98.272, 6.179, 0.010, 91.158, -57.942},
	{104.646, 61.200, -152.322, 108.223, 6.186, 0.010, 91.767, -58.003},
	{105.243, 59.689, -151.155, 116.739, 6.193, 0.010, 92.362, -58.059},
	{105.824, 58.190, -149.916, 123.943, 6.200, 0.010, 92.941, -58.109},
	{106.392, 56.703, -148.616, 129.960, 6.206, 0.010, 93.507, -58.155},
	{106.944, 55.231, -147.267, 134.914, 6.212, 0.010, 94.057, -58.196},
	{107.482, 53.772, -145.878, 138.914, 6.217, 0.010, 94.594, -58.232},
	{108.005, 52.327, -144.457, 142.064, 6.223, 0.010, 95.116, -58.265},
	{108.514, 50.897, -143.012, 144.466, 6.228, 0.010, 95.624, -58.295},
	{109.009, 49.482, -141.550, 146.206, 6.232, 0.010, 96.118, -58.321},
	{109.489, 48.081, -140.077, 147.363, 6.237, 0.010, 96.599, -58.345},
	{109.956, 46.695, -138.597, 148.010, 6.241, 0.010, 97.065, -58.366},
	{110.410, 45.324, -137.114, 148.213, 6.244, 0.010, 97.518, -58.384},
	{110.849, 43.968, -135.634, 148.025, 6.248, 0.010, 97.957, -58.400},
	{111.276, 42.626, -134.159, 147.498, 6.251, 0.010, 98.383, -58.415},
	{111.689, 41.299, -132.693, 146.672, 6.254, 0.010, 98.796, -58.427},
	{112.088, 39.987, -131.237, 145.586, 6.257, 0.010, 99.196, -58.438},
	{112.475, 38.689, -129.794, 144.268, 6.260, 0.010, 99.583, -58.448},
	{112.849, 37.405, -128.367, 142.742, 6.262, 0.010, 99.956, -58.456},
	{113.211, 36.136, -126.956, 141.034, 6.265, 0.010, 100.318, -58.463},
	{113.559, 34.880, -125.565, 139.157, 6.267, 0.010, 100.667, -58.469},
	{113.896, 33.638, -124.193, 137.120, 6.268, 0.010, 101.003, -58.475},
	{114.220, 32.410, -122.844, 134.943, 6.270, 0.010, 101.327, -58.479},
	{114.532, 31.194, -121.518, 132.622, 6.272, 0.010, 101.639, -58.483},
	{114.832, 29.992, -120.216, 130.166, 6.273, 0.010, 101.939, -58.486},
	{115.120, 28.803, -118.940, 127.581, 6.275, 0.010, 102.227, -58.489},
	{115.396, 27.626, -117.692, 124.861, 6.276, 0.010, 102.503, -58.491},
	{115.661, 26.461, -116.472, 122.011, 6.277, 0.010, 102.768, -58.493},
	{115.914, 25.308, -115.281, 119.026, 6.278, 0.010, 103.021, -58.494},
	{116.155, 24.167, -114.122, 115.908, 6.278, 0.010, 103.262, -58.496},
	{116.386, 23.037, -112.996, 112.651, 6.279, 0.010, 103.493, -58.497},
	{116.605, 21.918, -111.903, 109.253, 6.280, 0.010, 103.712, -58.497},
	{116.813, 20.810, -110.846, 105.713, 6.280, 0.010, 103.920, -58.498},
	{117.010, 19.711, -109.826, 102.028, 6.281, 0.010, 104.117, -58.499},
	{117.196, 18.623, -108.844, 98.196, 6.281, 0.010, 104.303, -58.499},
	{117.372, 17.544, -107.902, 94.215, 6.282, 0.010, 104.479, -58.499},
	{117.537, 16.474, -107.001, 90.085, 6.282, 0.010, 104.644, -58.499},
	{117.691, 15.412, -106.143, 85.806, 6.282, 0.010, 104.798, -58.500},
	{117.834, 14.359, -105.329, 81.380, 6.282, 0.010, 104.941, -58.500},
	{117.968, 13.314, -104.561, 76.808, 6.283, 0.010, 105.074, -58.500},
	{118.090, 12.275, -103.840, 72.093, 6.283, 0.010, 105.197, -58.500},
	{118.203, 11.244, -103.168, 67.240, 6.283, 0.010, 105.310, -58.500},
	{118.305, 10.218, -102.545, 62.254, 6.283, 0.010, 105.412, -58.500},
	{118.397, 9.198, -101.974, 57.141, 6.283, 0.010, 105.504, -58.500},
	{118.479, 8.193, -100.543, 143.044, 6.283, 0.010, 105.586, -58.500},
	{118.551, 7.231, -96.239, 430.462, 6.283, 0.010, 105.658, -58.500},
	{118.614, 6.331, -89.986, 625.262, 6.283, 0.010, 105.721, -58.500},
	{118.669, 5.493, -83.808, 617.786, 6.283, 0.010, 105.776, -58.500},
	{118.716, 4.716, -77.696, 611.207, 6.283, 0.010, 105.823, -58.500},
	{118.756, 3.999, -71.641, 605.480, 6.283, 0.010, 105.863, -58.500},
	{118.790, 3.343, -65.636, 600.556, 6.283, 0.010, 105.897, -58.500},
	{118.817, 2.746, -59.672, 596.382, 6.283, 0.010, 105.924, -58.500},
	{118.839, 2.209, -53.743, 592.904, 6.283, 0.010, 105.946, -58.500},
	{118.857, 1.730, -47.842, 590.061, 6.283, 0.010, 105.964, -58.500},
	{118.870, 1.311, -41.964, 587.795, 6.283, 0.010, 105.977, -58.500},
	{118.879, 0.950, -36.104, 586.041, 6.283, 0.010, 105.986, -58.500},
	{118.886, 0.647, -30.257, 584.735, 6.283, 0.010, 105.993, -58.500},
	{118.890, 0.403, -24.418, 583.812, 6.283, 0.010, 105.997, -58.500},
	{118.892, 0.217, -18.586, 583.205, 6.283, 0.010, 105.999, -58.500},
	{118.893, 0.089, -12.758, 582.848, 6.283, 0.010, 106.000, -58.500},
	{118.893, 0.020, -6.931, 582.673, 0.000, 0.010, 106.000, -58.500},
	{118.893, 0.000, -2.009, 492.213, 0.000, 0.010, 106.000, -58.500}};
};

#endif