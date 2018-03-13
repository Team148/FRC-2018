#ifndef FromRightSecondCube_ToRightScalePath_H
#define FromRightSecondCube_ToRightScalePath_H

#include "TrajectoryPath.h"

class FromRightSecondCube_ToRightScalePath : TrajectoryPath {

public:
	static TrajectoryPath* GetInstance();
	static FromRightSecondCube_ToRightScalePath *m_instance;
	int GetIndexLength();
	double GetInitialHeading();
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
	FromRightSecondCube_ToRightScalePath();
	int num_index = 278;
	double left_wheel[278][8] ={ 
	{0.000, 0.060, 5.963, 596.294, 5.232, 0.010, 211.589, 97.194},
	{0.001, 0.119, 5.963, -0.019, 5.232, 0.010, 211.590, 97.193},
	{0.004, 0.268, 14.906, 894.345, 5.232, 0.010, 211.591, 97.191},
	{0.009, 0.477, 20.866, 595.993, 5.232, 0.010, 211.594, 97.187},
	{0.016, 0.745, 26.822, 595.602, 5.232, 0.010, 211.597, 97.181},
	{0.027, 1.073, 32.772, 594.963, 5.232, 0.010, 211.603, 97.171},
	{0.042, 1.460, 38.712, 594.013, 5.232, 0.010, 211.610, 97.159},
	{0.061, 1.906, 44.639, 592.693, 5.232, 0.010, 211.619, 97.142},
	{0.085, 2.412, 50.548, 590.941, 5.232, 0.010, 211.631, 97.121},
	{0.115, 2.976, 56.435, 588.699, 5.232, 0.010, 211.646, 97.095},
	{0.151, 3.599, 62.294, 585.909, 5.232, 0.010, 211.664, 97.064},
	{0.193, 4.280, 68.119, 582.517, 5.232, 0.010, 211.685, 97.027},
	{0.244, 5.019, 73.904, 578.468, 5.232, 0.010, 211.710, 96.983},
	{0.302, 5.816, 79.641, 573.712, 5.232, 0.010, 211.739, 96.933},
	{0.369, 6.669, 85.323, 568.203, 5.232, 0.010, 211.772, 96.875},
	{0.444, 7.549, 87.984, 266.055, 5.232, 0.010, 211.809, 96.809},
	{0.528, 8.425, 87.636, -34.743, 5.232, 0.010, 211.851, 96.736},
	{0.621, 9.298, 87.250, -38.595, 5.232, 0.010, 211.897, 96.655},
	{0.723, 10.166, 86.827, -42.370, 5.232, 0.010, 211.948, 96.567},
	{0.833, 11.030, 86.366, -46.062, 5.232, 0.010, 212.003, 96.471},
	{0.952, 11.888, 85.870, -49.663, 5.232, 0.010, 212.062, 96.368},
	{1.079, 12.742, 85.338, -53.168, 5.232, 0.010, 212.125, 96.258},
	{1.215, 13.590, 84.772, -56.569, 5.232, 0.010, 212.192, 96.140},
	{1.360, 14.431, 84.174, -59.861, 5.233, 0.010, 212.264, 96.014},
	{1.512, 15.267, 83.543, -63.039, 5.233, 0.010, 212.340, 95.882},
	{1.673, 16.096, 82.882, -66.096, 5.233, 0.010, 212.420, 95.742},
	{1.842, 16.917, 82.192, -69.028, 5.234, 0.010, 212.504, 95.596},
	{2.020, 17.732, 81.474, -71.831, 5.234, 0.010, 212.593, 95.442},
	{2.205, 18.539, 80.729, -74.499, 5.235, 0.010, 212.685, 95.281},
	{2.399, 19.339, 79.958, -77.029, 5.235, 0.010, 212.782, 95.114},
	{2.600, 20.131, 79.164, -79.415, 5.236, 0.010, 212.882, 94.939},
	{2.809, 20.914, 78.348, -81.653, 5.236, 0.010, 212.987, 94.758},
	{3.026, 21.689, 77.510, -83.740, 5.237, 0.010, 213.095, 94.570},
	{3.251, 22.456, 76.654, -85.672, 5.238, 0.010, 213.208, 94.376},
	{3.483, 23.214, 75.779, -87.444, 5.239, 0.010, 213.325, 94.175},
	{3.722, 23.962, 74.889, -89.052, 5.240, 0.010, 213.445, 93.968},
	{3.969, 24.702, 73.984, -90.491, 5.241, 0.010, 213.570, 93.755},
	{4.224, 25.433, 73.066, -91.756, 5.242, 0.010, 213.698, 93.535},
	{4.485, 26.154, 72.138, -92.843, 5.244, 0.010, 213.830, 93.310},
	{4.754, 26.866, 71.200, -93.745, 5.245, 0.010, 213.967, 93.078},
	{5.030, 27.569, 70.256, -94.456, 5.247, 0.010, 214.107, 92.841},
	{5.312, 28.262, 69.306, -94.968, 5.249, 0.010, 214.251, 92.598},
	{5.602, 28.945, 68.353, -95.275, 5.251, 0.010, 214.399, 92.349},
	{5.898, 29.619, 67.400, -95.367, 5.253, 0.010, 214.552, 92.095},
	{6.201, 30.284, 66.447, -95.234, 5.255, 0.010, 214.708, 91.836},
	{6.510, 30.939, 65.499, -94.867, 5.258, 0.010, 214.868, 91.571},
	{6.826, 31.585, 64.556, -94.250, 5.260, 0.010, 215.032, 91.301},
	{7.148, 32.221, 63.622, -93.375, 5.263, 0.010, 215.200, 91.026},
	{7.477, 32.848, 62.700, -92.224, 5.266, 0.010, 215.372, 90.746},
	{7.811, 33.466, 61.792, -90.782, 5.269, 0.010, 215.549, 90.462},
	{8.152, 34.075, 60.902, -89.031, 5.272, 0.010, 215.729, 90.173},
	{8.499, 34.675, 60.032, -86.955, 5.276, 0.010, 215.914, 89.880},
	{8.851, 35.267, 59.187, -84.530, 5.280, 0.010, 216.103, 89.582},
	{9.210, 35.851, 58.370, -81.741, 5.284, 0.010, 216.296, 89.280},
	{9.574, 36.426, 57.584, -78.559, 5.288, 0.010, 216.493, 88.974},
	{9.944, 36.995, 56.834, -74.968, 5.292, 0.010, 216.695, 88.664},
	{10.320, 37.556, 56.125, -70.938, 5.297, 0.010, 216.902, 88.350},
	{10.701, 38.111, 55.461, -66.448, 5.302, 0.010, 217.113, 88.033},
	{11.087, 38.659, 54.846, -61.474, 5.307, 0.010, 217.328, 87.712},
	{11.479, 39.202, 54.286, -55.991, 5.312, 0.010, 217.549, 87.388},
	{11.877, 39.740, 53.786, -49.977, 5.318, 0.010, 217.774, 87.060},
	{12.279, 40.273, 53.352, -43.410, 5.323, 0.010, 218.004, 86.730},
	{12.688, 40.803, 52.989, -36.270, 5.330, 0.010, 218.239, 86.396},
	{13.101, 41.330, 52.704, -28.540, 5.336, 0.010, 218.480, 86.060},
	{13.519, 41.855, 52.502, -20.207, 5.343, 0.010, 218.725, 85.721},
	{13.943, 42.379, 52.389, -11.262, 5.349, 0.010, 218.976, 85.379},
	{14.372, 42.903, 52.372, -1.701, 5.357, 0.010, 219.232, 85.035},
	{14.806, 43.427, 52.457, 8.474, 5.364, 0.010, 219.494, 84.689},
	{15.246, 43.954, 52.650, 19.255, 5.371, 0.010, 219.762, 84.340},
	{15.691, 44.483, 52.956, 30.622, 5.379, 0.010, 220.036, 83.990},
	{16.141, 45.017, 53.381, 42.552, 5.387, 0.010, 220.316, 83.637},
	{16.597, 45.557, 53.931, 55.007, 5.396, 0.010, 220.602, 83.283},
	{17.058, 46.103, 54.611, 67.944, 5.404, 0.010, 220.895, 82.927},
	{17.524, 46.657, 55.424, 81.304, 5.413, 0.010, 221.194, 82.569},
	{17.996, 47.221, 56.374, 95.022, 5.422, 0.010, 221.500, 82.209},
	{18.474, 47.795, 57.464, 109.018, 5.432, 0.010, 221.814, 81.848},
	{18.958, 48.382, 58.696, 123.203, 5.441, 0.010, 222.134, 81.486},
	{19.448, 48.983, 60.071, 137.479, 5.451, 0.010, 222.462, 81.122},
	{19.944, 49.599, 61.588, 151.736, 5.461, 0.010, 222.798, 80.757},
	{20.446, 50.231, 63.247, 165.859, 5.471, 0.010, 223.141, 80.391},
	{20.955, 50.882, 65.044, 179.723, 5.481, 0.010, 223.493, 80.023},
	{21.471, 51.552, 66.976, 193.200, 5.492, 0.010, 223.854, 79.654},
	{21.993, 52.242, 69.038, 206.164, 5.502, 0.010, 224.223, 79.285},
	{22.523, 52.954, 71.223, 218.480, 5.513, 0.010, 224.601, 78.914},
	{23.059, 53.689, 73.523, 230.027, 5.524, 0.010, 224.988, 78.542},
	{23.604, 54.449, 75.930, 240.681, 5.534, 0.010, 225.385, 78.169},
	{24.156, 55.233, 78.433, 250.333, 5.545, 0.010, 225.791, 77.795},
	{24.717, 56.043, 81.022, 258.883, 5.556, 0.010, 226.208, 77.421},
	{25.286, 56.880, 83.684, 266.244, 5.567, 0.010, 226.635, 77.045},
	{25.863, 57.744, 86.408, 272.349, 5.578, 0.010, 227.073, 76.668},
	{26.449, 58.636, 89.179, 277.150, 5.590, 0.010, 227.522, 76.291},
	{27.045, 59.556, 91.985, 280.613, 5.601, 0.010, 227.982, 75.913},
	{27.650, 60.504, 94.813, 282.735, 5.612, 0.010, 228.453, 75.534},
	{28.265, 61.480, 97.648, 283.524, 5.623, 0.010, 228.937, 75.154},
	{28.890, 62.485, 100.478, 283.017, 5.633, 0.010, 229.432, 74.773},
	{29.525, 63.518, 103.291, 281.275, 5.644, 0.010, 229.940, 74.392},
	{30.171, 64.579, 106.075, 278.363, 5.655, 0.010, 230.461, 74.009},
	{30.827, 65.667, 108.818, 274.383, 5.665, 0.010, 230.994, 73.626},
	{31.495, 66.782, 111.513, 269.437, 5.676, 0.010, 231.540, 73.242},
	{32.174, 67.924, 114.149, 263.653, 5.686, 0.010, 232.100, 72.857},
	{32.865, 69.091, 116.721, 257.158, 5.696, 0.010, 232.673, 72.472},
	{33.568, 70.283, 119.222, 250.092, 5.706, 0.010, 233.260, 72.085},
	{34.283, 71.500, 121.648, 242.604, 5.715, 0.010, 233.861, 71.698},
	{35.010, 72.740, 123.996, 234.839, 5.725, 0.010, 234.476, 71.310},
	{35.750, 74.002, 126.266, 226.938, 5.734, 0.010, 235.106, 70.920},
	{36.503, 75.287, 128.456, 219.058, 5.743, 0.010, 235.750, 70.530},
	{37.269, 76.592, 130.569, 211.325, 5.751, 0.010, 236.408, 70.139},
	{38.048, 77.919, 132.608, 203.883, 5.760, 0.010, 237.081, 69.747},
	{38.841, 79.264, 134.577, 196.856, 5.768, 0.010, 237.769, 69.353},
	{39.647, 80.629, 136.480, 190.361, 5.775, 0.010, 238.472, 68.958},
	{40.467, 82.012, 138.326, 184.509, 5.782, 0.010, 239.190, 68.562},
	{41.302, 83.414, 140.120, 179.405, 5.789, 0.010, 239.924, 68.164},
	{42.150, 84.832, 141.871, 175.136, 5.796, 0.010, 240.672, 67.764},
	{43.013, 86.268, 143.589, 171.788, 5.802, 0.010, 241.435, 67.363},
	{43.890, 87.721, 145.283, 169.440, 5.808, 0.010, 242.214, 66.959},
	{44.782, 89.191, 146.965, 168.160, 5.813, 0.010, 243.008, 66.553},
	{45.689, 90.677, 148.645, 168.007, 5.818, 0.010, 243.818, 66.145},
	{46.610, 92.180, 150.335, 169.045, 5.823, 0.010, 244.643, 65.734},
	{47.547, 93.701, 152.049, 171.319, 5.827, 0.010, 245.483, 65.319},
	{48.500, 95.239, 153.797, 174.883, 5.831, 0.010, 246.339, 64.902},
	{49.468, 96.795, 155.595, 179.783, 5.834, 0.010, 247.211, 64.480},
	{50.451, 98.369, 157.456, 186.060, 5.837, 0.010, 248.097, 64.054},
	{51.451, 99.963, 159.393, 193.754, 5.839, 0.010, 249.000, 63.624},
	{52.467, 101.578, 161.422, 202.909, 5.841, 0.010, 249.917, 63.188},
	{53.499, 103.184, 160.619, -80.335, 5.842, 0.010, 250.850, 62.747},
	{54.546, 104.753, 156.888, -373.080, 5.843, 0.010, 251.798, 62.301},
	{55.609, 106.284, 153.114, -377.412, 5.843, 0.010, 252.759, 61.848},
	{56.687, 107.777, 149.306, -380.847, 5.843, 0.010, 253.734, 61.389},
	{57.779, 109.232, 145.471, -383.502, 5.842, 0.010, 254.722, 60.923},
	{58.886, 110.648, 141.615, -385.520, 5.841, 0.010, 255.723, 60.450},
	{60.006, 112.025, 137.745, -387.072, 5.839, 0.010, 256.735, 59.969},
	{61.139, 113.364, 133.861, -388.364, 5.836, 0.010, 257.757, 59.480},
	{62.286, 114.663, 129.965, -389.628, 5.832, 0.010, 258.790, 58.983},
	{63.445, 115.924, 126.053, -391.134, 5.829, 0.010, 259.833, 58.476},
	{64.617, 117.145, 122.122, -393.189, 5.824, 0.010, 260.884, 57.959},
	{65.800, 118.327, 118.160, -396.130, 5.819, 0.010, 261.943, 57.432},
	{66.995, 119.468, 114.157, -400.344, 5.813, 0.010, 263.010, 56.893},
	{68.200, 120.569, 110.094, -406.252, 5.806, 0.010, 264.083, 56.343},
	{69.416, 121.604, 103.436, -665.835, 5.799, 0.010, 265.161, 55.781},
	{70.642, 122.569, 96.583, -685.294, 5.790, 0.010, 266.243, 55.205},
	{71.877, 123.490, 92.058, -452.473, 5.782, 0.010, 267.328, 54.616},
	{73.121, 124.364, 87.351, -470.695, 5.772, 0.010, 268.416, 54.013},
	{74.373, 125.188, 82.419, -493.212, 5.762, 0.010, 269.505, 53.395},
	{75.632, 125.960, 77.213, -520.589, 5.751, 0.010, 270.593, 52.762},
	{76.899, 126.677, 71.680, -553.335, 5.739, 0.010, 271.681, 52.112},
	{78.172, 127.334, 65.761, -591.938, 5.726, 0.010, 272.766, 51.446},
	{79.452, 127.928, 59.393, -636.787, 5.713, 0.010, 273.848, 50.762},
	{80.736, 128.453, 52.511, -688.156, 5.699, 0.010, 274.924, 50.061},
	{82.025, 128.904, 45.050, -746.163, 5.684, 0.010, 275.994, 49.343},
	{83.318, 129.273, 36.942, -810.719, 5.669, 0.010, 277.056, 48.605},
	{84.613, 129.555, 28.127, -881.490, 5.652, 0.010, 278.108, 47.850},
	{85.911, 129.740, 18.549, -957.855, 5.635, 0.010, 279.149, 47.076},
	{87.209, 129.822, 8.160, -1038.869, 5.618, 0.010, 280.178, 46.283},
	{88.507, 129.820, -0.196, -835.657, 5.600, 0.010, 281.192, 45.473},
	{89.805, 129.764, -5.536, -533.947, 5.581, 0.010, 282.191, 44.644},
	{91.101, 129.658, -10.639, -510.353, 5.562, 0.010, 283.172, 43.797},
	{92.396, 129.494, -16.374, -573.490, 5.542, 0.010, 284.136, 42.933},
	{93.689, 129.267, -22.729, -635.466, 5.522, 0.010, 285.081, 42.050},
	{94.979, 128.970, -29.676, -694.683, 5.501, 0.010, 286.005, 41.151},
	{96.265, 128.598, -37.170, -749.430, 5.480, 0.010, 286.908, 40.235},
	{97.546, 128.147, -45.150, -798.042, 5.459, 0.010, 287.788, 39.304},
	{98.822, 127.612, -53.540, -838.915, 5.437, 0.010, 288.645, 38.358},
	{100.092, 126.989, -62.246, -870.636, 5.416, 0.010, 289.476, 37.398},
	{101.355, 126.277, -71.166, -892.044, 5.394, 0.010, 290.282, 36.426},
	{102.610, 125.476, -80.189, -902.300, 5.372, 0.010, 291.062, 35.443},
	{103.856, 124.584, -89.199, -900.950, 5.350, 0.010, 291.814, 34.450},
	{105.092, 123.603, -98.078, -887.940, 5.328, 0.010, 292.539, 33.448},
	{106.317, 122.536, -106.715, -863.630, 5.306, 0.010, 293.236, 32.440},
	{107.531, 121.386, -115.002, -828.766, 5.285, 0.010, 293.904, 31.427},
	{108.732, 120.157, -122.847, -784.435, 5.263, 0.010, 294.544, 30.410},
	{109.921, 118.855, -130.166, -731.980, 5.242, 0.010, 295.155, 29.391},
	{111.096, 117.486, -136.896, -672.970, 5.221, 0.010, 295.738, 28.371},
	{112.256, 116.057, -142.986, -609.038, 5.201, 0.010, 296.294, 27.352},
	{113.402, 114.573, -148.405, -541.879, 5.181, 0.010, 296.821, 26.335},
	{114.532, 113.041, -153.136, -473.108, 5.162, 0.010, 297.322, 25.321},
	{115.647, 111.469, -157.179, -404.239, 5.143, 0.010, 297.797, 24.313},
	{116.746, 109.864, -160.545, -336.617, 5.124, 0.010, 298.246, 23.310},
	{117.828, 108.231, -163.259, -271.377, 5.106, 0.010, 298.670, 22.314},
	{118.894, 106.578, -165.353, -209.463, 5.088, 0.010, 299.070, 21.326},
	{119.943, 104.909, -166.869, -151.581, 5.071, 0.010, 299.447, 20.347},
	{120.975, 103.231, -167.851, -98.234, 5.055, 0.010, 299.801, 19.378},
	{121.991, 101.547, -168.349, -49.736, 5.039, 0.010, 300.135, 18.419},
	{122.989, 99.863, -168.411, -6.230, 5.024, 0.010, 300.448, 17.470},
	{123.971, 98.182, -168.088, 32.298, 5.009, 0.010, 300.742, 16.534},
	{124.936, 96.508, -167.429, 65.950, 4.995, 0.010, 301.017, 15.609},
	{125.885, 94.843, -166.479, 94.938, 4.981, 0.010, 301.275, 14.696},
	{126.817, 93.190, -165.284, 119.547, 4.968, 0.010, 301.516, 13.796},
	{127.732, 91.551, -163.883, 140.103, 4.955, 0.010, 301.741, 12.908},
	{128.631, 89.928, -162.314, 156.916, 4.943, 0.010, 301.952, 12.034},
	{129.515, 88.322, -160.610, 170.399, 4.931, 0.010, 302.148, 11.173},
	{130.382, 86.734, -158.801, 180.858, 4.920, 0.010, 302.331, 10.325},
	{131.234, 85.165, -156.914, 188.674, 4.909, 0.010, 302.502, 9.491},
	{132.070, 83.615, -154.973, 194.164, 4.899, 0.010, 302.661, 8.670},
	{132.891, 82.085, -152.996, 197.642, 4.889, 0.010, 302.809, 7.863},
	{133.696, 80.575, -151.002, 199.396, 4.879, 0.010, 302.947, 7.069},
	{134.487, 79.085, -149.006, 199.676, 4.870, 0.010, 303.074, 6.288},
	{135.263, 77.615, -147.018, 198.742, 4.861, 0.010, 303.193, 5.521},
	{136.025, 76.165, -145.050, 196.765, 4.853, 0.010, 303.303, 4.767},
	{136.772, 74.733, -143.111, 193.976, 4.845, 0.010, 303.405, 4.027},
	{137.506, 73.321, -141.206, 190.505, 4.838, 0.010, 303.499, 3.300},
	{138.225, 71.928, -139.341, 186.510, 4.830, 0.010, 303.586, 2.586},
	{138.930, 70.553, -137.520, 182.103, 4.824, 0.010, 303.667, 1.885},
	{139.622, 69.195, -135.746, 177.399, 4.817, 0.010, 303.742, 1.197},
	{140.301, 67.855, -134.021, 172.490, 4.811, 0.010, 303.810, 0.522},
	{140.966, 66.532, -132.346, 167.451, 4.805, 0.010, 303.874, -0.140},
	{141.618, 65.224, -130.723, 162.320, 4.799, 0.010, 303.932, -0.790},
	{142.258, 63.933, -129.151, 157.205, 4.794, 0.010, 303.986, -1.427},
	{142.884, 62.657, -127.630, 152.086, 4.789, 0.010, 304.035, -2.052},
	{143.498, 61.395, -126.159, 147.061, 4.784, 0.010, 304.080, -2.664},
	{144.100, 60.148, -124.738, 142.101, 4.779, 0.010, 304.122, -3.264},
	{144.689, 58.914, -123.366, 137.268, 4.775, 0.010, 304.160, -3.852},
	{145.266, 57.694, -122.040, 132.567, 4.771, 0.010, 304.195, -4.428},
	{145.831, 56.486, -120.760, 128.008, 4.767, 0.010, 304.226, -4.992},
	{146.384, 55.291, -119.524, 123.604, 4.763, 0.010, 304.255, -5.544},
	{146.925, 54.107, -118.330, 119.358, 4.759, 0.010, 304.282, -6.084},
	{147.454, 52.936, -117.178, 115.276, 4.756, 0.010, 304.306, -6.613},
	{147.972, 51.775, -116.064, 111.356, 4.753, 0.010, 304.327, -7.130},
	{148.478, 50.625, -114.988, 107.608, 4.750, 0.010, 304.347, -7.636},
	{148.973, 49.486, -113.948, 104.011, 4.747, 0.010, 304.365, -8.131},
	{149.456, 48.356, -112.942, 100.576, 4.744, 0.010, 304.381, -8.614},
	{149.929, 47.237, -111.969, 97.298, 4.742, 0.010, 304.395, -9.086},
	{150.390, 46.126, -111.027, 94.163, 4.739, 0.010, 304.408, -9.547},
	{150.840, 45.025, -110.116, 91.170, 4.737, 0.010, 304.420, -9.997},
	{151.280, 43.933, -109.233, 88.319, 4.735, 0.010, 304.430, -10.437},
	{151.708, 42.849, -108.377, 85.591, 4.733, 0.010, 304.440, -10.865},
	{152.126, 41.774, -107.547, 82.989, 4.731, 0.010, 304.448, -11.283},
	{152.533, 40.706, -106.742, 80.495, 4.730, 0.010, 304.455, -11.690},
	{152.929, 39.647, -105.961, 78.119, 4.728, 0.010, 304.462, -12.086},
	{153.315, 38.595, -105.202, 75.834, 4.726, 0.010, 304.468, -12.472},
	{153.691, 37.550, -104.466, 73.644, 4.725, 0.010, 304.473, -12.847},
	{154.056, 36.512, -103.750, 71.539, 4.724, 0.010, 304.477, -13.212},
	{154.411, 35.482, -103.055, 69.512, 4.723, 0.010, 304.481, -13.567},
	{154.755, 34.458, -102.380, 67.554, 4.722, 0.010, 304.484, -13.912},
	{155.090, 33.441, -101.723, 65.664, 4.720, 0.010, 304.487, -14.246},
	{155.414, 32.430, -101.085, 63.826, 4.720, 0.010, 304.490, -14.570},
	{155.728, 31.425, -100.465, 62.039, 4.719, 0.010, 304.492, -14.885},
	{156.033, 30.427, -99.862, 60.294, 4.718, 0.010, 304.494, -15.189},
	{156.327, 29.434, -99.276, 58.591, 4.717, 0.010, 304.495, -15.483},
	{156.611, 28.447, -98.707, 56.913, 4.717, 0.010, 304.496, -15.768},
	{156.886, 27.465, -98.154, 55.263, 4.716, 0.010, 304.497, -16.042},
	{157.151, 26.489, -97.618, 53.633, 4.715, 0.010, 304.498, -16.307},
	{157.406, 25.518, -97.097, 52.017, 4.715, 0.010, 304.499, -16.563},
	{157.652, 24.552, -96.593, 50.410, 4.714, 0.010, 304.499, -16.808},
	{157.888, 23.591, -96.105, 48.808, 4.714, 0.010, 304.500, -17.044},
	{158.114, 22.635, -95.633, 47.209, 4.714, 0.010, 304.500, -17.270},
	{158.331, 21.683, -95.177, 45.601, 4.713, 0.010, 304.500, -17.487},
	{158.538, 20.736, -94.737, 43.992, 4.713, 0.010, 304.501, -17.694},
	{158.736, 19.793, -94.314, 42.368, 4.713, 0.010, 304.501, -17.892},
	{158.925, 18.854, -93.906, 40.732, 4.713, 0.010, 304.501, -18.081},
	{159.104, 17.918, -93.515, 39.080, 4.712, 0.010, 304.501, -18.260},
	{159.274, 16.987, -93.141, 37.409, 4.712, 0.010, 304.501, -18.430},
	{159.434, 16.059, -92.784, 35.719, 4.712, 0.010, 304.501, -18.591},
	{159.586, 15.135, -92.444, 34.004, 4.712, 0.010, 304.501, -18.742},
	{159.728, 14.213, -92.121, 32.269, 4.712, 0.010, 304.501, -18.884},
	{159.861, 13.295, -91.816, 30.507, 4.712, 0.010, 304.501, -19.017},
	{159.984, 12.380, -91.529, 28.721, 4.712, 0.010, 304.501, -19.141},
	{160.099, 11.467, -91.260, 26.910, 4.712, 0.010, 304.501, -19.256},
	{160.205, 10.557, -91.009, 25.074, 4.712, 0.010, 304.500, -19.361},
	{160.301, 9.650, -90.777, 23.213, 4.712, 0.010, 304.500, -19.458},
	{160.389, 8.744, -90.564, 21.328, 4.712, 0.010, 304.500, -19.545},
	{160.467, 7.840, -90.370, 19.421, 4.712, 0.010, 304.500, -19.623},
	{160.536, 6.938, -90.195, 17.491, 4.712, 0.010, 304.500, -19.693},
	{160.597, 6.061, -87.751, 244.421, 4.712, 0.010, 304.500, -19.753},
	{160.649, 5.237, -82.343, 540.720, 4.712, 0.010, 304.500, -19.806},
	{160.694, 4.475, -76.264, 607.918, 4.712, 0.010, 304.500, -19.851},
	{160.732, 3.773, -70.209, 605.503, 4.712, 0.010, 304.500, -19.888},
	{160.763, 3.131, -64.175, 603.444, 4.712, 0.010, 304.500, -19.920},
	{160.789, 2.549, -58.158, 601.715, 4.712, 0.010, 304.500, -19.945},
	{160.809, 2.028, -52.155, 600.288, 4.712, 0.010, 304.500, -19.965},
	{160.825, 1.566, -46.163, 599.136, 4.712, 0.010, 304.500, -19.981},
	{160.836, 1.164, -40.181, 598.229, 4.712, 0.010, 304.500, -19.993},
	{160.845, 0.822, -34.206, 597.540, 4.712, 0.010, 304.500, -20.001},
	{160.850, 0.540, -28.235, 597.038, 4.712, 0.010, 304.500, -20.006},
	{160.853, 0.317, -22.268, 596.694, 4.712, 0.010, 304.500, -20.009},
	{160.855, 0.154, -16.303, 596.478, 4.712, 0.010, 304.500, -20.011},
	{160.855, 0.051, -10.340, 596.360, 4.712, 0.010, 304.500, -20.011},
	{160.855, 0.007, -4.377, 596.308, 4.712, 0.010, 304.500, -20.012},
	{160.855, 0.000, -0.698, 367.915, 4.712, 0.010, 304.500, -20.012}};
	double right_wheel[278][8] ={ 
	{0.000, 0.060, 5.963, 596.294, 5.232, 0.010, 186.411, 82.805},
	{0.001, 0.119, 5.963, 0.019, 5.232, 0.010, 186.412, 82.804},
	{0.004, 0.268, 14.908, 894.536, 5.232, 0.010, 186.413, 82.802},
	{0.009, 0.477, 20.874, 596.594, 5.232, 0.010, 186.415, 82.797},
	{0.016, 0.746, 26.844, 596.985, 5.232, 0.010, 186.419, 82.791},
	{0.027, 1.074, 32.821, 597.624, 5.232, 0.010, 186.424, 82.782},
	{0.042, 1.462, 38.806, 598.574, 5.232, 0.010, 186.432, 82.769},
	{0.061, 1.910, 44.805, 599.894, 5.232, 0.010, 186.441, 82.752},
	{0.085, 2.418, 50.822, 601.646, 5.232, 0.010, 186.453, 82.731},
	{0.115, 2.987, 56.861, 603.888, 5.232, 0.010, 186.468, 82.706},
	{0.151, 3.616, 62.927, 606.678, 5.232, 0.010, 186.486, 82.674},
	{0.194, 4.306, 69.028, 610.070, 5.232, 0.010, 186.507, 82.637},
	{0.245, 5.058, 75.169, 614.119, 5.232, 0.010, 186.532, 82.593},
	{0.303, 5.871, 81.358, 618.875, 5.232, 0.010, 186.561, 82.542},
	{0.371, 6.748, 87.602, 624.384, 5.232, 0.010, 186.595, 82.483},
	{0.447, 7.657, 90.904, 330.239, 5.232, 0.010, 186.633, 82.417},
	{0.533, 8.569, 91.252, 34.743, 5.232, 0.010, 186.675, 82.342},
	{0.628, 9.485, 91.638, 38.595, 5.232, 0.010, 186.723, 82.260},
	{0.732, 10.406, 92.061, 42.370, 5.232, 0.010, 186.774, 82.170},
	{0.845, 11.331, 92.522, 46.062, 5.232, 0.010, 186.830, 82.071},
	{0.968, 12.261, 93.019, 49.663, 5.232, 0.010, 186.891, 81.965},
	{1.100, 13.197, 93.550, 53.167, 5.232, 0.010, 186.957, 81.850},
	{1.241, 14.138, 94.116, 56.569, 5.232, 0.010, 187.027, 81.728},
	{1.392, 15.085, 94.714, 59.861, 5.233, 0.010, 187.102, 81.597},
	{1.553, 16.039, 95.345, 63.038, 5.233, 0.010, 187.182, 81.458},
	{1.723, 16.999, 96.006, 66.096, 5.233, 0.010, 187.266, 81.310},
	{1.902, 17.966, 96.696, 69.029, 5.234, 0.010, 187.356, 81.154},
	{2.092, 18.940, 97.414, 71.831, 5.234, 0.010, 187.450, 80.990},
	{2.291, 19.921, 98.159, 74.499, 5.235, 0.010, 187.550, 80.817},
	{2.500, 20.911, 98.930, 77.028, 5.235, 0.010, 187.654, 80.636},
	{2.719, 21.908, 99.724, 79.414, 5.236, 0.010, 187.763, 80.446},
	{2.948, 22.913, 100.540, 81.653, 5.236, 0.010, 187.878, 80.248},
	{3.187, 23.927, 101.378, 83.740, 5.237, 0.010, 187.998, 80.041},
	{3.437, 24.950, 102.234, 85.671, 5.238, 0.010, 188.123, 79.825},
	{3.697, 25.981, 103.109, 87.443, 5.239, 0.010, 188.253, 79.600},
	{3.967, 27.021, 103.999, 89.051, 5.240, 0.010, 188.389, 79.367},
	{4.248, 28.070, 104.904, 90.490, 5.241, 0.010, 188.531, 79.124},
	{4.539, 29.128, 105.822, 91.756, 5.242, 0.010, 188.678, 78.873},
	{4.841, 30.195, 106.750, 92.841, 5.244, 0.010, 188.831, 78.613},
	{5.154, 31.272, 107.688, 93.743, 5.245, 0.010, 188.989, 78.343},
	{5.477, 32.359, 108.632, 94.454, 5.247, 0.010, 189.154, 78.065},
	{5.812, 33.454, 109.582, 94.966, 5.249, 0.010, 189.325, 77.777},
	{6.157, 34.560, 110.535, 95.272, 5.251, 0.010, 189.502, 77.480},
	{6.514, 35.675, 111.488, 95.365, 5.253, 0.010, 189.685, 77.174},
	{6.882, 36.799, 112.441, 95.231, 5.255, 0.010, 189.875, 76.859},
	{7.261, 37.933, 113.389, 94.862, 5.258, 0.010, 190.071, 76.534},
	{7.652, 39.076, 114.332, 94.248, 5.260, 0.010, 190.274, 76.200},
	{8.054, 40.229, 115.265, 93.371, 5.263, 0.010, 190.484, 75.857},
	{8.468, 41.391, 116.188, 92.219, 5.266, 0.010, 190.701, 75.504},
	{8.894, 42.562, 117.095, 90.776, 5.269, 0.010, 190.925, 75.143},
	{9.331, 43.742, 117.986, 89.026, 5.272, 0.010, 191.157, 74.772},
	{9.781, 44.930, 118.855, 86.948, 5.276, 0.010, 191.396, 74.391},
	{10.242, 46.127, 119.700, 84.525, 5.280, 0.010, 191.643, 74.002},
	{10.715, 47.332, 120.518, 81.733, 5.284, 0.010, 191.898, 73.603},
	{11.201, 48.545, 121.303, 78.553, 5.288, 0.010, 192.161, 73.195},
	{11.698, 49.766, 122.053, 74.958, 5.292, 0.010, 192.433, 72.778},
	{12.208, 50.994, 122.762, 70.930, 5.297, 0.010, 192.713, 72.352},
	{12.731, 52.228, 123.427, 66.440, 5.302, 0.010, 193.003, 71.917},
	{13.265, 53.468, 124.041, 61.465, 5.307, 0.010, 193.301, 71.474},
	{13.812, 54.714, 124.601, 55.981, 5.312, 0.010, 193.608, 71.021},
	{14.372, 55.965, 125.101, 49.968, 5.318, 0.010, 193.926, 70.560},
	{14.944, 57.221, 125.535, 43.399, 5.323, 0.010, 194.253, 70.090},
	{15.529, 58.480, 125.897, 36.260, 5.330, 0.010, 194.590, 69.612},
	{16.126, 59.741, 126.183, 28.529, 5.336, 0.010, 194.937, 69.126},
	{16.737, 61.005, 126.384, 20.197, 5.343, 0.010, 195.295, 68.632},
	{17.359, 62.270, 126.497, 11.251, 5.349, 0.010, 195.663, 68.130},
	{17.995, 63.535, 126.514, 1.690, 5.357, 0.010, 196.043, 67.621},
	{18.643, 64.800, 126.429, -8.485, 5.364, 0.010, 196.434, 67.104},
	{19.303, 66.062, 126.236, -19.265, 5.371, 0.010, 196.837, 66.581},
	{19.976, 67.321, 125.930, -30.632, 5.379, 0.010, 197.251, 66.050},
	{20.662, 68.576, 125.504, -42.561, 5.387, 0.010, 197.677, 65.513},
	{21.360, 69.826, 124.954, -55.016, 5.396, 0.010, 198.116, 64.970},
	{22.071, 71.069, 124.275, -67.951, 5.404, 0.010, 198.567, 64.421},
	{22.794, 72.303, 123.462, -81.311, 5.413, 0.010, 199.031, 63.866},
	{23.529, 73.528, 122.511, -95.027, 5.422, 0.010, 199.508, 63.306},
	{24.277, 74.743, 121.421, -109.022, 5.432, 0.010, 199.998, 62.742},
	{25.036, 75.944, 120.189, -123.206, 5.441, 0.010, 200.501, 62.173},
	{25.808, 77.133, 118.814, -137.480, 5.451, 0.010, 201.017, 61.600},
	{26.591, 78.306, 117.297, -151.736, 5.461, 0.010, 201.547, 61.023},
	{27.385, 79.462, 115.638, -165.855, 5.471, 0.010, 202.091, 60.444},
	{28.191, 80.600, 113.841, -179.718, 5.481, 0.010, 202.648, 59.862},
	{29.009, 81.719, 111.909, -193.194, 5.492, 0.010, 203.219, 59.277},
	{29.837, 82.818, 109.848, -206.153, 5.502, 0.010, 203.804, 58.691},
	{30.676, 83.895, 107.663, -218.469, 5.513, 0.010, 204.403, 58.103},
	{31.525, 84.948, 105.363, -230.013, 5.524, 0.010, 205.016, 57.515},
	{32.385, 85.978, 102.956, -240.665, 5.534, 0.010, 205.643, 56.926},
	{33.255, 86.982, 100.453, -250.315, 5.545, 0.010, 206.283, 56.338},
	{34.134, 87.961, 97.865, -258.862, 5.556, 0.010, 206.937, 55.750},
	{35.023, 88.913, 95.202, -266.222, 5.567, 0.010, 207.605, 55.162},
	{35.922, 89.838, 92.479, -272.326, 5.578, 0.010, 208.286, 54.577},
	{36.829, 90.735, 89.708, -277.123, 5.590, 0.010, 208.980, 53.993},
	{37.745, 91.604, 86.902, -280.588, 5.601, 0.010, 209.688, 53.411},
	{38.670, 92.445, 84.075, -282.704, 5.612, 0.010, 210.408, 52.832},
	{39.602, 93.257, 81.240, -283.495, 5.623, 0.010, 211.142, 52.255},
	{40.543, 94.041, 78.410, -282.992, 5.633, 0.010, 211.887, 51.682},
	{41.491, 94.797, 75.598, -281.241, 5.644, 0.010, 212.645, 51.113},
	{42.446, 95.525, 72.814, -278.336, 5.655, 0.010, 213.415, 50.547},
	{43.408, 96.226, 70.071, -274.353, 5.665, 0.010, 214.197, 49.986},
	{44.377, 96.900, 67.377, -269.412, 5.676, 0.010, 214.989, 49.429},
	{45.353, 97.547, 64.740, -263.625, 5.686, 0.010, 215.793, 48.876},
	{46.334, 98.169, 62.169, -257.130, 5.696, 0.010, 216.608, 48.328},
	{47.322, 98.765, 59.668, -250.071, 5.706, 0.010, 217.433, 47.785},
	{48.315, 99.338, 57.243, -242.581, 5.715, 0.010, 218.268, 47.247},
	{49.314, 99.887, 54.894, -234.814, 5.725, 0.010, 219.112, 46.714},
	{50.318, 100.413, 52.625, -226.924, 5.734, 0.010, 219.966, 46.186},
	{51.327, 100.917, 50.435, -219.037, 5.743, 0.010, 220.830, 45.663},
	{52.342, 101.401, 48.322, -211.312, 5.751, 0.010, 221.701, 45.145},
	{53.360, 101.863, 46.283, -203.871, 5.760, 0.010, 222.581, 44.632},
	{54.383, 102.307, 44.315, -196.845, 5.768, 0.010, 223.469, 44.124},
	{55.411, 102.731, 42.411, -190.353, 5.775, 0.010, 224.365, 43.621},
	{56.442, 103.136, 40.566, -184.506, 5.782, 0.010, 225.268, 43.123},
	{57.477, 103.524, 38.772, -179.400, 5.789, 0.010, 226.178, 42.629},
	{58.516, 103.894, 37.021, -175.134, 5.796, 0.010, 227.094, 42.139},
	{59.559, 104.247, 35.303, -171.791, 5.802, 0.010, 228.017, 41.654},
	{60.604, 104.583, 33.608, -169.445, 5.808, 0.010, 228.946, 41.173},
	{61.653, 104.903, 31.927, -168.165, 5.813, 0.010, 229.880, 40.696},
	{62.705, 105.205, 30.246, -168.018, 5.818, 0.010, 230.819, 40.222},
	{63.760, 105.491, 28.556, -169.055, 5.823, 0.010, 231.763, 39.751},
	{64.818, 105.759, 26.843, -171.335, 5.827, 0.010, 232.712, 39.283},
	{65.878, 106.010, 25.093, -174.903, 5.831, 0.010, 233.664, 38.818},
	{66.940, 106.243, 23.295, -179.804, 5.834, 0.010, 234.621, 38.355},
	{68.005, 106.457, 21.435, -186.083, 5.837, 0.010, 235.580, 37.895},
	{69.072, 106.652, 19.497, -193.784, 5.839, 0.010, 236.543, 37.435},
	{70.140, 106.827, 17.467, -202.940, 5.841, 0.010, 237.508, 36.977},
	{71.209, 106.950, 12.307, -515.996, 5.842, 0.010, 238.475, 36.521},
	{72.279, 106.991, 4.112, -819.548, 5.843, 0.010, 239.443, 36.064},
	{73.349, 106.951, -4.040, -815.222, 5.843, 0.010, 240.410, 35.609},
	{74.417, 106.829, -12.158, -811.792, 5.843, 0.010, 241.377, 35.154},
	{75.483, 106.627, -20.250, -809.143, 5.842, 0.010, 242.341, 34.699},
	{76.547, 106.343, -28.321, -807.131, 5.841, 0.010, 243.303, 34.244},
	{77.607, 105.980, -36.377, -805.583, 5.839, 0.010, 244.260, 33.790},
	{78.662, 105.536, -44.420, -804.298, 5.836, 0.010, 245.212, 33.334},
	{79.712, 105.011, -52.450, -803.039, 5.832, 0.010, 246.158, 32.879},
	{80.756, 104.406, -60.466, -801.536, 5.829, 0.010, 247.097, 32.422},
	{81.793, 103.722, -68.460, -799.489, 5.824, 0.010, 248.028, 31.964},
	{82.823, 102.958, -76.426, -796.550, 5.819, 0.010, 248.950, 31.506},
	{83.844, 102.114, -84.349, -792.341, 5.813, 0.010, 249.861, 31.045},
	{84.856, 101.192, -92.214, -786.439, 5.806, 0.010, 250.762, 30.584},
	{85.858, 100.171, -102.050, -983.614, 5.799, 0.010, 251.650, 30.120},
	{86.848, 99.054, -111.691, -964.158, 5.790, 0.010, 252.524, 29.655},
	{87.827, 97.864, -119.094, -740.219, 5.782, 0.010, 253.384, 29.189},
	{88.793, 96.600, -126.314, -722.000, 5.772, 0.010, 254.229, 28.720},
	{89.745, 95.267, -133.308, -699.474, 5.762, 0.010, 255.058, 28.250},
	{90.684, 93.867, -140.029, -672.102, 5.751, 0.010, 255.869, 27.778},
	{91.608, 92.403, -146.423, -639.344, 5.739, 0.010, 256.662, 27.304},
	{92.517, 90.878, -152.430, -600.734, 5.726, 0.010, 257.437, 26.829},
	{93.410, 89.299, -157.989, -555.875, 5.713, 0.010, 258.192, 26.352},
	{94.287, 87.668, -163.034, -504.490, 5.699, 0.010, 258.926, 25.873},
	{95.147, 85.993, -167.498, -446.466, 5.684, 0.010, 259.640, 25.394},
	{95.989, 84.280, -171.317, -381.888, 5.669, 0.010, 260.333, 24.913},
	{96.815, 82.536, -174.428, -311.094, 5.652, 0.010, 261.003, 24.432},
	{97.622, 80.768, -176.775, -234.704, 5.635, 0.010, 261.651, 23.950},
	{98.412, 78.985, -178.312, -153.659, 5.618, 0.010, 262.277, 23.468},
	{99.184, 77.212, -177.313, 99.903, 5.600, 0.010, 262.880, 22.986},
	{99.939, 75.478, -173.368, 394.484, 5.581, 0.010, 263.461, 22.504},
	{100.677, 73.795, -168.264, 510.448, 5.562, 0.010, 264.020, 22.022},
	{101.399, 72.170, -162.528, 573.598, 5.542, 0.010, 264.557, 21.540},
	{102.105, 70.608, -156.172, 635.606, 5.522, 0.010, 265.073, 21.058},
	{102.796, 69.116, -149.223, 694.835, 5.501, 0.010, 265.568, 20.576},
	{103.473, 67.699, -141.727, 749.608, 5.480, 0.010, 266.044, 20.094},
	{104.137, 66.362, -133.745, 798.232, 5.459, 0.010, 266.500, 19.611},
	{104.788, 65.108, -125.354, 839.120, 5.437, 0.010, 266.937, 19.129},
	{105.427, 63.942, -116.645, 870.851, 5.416, 0.010, 267.355, 18.646},
	{106.056, 62.864, -107.722, 892.262, 5.394, 0.010, 267.757, 18.162},
	{106.675, 61.877, -98.697, 902.520, 5.372, 0.010, 268.141, 17.677},
	{107.284, 60.981, -89.686, 901.164, 5.350, 0.010, 268.509, 17.191},
	{107.886, 60.172, -80.804, 888.146, 5.328, 0.010, 268.862, 16.703},
	{108.481, 59.451, -72.166, 863.823, 5.306, 0.010, 269.200, 16.214},
	{109.069, 58.812, -63.877, 828.943, 5.285, 0.010, 269.524, 15.723},
	{109.651, 58.252, -56.031, 784.587, 5.263, 0.010, 269.834, 15.230},
	{110.229, 57.765, -48.709, 732.119, 5.242, 0.010, 270.131, 14.735},
	{110.802, 57.345, -41.979, 673.077, 5.221, 0.010, 270.416, 14.237},
	{111.372, 56.986, -35.887, 609.128, 5.201, 0.010, 270.688, 13.737},
	{111.939, 56.681, -30.468, 541.942, 5.181, 0.010, 270.950, 13.234},
	{112.503, 56.424, -25.736, 473.151, 5.162, 0.010, 271.200, 12.728},
	{113.065, 56.207, -21.694, 404.261, 5.143, 0.010, 271.439, 12.219},
	{113.626, 56.024, -18.328, 336.616, 5.124, 0.010, 271.668, 11.708},
	{114.184, 55.868, -15.614, 271.365, 5.106, 0.010, 271.886, 11.194},
	{114.742, 55.732, -13.520, 209.435, 5.088, 0.010, 272.096, 10.677},
	{115.298, 55.612, -12.004, 151.540, 5.071, 0.010, 272.295, 10.158},
	{115.853, 55.502, -11.022, 98.184, 5.055, 0.010, 272.486, 9.637},
	{116.407, 55.397, -10.526, 49.678, 5.039, 0.010, 272.668, 9.114},
	{116.960, 55.292, -10.464, 6.162, 5.024, 0.010, 272.841, 8.589},
	{117.511, 55.184, -10.788, -32.361, 5.009, 0.010, 273.006, 8.062},
	{118.062, 55.070, -11.448, -66.017, 4.995, 0.010, 273.164, 7.534},
	{118.612, 54.946, -12.398, -95.014, 4.981, 0.010, 273.313, 7.005},
	{119.160, 54.810, -13.594, -119.623, 4.968, 0.010, 273.455, 6.476},
	{119.706, 54.660, -14.996, -140.161, 4.955, 0.010, 273.589, 5.946},
	{120.251, 54.494, -16.566, -156.996, 4.943, 0.010, 273.717, 5.416},
	{120.794, 54.312, -18.270, -170.454, 4.931, 0.010, 273.838, 4.887},
	{121.335, 54.111, -20.080, -180.924, 4.920, 0.010, 273.952, 4.358},
	{121.874, 53.891, -21.967, -188.732, 4.909, 0.010, 274.060, 3.830},
	{122.411, 53.652, -23.909, -194.220, 4.899, 0.010, 274.162, 3.303},
	{122.945, 53.393, -25.886, -197.695, 4.889, 0.010, 274.258, 2.778},
	{123.476, 53.114, -27.880, -199.441, 4.879, 0.010, 274.349, 2.255},
	{124.004, 52.816, -29.878, -199.729, 4.870, 0.010, 274.434, 1.734},
	{124.529, 52.497, -31.865, -198.774, 4.861, 0.010, 274.514, 1.215},
	{125.051, 52.159, -33.834, -196.816, 4.853, 0.010, 274.590, 0.699},
	{125.569, 51.801, -35.774, -194.009, 4.845, 0.010, 274.660, 0.185},
	{126.083, 51.424, -37.679, -190.538, 4.838, 0.010, 274.726, -0.325},
	{126.593, 51.029, -39.544, -186.536, 4.830, 0.010, 274.788, -0.831},
	{127.099, 50.615, -41.366, -182.134, 4.824, 0.010, 274.846, -1.334},
	{127.601, 50.184, -43.140, -177.430, 4.817, 0.010, 274.900, -1.833},
	{128.099, 49.735, -44.865, -172.513, 4.811, 0.010, 274.951, -2.328},
	{128.591, 49.270, -46.540, -167.461, 4.805, 0.010, 274.998, -2.818},
	{129.079, 48.788, -48.163, -162.355, 4.799, 0.010, 275.041, -3.304},
	{129.562, 48.291, -49.735, -157.210, 4.794, 0.010, 275.082, -3.785},
	{130.040, 47.778, -51.257, -152.116, 4.789, 0.010, 275.120, -4.261},
	{130.512, 47.251, -52.727, -147.062, 4.784, 0.010, 275.154, -4.733},
	{130.979, 46.709, -54.148, -142.120, 4.779, 0.010, 275.187, -5.199},
	{131.441, 46.154, -55.521, -137.283, 4.775, 0.010, 275.216, -5.659},
	{131.897, 45.586, -56.847, -132.577, 4.771, 0.010, 275.244, -6.114},
	{132.347, 45.004, -58.127, -128.018, 4.767, 0.010, 275.269, -6.564},
	{132.791, 44.411, -59.363, -123.611, 4.763, 0.010, 275.292, -7.007},
	{133.229, 43.805, -60.557, -119.366, 4.759, 0.010, 275.314, -7.445},
	{133.661, 43.188, -61.710, -115.284, 4.756, 0.010, 275.333, -7.876},
	{134.087, 42.560, -62.824, -111.368, 4.753, 0.010, 275.351, -8.301},
	{134.506, 41.921, -63.900, -107.608, 4.750, 0.010, 275.367, -8.720},
	{134.918, 41.271, -64.940, -104.018, 4.747, 0.010, 275.382, -9.133},
	{135.325, 40.612, -65.946, -100.584, 4.744, 0.010, 275.396, -9.538},
	{135.724, 39.943, -66.919, -97.299, 4.742, 0.010, 275.408, -9.938},
	{136.117, 39.264, -67.860, -94.167, 4.739, 0.010, 275.419, -10.330},
	{136.502, 38.576, -68.772, -91.178, 4.737, 0.010, 275.429, -10.716},
	{136.881, 37.880, -69.655, -88.319, 4.735, 0.010, 275.438, -11.095},
	{137.253, 37.175, -70.511, -85.595, 4.733, 0.010, 275.446, -11.466},
	{137.618, 36.461, -71.341, -82.989, 4.731, 0.010, 275.453, -11.831},
	{137.975, 35.740, -72.146, -80.503, 4.730, 0.010, 275.460, -12.188},
	{138.325, 35.011, -72.927, -78.116, 4.728, 0.010, 275.465, -12.538},
	{138.668, 34.274, -73.686, -75.836, 4.726, 0.010, 275.471, -12.881},
	{139.003, 33.529, -74.422, -73.646, 4.725, 0.010, 275.475, -13.216},
	{139.331, 32.778, -75.138, -71.541, 4.724, 0.010, 275.479, -13.544},
	{139.651, 32.020, -75.833, -69.513, 4.723, 0.010, 275.482, -13.864},
	{139.964, 31.255, -76.508, -67.559, 4.722, 0.010, 275.485, -14.177},
	{140.268, 30.483, -77.165, -65.662, 4.720, 0.010, 275.488, -14.481},
	{140.565, 29.705, -77.803, -63.826, 4.720, 0.010, 275.490, -14.778},
	{140.855, 28.921, -78.424, -62.040, 4.719, 0.010, 275.492, -15.068},
	{141.136, 28.131, -79.026, -60.298, 4.718, 0.010, 275.494, -15.349},
	{141.409, 27.334, -79.612, -58.588, 4.717, 0.010, 275.495, -15.622},
	{141.675, 26.533, -80.182, -56.914, 4.717, 0.010, 275.497, -15.888},
	{141.932, 25.725, -80.734, -55.264, 4.716, 0.010, 275.498, -16.145},
	{142.181, 24.913, -81.270, -53.633, 4.715, 0.010, 275.498, -16.394},
	{142.422, 24.095, -81.791, -52.017, 4.715, 0.010, 275.499, -16.635},
	{142.655, 23.272, -82.295, -50.411, 4.714, 0.010, 275.500, -16.868},
	{142.879, 22.444, -82.783, -48.809, 4.714, 0.010, 275.500, -17.092},
	{143.095, 21.611, -83.255, -47.206, 4.714, 0.010, 275.500, -17.308},
	{143.303, 20.774, -83.711, -45.604, 4.713, 0.010, 275.500, -17.516},
	{143.502, 19.933, -84.151, -43.990, 4.713, 0.010, 275.501, -17.715},
	{143.693, 19.087, -84.575, -42.368, 4.713, 0.010, 275.501, -17.906},
	{143.876, 18.237, -84.982, -40.732, 4.713, 0.010, 275.501, -18.089},
	{144.049, 17.383, -85.373, -39.080, 4.712, 0.010, 275.501, -18.262},
	{144.215, 16.526, -85.747, -37.410, 4.712, 0.010, 275.501, -18.428},
	{144.371, 15.665, -86.104, -35.717, 4.712, 0.010, 275.501, -18.584},
	{144.519, 14.800, -86.444, -34.006, 4.712, 0.010, 275.501, -18.732},
	{144.659, 13.933, -86.767, -32.268, 4.712, 0.010, 275.501, -18.872},
	{144.789, 13.062, -87.072, -30.507, 4.712, 0.010, 275.501, -19.002},
	{144.911, 12.188, -87.359, -28.721, 4.712, 0.010, 275.501, -19.124},
	{145.024, 11.312, -87.628, -26.910, 4.712, 0.010, 275.501, -19.237},
	{145.129, 10.433, -87.879, -25.074, 4.712, 0.010, 275.500, -19.342},
	{145.224, 9.552, -88.111, -23.213, 4.712, 0.010, 275.500, -19.437},
	{145.311, 8.669, -88.324, -21.328, 4.712, 0.010, 275.500, -19.524},
	{145.389, 7.784, -88.518, -19.420, 4.712, 0.010, 275.500, -19.602},
	{145.458, 6.897, -88.693, -17.491, 4.712, 0.010, 275.500, -19.671},
	{145.518, 6.031, -86.570, 212.340, 4.712, 0.010, 275.500, -19.731},
	{145.570, 5.217, -81.447, 512.333, 4.712, 0.010, 275.500, -19.783},
	{145.615, 4.461, -75.600, 584.669, 4.712, 0.010, 275.500, -19.828},
	{145.652, 3.763, -69.729, 587.084, 4.712, 0.010, 275.500, -19.865},
	{145.684, 3.125, -63.838, 589.143, 4.712, 0.010, 275.500, -19.897},
	{145.709, 2.546, -57.929, 590.873, 4.712, 0.010, 275.500, -19.922},
	{145.729, 2.026, -52.006, 592.299, 4.712, 0.010, 275.500, -19.942},
	{145.745, 1.565, -46.071, 593.451, 4.712, 0.010, 275.500, -19.958},
	{145.757, 1.164, -40.128, 594.358, 4.712, 0.010, 275.500, -19.970},
	{145.765, 0.822, -34.177, 595.047, 4.712, 0.010, 275.500, -19.978},
	{145.770, 0.540, -28.222, 595.549, 4.712, 0.010, 275.500, -19.983},
	{145.773, 0.317, -22.263, 595.893, 4.712, 0.010, 275.500, -19.986},
	{145.775, 0.154, -16.302, 596.109, 4.712, 0.010, 275.500, -19.988},
	{145.775, 0.051, -10.340, 596.228, 4.712, 0.010, 275.500, -19.988},
	{145.776, 0.007, -4.377, 596.279, 4.712, 0.010, 275.500, -19.988},
	{145.776, 0.000, -0.698, 367.912, 4.712, 0.010, 275.500, -19.988}};
};

#endif