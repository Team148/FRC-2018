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
	int num_index = 237;
	double left_wheel[237][8] ={ 
	{0.000, 0.058, 5.826, 582.601, 6.283, 0.010, 0.000, 12.450},
	{0.001, 0.117, 5.826, 0.017, 6.283, 0.010, 0.001, 12.450},
	{0.004, 0.262, 14.566, 873.991, 6.283, 0.010, 0.004, 12.450},
	{0.009, 0.466, 20.395, 582.881, 6.283, 0.010, 0.009, 12.450},
	{0.016, 0.728, 26.227, 583.246, 6.283, 0.010, 0.016, 12.450},
	{0.027, 1.049, 32.066, 583.843, 6.283, 0.010, 0.027, 12.450},
	{0.041, 1.428, 37.913, 584.729, 6.283, 0.010, 0.041, 12.450},
	{0.059, 1.866, 43.773, 585.961, 6.283, 0.010, 0.059, 12.450},
	{0.083, 2.362, 49.649, 587.595, 6.283, 0.010, 0.083, 12.450},
	{0.112, 2.918, 55.546, 589.687, 6.283, 0.010, 0.112, 12.450},
	{0.148, 3.533, 61.468, 592.289, 6.283, 0.010, 0.148, 12.450},
	{0.190, 4.207, 67.423, 595.453, 6.283, 0.010, 0.190, 12.450},
	{0.239, 4.941, 73.415, 599.229, 6.283, 0.010, 0.239, 12.450},
	{0.296, 5.735, 79.452, 603.665, 6.283, 0.010, 0.296, 12.450},
	{0.362, 6.591, 85.540, 608.803, 6.283, 0.010, 0.362, 12.450},
	{0.437, 7.508, 91.687, 614.685, 6.283, 0.010, 0.437, 12.450},
	{0.522, 8.487, 97.900, 621.348, 6.283, 0.010, 0.522, 12.450},
	{0.617, 9.499, 101.245, 334.505, 6.283, 0.010, 0.617, 12.450},
	{0.722, 10.516, 101.705, 45.977, 6.283, 0.010, 0.722, 12.450},
	{0.838, 11.538, 102.209, 50.438, 6.283, 0.010, 0.838, 12.450},
	{0.963, 12.566, 102.757, 54.795, 6.283, 0.010, 0.963, 12.450},
	{1.099, 13.599, 103.348, 59.042, 6.282, 0.010, 1.099, 12.450},
	{1.246, 14.639, 103.980, 63.173, 6.282, 0.010, 1.246, 12.450},
	{1.403, 15.686, 104.651, 67.183, 6.282, 0.010, 1.403, 12.449},
	{1.570, 16.739, 105.362, 71.071, 6.282, 0.010, 1.570, 12.449},
	{1.748, 17.800, 106.110, 74.831, 6.281, 0.010, 1.748, 12.449},
	{1.937, 18.869, 106.895, 78.466, 6.281, 0.010, 1.937, 12.448},
	{2.136, 19.946, 107.715, 81.972, 6.280, 0.010, 2.136, 12.448},
	{2.347, 21.032, 108.568, 85.350, 6.280, 0.010, 2.347, 12.447},
	{2.568, 22.127, 109.454, 88.603, 6.279, 0.010, 2.568, 12.446},
	{2.800, 23.230, 110.372, 91.727, 6.278, 0.010, 2.800, 12.445},
	{3.044, 24.344, 111.319, 94.729, 6.277, 0.010, 3.044, 12.444},
	{3.298, 25.467, 112.295, 97.609, 6.276, 0.010, 3.298, 12.442},
	{3.564, 26.600, 113.299, 100.367, 6.275, 0.010, 3.564, 12.440},
	{3.842, 27.743, 114.329, 103.009, 6.274, 0.010, 3.842, 12.438},
	{4.131, 28.897, 115.384, 105.536, 6.273, 0.010, 4.131, 12.435},
	{4.431, 30.061, 116.464, 107.948, 6.271, 0.010, 4.431, 12.432},
	{4.744, 31.237, 117.566, 110.248, 6.270, 0.010, 4.744, 12.428},
	{5.068, 32.424, 118.690, 112.433, 6.268, 0.010, 5.068, 12.423},
	{5.404, 33.622, 119.835, 114.505, 6.266, 0.010, 5.404, 12.418},
	{5.752, 34.832, 121.000, 116.460, 6.264, 0.010, 5.752, 12.412},
	{6.113, 36.054, 122.183, 118.294, 6.262, 0.010, 6.113, 12.404},
	{6.486, 37.288, 123.383, 120.000, 6.259, 0.010, 6.485, 12.396},
	{6.871, 38.534, 124.599, 121.569, 6.256, 0.010, 6.871, 12.386},
	{7.269, 39.792, 125.829, 122.989, 6.253, 0.010, 7.268, 12.375},
	{7.680, 41.063, 127.071, 124.244, 6.250, 0.010, 7.679, 12.362},
	{8.103, 42.346, 128.324, 125.318, 6.247, 0.010, 8.102, 12.347},
	{8.540, 43.642, 129.586, 126.185, 6.243, 0.010, 8.538, 12.330},
	{8.989, 44.951, 130.854, 126.816, 6.239, 0.010, 8.987, 12.312},
	{9.452, 46.272, 132.126, 127.185, 6.235, 0.010, 9.449, 12.290},
	{9.928, 47.606, 133.398, 127.247, 6.231, 0.010, 9.925, 12.266},
	{10.417, 48.952, 134.668, 126.960, 6.226, 0.010, 10.414, 12.240},
	{10.921, 50.312, 135.931, 126.275, 6.221, 0.010, 10.916, 12.210},
	{11.437, 51.684, 137.182, 125.133, 6.216, 0.010, 11.432, 12.176},
	{11.968, 53.068, 138.417, 123.473, 6.210, 0.010, 11.961, 12.139},
	{12.513, 54.464, 139.629, 121.219, 6.204, 0.010, 12.504, 12.098},
	{13.071, 55.872, 140.812, 118.299, 6.198, 0.010, 13.061, 12.052},
	{13.644, 57.292, 141.958, 114.618, 6.191, 0.010, 13.632, 12.001},
	{14.232, 58.722, 143.059, 110.098, 6.184, 0.010, 14.216, 11.945},
	{14.833, 60.163, 144.105, 104.622, 6.177, 0.010, 14.815, 11.883},
	{15.449, 61.614, 145.086, 98.103, 6.169, 0.010, 15.427, 11.816},
	{16.080, 63.074, 145.991, 90.422, 6.161, 0.010, 16.053, 11.741},
	{16.725, 64.542, 146.805, 81.472, 6.153, 0.010, 16.694, 11.660},
	{17.386, 66.017, 147.517, 71.141, 6.144, 0.010, 17.348, 11.571},
	{18.061, 67.498, 148.110, 59.321, 6.134, 0.010, 18.016, 11.474},
	{18.750, 68.984, 148.569, 45.910, 6.125, 0.010, 18.698, 11.369},
	{19.455, 70.473, 148.877, 30.812, 6.115, 0.010, 19.393, 11.254},
	{20.175, 71.963, 149.017, 13.949, 6.104, 0.010, 20.102, 11.129},
	{20.909, 73.453, 148.969, -4.738, 6.093, 0.010, 20.824, 10.995},
	{21.659, 74.940, 148.717, -25.285, 6.082, 0.010, 21.559, 10.849},
	{22.423, 76.422, 148.240, -47.700, 6.070, 0.010, 22.307, 10.692},
	{23.202, 77.898, 147.520, -71.947, 6.058, 0.010, 23.067, 10.523},
	{23.996, 79.363, 146.541, -97.954, 6.046, 0.010, 23.840, 10.341},
	{24.804, 80.816, 145.284, -125.601, 6.033, 0.010, 24.624, 10.146},
	{25.626, 82.253, 143.737, -154.712, 6.020, 0.010, 25.420, 9.938},
	{26.463, 83.672, 141.887, -185.058, 6.006, 0.010, 26.226, 9.714},
	{27.314, 85.069, 139.723, -216.355, 5.993, 0.010, 27.043, 9.476},
	{28.178, 86.442, 137.241, -248.259, 5.978, 0.010, 27.869, 9.223},
	{29.056, 87.786, 134.437, -280.373, 5.964, 0.010, 28.705, 8.953},
	{29.947, 89.099, 131.314, -312.257, 5.949, 0.010, 29.549, 8.668},
	{30.851, 90.378, 127.880, -343.434, 5.934, 0.010, 30.400, 8.365},
	{31.767, 91.619, 124.146, -373.394, 5.919, 0.010, 31.259, 8.045},
	{32.695, 92.821, 120.130, -401.626, 5.904, 0.010, 32.124, 7.708},
	{33.635, 93.979, 115.854, -427.620, 5.889, 0.010, 32.994, 7.354},
	{34.586, 95.093, 111.345, -450.894, 5.873, 0.010, 33.869, 6.981},
	{35.547, 96.159, 106.635, -471.010, 5.857, 0.010, 34.748, 6.591},
	{36.519, 97.177, 101.759, -487.591, 5.842, 0.010, 35.630, 6.183},
	{37.501, 98.144, 96.755, -500.342, 5.826, 0.010, 36.514, 5.757},
	{38.491, 99.061, 91.665, -509.059, 5.811, 0.010, 37.399, 5.313},
	{39.491, 99.926, 86.528, -513.642, 5.795, 0.010, 38.286, 4.851},
	{40.498, 100.740, 81.387, -514.097, 5.780, 0.010, 39.172, 4.372},
	{41.513, 101.503, 76.282, -510.545, 5.765, 0.010, 40.057, 3.876},
	{42.535, 102.215, 71.250, -503.199, 5.750, 0.010, 40.941, 3.363},
	{43.564, 102.879, 66.326, -492.383, 5.735, 0.010, 41.824, 2.834},
	{44.599, 103.494, 61.541, -478.489, 5.721, 0.010, 42.703, 2.288},
	{45.639, 104.063, 56.921, -461.984, 5.707, 0.010, 43.580, 1.728},
	{46.685, 104.588, 52.488, -443.372, 5.694, 0.010, 44.453, 1.152},
	{47.736, 105.071, 48.256, -423.202, 5.680, 0.010, 45.322, 0.562},
	{48.791, 105.513, 44.235, -402.021, 5.668, 0.010, 46.188, -0.042},
	{49.850, 105.917, 40.432, -380.369, 5.655, 0.010, 47.049, -0.659},
	{50.913, 106.286, 36.844, -358.777, 5.644, 0.010, 47.905, -1.288},
	{51.979, 106.620, 33.467, -337.726, 5.632, 0.010, 48.757, -1.930},
	{53.048, 106.890, 26.975, -649.134, 5.622, 0.010, 49.604, -2.582},
	{54.119, 107.065, 17.489, -948.634, 5.611, 0.010, 50.445, -3.244},
	{55.190, 107.149, 8.388, -910.045, 5.602, 0.010, 51.281, -3.915},
	{56.262, 107.146, -0.343, -873.120, 5.593, 0.010, 52.110, -4.593},
	{57.333, 107.058, -8.725, -838.259, 5.585, 0.010, 52.933, -5.278},
	{58.401, 106.890, -16.783, -805.765, 5.577, 0.010, 53.749, -5.969},
	{59.468, 106.645, -24.541, -775.817, 5.570, 0.010, 54.558, -6.663},
	{60.531, 106.325, -32.026, -748.490, 5.564, 0.010, 55.360, -7.361},
	{61.590, 105.932, -39.264, -723.778, 5.559, 0.010, 56.155, -8.061},
	{62.645, 105.469, -46.280, -701.581, 5.554, 0.010, 56.943, -8.762},
	{63.695, 104.938, -53.097, -681.743, 5.550, 0.010, 57.725, -9.462},
	{64.738, 104.341, -59.737, -664.042, 5.547, 0.010, 58.499, -10.162},
	{65.775, 103.679, -66.220, -648.215, 5.544, 0.010, 59.266, -10.859},
	{66.804, 102.953, -72.559, -633.958, 5.543, 0.010, 60.027, -11.553},
	{67.826, 102.166, -78.769, -620.945, 5.542, 0.010, 60.780, -12.243},
	{68.839, 101.308, -85.760, -699.091, 5.541, 0.010, 61.527, -12.927},
	{69.843, 100.353, -95.483, -972.314, 5.542, 0.010, 62.267, -13.605},
	{70.836, 99.312, -104.064, -858.092, 5.543, 0.010, 63.000, -14.275},
	{71.818, 98.217, -109.591, -552.784, 5.545, 0.010, 63.726, -14.937},
	{72.788, 97.067, -114.996, -540.419, 5.548, 0.010, 64.445, -15.589},
	{73.747, 95.864, -120.266, -527.054, 5.551, 0.010, 65.157, -16.231},
	{74.693, 94.610, -125.390, -512.341, 5.556, 0.010, 65.862, -16.862},
	{75.626, 93.307, -130.349, -495.958, 5.560, 0.010, 66.560, -17.481},
	{76.546, 91.955, -135.125, -477.615, 5.566, 0.010, 67.251, -18.087},
	{77.451, 90.558, -139.696, -457.062, 5.572, 0.010, 67.936, -18.680},
	{78.343, 89.118, -144.037, -434.095, 5.580, 0.010, 68.613, -19.259},
	{79.219, 87.637, -148.123, -408.571, 5.587, 0.010, 69.284, -19.824},
	{80.080, 86.117, -151.927, -380.425, 5.596, 0.010, 69.947, -20.373},
	{80.926, 84.563, -155.424, -349.666, 5.605, 0.010, 70.603, -20.907},
	{81.756, 82.977, -158.588, -316.409, 5.615, 0.010, 71.251, -21.424},
	{82.569, 81.363, -161.396, -280.866, 5.625, 0.010, 71.892, -21.926},
	{83.366, 79.725, -163.830, -243.368, 5.636, 0.010, 72.526, -22.410},
	{84.147, 78.074, -165.113, -128.297, 5.647, 0.010, 73.151, -22.877},
	{84.912, 76.438, -163.602, 151.125, 5.659, 0.010, 73.769, -23.328},
	{85.660, 74.836, -160.160, 344.172, 5.671, 0.010, 74.379, -23.761},
	{86.393, 73.271, -156.505, 365.449, 5.684, 0.010, 74.981, -24.178},
	{87.110, 71.745, -152.634, 387.120, 5.698, 0.010, 75.576, -24.579},
	{87.813, 70.259, -148.547, 408.690, 5.711, 0.010, 76.165, -24.963},
	{88.501, 68.817, -144.251, 429.624, 5.726, 0.010, 76.746, -25.331},
	{89.175, 67.419, -139.757, 449.376, 5.740, 0.010, 77.320, -25.684},
	{89.836, 66.069, -135.083, 467.398, 5.755, 0.010, 77.888, -26.021},
	{90.483, 64.766, -130.252, 483.152, 5.770, 0.010, 78.450, -26.344},
	{91.119, 63.513, -125.290, 496.144, 5.785, 0.010, 79.006, -26.652},
	{91.742, 62.311, -120.231, 505.928, 5.800, 0.010, 79.555, -26.945},
	{92.353, 61.160, -115.110, 512.129, 5.816, 0.010, 80.099, -27.225},
	{92.954, 60.060, -109.965, 514.461, 5.831, 0.010, 80.637, -27.492},
	{93.544, 59.012, -104.838, 512.734, 5.847, 0.010, 81.170, -27.746},
	{94.124, 58.014, -99.769, 506.866, 5.862, 0.010, 81.698, -27.987},
	{94.695, 57.066, -94.800, 496.882, 5.878, 0.010, 82.220, -28.216},
	{95.256, 56.166, -89.971, 482.915, 5.893, 0.010, 82.738, -28.433},
	{95.810, 55.313, -85.319, 465.200, 5.909, 0.010, 83.251, -28.640},
	{96.355, 54.504, -80.879, 444.058, 5.924, 0.010, 83.760, -28.835},
	{96.892, 53.738, -76.680, 419.887, 5.939, 0.010, 84.265, -29.020},
	{97.422, 53.010, -72.748, 393.141, 5.954, 0.010, 84.765, -29.195},
	{97.945, 52.319, -69.105, 364.313, 5.969, 0.010, 85.261, -29.361},
	{98.462, 51.661, -65.766, 333.915, 5.983, 0.010, 85.754, -29.517},
	{98.972, 51.034, -62.741, 302.462, 5.997, 0.010, 86.242, -29.665},
	{99.477, 50.434, -60.037, 270.450, 6.011, 0.010, 86.727, -29.804},
	{99.975, 49.857, -57.653, 238.350, 6.024, 0.010, 87.208, -29.935},
	{100.468, 49.301, -55.588, 206.590, 6.037, 0.010, 87.685, -30.058},
	{100.956, 48.763, -53.832, 175.548, 6.050, 0.010, 88.159, -30.174},
	{101.438, 48.239, -52.377, 145.552, 6.062, 0.010, 88.629, -30.283},
	{101.915, 47.727, -51.208, 116.870, 6.074, 0.010, 89.095, -30.385},
	{102.388, 47.224, -50.311, 89.710, 6.086, 0.010, 89.558, -30.480},
	{102.855, 46.727, -49.668, 64.235, 6.097, 0.010, 90.017, -30.569},
	{103.317, 46.235, -49.263, 40.548, 6.107, 0.010, 90.471, -30.652},
	{103.775, 45.744, -49.076, 18.707, 6.118, 0.010, 90.922, -30.730},
	{104.227, 45.253, -49.089, -1.262, 6.128, 0.010, 91.369, -30.802},
	{104.675, 44.760, -49.282, -19.382, 6.137, 0.010, 91.811, -30.869},
	{105.117, 44.264, -49.639, -35.691, 6.146, 0.010, 92.250, -30.932},
	{105.555, 43.762, -50.142, -50.256, 6.155, 0.010, 92.683, -30.989},
	{105.988, 43.255, -50.773, -63.166, 6.164, 0.010, 93.113, -31.043},
	{106.415, 42.739, -51.519, -74.513, 6.172, 0.010, 93.537, -31.092},
	{106.837, 42.216, -52.363, -84.403, 6.179, 0.010, 93.957, -31.138},
	{107.254, 41.683, -53.292, -92.948, 6.186, 0.010, 94.372, -31.179},
	{107.665, 41.140, -54.295, -100.257, 6.193, 0.010, 94.781, -31.218},
	{108.071, 40.586, -55.359, -106.441, 6.200, 0.010, 95.186, -31.253},
	{108.471, 40.022, -56.475, -111.608, 6.206, 0.010, 95.584, -31.285},
	{108.866, 39.445, -57.634, -115.859, 6.212, 0.010, 95.978, -31.314},
	{109.255, 38.857, -58.827, -119.291, 6.217, 0.010, 96.366, -31.341},
	{109.637, 38.256, -60.047, -121.997, 6.223, 0.010, 96.747, -31.365},
	{110.014, 37.644, -61.287, -124.057, 6.228, 0.010, 97.123, -31.387},
	{110.384, 37.018, -62.543, -125.548, 6.232, 0.010, 97.493, -31.406},
	{110.747, 36.380, -63.808, -126.541, 6.237, 0.010, 97.856, -31.424},
	{111.105, 35.729, -65.079, -127.097, 6.241, 0.010, 98.213, -31.440},
	{111.455, 35.066, -66.352, -127.268, 6.244, 0.010, 98.563, -31.454},
	{111.799, 34.390, -67.623, -127.107, 6.248, 0.010, 98.907, -31.467},
	{112.136, 33.701, -68.889, -126.653, 6.251, 0.010, 99.244, -31.478},
	{112.466, 32.999, -70.149, -125.944, 6.254, 0.010, 99.574, -31.488},
	{112.789, 32.285, -71.399, -125.009, 6.257, 0.010, 99.896, -31.497},
	{113.105, 31.559, -72.638, -123.876, 6.260, 0.010, 100.212, -31.505},
	{113.413, 30.820, -73.863, -122.568, 6.262, 0.010, 100.520, -31.512},
	{113.714, 30.069, -75.074, -121.099, 6.265, 0.010, 100.821, -31.518},
	{114.007, 29.307, -76.269, -119.485, 6.267, 0.010, 101.114, -31.523},
	{114.292, 28.532, -77.447, -117.741, 6.268, 0.010, 101.399, -31.528},
	{114.570, 27.746, -78.605, -115.866, 6.270, 0.010, 101.676, -31.531},
	{114.839, 26.949, -79.744, -113.875, 6.272, 0.010, 101.946, -31.535},
	{115.100, 26.140, -80.862, -111.767, 6.273, 0.010, 102.207, -31.537},
	{115.354, 25.321, -81.957, -109.544, 6.275, 0.010, 102.461, -31.540},
	{115.599, 24.490, -83.029, -107.211, 6.276, 0.010, 102.705, -31.542},
	{115.835, 23.650, -84.077, -104.762, 6.277, 0.010, 102.942, -31.543},
	{116.063, 22.799, -85.099, -102.201, 6.278, 0.010, 103.170, -31.545},
	{116.282, 21.938, -86.094, -99.521, 6.278, 0.010, 103.389, -31.546},
	{116.493, 21.067, -87.061, -96.725, 6.279, 0.010, 103.600, -31.547},
	{116.695, 20.187, -87.999, -93.808, 6.280, 0.010, 103.802, -31.548},
	{116.888, 19.298, -88.907, -90.768, 6.280, 0.010, 103.995, -31.548},
	{117.072, 18.400, -89.783, -87.604, 6.281, 0.010, 104.179, -31.549},
	{117.247, 17.494, -90.626, -84.313, 6.281, 0.010, 104.354, -31.549},
	{117.413, 16.579, -91.435, -80.895, 6.282, 0.010, 104.520, -31.549},
	{117.569, 15.657, -92.209, -77.349, 6.282, 0.010, 104.676, -31.549},
	{117.716, 14.728, -92.945, -73.675, 6.282, 0.010, 104.823, -31.550},
	{117.854, 13.791, -93.644, -69.875, 6.282, 0.010, 104.961, -31.550},
	{117.983, 12.848, -94.304, -65.949, 6.283, 0.010, 105.090, -31.550},
	{118.102, 11.899, -94.923, -61.901, 6.283, 0.010, 105.209, -31.550},
	{118.211, 10.944, -95.500, -57.734, 6.283, 0.010, 105.318, -31.550},
	{118.311, 9.984, -96.034, -53.452, 6.283, 0.010, 105.418, -31.550},
	{118.401, 9.019, -96.525, -49.062, 6.283, 0.010, 105.508, -31.550},
	{118.482, 8.058, -96.073, 45.197, 6.283, 0.010, 105.589, -31.550},
	{118.553, 7.131, -92.675, 339.831, 6.283, 0.010, 105.660, -31.550},
	{118.616, 6.259, -87.215, 545.971, 6.283, 0.010, 105.723, -31.550},
	{118.670, 5.442, -81.691, 552.390, 6.283, 0.010, 105.777, -31.550},
	{118.717, 4.681, -76.111, 558.039, 6.283, 0.010, 105.824, -31.550},
	{118.757, 3.976, -70.481, 562.957, 6.283, 0.010, 105.864, -31.550},
	{118.790, 3.328, -64.809, 567.185, 6.283, 0.010, 105.897, -31.550},
	{118.817, 2.737, -59.102, 570.768, 6.283, 0.010, 105.924, -31.550},
	{118.839, 2.203, -53.364, 573.755, 6.283, 0.010, 105.946, -31.550},
	{118.857, 1.727, -47.602, 576.195, 6.283, 0.010, 105.964, -31.550},
	{118.870, 1.309, -41.821, 578.141, 6.283, 0.010, 105.977, -31.550},
	{118.879, 0.949, -36.024, 579.648, 6.283, 0.010, 105.986, -31.550},
	{118.886, 0.647, -30.217, 580.769, 6.283, 0.010, 105.993, -31.550},
	{118.890, 0.403, -24.401, 581.561, 6.283, 0.010, 105.997, -31.550},
	{118.892, 0.217, -18.580, 582.082, 6.283, 0.010, 105.999, -31.550},
	{118.893, 0.089, -12.756, 582.389, 6.283, 0.010, 106.000, -31.550},
	{118.893, 0.020, -6.931, 582.539, 0.000, 0.010, 106.000, -31.550},
	{118.893, 0.000, -2.009, 492.193, 0.000, 0.010, 106.000, -31.550}};
	double right_wheel[237][8] ={ 
	{0.000, 0.058, 5.826, 582.601, 6.283, 0.010, 0.000, -12.450},
	{0.001, 0.117, 5.826, -0.017, 6.283, 0.010, 0.001, -12.450},
	{0.004, 0.262, 14.564, 873.812, 6.283, 0.010, 0.004, -12.450},
	{0.009, 0.466, 20.387, 582.320, 6.283, 0.010, 0.009, -12.450},
	{0.016, 0.728, 26.207, 581.956, 6.283, 0.010, 0.016, -12.450},
	{0.027, 1.048, 32.020, 581.359, 6.283, 0.010, 0.027, -12.450},
	{0.041, 1.427, 37.825, 580.473, 6.283, 0.010, 0.041, -12.450},
	{0.059, 1.863, 43.617, 579.241, 6.283, 0.010, 0.059, -12.450},
	{0.083, 2.357, 49.394, 577.607, 6.283, 0.010, 0.083, -12.450},
	{0.112, 2.908, 55.149, 575.515, 6.283, 0.010, 0.112, -12.450},
	{0.147, 3.517, 60.878, 572.913, 6.283, 0.010, 0.147, -12.450},
	{0.189, 4.183, 66.575, 569.749, 6.283, 0.010, 0.189, -12.450},
	{0.238, 4.905, 72.235, 565.972, 6.283, 0.010, 0.238, -12.450},
	{0.295, 5.684, 77.850, 561.537, 6.283, 0.010, 0.295, -12.450},
	{0.360, 6.518, 83.414, 556.399, 6.283, 0.010, 0.360, -12.450},
	{0.434, 7.407, 88.920, 550.517, 6.283, 0.010, 0.434, -12.450},
	{0.518, 8.350, 94.358, 543.854, 6.283, 0.010, 0.518, -12.450},
	{0.611, 9.319, 96.839, 248.096, 6.283, 0.010, 0.611, -12.450},
	{0.714, 10.283, 96.379, -45.977, 6.283, 0.010, 0.714, -12.450},
	{0.826, 11.241, 95.875, -50.438, 6.283, 0.010, 0.826, -12.450},
	{0.948, 12.195, 95.327, -54.796, 6.283, 0.010, 0.948, -12.450},
	{1.079, 13.142, 94.737, -59.042, 6.282, 0.010, 1.079, -12.450},
	{1.220, 14.083, 94.105, -63.173, 6.282, 0.010, 1.220, -12.450},
	{1.370, 15.017, 93.433, -67.183, 6.282, 0.010, 1.370, -12.451},
	{1.530, 15.945, 92.722, -71.070, 6.282, 0.010, 1.530, -12.451},
	{1.699, 16.864, 91.974, -74.832, 6.281, 0.010, 1.699, -12.451},
	{1.876, 17.776, 91.189, -78.466, 6.281, 0.010, 1.876, -12.452},
	{2.063, 18.680, 90.370, -81.973, 6.280, 0.010, 2.063, -12.452},
	{2.259, 19.575, 89.516, -85.352, 6.280, 0.010, 2.259, -12.453},
	{2.463, 20.461, 88.630, -88.602, 6.279, 0.010, 2.463, -12.453},
	{2.677, 21.339, 87.713, -91.729, 6.278, 0.010, 2.677, -12.454},
	{2.899, 22.206, 86.765, -94.730, 6.277, 0.010, 2.899, -12.456},
	{3.130, 23.064, 85.789, -97.608, 6.276, 0.010, 3.130, -12.457},
	{3.369, 23.912, 84.786, -100.369, 6.275, 0.010, 3.369, -12.459},
	{3.616, 24.749, 83.756, -103.011, 6.274, 0.010, 3.616, -12.461},
	{3.872, 25.576, 82.700, -105.537, 6.273, 0.010, 3.872, -12.463},
	{4.136, 26.393, 81.621, -107.950, 6.271, 0.010, 4.136, -12.466},
	{4.408, 27.198, 80.518, -110.249, 6.270, 0.010, 4.408, -12.470},
	{4.688, 27.992, 79.394, -112.436, 6.268, 0.010, 4.688, -12.474},
	{4.976, 28.774, 78.249, -114.509, 6.266, 0.010, 4.975, -12.478},
	{5.271, 29.545, 77.084, -116.464, 6.264, 0.010, 5.271, -12.484},
	{5.574, 30.304, 75.901, -118.298, 6.262, 0.010, 5.574, -12.490},
	{5.885, 31.051, 74.701, -120.005, 6.259, 0.010, 5.884, -12.497},
	{6.202, 31.786, 73.485, -121.574, 6.256, 0.010, 6.202, -12.505},
	{6.527, 32.509, 72.255, -122.995, 6.253, 0.010, 6.527, -12.514},
	{6.860, 33.219, 71.013, -124.252, 6.250, 0.010, 6.859, -12.525},
	{7.199, 33.916, 69.760, -125.325, 6.247, 0.010, 7.198, -12.537},
	{7.545, 34.601, 68.498, -126.192, 6.243, 0.010, 7.544, -12.550},
	{7.898, 35.274, 67.229, -126.828, 6.239, 0.010, 7.896, -12.565},
	{8.257, 35.933, 65.957, -127.194, 6.235, 0.010, 8.255, -12.581},
	{8.623, 36.580, 64.685, -127.258, 6.231, 0.010, 8.620, -12.599},
	{8.995, 37.214, 63.415, -126.973, 6.226, 0.010, 8.992, -12.620},
	{9.373, 37.836, 62.152, -126.288, 6.221, 0.010, 9.370, -12.642},
	{9.758, 38.445, 60.901, -125.149, 6.216, 0.010, 9.753, -12.667},
	{10.148, 39.041, 59.666, -123.488, 6.210, 0.010, 10.143, -12.695},
	{10.544, 39.626, 58.453, -121.239, 6.204, 0.010, 10.538, -12.725},
	{10.946, 40.199, 57.270, -118.316, 6.198, 0.010, 10.938, -12.758},
	{11.354, 40.760, 56.124, -114.643, 6.191, 0.010, 11.344, -12.794},
	{11.767, 41.310, 55.023, -110.116, 6.184, 0.010, 11.756, -12.833},
	{12.186, 41.850, 53.976, -104.650, 6.177, 0.010, 12.172, -12.876},
	{12.609, 42.380, 52.995, -98.127, 6.169, 0.010, 12.593, -12.923},
	{13.038, 42.901, 52.090, -90.448, 6.161, 0.010, 13.019, -12.973},
	{13.472, 43.413, 51.276, -81.499, 6.153, 0.010, 13.450, -13.028},
	{13.912, 43.919, 50.564, -71.170, 6.144, 0.010, 13.885, -13.087},
	{14.356, 44.419, 49.970, -59.351, 6.134, 0.010, 14.325, -13.151},
	{14.805, 44.914, 49.511, -45.939, 6.125, 0.010, 14.769, -13.220},
	{15.259, 45.406, 49.202, -30.842, 6.115, 0.010, 15.217, -13.293},
	{15.718, 45.897, 49.063, -13.980, 6.104, 0.010, 15.669, -13.373},
	{16.182, 46.388, 49.110, 4.709, 6.093, 0.010, 16.125, -13.458},
	{16.651, 46.881, 49.362, 25.258, 6.082, 0.010, 16.584, -13.549},
	{17.124, 47.380, 49.839, 47.673, 6.070, 0.010, 17.048, -13.646},
	{17.603, 47.885, 50.558, 71.923, 6.058, 0.010, 17.516, -13.750},
	{18.087, 48.401, 51.538, 97.934, 6.046, 0.010, 17.987, -13.861},
	{18.577, 48.929, 52.793, 125.583, 6.033, 0.010, 18.462, -13.979},
	{19.071, 49.472, 54.340, 154.699, 6.020, 0.010, 18.940, -14.105},
	{19.572, 50.034, 56.191, 185.052, 6.006, 0.010, 19.422, -14.238},
	{20.078, 50.617, 58.355, 216.354, 5.993, 0.010, 19.908, -14.380},
	{20.590, 51.226, 60.837, 248.263, 5.978, 0.010, 20.398, -14.530},
	{21.109, 51.862, 63.641, 280.386, 5.964, 0.010, 20.892, -14.689},
	{21.634, 52.530, 66.764, 312.279, 5.949, 0.010, 21.389, -14.858},
	{22.166, 53.232, 70.198, 343.462, 5.934, 0.010, 21.891, -15.036},
	{22.706, 53.971, 73.933, 373.432, 5.919, 0.010, 22.397, -15.224},
	{23.254, 54.751, 77.949, 401.671, 5.904, 0.010, 22.907, -15.423},
	{23.809, 55.573, 82.226, 427.674, 5.889, 0.010, 23.421, -15.633},
	{24.374, 56.440, 86.736, 450.956, 5.873, 0.010, 23.941, -15.854},
	{24.947, 57.355, 91.447, 471.079, 5.857, 0.010, 24.465, -16.086},
	{25.530, 58.318, 96.323, 487.667, 5.842, 0.010, 24.994, -16.331},
	{26.124, 59.331, 101.327, 500.423, 5.826, 0.010, 25.529, -16.589},
	{26.728, 60.395, 106.419, 509.144, 5.811, 0.010, 26.068, -16.860},
	{27.343, 61.511, 111.556, 513.729, 5.795, 0.010, 26.614, -17.144},
	{27.970, 62.678, 116.698, 514.188, 5.780, 0.010, 27.165, -17.442},
	{28.609, 63.896, 121.804, 510.633, 5.765, 0.010, 27.723, -17.754},
	{29.260, 65.164, 126.837, 503.289, 5.750, 0.010, 28.286, -18.081},
	{29.925, 66.482, 131.762, 492.469, 5.735, 0.010, 28.856, -18.423},
	{30.603, 67.847, 136.548, 478.571, 5.721, 0.010, 29.433, -18.781},
	{31.296, 69.259, 141.168, 462.058, 5.707, 0.010, 30.017, -19.154},
	{32.003, 70.715, 145.603, 443.444, 5.694, 0.010, 30.607, -19.543},
	{32.725, 72.214, 149.835, 423.265, 5.680, 0.010, 31.204, -19.949},
	{33.463, 73.752, 153.856, 402.073, 5.668, 0.010, 31.809, -20.371},
	{34.216, 75.329, 157.660, 380.417, 5.655, 0.010, 32.422, -20.810},
	{34.986, 76.941, 161.248, 358.813, 5.644, 0.010, 33.042, -21.265},
	{35.771, 78.587, 164.626, 337.756, 5.632, 0.010, 33.669, -21.738},
	{36.574, 80.240, 165.292, 66.561, 5.622, 0.010, 34.305, -22.228},
	{37.393, 81.872, 163.126, -216.547, 5.611, 0.010, 34.948, -22.734},
	{38.227, 83.477, 160.575, -255.146, 5.602, 0.010, 35.599, -23.257},
	{39.078, 85.054, 157.654, -292.091, 5.593, 0.010, 36.258, -23.795},
	{39.944, 86.598, 154.384, -326.960, 5.585, 0.010, 36.923, -24.349},
	{40.825, 88.106, 150.789, -359.468, 5.577, 0.010, 37.596, -24.918},
	{41.721, 89.575, 146.895, -389.429, 5.570, 0.010, 38.275, -25.502},
	{42.631, 91.002, 142.728, -416.763, 5.564, 0.010, 38.962, -26.099},
	{43.555, 92.385, 138.313, -441.486, 5.559, 0.010, 39.655, -26.709},
	{44.492, 93.722, 133.676, -463.689, 5.554, 0.010, 40.356, -27.332},
	{45.442, 95.010, 128.840, -483.535, 5.550, 0.010, 41.063, -27.967},
	{46.404, 96.248, 123.828, -501.241, 5.547, 0.010, 41.777, -28.612},
	{47.379, 97.435, 118.657, -517.074, 5.544, 0.010, 42.498, -29.267},
	{48.364, 98.568, 113.344, -531.332, 5.543, 0.010, 43.227, -29.932},
	{49.361, 99.647, 107.900, -544.349, 5.542, 0.010, 43.962, -30.604},
	{50.367, 100.662, 101.430, -647.003, 5.541, 0.010, 44.704, -31.284},
	{51.383, 101.580, 91.867, -956.382, 5.542, 0.010, 45.453, -31.971},
	{52.407, 102.410, 82.969, -889.806, 5.543, 0.010, 46.209, -32.662},
	{53.439, 103.179, 76.843, -612.512, 5.545, 0.010, 46.971, -33.357},
	{54.478, 103.884, 70.595, -624.873, 5.548, 0.010, 47.740, -34.055},
	{55.523, 104.527, 64.212, -638.237, 5.551, 0.010, 48.517, -34.755},
	{56.574, 105.103, 57.683, -652.946, 5.556, 0.010, 49.300, -35.455},
	{57.630, 105.613, 50.990, -669.323, 5.560, 0.010, 50.090, -36.156},
	{58.691, 106.054, 44.113, -687.659, 5.566, 0.010, 50.888, -36.855},
	{59.755, 106.425, 37.031, -708.207, 5.572, 0.010, 51.692, -37.552},
	{60.822, 106.722, 29.719, -731.167, 5.580, 0.010, 52.503, -38.246},
	{61.892, 106.943, 22.152, -756.679, 5.587, 0.010, 53.321, -38.934},
	{62.963, 107.087, 14.304, -784.818, 5.596, 0.010, 54.146, -39.617},
	{64.034, 107.148, 6.149, -815.562, 5.605, 0.010, 54.977, -40.294},
	{65.105, 107.125, -2.339, -848.809, 5.615, 0.010, 55.815, -40.962},
	{66.176, 107.013, -11.183, -884.337, 5.625, 0.010, 56.658, -41.621},
	{67.244, 106.809, -20.401, -921.820, 5.636, 0.010, 57.506, -42.270},
	{68.309, 106.519, -28.962, -856.085, 5.647, 0.010, 58.359, -42.908},
	{69.371, 106.174, -34.491, -552.897, 5.659, 0.010, 59.217, -43.533},
	{70.429, 105.795, -37.932, -344.144, 5.671, 0.010, 60.079, -44.146},
	{71.482, 105.379, -41.586, -365.408, 5.684, 0.010, 60.946, -44.746},
	{72.532, 104.924, -45.457, -387.072, 5.698, 0.010, 61.816, -45.332},
	{73.576, 104.429, -49.543, -408.631, 5.711, 0.010, 62.691, -45.903},
	{74.615, 103.891, -53.839, -429.560, 5.726, 0.010, 63.568, -46.459},
	{75.648, 103.307, -58.332, -449.306, 5.740, 0.010, 64.449, -46.999},
	{76.675, 102.677, -63.005, -467.318, 5.755, 0.010, 65.332, -47.523},
	{77.695, 101.999, -67.836, -483.070, 5.770, 0.010, 66.216, -48.031},
	{78.707, 101.271, -72.796, -496.058, 5.785, 0.010, 67.102, -48.522},
	{79.712, 100.492, -77.855, -505.838, 5.800, 0.010, 67.988, -48.996},
	{80.709, 99.663, -82.975, -512.040, 5.816, 0.010, 68.874, -49.452},
	{81.697, 98.781, -88.119, -514.371, 5.831, 0.010, 69.760, -49.890},
	{82.675, 97.849, -93.245, -512.647, 5.847, 0.010, 70.643, -50.311},
	{83.644, 96.866, -98.313, -506.781, 5.862, 0.010, 71.524, -50.714},
	{84.602, 95.833, -103.281, -496.803, 5.878, 0.010, 72.402, -51.098},
	{85.550, 94.752, -108.110, -482.842, 5.893, 0.010, 73.275, -51.465},
	{86.486, 93.624, -112.761, -465.133, 5.909, 0.010, 74.144, -51.814},
	{87.410, 92.452, -117.201, -443.999, 5.924, 0.010, 75.007, -52.146},
	{88.323, 91.238, -121.399, -419.836, 5.939, 0.010, 75.864, -52.460},
	{89.223, 89.985, -125.330, -393.098, 5.954, 0.010, 76.713, -52.758},
	{90.110, 88.695, -128.973, -364.278, 5.969, 0.010, 77.554, -53.038},
	{90.983, 87.372, -132.312, -333.889, 5.983, 0.010, 78.387, -53.303},
	{91.844, 86.019, -135.336, -302.443, 5.997, 0.010, 79.211, -53.551},
	{92.690, 84.638, -138.041, -270.440, 6.011, 0.010, 80.024, -53.785},
	{93.522, 83.234, -140.424, -238.346, 6.024, 0.010, 80.827, -54.004},
	{94.340, 81.809, -142.490, -206.593, 6.037, 0.010, 81.619, -54.208},
	{95.144, 80.367, -144.246, -175.558, 6.050, 0.010, 82.400, -54.399},
	{95.933, 78.910, -145.701, -145.567, 6.062, 0.010, 83.169, -54.577},
	{96.708, 77.441, -146.870, -116.885, 6.074, 0.010, 83.925, -54.742},
	{97.467, 75.963, -147.768, -89.734, 6.086, 0.010, 84.669, -54.895},
	{98.212, 74.479, -148.410, -64.260, 6.097, 0.010, 85.400, -55.037},
	{98.942, 72.991, -148.816, -40.572, 6.107, 0.010, 86.118, -55.169},
	{99.657, 71.501, -149.003, -18.738, 6.118, 0.010, 86.823, -55.290},
	{100.357, 70.011, -148.991, 1.235, 6.128, 0.010, 87.514, -55.402},
	{101.042, 68.523, -148.798, 19.351, 6.137, 0.010, 88.192, -55.505},
	{101.713, 67.039, -148.441, 35.660, 6.146, 0.010, 88.855, -55.599},
	{102.368, 65.559, -147.939, 50.228, 6.155, 0.010, 89.505, -55.686},
	{103.009, 64.086, -147.307, 63.136, 6.164, 0.010, 90.141, -55.765},
	{103.635, 62.621, -146.562, 74.484, 6.172, 0.010, 90.763, -55.837},
	{104.247, 61.164, -145.719, 84.376, 6.179, 0.010, 91.371, -55.903},
	{104.844, 59.716, -144.789, 92.921, 6.186, 0.010, 91.965, -55.963},
	{105.427, 58.278, -143.787, 100.232, 6.193, 0.010, 92.546, -56.017},
	{105.995, 56.851, -142.723, 106.418, 6.200, 0.010, 93.112, -56.066},
	{106.550, 55.435, -141.607, 111.585, 6.206, 0.010, 93.665, -56.111},
	{107.090, 54.030, -140.449, 115.838, 6.212, 0.010, 94.203, -56.151},
	{107.616, 52.637, -139.256, 119.273, 6.217, 0.010, 94.729, -56.187},
	{108.129, 51.257, -138.036, 121.978, 6.223, 0.010, 95.240, -56.219},
	{108.628, 49.889, -136.796, 124.040, 6.228, 0.010, 95.738, -56.248},
	{109.113, 48.534, -135.540, 125.534, 6.232, 0.010, 96.223, -56.274},
	{109.585, 47.191, -134.275, 126.528, 6.237, 0.010, 96.694, -56.297},
	{110.044, 45.861, -133.004, 127.083, 6.241, 0.010, 97.152, -56.318},
	{110.489, 44.544, -131.732, 127.258, 6.244, 0.010, 97.597, -56.336},
	{110.922, 43.239, -130.461, 127.096, 6.248, 0.010, 98.029, -56.352},
	{111.341, 41.947, -129.194, 126.644, 6.251, 0.010, 98.449, -56.366},
	{111.748, 40.668, -127.935, 125.935, 6.254, 0.010, 98.855, -56.378},
	{112.142, 39.401, -126.685, 125.002, 6.257, 0.010, 99.249, -56.389},
	{112.523, 38.146, -125.446, 123.871, 6.260, 0.010, 99.630, -56.398},
	{112.892, 36.904, -124.221, 122.561, 6.262, 0.010, 99.999, -56.407},
	{113.249, 35.674, -123.010, 121.094, 6.265, 0.010, 100.356, -56.414},
	{113.594, 34.456, -121.815, 119.483, 6.267, 0.010, 100.701, -56.420},
	{113.926, 33.250, -120.638, 117.734, 6.268, 0.010, 101.033, -56.425},
	{114.247, 32.055, -119.479, 115.864, 6.270, 0.010, 101.354, -56.429},
	{114.555, 30.871, -118.340, 113.872, 6.272, 0.010, 101.662, -56.433},
	{114.852, 29.699, -117.223, 111.763, 6.273, 0.010, 101.959, -56.436},
	{115.138, 28.538, -116.127, 109.544, 6.275, 0.010, 102.245, -56.439},
	{115.412, 27.387, -115.055, 107.208, 6.276, 0.010, 102.518, -56.441},
	{115.674, 26.247, -114.007, 104.761, 6.277, 0.010, 102.781, -56.443},
	{115.925, 25.117, -112.985, 102.198, 6.278, 0.010, 103.032, -56.444},
	{116.165, 23.998, -111.990, 99.521, 6.278, 0.010, 103.272, -56.446},
	{116.394, 22.887, -111.023, 96.724, 6.279, 0.010, 103.501, -56.447},
	{116.612, 21.786, -110.085, 93.807, 6.280, 0.010, 103.719, -56.447},
	{116.819, 20.695, -109.177, 90.768, 6.280, 0.010, 103.926, -56.448},
	{117.015, 19.612, -108.301, 87.603, 6.281, 0.010, 104.122, -56.449},
	{117.200, 18.537, -107.458, 84.313, 6.281, 0.010, 104.307, -56.449},
	{117.375, 17.471, -106.649, 80.895, 6.282, 0.010, 104.482, -56.449},
	{117.539, 16.412, -105.876, 77.349, 6.282, 0.010, 104.646, -56.449},
	{117.693, 15.360, -105.139, 73.675, 6.282, 0.010, 104.800, -56.450},
	{117.836, 14.316, -104.440, 69.874, 6.282, 0.010, 104.943, -56.450},
	{117.969, 13.278, -103.781, 65.949, 6.283, 0.010, 105.076, -56.450},
	{118.091, 12.247, -103.162, 61.901, 6.283, 0.010, 105.198, -56.450},
	{118.203, 11.221, -102.584, 57.734, 6.283, 0.010, 105.310, -56.450},
	{118.305, 10.200, -102.050, 53.452, 6.283, 0.010, 105.412, -56.450},
	{118.397, 9.185, -101.559, 49.062, 6.283, 0.010, 105.504, -56.450},
	{118.479, 8.183, -100.203, 135.602, 6.283, 0.010, 105.586, -56.450},
	{118.551, 7.223, -95.968, 423.568, 6.283, 0.010, 105.658, -56.450},
	{118.615, 6.325, -89.775, 619.231, 6.283, 0.010, 105.721, -56.450},
	{118.669, 5.489, -83.647, 612.812, 6.283, 0.010, 105.776, -56.450},
	{118.717, 4.713, -77.575, 607.163, 6.283, 0.010, 105.823, -56.450},
	{118.756, 3.997, -71.553, 602.245, 6.283, 0.010, 105.863, -56.450},
	{118.790, 3.342, -65.573, 598.017, 6.283, 0.010, 105.897, -56.450},
	{118.817, 2.745, -59.629, 594.434, 6.283, 0.010, 105.924, -56.450},
	{118.839, 2.208, -53.714, 591.447, 6.283, 0.010, 105.946, -56.450},
	{118.857, 1.730, -47.824, 589.007, 6.283, 0.010, 105.964, -56.450},
	{118.870, 1.311, -41.953, 587.060, 6.283, 0.010, 105.977, -56.450},
	{118.879, 0.950, -36.098, 585.554, 6.283, 0.010, 105.986, -56.450},
	{118.886, 0.647, -30.253, 584.433, 6.283, 0.010, 105.993, -56.450},
	{118.890, 0.403, -24.417, 583.641, 6.283, 0.010, 105.997, -56.450},
	{118.892, 0.217, -18.586, 583.120, 6.283, 0.010, 105.999, -56.450},
	{118.893, 0.089, -12.758, 582.813, 6.283, 0.010, 106.000, -56.450},
	{118.893, 0.020, -6.931, 582.662, 0.000, 0.010, 106.000, -56.450},
	{118.893, 0.000, -2.009, 492.211, 0.000, 0.010, 106.000, -56.450}};
};

#endif